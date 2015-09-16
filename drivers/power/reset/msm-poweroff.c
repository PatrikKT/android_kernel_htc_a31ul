/* Copyright (c) 2013-2014, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/delay.h>
#include <linux/err.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/reboot.h>
#include <linux/pm.h>
#include <linux/delay.h>
#include <linux/qpnp/power-on.h>
#include <linux/of_address.h>
#include <linux/console.h>

#include <asm/cacheflush.h>
#include <asm/system_misc.h>

#include <soc/qcom/scm.h>
#include <soc/qcom/restart.h>

#include "htc_restart_handler.h"

#ifdef CONFIG_ARCH_MSM8916
#include <soc/qcom/socinfo.h>
#endif

#define EMERGENCY_DLOAD_MAGIC1    0x322A4F99
#define EMERGENCY_DLOAD_MAGIC2    0xC67E4350
#define EMERGENCY_DLOAD_MAGIC3    0x77777777

#define SCM_IO_DISABLE_PMIC_ARBITER	1
#define SCM_WDOG_DEBUG_BOOT_PART	0x9
#define SCM_DLOAD_MODE			0X10
#define SCM_EDLOAD_MODE			0X01
#define SCM_DLOAD_CMD			0x10

extern void msm_watchdog_bark(void);

static int restart_mode;
static bool scm_pmic_arbiter_disable_supported;
/* Download mode master kill-switch */
static void __iomem *msm_ps_hold;

#ifdef CONFIG_MSM_DLOAD_MODE
#define EDL_MODE_PROP "qcom,msm-imem-emergency_download_mode"
#define DL_MODE_PROP "qcom,msm-imem-download_mode"

static int in_panic;
static void *dload_mode_addr;
static bool dload_mode_enabled;
static void *emergency_dload_mode_addr;
static bool scm_dload_supported;

static int dload_set(const char *val, struct kernel_param *kp);
static int download_mode = 1;
module_param_call(download_mode, dload_set, param_get_int,
			&download_mode, 0644);
static int panic_prep_restart(struct notifier_block *this,
			      unsigned long event, void *ptr)
{
	in_panic = 1;
	return NOTIFY_DONE;
}

static struct notifier_block panic_blk = {
	.notifier_call	= panic_prep_restart,
};

static void set_dload_mode(int on)
{
	int ret;

	if (dload_mode_addr) {
		__raw_writel(on ? 0xE47B337D : 0, dload_mode_addr);
		__raw_writel(on ? 0xCE14091A : 0,
		       dload_mode_addr + sizeof(unsigned int));
		mb();
	}

	if (scm_dload_supported) {
		ret = scm_call_atomic2(SCM_SVC_BOOT,
				SCM_DLOAD_CMD, on ? SCM_DLOAD_MODE : 0, 0);
		if (ret)
			pr_err("Failed to set DLOAD mode: %d\n", ret);
	}

	dload_mode_enabled = on;
}

static bool get_dload_mode(void)
{
	return dload_mode_enabled;
}

static void enable_emergency_dload_mode(void)
{
	int ret;

	if (emergency_dload_mode_addr) {
		__raw_writel(EMERGENCY_DLOAD_MAGIC1,
				emergency_dload_mode_addr);
		__raw_writel(EMERGENCY_DLOAD_MAGIC2,
				emergency_dload_mode_addr +
				sizeof(unsigned int));
		__raw_writel(EMERGENCY_DLOAD_MAGIC3,
				emergency_dload_mode_addr +
				(2 * sizeof(unsigned int)));

		/* Need disable the pmic wdt, then the emergency dload mode
		 * will not auto reset. */
		qpnp_pon_wd_config(0);
		mb();
	}

	if (scm_dload_supported) {
		ret = scm_call_atomic2(SCM_SVC_BOOT,
				SCM_DLOAD_CMD, SCM_EDLOAD_MODE, 0);
		if (ret)
			pr_err("Failed to set EDLOAD mode: %d\n", ret);
	}
}

static int dload_set(const char *val, struct kernel_param *kp)
{
	int ret;
	int old_val = download_mode;

	ret = param_set_int(val, kp);

	if (ret)
		return ret;

	/* If download_mode is not zero or one, ignore. */
	if (download_mode >> 1) {
		download_mode = old_val;
		return -EINVAL;
	}

	set_dload_mode(download_mode);

	return 0;
}
#else
#define set_dload_mode(x) do {} while (0)

static void enable_emergency_dload_mode(void)
{
	pr_err("dload mode is not enabled on target\n");
}
#endif

void msm_set_restart_mode(int mode)
{
	restart_mode = mode;
}
EXPORT_SYMBOL(msm_set_restart_mode);

static void msm_flush_console(void)
{
	unsigned long flags;

	printk("\n");
	printk(KERN_EMERG "[K] Restarting %s\n", linux_banner);
	if (console_trylock()) {
		console_unlock();
		return;
	}

	mdelay(50);

	local_irq_save(flags);

	if (console_trylock())
		printk(KERN_EMERG "[K] restart: Console was locked! Busting\n");
	else
		printk(KERN_EMERG "[K] restart: Console was locked!\n");
	console_unlock();

	local_irq_restore(flags);
}

/*
 * Force the SPMI PMIC arbiter to shutdown so that no more SPMI transactions
 * are sent from the MSM to the PMIC.  This is required in order to avoid an
 * SPMI lockup on certain PMIC chips if PS_HOLD is lowered in the middle of
 * an SPMI transaction.
 */
static void halt_spmi_pmic_arbiter(void)
{
	if (scm_pmic_arbiter_disable_supported) {
		pr_crit("Calling SCM to disable SPMI PMIC arbiter\n");
		scm_call_atomic1(SCM_SVC_PWR, SCM_IO_DISABLE_PMIC_ARBITER, 0);
	}
}

static void msm_restart_prepare(char mode, const char *cmd)
{
#ifdef CONFIG_MSM_DLOAD_MODE

	/* Write download mode flags if we're panic'ing
	 * Write download mode flags if restart_mode says so
	 * Kill download mode if master-kill switch is set
	 */

	set_dload_mode(download_mode &&
			(in_panic || restart_mode == RESTART_DLOAD));
#endif

	
	qpnp_pon_system_pwr_off(PON_POWER_OFF_WARM_RESET);

	pr_info("%s: restart by command: [%s]\r\n", __func__, (cmd) ? cmd : "");

	if (in_panic) {
		
	} else if (cmd != NULL) {
		if (!strncmp(cmd, "bootloader", 10)) {
			set_restart_action(RESTART_REASON_BOOTLOADER, NULL);
		} else if (!strncmp(cmd, "recovery", 8)) {
			set_restart_action(RESTART_REASON_RECOVERY, NULL);
		} else if (!strcmp(cmd, "eraseflash")) {
			set_restart_action(RESTART_REASON_ERASE_FLASH, NULL);
#if defined(CONFIG_HTC_FEATURES_RIL_PCN0001_REBOOT_WITH_ERASE_EFS)
		} else if (!strcmp(cmd, "erase-efs")) {
			set_restart_action(RESTART_REASON_ERASE_EFS, NULL);
#endif
		} else if (!strncmp(cmd, "oem-", 4)) {
			unsigned long code;
			code = simple_strtoul(cmd + 4, NULL, 16) & 0xff;
			set_restart_to_oem(code, NULL);
		} else if (!strncmp(cmd, "ftm", 3)) {
			#define FTM_BASE_FLAG 0xf0
			unsigned long code;
			code = (simple_strtoul(cmd + 3, NULL, 16) & 0xff) | FTM_BASE_FLAG;
			set_restart_to_oem(code, NULL);
		} else if (!strncmp(cmd, "edl", 3)) {
			enable_emergency_dload_mode();
		} else if (!strncmp(cmd, "force-dog-bark", 14)) {
			set_restart_to_ramdump("force-dog-bark");
		} else if (!strncmp(cmd, "force-hard", 10)) {
				set_restart_action(RESTART_REASON_RAMDUMP, cmd);
		} else {
				set_restart_action(RESTART_REASON_REBOOT, NULL);
		}
	} else {
		set_restart_action(RESTART_REASON_REBOOT, NULL);
	}

	msm_flush_console();
	flush_cache_all();

	/*outer_flush_all is not supported by 64bit kernel*/
#ifndef CONFIG_ARM64
	outer_flush_all();
#endif

	if (cmd && !strncmp(cmd, "force-dog-bark", 14)) {
		pr_info("%s: Force dog bark!\r\n", __func__);
#if defined(CONFIG_HTC_DEBUG_WATCHDOG)
		msm_watchdog_bark();
#endif
		mdelay(10000);
		pr_info("%s: Force Watchdog bark does not work, falling back to normal process.\r\n", __func__);
	}
}

static void do_msm_restart(enum reboot_mode reboot_mode, const char *cmd)
{
	int ret;

	pr_notice("[K] Going down for restart now\n");

	msm_restart_prepare((char)reboot_mode, cmd);

	/* Needed to bypass debug image on some chips */
	ret = scm_call_atomic2(SCM_SVC_BOOT,
			       SCM_WDOG_DEBUG_BOOT_PART, 1, 0);
	if (ret)
		pr_err("Failed to disable wdog debug: %d\n", ret);

	halt_spmi_pmic_arbiter();
	__raw_writel(0, msm_ps_hold);

	mdelay(10000);
}

static void do_msm_poweroff(void)
{
	int ret;

	pr_notice("[K] Powering off the SoC\n");
#ifdef CONFIG_MSM_DLOAD_MODE
	set_dload_mode(0);
#endif
	qpnp_pon_system_pwr_off(PON_POWER_OFF_SHUTDOWN);
	/* Needed to bypass debug image on some chips */
	ret = scm_call_atomic2(SCM_SVC_BOOT,
			       SCM_WDOG_DEBUG_BOOT_PART, 1, 0);
	if (ret)
		pr_err("Failed to disable wdog debug: %d\n", ret);

	halt_spmi_pmic_arbiter();
	/* MSM initiated power off, lower ps_hold */
	__raw_writel(0, msm_ps_hold);

	mdelay(10000);
	pr_err("Powering off has failed\n");
	return;
}

static int msm_restart_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct resource *mem;
#ifdef CONFIG_MSM_DLOAD_MODE
	struct device_node *np;
#endif
	int ret = 0;

	ret = htc_restart_handler_init();
	if (ret) {
		pr_err("htc restart handler init fail\n");
		goto err_htc_restart_handle;
	}

	atomic_notifier_chain_register(&panic_notifier_list, &panic_blk);
#ifdef CONFIG_MSM_DLOAD_MODE
	if (scm_is_call_available(SCM_SVC_BOOT, SCM_DLOAD_CMD) > 0)
		scm_dload_supported = true;

	np = of_find_compatible_node(NULL, NULL, DL_MODE_PROP);
	if (!np) {
		pr_err("unable to find DT imem DLOAD mode node\n");
	} else {
		dload_mode_addr = of_iomap(np, 0);
		if (!dload_mode_addr)
			pr_err("unable to map imem DLOAD offset\n");
	}

	np = of_find_compatible_node(NULL, NULL, EDL_MODE_PROP);
	if (!np) {
		pr_err("unable to find DT imem EDLOAD mode node\n");
	} else {
		emergency_dload_mode_addr = of_iomap(np, 0);
		if (!emergency_dload_mode_addr)
			pr_err("unable to map imem EDLOAD mode offset\n");
	}

	set_dload_mode(download_mode);
#endif

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	msm_ps_hold = devm_ioremap_resource(dev, mem);
	if (IS_ERR(msm_ps_hold))
		return PTR_ERR(msm_ps_hold);

	pm_power_off = do_msm_poweroff;
	arm_pm_restart = do_msm_restart;

	if (scm_is_call_available(SCM_SVC_PWR, SCM_IO_DISABLE_PMIC_ARBITER) > 0)
		scm_pmic_arbiter_disable_supported = true;

#ifdef CONFIG_ARCH_MSM8916
	
	ret = scm_call_atomic2(SCM_SVC_BOOT,
			       SCM_WDOG_DEBUG_BOOT_PART, 1, 0);
	if (ret)
		pr_err("Failed to disable wdog debug: %d\n", ret);
#endif

	return 0;

#ifdef CONFIG_MSM_DLOAD_MODE
	iounmap(emergency_dload_mode_addr);
	iounmap(dload_mode_addr);
#endif
err_htc_restart_handle:
	return ret;
}

static const struct of_device_id of_msm_restart_match[] = {
	{ .compatible = "qcom,pshold", },
	{},
};
MODULE_DEVICE_TABLE(of, of_msm_restart_match);

static struct platform_driver msm_restart_driver = {
	.probe = msm_restart_probe,
	.driver = {
		.name = "msm-restart",
		.of_match_table = of_match_ptr(of_msm_restart_match),
	},
};

static int __init msm_restart_init(void)
{
	return platform_driver_register(&msm_restart_driver);
}
device_initcall(msm_restart_init);
