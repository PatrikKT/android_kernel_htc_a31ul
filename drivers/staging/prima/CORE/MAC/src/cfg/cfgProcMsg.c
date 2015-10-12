/*
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
/*
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#include "palTypes.h"
#include "aniGlobal.h"
#include "cfgPriv.h"
#include "cfgDebug.h"
#include "wlan_qct_wda.h"


static void ProcDnldRsp        (tpAniSirGlobal, tANI_U16, tANI_U32*);
static void ProcGetReq         (tpAniSirGlobal, tANI_U16, tANI_U32*);
static void ProcSetReq         (tpAniSirGlobal, tANI_U16, tANI_U32*);
static void ProcSetReqNoRsp    (tpAniSirGlobal, tANI_U16, tANI_U32*);

static tANI_U8 CheckParam(tpAniSirGlobal, tANI_U16, tANI_U32, tANI_U32, tANI_U32*);
static void GetStrValue(tANI_U8*, tANI_U8*, tANI_U32);



void    (*gCfgFunc[])(tpAniSirGlobal, tANI_U16, tANI_U32*) =
{ ProcDnldRsp,
    ProcGetReq,
    ProcSetReq,
    ProcSetReqNoRsp
};

void
cfgProcessMbMsg(tpAniSirGlobal pMac, tSirMbMsg *pMsg)
{
    tANI_U16    index;
    tANI_U16    len;
    tANI_U32   *pParam;

    
    index = CFG_GET_FUNC_INDX(pMsg->type);

    if (index >= (sizeof(gCfgFunc) / sizeof(gCfgFunc[0])))
    {
        vos_mem_free(pMsg);
        return;
    }
    len    = pMsg->msgLen - WNI_CFG_MB_HDR_LEN;
    pParam = ((tANI_U32*)pMsg) + 1;

    
    gCfgFunc[index](pMac, len, pParam);

    
    vos_mem_free(pMsg);

} 

static void
ProcDnldRsp(tpAniSirGlobal pMac, tANI_U16 length, tANI_U32 *pParam)
{
    tANI_S32    i;

    tANI_U32    expLen, retVal, bufStart, bufEnd;
    tANI_U32    *pSrc, *pDst, *pDstEnd;
    tANI_U32    strSize, j;
    tANI_U8     pStr[CFG_MAX_STR_LEN];
    tpCfgBinHdr pHdr;
    tANI_U32    logLevel;
    tSirMsgQ    mmhMsg;

    
    PELOGW(cfgLog(pMac, LOGW, FL("CFG size %d bytes MAGIC dword is 0x%x"),
           length, sirReadU32N((tANI_U8*)pParam) );)

    
        if (*pParam == CFG_STA_MAGIC_DWORD) {}




    else
    {
        PELOGE(cfgLog(pMac, LOGE, FL("Invalid magic dword 0x%x"),sirReadU32N((tANI_U8*)pParam) );)
        retVal = WNI_CFG_INVALID_LEN;
        goto end;
    }

    pParam++;
    length -= 4;

    
    {
        pMac->cfg.gCfgMaxIBufSize = CFG_STA_IBUF_MAX_SIZE;
        pMac->cfg.gCfgMaxSBufSize = CFG_STA_SBUF_MAX_SIZE;
    }

    
    pHdr = (tpCfgBinHdr) pParam;
    pParam += (sizeof(tCfgBinHdr) >> 2);
    PELOGW(cfgLog(pMac, LOGW, FL("CFG hdr totParams %d intParams %d strBufSize %d/%d"),
           pHdr->controlSize, pHdr->iBufSize, pHdr->sBufSize, pMac->cfg.gCfgMaxSBufSize);)

    expLen = ((CFG_PARAM_MAX_NUM + 3 * pMac->cfg.gCfgMaxIBufSize) << 2) +
             pHdr->sBufSize + sizeof(tCfgBinHdr);

    if (length != expLen)
    {
        PELOGE(cfgLog(pMac, LOGE, FL("<CFG> DNLD_RSP invalid length %d (exp %d)"),
               length, expLen);)
        retVal = WNI_CFG_INVALID_LEN;
        goto end;
    }


    if (pHdr->controlSize != CFG_PARAM_MAX_NUM)
    {
        PELOGE(cfgLog(pMac, LOGE, FL("<CFG> Total parameter count mismatch"));)
        retVal = WNI_CFG_INVALID_LEN;
        goto end;
    }

    if (pHdr->iBufSize != pMac->cfg.gCfgMaxIBufSize)
    {
        PELOGE(cfgLog(pMac, LOGE, FL("<CFG> Integer parameter count mismatch"));)
        retVal = WNI_CFG_INVALID_LEN;
        goto end;
    }

    
    pDst = (tANI_U32*)pMac->cfg.gCfgEntry;
    pDstEnd = pDst + CFG_PARAM_MAX_NUM;
    pSrc = pParam;
    while (pDst < pDstEnd)
    {
        *pDst++ = *pSrc++;
    }
    
    pDst = pMac->cfg.gCfgIBuf;
    pDstEnd = pDst + pMac->cfg.gCfgMaxIBufSize;
    while (pDst < pDstEnd)
    {
        *pDst++ = *pSrc++;
    }

    
    pDst = pMac->cfg.gCfgIBufMin;
    pDstEnd = pDst + pMac->cfg.gCfgMaxIBufSize;
    while (pDst < pDstEnd)
    {
        *pDst++ = *pSrc++;
    }

    
    pDst = pMac->cfg.gCfgIBufMax;
    pDstEnd = pDst + pMac->cfg.gCfgMaxIBufSize;
    while (pDst < pDstEnd)
    {
        *pDst++ = *pSrc++;
    }

    for (i=0; i<pMac->cfg.gCfgMaxIBufSize; i++)
        if (pMac->cfg.gCfgIBuf[i] < pMac->cfg.gCfgIBufMin[i] ||
            pMac->cfg.gCfgIBuf[i] > pMac->cfg.gCfgIBufMax[i])
        {
            PELOGE(cfgLog(pMac, LOGE, FL("cfg id %d Invalid def value %d "
                            "min %d max %d"),
                   i, pMac->cfg.gCfgIBuf[i], pMac->cfg.gCfgIBufMin[i],
                   pMac->cfg.gCfgIBufMax[i]);)
        }

    
    bufEnd = pMac->cfg.gCfgMaxSBufSize;
    for (i = CFG_PARAM_MAX_NUM - 1; i >= 0; i--)
    {
        if ((pMac->cfg.gCfgEntry[i].control & CFG_CTL_INT) != 0)
            continue;

        if ((pMac->cfg.gCfgEntry[i].control & CFG_CTL_VALID) == 0)
            continue;

        bufStart = pMac->cfg.gCfgEntry[i].control & CFG_BUF_INDX_MASK;
        pMac->cfg.gCfgSBuf[bufStart] = (tANI_U8)(bufEnd - bufStart - 2);

       PELOG1(cfgLog(pMac, LOG1, FL("id %d max %d bufStart %d bufEnd %d"),
               i, pMac->cfg.gCfgSBuf[bufStart], bufStart, bufEnd);)

        bufEnd = bufStart;
    }

    
    strSize = pHdr->sBufSize;
    while (strSize)
    {
        tANI_U32 paramId, paramLen, paramLenCeil4;

        if (strSize < 4)
        {
            PELOGE(cfgLog(pMac, LOGE, FL("Error parsing str defaults, rem %d bytes"), strSize);)
            retVal = WNI_CFG_INVALID_LEN;
            goto end;
        }
        paramId = *pSrc >> 16;
        paramLen = *pSrc & 0xff;
        pSrc++;
        strSize -= 4;

        paramLenCeil4 = ((paramLen + 3) >> 2);
        if (strSize < paramLenCeil4 << 2)
        {
            PELOGE(cfgLog(pMac, LOGE, FL("Error parsing str defaults, rem %d bytes"), strSize);)
            PELOGE(cfgLog(pMac, LOGE, FL("param id %d len %d bytes"), paramId, paramLen);)
            retVal = WNI_CFG_INVALID_LEN;
            goto end;
        }
        for (j=0; j < paramLenCeil4; j++)
        {
            pStr[4*j] = (tANI_U8) (*pSrc >> 24) & 0xff;
            pStr[4*j+1] = (tANI_U8) (*pSrc >> 16) & 0xff;
            pStr[4*j+2] = (tANI_U8) (*pSrc >> 8) & 0xff;
            pStr[4*j+3] = (tANI_U8) (*pSrc) & 0xff;

            pSrc++;
            strSize -= 4;
        }

        PELOG1(cfgLog(pMac, LOG1, FL("set str id %d len %d"), paramId, paramLen);)

        if (cfgSetStr(pMac, (tANI_U16) paramId, pStr, paramLen) != eSIR_SUCCESS)
        {
            PELOGE(cfgLog(pMac, LOGE, FL("Error setting str default param %d len %d"), paramId, paramLen);)
            retVal = WNI_CFG_INVALID_LEN;
            goto end;
        }
    }

    
    wlan_cfgGetInt(pMac, WNI_CFG_LOG_LEVEL, &logLevel);
    for (i = 0; i < LOG_ENTRY_NUM; i++)
        pMac->utils.gLogEvtLevel[i] = pMac->utils.gLogDbgLevel[i] = logLevel;

    
    pMac->cfg.gCfgStatus = CFG_SUCCESS;
    retVal = WNI_CFG_SUCCESS;
    PELOG1(cfgLog(pMac, LOG1, "<CFG> Completed successfully");)

    end:

    if ( retVal != WNI_CFG_SUCCESS )
        pMac->cfg.gCfgStatus = CFG_FAILURE;

    
    pMac->cfg.gParamList[WNI_CFG_DNLD_CNF_RES] = retVal;
    cfgSendHostMsg(pMac, WNI_CFG_DNLD_CNF, WNI_CFG_DNLD_CNF_LEN,
                   WNI_CFG_DNLD_CNF_NUM, pMac->cfg.gParamList, 0, 0);

    
    mmhMsg.type = SIR_CFG_DOWNLOAD_COMPLETE_IND;
    mmhMsg.bodyptr = NULL;
    mmhMsg.bodyval = 0;

    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    if (wdaPostCtrlMsg(pMac, &mmhMsg) != eSIR_SUCCESS)
    {
        PELOGE(cfgLog(pMac, LOGE, FL("WDAPostMsgApi failed!"));)
    }

} 


static void
ProcGetReq(tpAniSirGlobal pMac, tANI_U16 length, tANI_U32 *pParam)
{
    tANI_U16    cfgId, i;
    tANI_U32    value, valueLen, result;
    tANI_U32    *pValue;

    PELOG1(cfgLog(pMac, LOG1, FL("Rcvd cfg get request %d bytes"), length);)
    for (i=0; i<length/4; i++)
        PELOG2(cfgLog(pMac, LOG2, FL("[%2d] 0x%08x"), i, pParam[i]);)

    if (!pMac->cfg.gCfgStatus)
    {
        cfgId = (tANI_U16)sirReadU32N((tANI_U8*)pParam);
        PELOGE(cfgLog(pMac, LOGE, FL("CFG not ready, param %d"), cfgId);)
        pMac->cfg.gParamList[WNI_CFG_GET_RSP_RES]  = WNI_CFG_NOT_READY;
        pMac->cfg.gParamList[WNI_CFG_GET_RSP_PID]  = cfgId;
        pMac->cfg.gParamList[WNI_CFG_GET_RSP_PLEN] = 0;
        cfgSendHostMsg(pMac, WNI_CFG_GET_RSP, WNI_CFG_GET_RSP_PARTIAL_LEN,
                       WNI_CFG_GET_RSP_NUM, pMac->cfg.gParamList, 0, 0);
    }
    else
    {
        
        while (length >= sizeof(tANI_U32))
        {
            cfgId = (tANI_U16)*pParam++;
            pValue   = 0;
            valueLen = 0;

            PELOG1(cfgLog(pMac, LOG1, FL("Cfg get param %d"), cfgId);)

            
            if (CheckParam(pMac, cfgId, CFG_CTL_RE, WNI_CFG_WO_PARAM, &result))
            {
                if ((pMac->cfg.gCfgEntry[cfgId].control & CFG_CTL_INT) != 0)
                {
                    
                    result = (wlan_cfgGetInt(pMac, cfgId, &value) == eSIR_SUCCESS ?
                              WNI_CFG_SUCCESS : WNI_CFG_OTHER_ERROR);
                    pValue   = &value;
                    valueLen = sizeof(tANI_U32);
                }
                else
                {
                    
                    valueLen = sizeof(pMac->cfg.gSBuffer);
                    result = (wlan_cfgGetStr(pMac, cfgId, pMac->cfg.gSBuffer, &valueLen)
                              == eSIR_SUCCESS ?
                              WNI_CFG_SUCCESS : WNI_CFG_OTHER_ERROR);
                    pValue = (tANI_U32*)pMac->cfg.gSBuffer;
                }
            }
            else
            {
                PELOGE(cfgLog(pMac, LOGE, FL("Check param failed, param %d"), cfgId);)
                result = WNI_CFG_INVALID_LEN;
            }

            
            pMac->cfg.gParamList[WNI_CFG_GET_RSP_RES]  = result;
            pMac->cfg.gParamList[WNI_CFG_GET_RSP_PID]  = cfgId;
            pMac->cfg.gParamList[WNI_CFG_GET_RSP_PLEN] = valueLen;

            
            valueLen = (((valueLen + 3) >> 2) << 2);
            cfgSendHostMsg(pMac, WNI_CFG_GET_RSP,
                           WNI_CFG_GET_RSP_PARTIAL_LEN + valueLen,
                           WNI_CFG_GET_RSP_NUM, pMac->cfg.gParamList, valueLen, pValue);

            
            length -= sizeof(tANI_U32);
        }
    }

} 



static void
ProcSetReqInternal(tpAniSirGlobal pMac, tANI_U16 length, tANI_U32 *pParam, tANI_BOOLEAN fRsp)
{
    tANI_U16    cfgId, valueLen, valueLenRoundedUp4;
    tANI_U32    value, result;

    PELOG1(cfgLog(pMac, LOG1, FL("Rcvd cfg set request %d bytes"), length);)
    
      

    if (!pMac->cfg.gCfgStatus)
    {
        cfgId = (tANI_U16)sirReadU32N((tANI_U8*)pParam);
        PELOG1(cfgLog(pMac, LOGW, FL("CFG not ready, param %d"), cfgId);)
        pMac->cfg.gParamList[WNI_CFG_SET_CNF_RES] = WNI_CFG_NOT_READY;
        pMac->cfg.gParamList[WNI_CFG_SET_CNF_PID] = cfgId;
        if( fRsp )
        {
           cfgSendHostMsg(pMac, WNI_CFG_SET_CNF, WNI_CFG_SET_CNF_LEN,
                          WNI_CFG_SET_CNF_NUM, pMac->cfg.gParamList, 0, 0);
        }
    }
    else
    {
        
        while (length >= (sizeof(tANI_U32) * 2))
        {
            cfgId    = (tANI_U16) *pParam++;
            valueLen = (tANI_U16) *pParam++;
            length -= (sizeof(tANI_U32) * 2);
            
            valueLenRoundedUp4 = (((valueLen + 3) >> 2) << 2);

            
            if (CheckParam(pMac, cfgId, CFG_CTL_WE, WNI_CFG_RO_PARAM, &result))
            {
                PELOG1(cfgLog(pMac, LOGW, (char *) gCfgParamName[cfgId]);)
                
                if ((pMac->cfg.gCfgEntry[cfgId].control & CFG_CTL_INT) != 0)
                {
                    
                    if (valueLen != sizeof(tANI_U32))
                    {
                        PELOGE(cfgLog(pMac, LOGE, FL("Invalid value length %d in set param %d (tot %d)"),
                               valueLen, cfgId, length);)
                        result = WNI_CFG_INVALID_LEN;
                    }
                    else
                    {
                        value = *pParam;
                        PELOG1(cfgLog(pMac, LOGW, FL("Cfg set int %d len %d(%d) val %d"),
                               cfgId, valueLen, valueLenRoundedUp4, value);)
                        result = (cfgSetInt(pMac, cfgId, value) == eSIR_SUCCESS ?
                                  WNI_CFG_SUCCESS : WNI_CFG_OTHER_ERROR);
                        if (result == WNI_CFG_SUCCESS)
                        {
                            if (cfgNeedRestart(pMac, cfgId))
                            {
                                result = WNI_CFG_NEED_RESTART ;
                            }
                            else
                                if (cfgNeedReload(pMac, cfgId))
                                {
                                   result = WNI_CFG_NEED_RELOAD ;
                                }
                        }
                    }
                }
                
                else
                {
                    if (valueLenRoundedUp4 > length)
                    {
                        PELOGE(cfgLog(pMac, LOGE, FL("Invalid string length %d"
                               "in set param %d (tot %d)"), valueLen,
                                                       cfgId, length);)
                        result = WNI_CFG_INVALID_LEN;
                    }
                    else
                    {
                        GetStrValue((tANI_U8*)pParam, pMac->cfg.gSBuffer, valueLen);
                        PELOG1(cfgLog(pMac, LOGW, FL("Cfg set str %d len %d(%d) bytes"),
                               cfgId, valueLen, valueLenRoundedUp4);)
                        result = (cfgSetStr(pMac, cfgId, pMac->cfg.gSBuffer, valueLen) == eSIR_SUCCESS ?
                                  WNI_CFG_SUCCESS : WNI_CFG_OTHER_ERROR);
                        if (result == WNI_CFG_SUCCESS)
                        {
                            if (cfgNeedRestart(pMac, cfgId))
                            {
                                result = WNI_CFG_NEED_RESTART ;
                            }
                            else
                                if (cfgNeedReload(pMac, cfgId))
                                {
                                   result = WNI_CFG_NEED_RELOAD ;
                                }
                        }
                    }
                }
            }
            else
            {
                PELOGE(cfgLog(pMac, LOGE, FL("Check param failed, param %d"), cfgId);)
                result = WNI_CFG_INVALID_LEN;
            }

            
            pMac->cfg.gParamList[WNI_CFG_SET_CNF_RES] = result;
            pMac->cfg.gParamList[WNI_CFG_SET_CNF_PID] = cfgId;
            if( fRsp )
            {
                cfgSendHostMsg(pMac, WNI_CFG_SET_CNF, WNI_CFG_SET_CNF_LEN,
                               WNI_CFG_SET_CNF_NUM, pMac->cfg.gParamList, 0, 0);
            }
            else
            {
                PELOGW(cfgLog( pMac, LOG2, "  CFGID %d no rsp", cfgId);)
            }

            if (valueLenRoundedUp4 > length)
                length = 0;
            else
            {
                length -= valueLenRoundedUp4;
                pParam += (valueLenRoundedUp4 >> 2);
            }
        }
    }
}



static void
ProcSetReq(tpAniSirGlobal pMac, tANI_U16 length, tANI_U32 *pParam)
{
    ProcSetReqInternal( pMac, length, pParam, eANI_BOOLEAN_TRUE );
}

static void
ProcSetReqNoRsp(tpAniSirGlobal pMac, tANI_U16 length, tANI_U32 *pParam)
{
    ProcSetReqInternal( pMac, length, pParam, eANI_BOOLEAN_FALSE );
}



static tANI_U8
CheckParam(tpAniSirGlobal pMac, tANI_U16 cfgId, tANI_U32 flag, tANI_U32 failedResult, tANI_U32 *pResult)
{
    
    if (cfgId >= CFG_PARAM_MAX_NUM)
    {
        PELOGE(cfgLog(pMac, LOGE, FL("Invalid param id %d"), cfgId);)
        *pResult = WNI_CFG_INVALID_PID;
    }
    else
    {
        
        if ((pMac->cfg.gCfgEntry[cfgId].control & CFG_CTL_VALID) == 0)
        {
            PELOGE(cfgLog(pMac, LOGE, FL("Param id %d not valid"), cfgId);)
            *pResult = WNI_CFG_INVALID_PID;
        }
        else
        {
            
            if ((pMac->cfg.gCfgEntry[cfgId].control & flag) == 0)
            {
                PELOGE(cfgLog(pMac, LOGE, FL("Param id %d wrong permissions %x"),
                       cfgId, pMac->cfg.gCfgEntry[cfgId].control);)
                *pResult = failedResult;
            }
            else
                return(true);
        }
    }
    return(false);

} 


static void
GetStrValue(tANI_U8 *pBuf, tANI_U8 *pValue, tANI_U32 length)
{
    tANI_U8     *pEnd;

    pEnd = pValue + length;
    while (pValue < pEnd)
        *pValue++ = *pBuf++;
} 



void
processCfgDownloadReq(tpAniSirGlobal pMac, tANI_U16 length, 
                      tANI_U32 *pConfig)
{
    tANI_S32    i;

    tANI_U32    expLen, retVal, bufStart, bufEnd;
    tANI_U32    *pSrc, *pDst, *pDstEnd;
    tANI_U32    strSize, j;
    tANI_U8     pStr[CFG_MAX_STR_LEN];
    tpCfgBinHdr pHdr;
    tANI_U32    logLevel;

    
    PELOGW(cfgLog(pMac, LOGW, FL("CFG size %d bytes MAGIC dword is 0x%x"),
           length, sirReadU32N((tANI_U8*)pConfig) );)

    
    if (CFG_STA_MAGIC_DWORD != *pConfig)
    {
        PELOGE(cfgLog(pMac, LOGE, FL("Invalid magic dword 0x%x"),
                                             sirReadU32N((tANI_U8*)pConfig) );)
        retVal = WNI_CFG_INVALID_LEN;
        goto end;
    }

    pConfig++;
    length -= 4;

    
    pMac->cfg.gCfgMaxIBufSize = CFG_STA_IBUF_MAX_SIZE;
    pMac->cfg.gCfgMaxSBufSize = CFG_STA_SBUF_MAX_SIZE;

    
    pHdr = (tpCfgBinHdr) pConfig;
    pConfig += (sizeof(tCfgBinHdr) >> 2);

    PELOGW(cfgLog(pMac, LOGW, FL("CFG hdr totParams %d intParams %d strBufSize %d/%d"),
                           pHdr->controlSize,pHdr->iBufSize,
                         pHdr->sBufSize, pMac->cfg.gCfgMaxSBufSize);)

    expLen = ((CFG_PARAM_MAX_NUM + 3 * pMac->cfg.gCfgMaxIBufSize) << 2) +
                                            pHdr->sBufSize + sizeof(tCfgBinHdr);

    if (length != expLen)
    {
        PELOGE(cfgLog(pMac, LOGE, FL("<CFG> DNLD_RSP invalid length %d (exp %d)"),
               length, expLen);)
        retVal = WNI_CFG_INVALID_LEN;
        goto end;
    }


    if (CFG_PARAM_MAX_NUM != pHdr->controlSize )
    {
        PELOGE(cfgLog(pMac, LOGE, FL("<CFG> Total parameter count mismatch"));)
        retVal = WNI_CFG_INVALID_LEN;
        goto end;
    }

    if (pHdr->iBufSize != pMac->cfg.gCfgMaxIBufSize)
    {
        PELOGE(cfgLog(pMac, LOGE, FL("<CFG> Integer parameter count mismatch"));)
        retVal = WNI_CFG_INVALID_LEN;
        goto end;
    }

    
    pDst = (tANI_U32*)pMac->cfg.gCfgEntry;
    pDstEnd = pDst + CFG_PARAM_MAX_NUM;
    pSrc = pConfig;
    while (pDst < pDstEnd)
    {
        *pDst++ = *pSrc++;
    }

    
    pDst = pMac->cfg.gCfgIBuf;
    pDstEnd = pDst + pMac->cfg.gCfgMaxIBufSize;
    while (pDst < pDstEnd)
    {
        *pDst++ = *pSrc++;
    }

    
    pDst = pMac->cfg.gCfgIBufMin;
    pDstEnd = pDst + pMac->cfg.gCfgMaxIBufSize;
    while (pDst < pDstEnd)
    {
        *pDst++ = *pSrc++;
    }

    
    pDst = pMac->cfg.gCfgIBufMax;
    pDstEnd = pDst + pMac->cfg.gCfgMaxIBufSize;
    while (pDst < pDstEnd)
    {
        *pDst++ = *pSrc++;
    }

    for (i=0; i<pMac->cfg.gCfgMaxIBufSize; i++)
    {
        if (pMac->cfg.gCfgIBuf[i] < pMac->cfg.gCfgIBufMin[i] ||
            pMac->cfg.gCfgIBuf[i] > pMac->cfg.gCfgIBufMax[i])
        {
            PELOGE(cfgLog(pMac, LOGE, FL("cfg id %d Invalid def value %d "
                             "min %d max %d"),
                             i, pMac->cfg.gCfgIBuf[i], pMac->cfg.gCfgIBufMin[i],
                             pMac->cfg.gCfgIBufMax[i]);)
        }
    }

    
    bufEnd = pMac->cfg.gCfgMaxSBufSize;
    for (i = CFG_PARAM_MAX_NUM - 1; i >= 0; i--)
    {
        if ((pMac->cfg.gCfgEntry[i].control & CFG_CTL_INT) != 0)
            continue;

        if ((pMac->cfg.gCfgEntry[i].control & CFG_CTL_VALID) == 0)
            continue;

        bufStart = pMac->cfg.gCfgEntry[i].control & CFG_BUF_INDX_MASK;
        pMac->cfg.gCfgSBuf[bufStart] = (tANI_U8)(bufEnd - bufStart - 2);

        PELOG1(cfgLog(pMac, LOG1, FL("id %d max %d bufStart %d bufEnd %d"),
               i, pMac->cfg.gCfgSBuf[bufStart], bufStart, bufEnd);)

        bufEnd = bufStart;
    }

    
    strSize = pHdr->sBufSize;
    while (strSize)
    {
        tANI_U32 paramId, paramLen, paramLenCeil4;

        if (strSize < 4)
        {
            PELOGE(cfgLog(pMac, LOGE, FL("Error parsing str defaults, rem %d bytes"),
                                                                      strSize);)
            retVal = WNI_CFG_INVALID_LEN;
            goto end;
        }
        paramId = *pSrc >> 16;
        paramLen = *pSrc & 0xff;

        pSrc++;
        strSize -= 4;

        paramLenCeil4 = ((paramLen + 3) >> 2);
        if (strSize < paramLenCeil4 << 2)
        {
            PELOGE(cfgLog(pMac, LOGE, FL("Error parsing str defaults, rem %d"
                                                            "bytes"), strSize);)
            PELOGE(cfgLog(pMac, LOGE, FL("param id %d len %d bytes"),
                                                            paramId, paramLen);)
            retVal = WNI_CFG_INVALID_LEN;
            goto end;
        }

        for (j=0; j < paramLenCeil4; j++)
        {
            pStr[4*j] = (tANI_U8) (*pSrc >> 24) & 0xff;
            pStr[4*j+1] = (tANI_U8) (*pSrc >> 16) & 0xff;
            pStr[4*j+2] = (tANI_U8) (*pSrc >> 8) & 0xff;
            pStr[4*j+3] = (tANI_U8) (*pSrc) & 0xff;

            pSrc++;
            strSize -= 4;
        }

        PELOG1(cfgLog(pMac, LOG1, FL("set str id %d len %d"), paramId, paramLen);)

        if (cfgSetStrNotify(pMac, (tANI_U16)paramId, pStr, paramLen, FALSE) != eSIR_SUCCESS)
        {
            PELOGE(cfgLog(pMac, LOGE, FL("Error setting str default param %d "
                                                "len %d"), paramId, paramLen);)
            retVal = WNI_CFG_INVALID_LEN;
            goto end;
        }
    }

    
    wlan_cfgGetInt(pMac, WNI_CFG_LOG_LEVEL, &logLevel);
    for (i = 0; i < LOG_ENTRY_NUM; i++)
        pMac->utils.gLogEvtLevel[i] = pMac->utils.gLogDbgLevel[i] = logLevel;

    
    pMac->cfg.gCfgStatus = CFG_SUCCESS;
    retVal = WNI_CFG_SUCCESS;
    PELOG1(cfgLog(pMac, LOG1, "<CFG> Completed successfully");)

end:

    if ( WNI_CFG_SUCCESS != retVal )
        pMac->cfg.gCfgStatus = CFG_FAILURE;

    pMac->cfg.gParamList[WNI_CFG_DNLD_CNF_RES] = retVal;

} 




