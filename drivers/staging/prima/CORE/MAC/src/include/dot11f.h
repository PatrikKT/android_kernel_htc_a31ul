/*
 * Copyright (c) 2012-2014 The Linux Foundation. All rights reserved.
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


#ifndef DOT11F_H
#define DOT11F_H

typedef tANI_U32 tDOT11F_U64[2];

#if defined ( _MSC_VER )
#   pragma warning (disable: 4214) 
#endif 


#define DOT11F_PARSE_SUCCESS         ( 0x00000000 )
#define DOT11F_UNKNOWN_IES           ( 0x00000001 )
#define DOT11F_MANDATORY_IE_MISSING  ( 0x00000002 )
#define DOT11F_INCOMPLETE_IE         ( 0x00000004 )
#define DOT11F_SKIPPED_BAD_IE        ( 0x00000008 )
#define DOT11F_LAST_IE_TOO_LONG      ( 0x00000010 )
#define DOT11F_DUPLICATE_IE          ( 0x00000020 )
#define DOT11F_BAD_FIXED_VALUE       ( 0x00000040 )
#define DOT11F_INCOMPLETE_TLV        ( 0x00000080 )
#define DOT11F_INVALID_TLV_LENGTH    ( 0x00000100 )
#define DOT11F_SKIPPED_BAD_TLV       ( 0x00000200 )
#define DOT11F_UNKNOWN_TLVS          ( 0x00000400 )
#define DOT11F_LAST_TLV_TOO_LONG     ( 0x00000800 )
#define DOT11F_INTERNAL_ERROR        ( 0x10000001 )
#define DOT11F_MISSING_FIXED_FIELD   ( 0x10000002 )
#define DOT11F_BAD_INPUT_BUFFER      ( 0x10000003 )
#define DOT11F_BAD_OUTPUT_BUFFER     ( 0x10000004 )
#define DOT11F_BUFFER_OVERFLOW       ( 0x10000005 )
#define DOT11F_MANDATORY_TLV_MISSING ( 0x00001000 )
#define DOT11F_FAILED(code)          ( (code) & 0x10000000 )
#define DOT11F_WARNED(code)          ( ( ( 0 == (code) ) & 0x10000000 ) && code)
#define DOT11F_SUCCEEDED(code)       ( (code) == 0 )


typedef struct sDot11fFfAID {
    tANI_U16 associd;
} tDot11fFfAID;

#define DOT11F_FF_AID_LEN ( 2 )

void dot11fUnpackFfAID(tpAniSirGlobal, tANI_U8*, tDot11fFfAID*);

void dot11fPackFfAID(tpAniSirGlobal, tDot11fFfAID*, tANI_U8*);

typedef struct sDot11fFfAction {
    tANI_U8 action;
} tDot11fFfAction;

#define DOT11F_FF_ACTION_LEN ( 1 )

void dot11fUnpackFfAction(tpAniSirGlobal, tANI_U8*, tDot11fFfAction*);

void dot11fPackFfAction(tpAniSirGlobal, tDot11fFfAction*, tANI_U8*);

typedef struct sDot11fFfAddBAParameterSet {
    tANI_U16  amsduSupported: 1;
    tANI_U16          policy: 1;
    tANI_U16             tid: 4;
    tANI_U16      bufferSize: 10;
} tDot11fFfAddBAParameterSet;

#define DOT11F_FF_ADDBAPARAMETERSET_LEN ( 2 )

void dot11fUnpackFfAddBAParameterSet(tpAniSirGlobal, tANI_U8*, tDot11fFfAddBAParameterSet*);

void dot11fPackFfAddBAParameterSet(tpAniSirGlobal, tDot11fFfAddBAParameterSet*, tANI_U8*);

#define ADDBAPARAMETERSET_AMSDUSUPPORTED_OFFSET 0
#define ADDBAPARAMETERSET_AMSDUSUPPORTED_WIDTH  1
#define ADDBAPARAMETERSET_POLICY_OFFSET         1
#define ADDBAPARAMETERSET_POLICY_WIDTH          1
#define ADDBAPARAMETERSET_TID_OFFSET            2
#define ADDBAPARAMETERSET_TID_WIDTH             4
#define ADDBAPARAMETERSET_BUFFERSIZE_OFFSET     6
#define ADDBAPARAMETERSET_BUFFERSIZE_WIDTH      10

typedef struct sDot11fFfAuthAlgo {
    tANI_U16 algo;
} tDot11fFfAuthAlgo;

#define DOT11F_FF_AUTHALGO_LEN ( 2 )

void dot11fUnpackFfAuthAlgo(tpAniSirGlobal, tANI_U8*, tDot11fFfAuthAlgo*);

void dot11fPackFfAuthAlgo(tpAniSirGlobal, tDot11fFfAuthAlgo*, tANI_U8*);

typedef struct sDot11fFfAuthSeqNo {
    tANI_U16 no;
} tDot11fFfAuthSeqNo;

#define DOT11F_FF_AUTHSEQNO_LEN ( 2 )

void dot11fUnpackFfAuthSeqNo(tpAniSirGlobal, tANI_U8*, tDot11fFfAuthSeqNo*);

void dot11fPackFfAuthSeqNo(tpAniSirGlobal, tDot11fFfAuthSeqNo*, tANI_U8*);

typedef struct sDot11fFfBAStartingSequenceControl {
    tANI_U16  fragNumber: 4;
    tANI_U16         ssn: 12;
} tDot11fFfBAStartingSequenceControl;

#define DOT11F_FF_BASTARTINGSEQUENCECONTROL_LEN ( 2 )

void dot11fUnpackFfBAStartingSequenceControl(tpAniSirGlobal, tANI_U8*, tDot11fFfBAStartingSequenceControl*);

void dot11fPackFfBAStartingSequenceControl(tpAniSirGlobal, tDot11fFfBAStartingSequenceControl*, tANI_U8*);

#define BASTARTINGSEQUENCECONTROL_FRAGNUMBER_OFFSET 0
#define BASTARTINGSEQUENCECONTROL_FRAGNUMBER_WIDTH  4
#define BASTARTINGSEQUENCECONTROL_SSN_OFFSET        4
#define BASTARTINGSEQUENCECONTROL_SSN_WIDTH         12

typedef struct sDot11fFfBATimeout {
    tANI_U16 timeout;
} tDot11fFfBATimeout;

#define DOT11F_FF_BATIMEOUT_LEN ( 2 )

void dot11fUnpackFfBATimeout(tpAniSirGlobal, tANI_U8*, tDot11fFfBATimeout*);

void dot11fPackFfBATimeout(tpAniSirGlobal, tDot11fFfBATimeout*, tANI_U8*);

typedef struct sDot11fFfBeaconInterval {
    tANI_U16 interval;
} tDot11fFfBeaconInterval;

#define DOT11F_FF_BEACONINTERVAL_LEN ( 2 )

void dot11fUnpackFfBeaconInterval(tpAniSirGlobal, tANI_U8*, tDot11fFfBeaconInterval*);

void dot11fPackFfBeaconInterval(tpAniSirGlobal, tDot11fFfBeaconInterval*, tANI_U8*);

typedef struct sDot11fFfCapabilities {
    tANI_U16             ess: 1;
    tANI_U16            ibss: 1;
    tANI_U16      cfPollable: 1;
    tANI_U16       cfPollReq: 1;
    tANI_U16         privacy: 1;
    tANI_U16   shortPreamble: 1;
    tANI_U16            pbcc: 1;
    tANI_U16  channelAgility: 1;
    tANI_U16     spectrumMgt: 1;
    tANI_U16             qos: 1;
    tANI_U16   shortSlotTime: 1;
    tANI_U16            apsd: 1;
    tANI_U16             rrm: 1;
    tANI_U16        dsssOfdm: 1;
    tANI_U16       delayedBA: 1;
    tANI_U16     immediateBA: 1;
} tDot11fFfCapabilities;

#define DOT11F_FF_CAPABILITIES_LEN ( 2 )

void dot11fUnpackFfCapabilities(tpAniSirGlobal, tANI_U8*, tDot11fFfCapabilities*);

void dot11fPackFfCapabilities(tpAniSirGlobal, tDot11fFfCapabilities*, tANI_U8*);

#define CAPABILITIES_ESS_OFFSET            0
#define CAPABILITIES_ESS_WIDTH             1
#define CAPABILITIES_IBSS_OFFSET           1
#define CAPABILITIES_IBSS_WIDTH            1
#define CAPABILITIES_CFPOLLABLE_OFFSET     2
#define CAPABILITIES_CFPOLLABLE_WIDTH      1
#define CAPABILITIES_CFPOLLREQ_OFFSET      3
#define CAPABILITIES_CFPOLLREQ_WIDTH       1
#define CAPABILITIES_PRIVACY_OFFSET        4
#define CAPABILITIES_PRIVACY_WIDTH         1
#define CAPABILITIES_SHORTPREAMBLE_OFFSET  5
#define CAPABILITIES_SHORTPREAMBLE_WIDTH   1
#define CAPABILITIES_PBCC_OFFSET           6
#define CAPABILITIES_PBCC_WIDTH            1
#define CAPABILITIES_CHANNELAGILITY_OFFSET 7
#define CAPABILITIES_CHANNELAGILITY_WIDTH  1
#define CAPABILITIES_SPECTRUMMGT_OFFSET    8
#define CAPABILITIES_SPECTRUMMGT_WIDTH     1
#define CAPABILITIES_QOS_OFFSET            9
#define CAPABILITIES_QOS_WIDTH             1
#define CAPABILITIES_SHORTSLOTTIME_OFFSET  10
#define CAPABILITIES_SHORTSLOTTIME_WIDTH   1
#define CAPABILITIES_APSD_OFFSET           11
#define CAPABILITIES_APSD_WIDTH            1
#define CAPABILITIES_RRM_OFFSET            12
#define CAPABILITIES_RRM_WIDTH             1
#define CAPABILITIES_DSSSOFDM_OFFSET       13
#define CAPABILITIES_DSSSOFDM_WIDTH        1
#define CAPABILITIES_DELAYEDBA_OFFSET      14
#define CAPABILITIES_DELAYEDBA_WIDTH       1
#define CAPABILITIES_IMMEDIATEBA_OFFSET    15
#define CAPABILITIES_IMMEDIATEBA_WIDTH     1

typedef struct sDot11fFfCategory {
    tANI_U8 category;
} tDot11fFfCategory;

#define DOT11F_FF_CATEGORY_LEN ( 1 )

void dot11fUnpackFfCategory(tpAniSirGlobal, tANI_U8*, tDot11fFfCategory*);

void dot11fPackFfCategory(tpAniSirGlobal, tDot11fFfCategory*, tANI_U8*);

typedef struct sDot11fFfCurrentAPAddress {
    tANI_U8 mac[6];
} tDot11fFfCurrentAPAddress;

#define DOT11F_FF_CURRENTAPADDRESS_LEN ( 6 )

void dot11fUnpackFfCurrentAPAddress(tpAniSirGlobal, tANI_U8*, tDot11fFfCurrentAPAddress*);

void dot11fPackFfCurrentAPAddress(tpAniSirGlobal, tDot11fFfCurrentAPAddress*, tANI_U8*);

typedef struct sDot11fFfDelBAParameterSet {
    tANI_U16   reserved: 11;
    tANI_U16  initiator: 1;
    tANI_U16        tid: 4;
} tDot11fFfDelBAParameterSet;

#define DOT11F_FF_DELBAPARAMETERSET_LEN ( 2 )

void dot11fUnpackFfDelBAParameterSet(tpAniSirGlobal, tANI_U8*, tDot11fFfDelBAParameterSet*);

void dot11fPackFfDelBAParameterSet(tpAniSirGlobal, tDot11fFfDelBAParameterSet*, tANI_U8*);

#define DELBAPARAMETERSET_RESERVED_OFFSET  0
#define DELBAPARAMETERSET_RESERVED_WIDTH   11
#define DELBAPARAMETERSET_INITIATOR_OFFSET 11
#define DELBAPARAMETERSET_INITIATOR_WIDTH  1
#define DELBAPARAMETERSET_TID_OFFSET       12
#define DELBAPARAMETERSET_TID_WIDTH        4

typedef struct sDot11fFfDialogToken {
    tANI_U8 token;
} tDot11fFfDialogToken;

#define DOT11F_FF_DIALOGTOKEN_LEN ( 1 )

void dot11fUnpackFfDialogToken(tpAniSirGlobal, tANI_U8*, tDot11fFfDialogToken*);

void dot11fPackFfDialogToken(tpAniSirGlobal, tDot11fFfDialogToken*, tANI_U8*);

typedef struct sDot11fFfLeader {
    tANI_U8 mac[6];
} tDot11fFfLeader;

#define DOT11F_FF_LEADER_LEN ( 6 )

void dot11fUnpackFfLeader(tpAniSirGlobal, tANI_U8*, tDot11fFfLeader*);

void dot11fPackFfLeader(tpAniSirGlobal, tDot11fFfLeader*, tANI_U8*);

typedef struct sDot11fFfLinkMargin {
    tANI_U8 linkMargin;
} tDot11fFfLinkMargin;

#define DOT11F_FF_LINKMARGIN_LEN ( 1 )

void dot11fUnpackFfLinkMargin(tpAniSirGlobal, tANI_U8*, tDot11fFfLinkMargin*);

void dot11fPackFfLinkMargin(tpAniSirGlobal, tDot11fFfLinkMargin*, tANI_U8*);

typedef struct sDot11fFfListenInterval {
    tANI_U16 interval;
} tDot11fFfListenInterval;

#define DOT11F_FF_LISTENINTERVAL_LEN ( 2 )

void dot11fUnpackFfListenInterval(tpAniSirGlobal, tANI_U8*, tDot11fFfListenInterval*);

void dot11fPackFfListenInterval(tpAniSirGlobal, tDot11fFfListenInterval*, tANI_U8*);

typedef struct sDot11fFfMagicCode {
    tANI_U8 magic[6];
} tDot11fFfMagicCode;

#define DOT11F_FF_MAGICCODE_LEN ( 6 )

void dot11fUnpackFfMagicCode(tpAniSirGlobal, tANI_U8*, tDot11fFfMagicCode*);

void dot11fPackFfMagicCode(tpAniSirGlobal, tDot11fFfMagicCode*, tANI_U8*);

typedef struct sDot11fFfMaxTxPower {
    tANI_U8 maxTxPower;
} tDot11fFfMaxTxPower;

#define DOT11F_FF_MAXTXPOWER_LEN ( 1 )

void dot11fUnpackFfMaxTxPower(tpAniSirGlobal, tANI_U8*, tDot11fFfMaxTxPower*);

void dot11fPackFfMaxTxPower(tpAniSirGlobal, tDot11fFfMaxTxPower*, tANI_U8*);

typedef struct sDot11fFfNumOfRepetitions {
    tANI_U16 repetitions;
} tDot11fFfNumOfRepetitions;

#define DOT11F_FF_NUMOFREPETITIONS_LEN ( 2 )

void dot11fUnpackFfNumOfRepetitions(tpAniSirGlobal, tANI_U8*, tDot11fFfNumOfRepetitions*);

void dot11fPackFfNumOfRepetitions(tpAniSirGlobal, tDot11fFfNumOfRepetitions*, tANI_U8*);

typedef struct sDot11fFfOperatingMode {
    tANI_U8  chanWidth: 2;
    tANI_U8   reserved: 2;
    tANI_U8      rxNSS: 3;
    tANI_U8  rxNSSType: 1;
} tDot11fFfOperatingMode;

#define DOT11F_FF_OPERATINGMODE_LEN ( 1 )

void dot11fUnpackFfOperatingMode(tpAniSirGlobal, tANI_U8*, tDot11fFfOperatingMode*);

void dot11fPackFfOperatingMode(tpAniSirGlobal, tDot11fFfOperatingMode*, tANI_U8*);

#define OPERATINGMODE_CHANWIDTH_OFFSET 0
#define OPERATINGMODE_CHANWIDTH_WIDTH  2
#define OPERATINGMODE_RESERVED_OFFSET  2
#define OPERATINGMODE_RESERVED_WIDTH   2
#define OPERATINGMODE_RXNSS_OFFSET     4
#define OPERATINGMODE_RXNSS_WIDTH      3
#define OPERATINGMODE_RXNSSTYPE_OFFSET 7
#define OPERATINGMODE_RXNSSTYPE_WIDTH  1

typedef struct sDot11fFfP2POUI {
    tANI_U32 oui;
} tDot11fFfP2POUI;

#define DOT11F_FF_P2POUI_LEN ( 4 )

void dot11fUnpackFfP2POUI(tpAniSirGlobal, tANI_U8*, tDot11fFfP2POUI*);

void dot11fPackFfP2POUI(tpAniSirGlobal, tDot11fFfP2POUI*, tANI_U8*);

typedef struct sDot11fFfP2POUISubType {
    tANI_U8 ouiSubtype;
} tDot11fFfP2POUISubType;

#define DOT11F_FF_P2POUISUBTYPE_LEN ( 1 )

void dot11fUnpackFfP2POUISubType(tpAniSirGlobal, tANI_U8*, tDot11fFfP2POUISubType*);

void dot11fPackFfP2POUISubType(tpAniSirGlobal, tDot11fFfP2POUISubType*, tANI_U8*);

typedef struct sDot11fFfRCPI {
    tANI_U8 rcpi;
} tDot11fFfRCPI;

#define DOT11F_FF_RCPI_LEN ( 1 )

void dot11fUnpackFfRCPI(tpAniSirGlobal, tANI_U8*, tDot11fFfRCPI*);

void dot11fPackFfRCPI(tpAniSirGlobal, tDot11fFfRCPI*, tANI_U8*);

typedef struct sDot11fFfRMCDialogToken {
    tANI_U32 token;
} tDot11fFfRMCDialogToken;

#define DOT11F_FF_RMCDIALOGTOKEN_LEN ( 4 )

void dot11fUnpackFfRMCDialogToken(tpAniSirGlobal, tANI_U8*, tDot11fFfRMCDialogToken*);

void dot11fPackFfRMCDialogToken(tpAniSirGlobal, tDot11fFfRMCDialogToken*, tANI_U8*);

typedef struct sDot11fFfRMCOUI {
    tANI_U8 oui[3];
} tDot11fFfRMCOUI;

#define DOT11F_FF_RMCOUI_LEN ( 3 )

void dot11fUnpackFfRMCOUI(tpAniSirGlobal, tANI_U8*, tDot11fFfRMCOUI*);

void dot11fPackFfRMCOUI(tpAniSirGlobal, tDot11fFfRMCOUI*, tANI_U8*);

typedef struct sDot11fFfRMCVersion {
    tANI_U8 version;
} tDot11fFfRMCVersion;

#define DOT11F_FF_RMCVERSION_LEN ( 1 )

void dot11fUnpackFfRMCVersion(tpAniSirGlobal, tANI_U8*, tDot11fFfRMCVersion*);

void dot11fPackFfRMCVersion(tpAniSirGlobal, tDot11fFfRMCVersion*, tANI_U8*);

typedef struct sDot11fFfRSNI {
    tANI_U8 rsni;
} tDot11fFfRSNI;

#define DOT11F_FF_RSNI_LEN ( 1 )

void dot11fUnpackFfRSNI(tpAniSirGlobal, tANI_U8*, tDot11fFfRSNI*);

void dot11fPackFfRSNI(tpAniSirGlobal, tDot11fFfRSNI*, tANI_U8*);

typedef struct sDot11fFfReason {
    tANI_U16 code;
} tDot11fFfReason;

#define DOT11F_FF_REASON_LEN ( 2 )

void dot11fUnpackFfReason(tpAniSirGlobal, tANI_U8*, tDot11fFfReason*);

void dot11fPackFfReason(tpAniSirGlobal, tDot11fFfReason*, tANI_U8*);

typedef struct sDot11fFfRxAntennaId {
    tANI_U8 antennaId;
} tDot11fFfRxAntennaId;

#define DOT11F_FF_RXANTENNAID_LEN ( 1 )

void dot11fUnpackFfRxAntennaId(tpAniSirGlobal, tANI_U8*, tDot11fFfRxAntennaId*);

void dot11fPackFfRxAntennaId(tpAniSirGlobal, tDot11fFfRxAntennaId*, tANI_U8*);

typedef struct sDot11fFfSMPowerModeSet {
    tANI_U8  PowerSave_En: 1;
    tANI_U8          Mode: 1;
    tANI_U8      reserved: 6;
} tDot11fFfSMPowerModeSet;

#define DOT11F_FF_SMPOWERMODESET_LEN ( 1 )

void dot11fUnpackFfSMPowerModeSet(tpAniSirGlobal, tANI_U8*, tDot11fFfSMPowerModeSet*);

void dot11fPackFfSMPowerModeSet(tpAniSirGlobal, tDot11fFfSMPowerModeSet*, tANI_U8*);

#define SMPOWERMODESET_POWERSAVE_EN_OFFSET 0
#define SMPOWERMODESET_POWERSAVE_EN_WIDTH  1
#define SMPOWERMODESET_MODE_OFFSET         1
#define SMPOWERMODESET_MODE_WIDTH          1
#define SMPOWERMODESET_RESERVED_OFFSET     2
#define SMPOWERMODESET_RESERVED_WIDTH      6

typedef struct sDot11fFfStatus {
    tANI_U16 status;
} tDot11fFfStatus;

#define DOT11F_FF_STATUS_LEN ( 2 )

void dot11fUnpackFfStatus(tpAniSirGlobal, tANI_U8*, tDot11fFfStatus*);

void dot11fPackFfStatus(tpAniSirGlobal, tDot11fFfStatus*, tANI_U8*);

typedef struct sDot11fFfStatusCode {
    tANI_U8 statusCode;
} tDot11fFfStatusCode;

#define DOT11F_FF_STATUSCODE_LEN ( 1 )

void dot11fUnpackFfStatusCode(tpAniSirGlobal, tANI_U8*, tDot11fFfStatusCode*);

void dot11fPackFfStatusCode(tpAniSirGlobal, tDot11fFfStatusCode*, tANI_U8*);

typedef struct sDot11fFfTPCEleID {
    tANI_U8 TPCId;
} tDot11fFfTPCEleID;

#define DOT11F_FF_TPCELEID_LEN ( 1 )

void dot11fUnpackFfTPCEleID(tpAniSirGlobal, tANI_U8*, tDot11fFfTPCEleID*);

void dot11fPackFfTPCEleID(tpAniSirGlobal, tDot11fFfTPCEleID*, tANI_U8*);

typedef struct sDot11fFfTPCEleLen {
    tANI_U8 TPCLen;
} tDot11fFfTPCEleLen;

#define DOT11F_FF_TPCELELEN_LEN ( 1 )

void dot11fUnpackFfTPCEleLen(tpAniSirGlobal, tANI_U8*, tDot11fFfTPCEleLen*);

void dot11fPackFfTPCEleLen(tpAniSirGlobal, tDot11fFfTPCEleLen*, tANI_U8*);

typedef struct sDot11fFfTSInfo {
    tANI_U32    traffic_type: 1;
    tANI_U32            tsid: 4;
    tANI_U32       direction: 2;
    tANI_U32   access_policy: 2;
    tANI_U32     aggregation: 1;
    tANI_U32             psb: 1;
    tANI_U32   user_priority: 3;
    tANI_U32  tsinfo_ack_pol: 2;
    tANI_U32        schedule: 1;
    tANI_U32          unused: 15;
} tDot11fFfTSInfo;

#define DOT11F_FF_TSINFO_LEN ( 3 )

void dot11fUnpackFfTSInfo(tpAniSirGlobal, tANI_U8*, tDot11fFfTSInfo*);

void dot11fPackFfTSInfo(tpAniSirGlobal, tDot11fFfTSInfo*, tANI_U8*);

#define TSINFO_TRAFFIC_TYPE_OFFSET   0
#define TSINFO_TRAFFIC_TYPE_WIDTH    1
#define TSINFO_TSID_OFFSET           1
#define TSINFO_TSID_WIDTH            4
#define TSINFO_DIRECTION_OFFSET      5
#define TSINFO_DIRECTION_WIDTH       2
#define TSINFO_ACCESS_POLICY_OFFSET  7
#define TSINFO_ACCESS_POLICY_WIDTH   2
#define TSINFO_AGGREGATION_OFFSET    9
#define TSINFO_AGGREGATION_WIDTH     1
#define TSINFO_PSB_OFFSET            10
#define TSINFO_PSB_WIDTH             1
#define TSINFO_USER_PRIORITY_OFFSET  11
#define TSINFO_USER_PRIORITY_WIDTH   3
#define TSINFO_TSINFO_ACK_POL_OFFSET 14
#define TSINFO_TSINFO_ACK_POL_WIDTH  2
#define TSINFO_SCHEDULE_OFFSET       16
#define TSINFO_SCHEDULE_WIDTH        1
#define TSINFO_UNUSED_OFFSET         17
#define TSINFO_UNUSED_WIDTH          15

typedef struct sDot11fFfTimeStamp {
    tDOT11F_U64 timestamp;
} tDot11fFfTimeStamp;

#define DOT11F_FF_TIMESTAMP_LEN ( 8 )

void dot11fUnpackFfTimeStamp(tpAniSirGlobal, tANI_U8*, tDot11fFfTimeStamp*);

void dot11fPackFfTimeStamp(tpAniSirGlobal, tDot11fFfTimeStamp*, tANI_U8*);

typedef struct sDot11fFfTransactionId {
    tANI_U8 transId[2];
} tDot11fFfTransactionId;

#define DOT11F_FF_TRANSACTIONID_LEN ( 2 )

void dot11fUnpackFfTransactionId(tpAniSirGlobal, tANI_U8*, tDot11fFfTransactionId*);

void dot11fPackFfTransactionId(tpAniSirGlobal, tDot11fFfTransactionId*, tANI_U8*);

typedef struct sDot11fFfTxAntennaId {
    tANI_U8 antennaId;
} tDot11fFfTxAntennaId;

#define DOT11F_FF_TXANTENNAID_LEN ( 1 )

void dot11fUnpackFfTxAntennaId(tpAniSirGlobal, tANI_U8*, tDot11fFfTxAntennaId*);

void dot11fPackFfTxAntennaId(tpAniSirGlobal, tDot11fFfTxAntennaId*, tANI_U8*);

typedef struct sDot11fFfTxPower {
    tANI_U8 txPower;
} tDot11fFfTxPower;

#define DOT11F_FF_TXPOWER_LEN ( 1 )

void dot11fUnpackFfTxPower(tpAniSirGlobal, tANI_U8*, tDot11fFfTxPower*);

void dot11fPackFfTxPower(tpAniSirGlobal, tDot11fFfTxPower*, tANI_U8*);

typedef struct sDot11fFfVhtMembershipStatusArray {
    tANI_U8 membershipStatusArray[8];
} tDot11fFfVhtMembershipStatusArray;

#define DOT11F_FF_VHTMEMBERSHIPSTATUSARRAY_LEN ( 8 )

void dot11fUnpackFfVhtMembershipStatusArray(tpAniSirGlobal, tANI_U8*, tDot11fFfVhtMembershipStatusArray*);

void dot11fPackFfVhtMembershipStatusArray(tpAniSirGlobal, tDot11fFfVhtMembershipStatusArray*, tANI_U8*);

typedef struct sDot11fFfVhtUserPositionArray {
    tANI_U8 userPositionArray[16];
} tDot11fFfVhtUserPositionArray;

#define DOT11F_FF_VHTUSERPOSITIONARRAY_LEN ( 16 )

void dot11fUnpackFfVhtUserPositionArray(tpAniSirGlobal, tANI_U8*, tDot11fFfVhtUserPositionArray*);

void dot11fPackFfVhtUserPositionArray(tpAniSirGlobal, tDot11fFfVhtUserPositionArray*, tANI_U8*);


typedef struct sDot11fTLVAuthorizedMACs {
    tANI_U8      present;
    tANI_U8      mac[6];
} tDot11fTLVAuthorizedMACs;

#define DOT11F_TLV_AUTHORIZEDMACS ( 1 )

#define DOT11F_TLV_AUTHORIZEDMACS_MIN_LEN ( 6 )

#define DOT11F_TLV_AUTHORIZEDMACS_MAX_LEN ( 6 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvAuthorizedMACs(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVAuthorizedMACs*);

tANI_U32 dot11fPackTlvAuthorizedMACs(tpAniSirGlobal, tDot11fTLVAuthorizedMACs*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvAuthorizedMACs(tpAniSirGlobal, tDot11fTLVAuthorizedMACs*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVRequestToEnroll {
    tANI_U8      present;
    tANI_U8      req;
} tDot11fTLVRequestToEnroll;

#define DOT11F_TLV_REQUESTTOENROLL ( 3 )

#define DOT11F_TLV_REQUESTTOENROLL_MIN_LEN ( 1 )

#define DOT11F_TLV_REQUESTTOENROLL_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvRequestToEnroll(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVRequestToEnroll*);

tANI_U32 dot11fPackTlvRequestToEnroll(tpAniSirGlobal, tDot11fTLVRequestToEnroll*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvRequestToEnroll(tpAniSirGlobal, tDot11fTLVRequestToEnroll*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVVersion2 {
    tANI_U8      present;
    tANI_U8            minor: 4;
    tANI_U8            major: 4;
} tDot11fTLVVersion2;

#define DOT11F_TLV_VERSION2 ( 0 )

#define DOT11F_TLV_VERSION2_MIN_LEN ( 1 )

#define DOT11F_TLV_VERSION2_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvVersion2(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVVersion2*);

tANI_U32 dot11fPackTlvVersion2(tpAniSirGlobal, tDot11fTLVVersion2*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvVersion2(tpAniSirGlobal, tDot11fTLVVersion2*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVAPSetupLocked {
    tANI_U8      present;
    tANI_U8      fLocked;
} tDot11fTLVAPSetupLocked;

#define DOT11F_TLV_APSETUPLOCKED ( 4183 )

#define DOT11F_TLV_APSETUPLOCKED_MIN_LEN ( 3 )

#define DOT11F_TLV_APSETUPLOCKED_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvAPSetupLocked(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVAPSetupLocked*);

tANI_U32 dot11fPackTlvAPSetupLocked(tpAniSirGlobal, tDot11fTLVAPSetupLocked*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvAPSetupLocked(tpAniSirGlobal, tDot11fTLVAPSetupLocked*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVAssociationState {
    tANI_U8      present;
    tANI_U16     state;
} tDot11fTLVAssociationState;

#define DOT11F_TLV_ASSOCIATIONSTATE ( 4098 )

#define DOT11F_TLV_ASSOCIATIONSTATE_MIN_LEN ( 4 )

#define DOT11F_TLV_ASSOCIATIONSTATE_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvAssociationState(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVAssociationState*);

tANI_U32 dot11fPackTlvAssociationState(tpAniSirGlobal, tDot11fTLVAssociationState*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvAssociationState(tpAniSirGlobal, tDot11fTLVAssociationState*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVChannelList {
    tANI_U8      present;
    tANI_U8      countryString[3];
    tANI_U8      num_channelList;
    tANI_U8      channelList[251];
} tDot11fTLVChannelList;

#define DOT11F_TLV_CHANNELLIST ( 11 )

#define DOT11F_TLV_CHANNELLIST_MIN_LEN ( 4 )

#define DOT11F_TLV_CHANNELLIST_MAX_LEN ( 255 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvChannelList(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVChannelList*);

tANI_U32 dot11fPackTlvChannelList(tpAniSirGlobal, tDot11fTLVChannelList*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvChannelList(tpAniSirGlobal, tDot11fTLVChannelList*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVConfigMethods {
    tANI_U8      present;
    tANI_U16     methods;
} tDot11fTLVConfigMethods;

#define DOT11F_TLV_CONFIGMETHODS ( 4104 )

#define DOT11F_TLV_CONFIGMETHODS_MIN_LEN ( 4 )

#define DOT11F_TLV_CONFIGMETHODS_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvConfigMethods(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVConfigMethods*);

tANI_U32 dot11fPackTlvConfigMethods(tpAniSirGlobal, tDot11fTLVConfigMethods*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvConfigMethods(tpAniSirGlobal, tDot11fTLVConfigMethods*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVConfigurationError {
    tANI_U8      present;
    tANI_U16     error;
} tDot11fTLVConfigurationError;

#define DOT11F_TLV_CONFIGURATIONERROR ( 4105 )

#define DOT11F_TLV_CONFIGURATIONERROR_MIN_LEN ( 4 )

#define DOT11F_TLV_CONFIGURATIONERROR_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvConfigurationError(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVConfigurationError*);

tANI_U32 dot11fPackTlvConfigurationError(tpAniSirGlobal, tDot11fTLVConfigurationError*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvConfigurationError(tpAniSirGlobal, tDot11fTLVConfigurationError*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVConfigurationTimeout {
    tANI_U8      present;
    tANI_U8      GOConfigTimeout;
    tANI_U8      CLConfigTimeout;
} tDot11fTLVConfigurationTimeout;

#define DOT11F_TLV_CONFIGURATIONTIMEOUT ( 5 )

#define DOT11F_TLV_CONFIGURATIONTIMEOUT_MIN_LEN ( 3 )

#define DOT11F_TLV_CONFIGURATIONTIMEOUT_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvConfigurationTimeout(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVConfigurationTimeout*);

tANI_U32 dot11fPackTlvConfigurationTimeout(tpAniSirGlobal, tDot11fTLVConfigurationTimeout*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvConfigurationTimeout(tpAniSirGlobal, tDot11fTLVConfigurationTimeout*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVDeviceName {
    tANI_U8      present;
    tANI_U8      num_text;
    tANI_U8      text[32];
} tDot11fTLVDeviceName;

#define DOT11F_TLV_DEVICENAME ( 4113 )

#define DOT11F_TLV_DEVICENAME_MIN_LEN ( 2 )

#define DOT11F_TLV_DEVICENAME_MAX_LEN ( 34 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvDeviceName(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVDeviceName*);

tANI_U32 dot11fPackTlvDeviceName(tpAniSirGlobal, tDot11fTLVDeviceName*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvDeviceName(tpAniSirGlobal, tDot11fTLVDeviceName*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVDevicePasswordID {
    tANI_U8      present;
    tANI_U16     id;
} tDot11fTLVDevicePasswordID;

#define DOT11F_TLV_DEVICEPASSWORDID ( 4114 )

#define DOT11F_TLV_DEVICEPASSWORDID_MIN_LEN ( 4 )

#define DOT11F_TLV_DEVICEPASSWORDID_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvDevicePasswordID(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVDevicePasswordID*);

tANI_U32 dot11fPackTlvDevicePasswordID(tpAniSirGlobal, tDot11fTLVDevicePasswordID*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvDevicePasswordID(tpAniSirGlobal, tDot11fTLVDevicePasswordID*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVExtendedListenTiming {
    tANI_U8      present;
    tANI_U16     availibilityPeriod;
    tANI_U16     availibilityInterval;
} tDot11fTLVExtendedListenTiming;

#define DOT11F_TLV_EXTENDEDLISTENTIMING ( 8 )

#define DOT11F_TLV_EXTENDEDLISTENTIMING_MIN_LEN ( 5 )

#define DOT11F_TLV_EXTENDEDLISTENTIMING_MAX_LEN ( 5 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvExtendedListenTiming(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVExtendedListenTiming*);

tANI_U32 dot11fPackTlvExtendedListenTiming(tpAniSirGlobal, tDot11fTLVExtendedListenTiming*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvExtendedListenTiming(tpAniSirGlobal, tDot11fTLVExtendedListenTiming*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVGOIntent {
    tANI_U8      present;
    tANI_U8      GOIntent;
} tDot11fTLVGOIntent;

#define DOT11F_TLV_GOINTENT ( 4 )

#define DOT11F_TLV_GOINTENT_MIN_LEN ( 2 )

#define DOT11F_TLV_GOINTENT_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvGOIntent(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVGOIntent*);

tANI_U32 dot11fPackTlvGOIntent(tpAniSirGlobal, tDot11fTLVGOIntent*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvGOIntent(tpAniSirGlobal, tDot11fTLVGOIntent*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVIntendedP2PInterfaceAddress {
    tANI_U8      present;
    tANI_U8      P2PInterfaceAddress[6];
} tDot11fTLVIntendedP2PInterfaceAddress;

#define DOT11F_TLV_INTENDEDP2PINTERFACEADDRESS ( 9 )

#define DOT11F_TLV_INTENDEDP2PINTERFACEADDRESS_MIN_LEN ( 7 )

#define DOT11F_TLV_INTENDEDP2PINTERFACEADDRESS_MAX_LEN ( 7 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvIntendedP2PInterfaceAddress(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVIntendedP2PInterfaceAddress*);

tANI_U32 dot11fPackTlvIntendedP2PInterfaceAddress(tpAniSirGlobal, tDot11fTLVIntendedP2PInterfaceAddress*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvIntendedP2PInterfaceAddress(tpAniSirGlobal, tDot11fTLVIntendedP2PInterfaceAddress*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVInvitationFlags {
    tANI_U8      present;
    tANI_U8      invitationFlags;
} tDot11fTLVInvitationFlags;

#define DOT11F_TLV_INVITATIONFLAGS ( 18 )

#define DOT11F_TLV_INVITATIONFLAGS_MIN_LEN ( 2 )

#define DOT11F_TLV_INVITATIONFLAGS_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvInvitationFlags(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVInvitationFlags*);

tANI_U32 dot11fPackTlvInvitationFlags(tpAniSirGlobal, tDot11fTLVInvitationFlags*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvInvitationFlags(tpAniSirGlobal, tDot11fTLVInvitationFlags*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVListenChannel {
    tANI_U8      present;
    tANI_U8      countryString[3];
    tANI_U8      regulatoryClass;
    tANI_U8      channel;
} tDot11fTLVListenChannel;

#define DOT11F_TLV_LISTENCHANNEL ( 6 )

#define DOT11F_TLV_LISTENCHANNEL_MIN_LEN ( 6 )

#define DOT11F_TLV_LISTENCHANNEL_MAX_LEN ( 6 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvListenChannel(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVListenChannel*);

tANI_U32 dot11fPackTlvListenChannel(tpAniSirGlobal, tDot11fTLVListenChannel*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvListenChannel(tpAniSirGlobal, tDot11fTLVListenChannel*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVManufacturer {
    tANI_U8      present;
    tANI_U8      num_name;
    tANI_U8      name[64];
} tDot11fTLVManufacturer;

#define DOT11F_TLV_MANUFACTURER ( 4129 )

#define DOT11F_TLV_MANUFACTURER_MIN_LEN ( 2 )

#define DOT11F_TLV_MANUFACTURER_MAX_LEN ( 66 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvManufacturer(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVManufacturer*);

tANI_U32 dot11fPackTlvManufacturer(tpAniSirGlobal, tDot11fTLVManufacturer*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvManufacturer(tpAniSirGlobal, tDot11fTLVManufacturer*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVMinorReasonCode {
    tANI_U8      present;
    tANI_U8      minorReasonCode;
} tDot11fTLVMinorReasonCode;

#define DOT11F_TLV_MINORREASONCODE ( 1 )

#define DOT11F_TLV_MINORREASONCODE_MIN_LEN ( 2 )

#define DOT11F_TLV_MINORREASONCODE_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvMinorReasonCode(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVMinorReasonCode*);

tANI_U32 dot11fPackTlvMinorReasonCode(tpAniSirGlobal, tDot11fTLVMinorReasonCode*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvMinorReasonCode(tpAniSirGlobal, tDot11fTLVMinorReasonCode*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVModelName {
    tANI_U8      present;
    tANI_U8      num_text;
    tANI_U8      text[32];
} tDot11fTLVModelName;

#define DOT11F_TLV_MODELNAME ( 4131 )

#define DOT11F_TLV_MODELNAME_MIN_LEN ( 2 )

#define DOT11F_TLV_MODELNAME_MAX_LEN ( 34 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvModelName(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVModelName*);

tANI_U32 dot11fPackTlvModelName(tpAniSirGlobal, tDot11fTLVModelName*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvModelName(tpAniSirGlobal, tDot11fTLVModelName*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVModelNumber {
    tANI_U8      present;
    tANI_U8      num_text;
    tANI_U8      text[32];
} tDot11fTLVModelNumber;

#define DOT11F_TLV_MODELNUMBER ( 4132 )

#define DOT11F_TLV_MODELNUMBER_MIN_LEN ( 2 )

#define DOT11F_TLV_MODELNUMBER_MAX_LEN ( 34 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvModelNumber(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVModelNumber*);

tANI_U32 dot11fPackTlvModelNumber(tpAniSirGlobal, tDot11fTLVModelNumber*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvModelNumber(tpAniSirGlobal, tDot11fTLVModelNumber*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVNoticeOfAbsence {
    tANI_U8      present;
    tANI_U8      index;
    tANI_U8      CTSWindowOppPS;
    tANI_U8      num_NoADesc;
    tANI_U8      NoADesc[36];
} tDot11fTLVNoticeOfAbsence;

#define DOT11F_TLV_NOTICEOFABSENCE ( 12 )

#define DOT11F_TLV_NOTICEOFABSENCE_MIN_LEN ( 3 )

#define DOT11F_TLV_NOTICEOFABSENCE_MAX_LEN ( 39 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvNoticeOfAbsence(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVNoticeOfAbsence*);

tANI_U32 dot11fPackTlvNoticeOfAbsence(tpAniSirGlobal, tDot11fTLVNoticeOfAbsence*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvNoticeOfAbsence(tpAniSirGlobal, tDot11fTLVNoticeOfAbsence*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVOperatingChannel {
    tANI_U8      present;
    tANI_U8      countryString[3];
    tANI_U8      regulatoryClass;
    tANI_U8      channel;
} tDot11fTLVOperatingChannel;

#define DOT11F_TLV_OPERATINGCHANNEL ( 17 )

#define DOT11F_TLV_OPERATINGCHANNEL_MIN_LEN ( 6 )

#define DOT11F_TLV_OPERATINGCHANNEL_MAX_LEN ( 6 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvOperatingChannel(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVOperatingChannel*);

tANI_U32 dot11fPackTlvOperatingChannel(tpAniSirGlobal, tDot11fTLVOperatingChannel*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvOperatingChannel(tpAniSirGlobal, tDot11fTLVOperatingChannel*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVP2PCapability {
    tANI_U8      present;
    tANI_U8      deviceCapability;
    tANI_U8      groupCapability;
} tDot11fTLVP2PCapability;

#define DOT11F_TLV_P2PCAPABILITY ( 2 )

#define DOT11F_TLV_P2PCAPABILITY_MIN_LEN ( 3 )

#define DOT11F_TLV_P2PCAPABILITY_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvP2PCapability(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVP2PCapability*);

tANI_U32 dot11fPackTlvP2PCapability(tpAniSirGlobal, tDot11fTLVP2PCapability*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvP2PCapability(tpAniSirGlobal, tDot11fTLVP2PCapability*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVP2PDeviceId {
    tANI_U8      present;
    tANI_U8      P2PDeviceAddress[6];
} tDot11fTLVP2PDeviceId;

#define DOT11F_TLV_P2PDEVICEID ( 3 )

#define DOT11F_TLV_P2PDEVICEID_MIN_LEN ( 7 )

#define DOT11F_TLV_P2PDEVICEID_MAX_LEN ( 7 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvP2PDeviceId(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVP2PDeviceId*);

tANI_U32 dot11fPackTlvP2PDeviceId(tpAniSirGlobal, tDot11fTLVP2PDeviceId*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvP2PDeviceId(tpAniSirGlobal, tDot11fTLVP2PDeviceId*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVP2PDeviceInfo {
    tANI_U8              present;
    tANI_U8              P2PDeviceAddress[6];
    tANI_U16             configMethod;
    tANI_U8              primaryDeviceType[8];
    tDot11fTLVDeviceName DeviceName;
} tDot11fTLVP2PDeviceInfo;

#define DOT11F_TLV_P2PDEVICEINFO ( 13 )

#define DOT11F_TLV_P2PDEVICEINFO_MIN_LEN ( 17 )

#define DOT11F_TLV_P2PDEVICEINFO_MAX_LEN ( 53 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvP2PDeviceInfo(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVP2PDeviceInfo*);

tANI_U32 dot11fPackTlvP2PDeviceInfo(tpAniSirGlobal, tDot11fTLVP2PDeviceInfo*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvP2PDeviceInfo(tpAniSirGlobal, tDot11fTLVP2PDeviceInfo*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVP2PGroupBssid {
    tANI_U8      present;
    tANI_U8      P2PGroupBssid[6];
} tDot11fTLVP2PGroupBssid;

#define DOT11F_TLV_P2PGROUPBSSID ( 7 )

#define DOT11F_TLV_P2PGROUPBSSID_MIN_LEN ( 7 )

#define DOT11F_TLV_P2PGROUPBSSID_MAX_LEN ( 7 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvP2PGroupBssid(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVP2PGroupBssid*);

tANI_U32 dot11fPackTlvP2PGroupBssid(tpAniSirGlobal, tDot11fTLVP2PGroupBssid*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvP2PGroupBssid(tpAniSirGlobal, tDot11fTLVP2PGroupBssid*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVP2PGroupId {
    tANI_U8      present;
    tANI_U8      deviceAddress[6];
    tANI_U8      num_ssid;
    tANI_U8      ssid[32];
} tDot11fTLVP2PGroupId;

#define DOT11F_TLV_P2PGROUPID ( 15 )

#define DOT11F_TLV_P2PGROUPID_MIN_LEN ( 7 )

#define DOT11F_TLV_P2PGROUPID_MAX_LEN ( 39 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvP2PGroupId(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVP2PGroupId*);

tANI_U32 dot11fPackTlvP2PGroupId(tpAniSirGlobal, tDot11fTLVP2PGroupId*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvP2PGroupId(tpAniSirGlobal, tDot11fTLVP2PGroupId*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVP2PGroupInfo {
    tANI_U8      present;
    tANI_U8      num_P2PClientInfoDesc;
    tANI_U8      P2PClientInfoDesc[1024];
} tDot11fTLVP2PGroupInfo;

#define DOT11F_TLV_P2PGROUPINFO ( 14 )

#define DOT11F_TLV_P2PGROUPINFO_MIN_LEN ( 1 )

#define DOT11F_TLV_P2PGROUPINFO_MAX_LEN ( 1025 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvP2PGroupInfo(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVP2PGroupInfo*);

tANI_U32 dot11fPackTlvP2PGroupInfo(tpAniSirGlobal, tDot11fTLVP2PGroupInfo*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvP2PGroupInfo(tpAniSirGlobal, tDot11fTLVP2PGroupInfo*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVP2PStatus {
    tANI_U8      present;
    tANI_U8      status;
} tDot11fTLVP2PStatus;

#define DOT11F_TLV_P2PSTATUS ( 0 )

#define DOT11F_TLV_P2PSTATUS_MIN_LEN ( 2 )

#define DOT11F_TLV_P2PSTATUS_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvP2PStatus(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVP2PStatus*);

tANI_U32 dot11fPackTlvP2PStatus(tpAniSirGlobal, tDot11fTLVP2PStatus*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvP2PStatus(tpAniSirGlobal, tDot11fTLVP2PStatus*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVPrimaryDeviceType {
    tANI_U8      present;
    tANI_U16     primary_category;
    tANI_U8      oui[4];
    tANI_U16     sub_category;
} tDot11fTLVPrimaryDeviceType;

#define DOT11F_TLV_PRIMARYDEVICETYPE ( 4180 )

#define DOT11F_TLV_PRIMARYDEVICETYPE_MIN_LEN ( 10 )

#define DOT11F_TLV_PRIMARYDEVICETYPE_MAX_LEN ( 10 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvPrimaryDeviceType(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVPrimaryDeviceType*);

tANI_U32 dot11fPackTlvPrimaryDeviceType(tpAniSirGlobal, tDot11fTLVPrimaryDeviceType*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvPrimaryDeviceType(tpAniSirGlobal, tDot11fTLVPrimaryDeviceType*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVRFBands {
    tANI_U8      present;
    tANI_U8      bands;
} tDot11fTLVRFBands;

#define DOT11F_TLV_RFBANDS ( 4156 )

#define DOT11F_TLV_RFBANDS_MIN_LEN ( 3 )

#define DOT11F_TLV_RFBANDS_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvRFBands(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVRFBands*);

tANI_U32 dot11fPackTlvRFBands(tpAniSirGlobal, tDot11fTLVRFBands*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvRFBands(tpAniSirGlobal, tDot11fTLVRFBands*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVRequestDeviceType {
    tANI_U8      present;
    tANI_U16     primary_category;
    tANI_U8      oui[4];
    tANI_U16     sub_category;
} tDot11fTLVRequestDeviceType;

#define DOT11F_TLV_REQUESTDEVICETYPE ( 4202 )

#define DOT11F_TLV_REQUESTDEVICETYPE_MIN_LEN ( 10 )

#define DOT11F_TLV_REQUESTDEVICETYPE_MAX_LEN ( 10 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvRequestDeviceType(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVRequestDeviceType*);

tANI_U32 dot11fPackTlvRequestDeviceType(tpAniSirGlobal, tDot11fTLVRequestDeviceType*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvRequestDeviceType(tpAniSirGlobal, tDot11fTLVRequestDeviceType*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVRequestType {
    tANI_U8      present;
    tANI_U8      reqType;
} tDot11fTLVRequestType;

#define DOT11F_TLV_REQUESTTYPE ( 4154 )

#define DOT11F_TLV_REQUESTTYPE_MIN_LEN ( 3 )

#define DOT11F_TLV_REQUESTTYPE_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvRequestType(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVRequestType*);

tANI_U32 dot11fPackTlvRequestType(tpAniSirGlobal, tDot11fTLVRequestType*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvRequestType(tpAniSirGlobal, tDot11fTLVRequestType*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVResponseType {
    tANI_U8      present;
    tANI_U8      resType;
} tDot11fTLVResponseType;

#define DOT11F_TLV_RESPONSETYPE ( 4155 )

#define DOT11F_TLV_RESPONSETYPE_MIN_LEN ( 3 )

#define DOT11F_TLV_RESPONSETYPE_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvResponseType(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVResponseType*);

tANI_U32 dot11fPackTlvResponseType(tpAniSirGlobal, tDot11fTLVResponseType*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvResponseType(tpAniSirGlobal, tDot11fTLVResponseType*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVSelectedRegistrar {
    tANI_U8      present;
    tANI_U8      selected;
} tDot11fTLVSelectedRegistrar;

#define DOT11F_TLV_SELECTEDREGISTRAR ( 4161 )

#define DOT11F_TLV_SELECTEDREGISTRAR_MIN_LEN ( 3 )

#define DOT11F_TLV_SELECTEDREGISTRAR_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvSelectedRegistrar(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVSelectedRegistrar*);

tANI_U32 dot11fPackTlvSelectedRegistrar(tpAniSirGlobal, tDot11fTLVSelectedRegistrar*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvSelectedRegistrar(tpAniSirGlobal, tDot11fTLVSelectedRegistrar*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVSelectedRegistrarConfigMethods {
    tANI_U8      present;
    tANI_U16     methods;
} tDot11fTLVSelectedRegistrarConfigMethods;

#define DOT11F_TLV_SELECTEDREGISTRARCONFIGMETHODS ( 4179 )

#define DOT11F_TLV_SELECTEDREGISTRARCONFIGMETHODS_MIN_LEN ( 4 )

#define DOT11F_TLV_SELECTEDREGISTRARCONFIGMETHODS_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvSelectedRegistrarConfigMethods(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVSelectedRegistrarConfigMethods*);

tANI_U32 dot11fPackTlvSelectedRegistrarConfigMethods(tpAniSirGlobal, tDot11fTLVSelectedRegistrarConfigMethods*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvSelectedRegistrarConfigMethods(tpAniSirGlobal, tDot11fTLVSelectedRegistrarConfigMethods*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVSerialNumber {
    tANI_U8      present;
    tANI_U8      num_text;
    tANI_U8      text[32];
} tDot11fTLVSerialNumber;

#define DOT11F_TLV_SERIALNUMBER ( 4162 )

#define DOT11F_TLV_SERIALNUMBER_MIN_LEN ( 2 )

#define DOT11F_TLV_SERIALNUMBER_MAX_LEN ( 34 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvSerialNumber(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVSerialNumber*);

tANI_U32 dot11fPackTlvSerialNumber(tpAniSirGlobal, tDot11fTLVSerialNumber*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvSerialNumber(tpAniSirGlobal, tDot11fTLVSerialNumber*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVUUID_E {
    tANI_U8      present;
    tANI_U8      uuid[16];
} tDot11fTLVUUID_E;

#define DOT11F_TLV_UUID_E ( 4167 )

#define DOT11F_TLV_UUID_E_MIN_LEN ( 18 )

#define DOT11F_TLV_UUID_E_MAX_LEN ( 18 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvUUID_E(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVUUID_E*);

tANI_U32 dot11fPackTlvUUID_E(tpAniSirGlobal, tDot11fTLVUUID_E*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvUUID_E(tpAniSirGlobal, tDot11fTLVUUID_E*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVUUID_R {
    tANI_U8      present;
    tANI_U8      uuid[16];
} tDot11fTLVUUID_R;

#define DOT11F_TLV_UUID_R ( 4168 )

#define DOT11F_TLV_UUID_R_MIN_LEN ( 18 )

#define DOT11F_TLV_UUID_R_MAX_LEN ( 18 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvUUID_R(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVUUID_R*);

tANI_U32 dot11fPackTlvUUID_R(tpAniSirGlobal, tDot11fTLVUUID_R*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvUUID_R(tpAniSirGlobal, tDot11fTLVUUID_R*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVVendorExtension {
    tANI_U8                   present;
    tANI_U8                   vendorId[3];
    tDot11fTLVVersion2        Version2;
    tDot11fTLVAuthorizedMACs  AuthorizedMACs;
    tDot11fTLVRequestToEnroll RequestToEnroll;
} tDot11fTLVVendorExtension;

#define DOT11F_TLV_VENDOREXTENSION ( 4169 )

#define DOT11F_TLV_VENDOREXTENSION_MIN_LEN ( 5 )

#define DOT11F_TLV_VENDOREXTENSION_MAX_LEN ( 19 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvVendorExtension(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVVendorExtension*);

tANI_U32 dot11fPackTlvVendorExtension(tpAniSirGlobal, tDot11fTLVVendorExtension*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvVendorExtension(tpAniSirGlobal, tDot11fTLVVendorExtension*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVVersion {
    tANI_U8      present;
    tANI_U8            minor: 4;
    tANI_U8            major: 4;
} tDot11fTLVVersion;

#define DOT11F_TLV_VERSION ( 4170 )

#define DOT11F_TLV_VERSION_MIN_LEN ( 3 )

#define DOT11F_TLV_VERSION_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvVersion(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVVersion*);

tANI_U32 dot11fPackTlvVersion(tpAniSirGlobal, tDot11fTLVVersion*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvVersion(tpAniSirGlobal, tDot11fTLVVersion*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVWPSState {
    tANI_U8      present;
    tANI_U8      state;
} tDot11fTLVWPSState;

#define DOT11F_TLV_WPSSTATE ( 4164 )

#define DOT11F_TLV_WPSSTATE_MIN_LEN ( 3 )

#define DOT11F_TLV_WPSSTATE_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvWPSState(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVWPSState*);

tANI_U32 dot11fPackTlvWPSState(tpAniSirGlobal, tDot11fTLVWPSState*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvWPSState(tpAniSirGlobal, tDot11fTLVWPSState*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVP2PInterface {
    tANI_U8      present;
    tANI_U8      P2PDeviceAddress[6];
} tDot11fTLVP2PInterface;

#define DOT11F_TLV_P2PINTERFACE ( 16 )

#define DOT11F_TLV_P2PINTERFACE_MIN_LEN ( 7 )

#define DOT11F_TLV_P2PINTERFACE_MAX_LEN ( 7 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvP2PInterface(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVP2PInterface*);

tANI_U32 dot11fPackTlvP2PInterface(tpAniSirGlobal, tDot11fTLVP2PInterface*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvP2PInterface(tpAniSirGlobal, tDot11fTLVP2PInterface*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fTLVP2PManageability {
    tANI_U8      present;
    tANI_U8      manageability;
} tDot11fTLVP2PManageability;

#define DOT11F_TLV_P2PMANAGEABILITY ( 10 )

#define DOT11F_TLV_P2PMANAGEABILITY_MIN_LEN ( 2 )

#define DOT11F_TLV_P2PMANAGEABILITY_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackTlvP2PManageability(tpAniSirGlobal, tANI_U8*,tANI_U16, tDot11fTLVP2PManageability*);

tANI_U32 dot11fPackTlvP2PManageability(tpAniSirGlobal, tDot11fTLVP2PManageability*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedTlvP2PManageability(tpAniSirGlobal, tDot11fTLVP2PManageability*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 

typedef struct sDot11fIEAPName {
    tANI_U8      present;
    tANI_U8      num_name;
    tANI_U8      name[32];
} tDot11fIEAPName;

#define DOT11F_EID_APNAME ( 1 )

#define DOT11F_IE_APNAME_MIN_LEN ( 1 )

#define DOT11F_IE_APNAME_MAX_LEN ( 32 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeAPName(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEAPName*);

tANI_U32 dot11fPackIeAPName(tpAniSirGlobal, tDot11fIEAPName*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEAPName(tpAniSirGlobal, tDot11fIEAPName*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEBPIndicator {
    tANI_U8      present;
    tANI_U8      indicator;
    tANI_U8      type;
} tDot11fIEBPIndicator;

#define DOT11F_EID_BPINDICATOR ( 4 )

#define DOT11F_IE_BPINDICATOR_MIN_LEN ( 2 )

#define DOT11F_IE_BPINDICATOR_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeBPIndicator(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEBPIndicator*);

tANI_U32 dot11fPackIeBPIndicator(tpAniSirGlobal, tDot11fIEBPIndicator*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEBPIndicator(tpAniSirGlobal, tDot11fIEBPIndicator*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIECondensedCountryStr {
    tANI_U8      present;
    tANI_U8      countryStr[2];
} tDot11fIECondensedCountryStr;

#define DOT11F_EID_CONDENSEDCOUNTRYSTR ( 2 )

#define DOT11F_IE_CONDENSEDCOUNTRYSTR_MIN_LEN ( 2 )

#define DOT11F_IE_CONDENSEDCOUNTRYSTR_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeCondensedCountryStr(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIECondensedCountryStr*);

tANI_U32 dot11fPackIeCondensedCountryStr(tpAniSirGlobal, tDot11fIECondensedCountryStr*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIECondensedCountryStr(tpAniSirGlobal, tDot11fIECondensedCountryStr*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEGTK {
    tANI_U8      present;
    tANI_U16            keyId: 2;
    tANI_U16         reserved: 14;
    tANI_U8      keyLength;
    tANI_U8      RSC[8];
    tANI_U8      num_key;
    tANI_U8      key[32];
} tDot11fIEGTK;

#define DOT11F_EID_GTK ( 2 )

#define DOT11F_IE_GTK_MIN_LEN ( 16 )

#define DOT11F_IE_GTK_MAX_LEN ( 43 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeGTK(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEGTK*);

tANI_U32 dot11fPackIeGTK(tpAniSirGlobal, tDot11fIEGTK*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEGTK(tpAniSirGlobal, tDot11fIEGTK*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEHCF {
    tANI_U8      present;
    tANI_U8      enabled;
} tDot11fIEHCF;

#define DOT11F_EID_HCF ( 2 )

#define DOT11F_IE_HCF_MIN_LEN ( 1 )

#define DOT11F_IE_HCF_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeHCF(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEHCF*);

tANI_U32 dot11fPackIeHCF(tpAniSirGlobal, tDot11fIEHCF*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEHCF(tpAniSirGlobal, tDot11fIEHCF*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEIGTK {
    tANI_U8      present;
    tANI_U8      keyID[2];
    tANI_U8      IPN[6];
    tANI_U8      keyLength;
    tANI_U8      key[24];
} tDot11fIEIGTK;

#define DOT11F_EID_IGTK ( 4 )

#define DOT11F_IE_IGTK_MIN_LEN ( 33 )

#define DOT11F_IE_IGTK_MAX_LEN ( 33 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeIGTK(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEIGTK*);

tANI_U32 dot11fPackIeIGTK(tpAniSirGlobal, tDot11fIEIGTK*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEIGTK(tpAniSirGlobal, tDot11fIEIGTK*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIELLAttr {
    tANI_U8      present;
    tANI_U32     defer_threshold;
} tDot11fIELLAttr;

#define DOT11F_EID_LLATTR ( 9 )

#define DOT11F_IE_LLATTR_MIN_LEN ( 4 )

#define DOT11F_IE_LLATTR_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeLLAttr(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIELLAttr*);

tANI_U32 dot11fPackIeLLAttr(tpAniSirGlobal, tDot11fIELLAttr*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIELLAttr(tpAniSirGlobal, tDot11fIELLAttr*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIELoadBalance {
    tANI_U8      present;
    tANI_U8      bssid[6];
    tANI_U8      channel;
} tDot11fIELoadBalance;

#define DOT11F_EID_LOADBALANCE ( 8 )

#define DOT11F_IE_LOADBALANCE_MIN_LEN ( 7 )

#define DOT11F_IE_LOADBALANCE_MAX_LEN ( 7 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeLoadBalance(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIELoadBalance*);

tANI_U32 dot11fPackIeLoadBalance(tpAniSirGlobal, tDot11fIELoadBalance*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIELoadBalance(tpAniSirGlobal, tDot11fIELoadBalance*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIELoadInfo {
    tANI_U8      present;
    tANI_U16     num_stas;
    tANI_U16     channel_util;
} tDot11fIELoadInfo;

#define DOT11F_EID_LOADINFO ( 6 )

#define DOT11F_IE_LOADINFO_MIN_LEN ( 4 )

#define DOT11F_IE_LOADINFO_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeLoadInfo(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIELoadInfo*);

tANI_U32 dot11fPackIeLoadInfo(tpAniSirGlobal, tDot11fIELoadInfo*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIELoadInfo(tpAniSirGlobal, tDot11fIELoadInfo*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEPropAssocType {
    tANI_U8      present;
    tANI_U8      type;
} tDot11fIEPropAssocType;

#define DOT11F_EID_PROPASSOCTYPE ( 7 )

#define DOT11F_IE_PROPASSOCTYPE_MIN_LEN ( 1 )

#define DOT11F_IE_PROPASSOCTYPE_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIePropAssocType(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEPropAssocType*);

tANI_U32 dot11fPackIePropAssocType(tpAniSirGlobal, tDot11fIEPropAssocType*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEPropAssocType(tpAniSirGlobal, tDot11fIEPropAssocType*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEPropCapability {
    tANI_U8      present;
    tANI_U16     capability;
} tDot11fIEPropCapability;

#define DOT11F_EID_PROPCAPABILITY ( 10 )

#define DOT11F_IE_PROPCAPABILITY_MIN_LEN ( 2 )

#define DOT11F_IE_PROPCAPABILITY_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIePropCapability(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEPropCapability*);

tANI_U32 dot11fPackIePropCapability(tpAniSirGlobal, tDot11fIEPropCapability*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEPropCapability(tpAniSirGlobal, tDot11fIEPropCapability*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEPropChannSwitchAnn {
    tANI_U8      present;
    tANI_U8      mode;
    tANI_U8      primary_channel;
    tANI_U8      sub_band;
    tANI_U8      channel_switch_count;
} tDot11fIEPropChannSwitchAnn;

#define DOT11F_EID_PROPCHANNSWITCHANN ( 15 )

#define DOT11F_IE_PROPCHANNSWITCHANN_MIN_LEN ( 4 )

#define DOT11F_IE_PROPCHANNSWITCHANN_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIePropChannSwitchAnn(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEPropChannSwitchAnn*);

tANI_U32 dot11fPackIePropChannSwitchAnn(tpAniSirGlobal, tDot11fIEPropChannSwitchAnn*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEPropChannSwitchAnn(tpAniSirGlobal, tDot11fIEPropChannSwitchAnn*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEPropEDCAParams {
    tANI_U8      present;
    tANI_U8      qos;
    tANI_U8      reserved;
    tANI_U8       acbe_aifsn: 4;
    tANI_U8         acbe_acm: 1;
    tANI_U8         acbe_aci: 2;
    tANI_U8          unused1: 1;
    tANI_U8         acbe_min: 4;
    tANI_U8         acbe_max: 4;
    tANI_U16     acbe_txoplimit;
    tANI_U8       acbk_aifsn: 4;
    tANI_U8         acbk_acm: 1;
    tANI_U8         acbk_aci: 2;
    tANI_U8          unused2: 1;
    tANI_U8         acbk_min: 4;
    tANI_U8         acbk_max: 4;
    tANI_U16     acbk_txoplimit;
    tANI_U8       acvi_aifsn: 4;
    tANI_U8         acvi_acm: 1;
    tANI_U8         acvi_aci: 2;
    tANI_U8          unused3: 1;
    tANI_U8         acvi_min: 4;
    tANI_U8         acvi_max: 4;
    tANI_U16     acvi_txoplimit;
    tANI_U8       acvo_aifsn: 4;
    tANI_U8         acvo_acm: 1;
    tANI_U8         acvo_aci: 2;
    tANI_U8          unused4: 1;
    tANI_U8         acvo_min: 4;
    tANI_U8         acvo_max: 4;
    tANI_U16     acvo_txoplimit;
} tDot11fIEPropEDCAParams;

#define DOT11F_EID_PROPEDCAPARAMS ( 12 )

#define DOT11F_IE_PROPEDCAPARAMS_MIN_LEN ( 18 )

#define DOT11F_IE_PROPEDCAPARAMS_MAX_LEN ( 18 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIePropEDCAParams(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEPropEDCAParams*);

tANI_U32 dot11fPackIePropEDCAParams(tpAniSirGlobal, tDot11fIEPropEDCAParams*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEPropEDCAParams(tpAniSirGlobal, tDot11fIEPropEDCAParams*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEPropQuietBSS {
    tANI_U8      present;
    tANI_U8      quiet_count;
    tANI_U8      quiet_period;
    tANI_U16     quiet_duration;
    tANI_U16     quiet_offset;
} tDot11fIEPropQuietBSS;

#define DOT11F_EID_PROPQUIETBSS ( 16 )

#define DOT11F_IE_PROPQUIETBSS_MIN_LEN ( 6 )

#define DOT11F_IE_PROPQUIETBSS_MAX_LEN ( 6 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIePropQuietBSS(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEPropQuietBSS*);

tANI_U32 dot11fPackIePropQuietBSS(tpAniSirGlobal, tDot11fIEPropQuietBSS*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEPropQuietBSS(tpAniSirGlobal, tDot11fIEPropQuietBSS*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEPropSuppRates {
    tANI_U8      present;
    tANI_U8      num_rates;
    tANI_U8      rates[12];
} tDot11fIEPropSuppRates;

#define DOT11F_EID_PROPSUPPRATES ( 0 )

#define DOT11F_IE_PROPSUPPRATES_MIN_LEN ( 1 )

#define DOT11F_IE_PROPSUPPRATES_MAX_LEN ( 12 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIePropSuppRates(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEPropSuppRates*);

tANI_U32 dot11fPackIePropSuppRates(tpAniSirGlobal, tDot11fIEPropSuppRates*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEPropSuppRates(tpAniSirGlobal, tDot11fIEPropSuppRates*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIER0KH_ID {
    tANI_U8      present;
    tANI_U8      num_PMK_R0_ID;
    tANI_U8      PMK_R0_ID[48];
} tDot11fIER0KH_ID;

#define DOT11F_EID_R0KH_ID ( 3 )

#define DOT11F_IE_R0KH_ID_MIN_LEN ( 1 )

#define DOT11F_IE_R0KH_ID_MAX_LEN ( 48 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeR0KH_ID(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIER0KH_ID*);

tANI_U32 dot11fPackIeR0KH_ID(tpAniSirGlobal, tDot11fIER0KH_ID*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIER0KH_ID(tpAniSirGlobal, tDot11fIER0KH_ID*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIER1KH_ID {
    tANI_U8      present;
    tANI_U8      PMK_R1_ID[6];
} tDot11fIER1KH_ID;

#define DOT11F_EID_R1KH_ID ( 1 )

#define DOT11F_IE_R1KH_ID_MIN_LEN ( 6 )

#define DOT11F_IE_R1KH_ID_MAX_LEN ( 6 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeR1KH_ID(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIER1KH_ID*);

tANI_U32 dot11fPackIeR1KH_ID(tpAniSirGlobal, tDot11fIER1KH_ID*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIER1KH_ID(tpAniSirGlobal, tDot11fIER1KH_ID*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETSFInfo {
    tANI_U8      present;
    tANI_U16     TsfOffset;
    tANI_U16     BeaconIntvl;
} tDot11fIETSFInfo;

#define DOT11F_EID_TSFINFO ( 1 )

#define DOT11F_IE_TSFINFO_MIN_LEN ( 4 )

#define DOT11F_IE_TSFINFO_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTSFInfo(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETSFInfo*);

tANI_U32 dot11fPackIeTSFInfo(tpAniSirGlobal, tDot11fIETSFInfo*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETSFInfo(tpAniSirGlobal, tDot11fIETSFInfo*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETaurus {
    tANI_U8      present;
    tANI_U16     baTIDBitmap;
    tANI_U16     baPolicy;
    tANI_U16     baBufferSize: 12;
    tANI_U16             rsvd: 4;
} tDot11fIETaurus;

#define DOT11F_EID_TAURUS ( 18 )

#define DOT11F_IE_TAURUS_MIN_LEN ( 6 )

#define DOT11F_IE_TAURUS_MAX_LEN ( 6 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTaurus(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETaurus*);

tANI_U32 dot11fPackIeTaurus(tpAniSirGlobal, tDot11fIETaurus*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETaurus(tpAniSirGlobal, tDot11fIETaurus*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETitan {
    tANI_U8      present;
    tANI_U8      concat_tcid_bitmap;
    tANI_U8      compression_tcid_bitmap;
    tANI_U8      cb_state;
    tANI_U8      rev_fcs_state;
} tDot11fIETitan;

#define DOT11F_EID_TITAN ( 14 )

#define DOT11F_IE_TITAN_MIN_LEN ( 4 )

#define DOT11F_IE_TITAN_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTitan(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETitan*);

tANI_U32 dot11fPackIeTitan(tpAniSirGlobal, tDot11fIETitan*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETitan(tpAniSirGlobal, tDot11fIETitan*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETriggerStaBgScan {
    tANI_U8      present;
    tANI_U8      enable;
} tDot11fIETriggerStaBgScan;

#define DOT11F_EID_TRIGGERSTABGSCAN ( 17 )

#define DOT11F_IE_TRIGGERSTABGSCAN_MIN_LEN ( 1 )

#define DOT11F_IE_TRIGGERSTABGSCAN_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTriggerStaBgScan(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETriggerStaBgScan*);

tANI_U32 dot11fPackIeTriggerStaBgScan(tpAniSirGlobal, tDot11fIETriggerStaBgScan*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETriggerStaBgScan(tpAniSirGlobal, tDot11fIETriggerStaBgScan*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEVersion {
    tANI_U8      present;
    tANI_U32     chip_rev;
    tANI_U8      card_type;
    tANI_U8      num_build_version;
    tANI_U8      build_version[20];
} tDot11fIEVersion;

#define DOT11F_EID_VERSION ( 11 )

#define DOT11F_IE_VERSION_MIN_LEN ( 5 )

#define DOT11F_IE_VERSION_MAX_LEN ( 25 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeVersion(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEVersion*);

tANI_U32 dot11fPackIeVersion(tpAniSirGlobal, tDot11fIEVersion*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEVersion(tpAniSirGlobal, tDot11fIEVersion*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWDS {
    tANI_U8      present;
    tANI_U8      num_wdsData;
    tANI_U8      wdsData[64];
} tDot11fIEWDS;

#define DOT11F_EID_WDS ( 3 )

#define DOT11F_IE_WDS_MIN_LEN ( 0 )

#define DOT11F_IE_WDS_MAX_LEN ( 64 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWDS(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWDS*);

tANI_U32 dot11fPackIeWDS(tpAniSirGlobal, tDot11fIEWDS*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWDS(tpAniSirGlobal, tDot11fIEWDS*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEAPChannelReport {
    tANI_U8      present;
    tANI_U8      regulatoryClass;
    tANI_U8      num_channelList;
    tANI_U8      channelList[50];
} tDot11fIEAPChannelReport;

#define DOT11F_EID_APCHANNELREPORT ( 51 )

#define DOT11F_IE_APCHANNELREPORT_MIN_LEN ( 1 )

#define DOT11F_IE_APCHANNELREPORT_MAX_LEN ( 51 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeAPChannelReport(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEAPChannelReport*);

tANI_U32 dot11fPackIeAPChannelReport(tpAniSirGlobal, tDot11fIEAPChannelReport*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEAPChannelReport(tpAniSirGlobal, tDot11fIEAPChannelReport*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEBcnReportingDetail {
    tANI_U8      present;
    tANI_U8      reportingDetail;
} tDot11fIEBcnReportingDetail;

#define DOT11F_EID_BCNREPORTINGDETAIL ( 2 )

#define DOT11F_IE_BCNREPORTINGDETAIL_MIN_LEN ( 1 )

#define DOT11F_IE_BCNREPORTINGDETAIL_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeBcnReportingDetail(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEBcnReportingDetail*);

tANI_U32 dot11fPackIeBcnReportingDetail(tpAniSirGlobal, tDot11fIEBcnReportingDetail*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEBcnReportingDetail(tpAniSirGlobal, tDot11fIEBcnReportingDetail*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEBeaconReportFrmBody {
    tANI_U8      present;
    tANI_U8      num_reportedFields;
    tANI_U8      reportedFields[224];
} tDot11fIEBeaconReportFrmBody;

#define DOT11F_EID_BEACONREPORTFRMBODY ( 1 )

#define DOT11F_IE_BEACONREPORTFRMBODY_MIN_LEN ( 0 )

#define DOT11F_IE_BEACONREPORTFRMBODY_MAX_LEN ( 224 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeBeaconReportFrmBody(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEBeaconReportFrmBody*);

tANI_U32 dot11fPackIeBeaconReportFrmBody(tpAniSirGlobal, tDot11fIEBeaconReportFrmBody*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEBeaconReportFrmBody(tpAniSirGlobal, tDot11fIEBeaconReportFrmBody*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEBeaconReporting {
    tANI_U8      present;
    tANI_U8      reportingCondition;
    tANI_U8      threshold;
} tDot11fIEBeaconReporting;

#define DOT11F_EID_BEACONREPORTING ( 1 )

#define DOT11F_IE_BEACONREPORTING_MIN_LEN ( 2 )

#define DOT11F_IE_BEACONREPORTING_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeBeaconReporting(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEBeaconReporting*);

tANI_U32 dot11fPackIeBeaconReporting(tpAniSirGlobal, tDot11fIEBeaconReporting*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEBeaconReporting(tpAniSirGlobal, tDot11fIEBeaconReporting*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEMeasurementPilot {
    tANI_U8      present;
    tANI_U8      measurementPilot;
    tANI_U8      num_vendorSpecific;
    tANI_U8      vendorSpecific[255];
} tDot11fIEMeasurementPilot;

#define DOT11F_EID_MEASUREMENTPILOT ( 66 )

#define DOT11F_IE_MEASUREMENTPILOT_MIN_LEN ( 1 )

#define DOT11F_IE_MEASUREMENTPILOT_MAX_LEN ( 256 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeMeasurementPilot(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEMeasurementPilot*);

tANI_U32 dot11fPackIeMeasurementPilot(tpAniSirGlobal, tDot11fIEMeasurementPilot*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEMeasurementPilot(tpAniSirGlobal, tDot11fIEMeasurementPilot*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEMultiBssid {
    tANI_U8      present;
    tANI_U8      maxBSSIDIndicator;
    tANI_U8      num_vendorSpecific;
    tANI_U8      vendorSpecific[255];
} tDot11fIEMultiBssid;

#define DOT11F_EID_MULTIBSSID ( 71 )

#define DOT11F_IE_MULTIBSSID_MIN_LEN ( 1 )

#define DOT11F_IE_MULTIBSSID_MAX_LEN ( 256 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeMultiBssid(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEMultiBssid*);

tANI_U32 dot11fPackIeMultiBssid(tpAniSirGlobal, tDot11fIEMultiBssid*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEMultiBssid(tpAniSirGlobal, tDot11fIEMultiBssid*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIERICData {
    tANI_U8      present;
    tANI_U8      Identifier;
    tANI_U8      resourceDescCount;
    tANI_U16     statusCode;
} tDot11fIERICData;

#define DOT11F_EID_RICDATA ( 57 )

#define DOT11F_IE_RICDATA_MIN_LEN ( 4 )

#define DOT11F_IE_RICDATA_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeRICData(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIERICData*);

tANI_U32 dot11fPackIeRICData(tpAniSirGlobal, tDot11fIERICData*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIERICData(tpAniSirGlobal, tDot11fIERICData*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIERICDescriptor {
    tANI_U8      present;
    tANI_U8      resourceType;
    tANI_U8      num_variableData;
    tANI_U8      variableData[255];
} tDot11fIERICDescriptor;

#define DOT11F_EID_RICDESCRIPTOR ( 75 )

#define DOT11F_IE_RICDESCRIPTOR_MIN_LEN ( 1 )

#define DOT11F_IE_RICDESCRIPTOR_MAX_LEN ( 256 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeRICDescriptor(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIERICDescriptor*);

tANI_U32 dot11fPackIeRICDescriptor(tpAniSirGlobal, tDot11fIERICDescriptor*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIERICDescriptor(tpAniSirGlobal, tDot11fIERICDescriptor*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIERRMEnabledCap {
    tANI_U8      present;
    tANI_U8  LinkMeasurement: 1;
    tANI_U8      NeighborRpt: 1;
    tANI_U8         parallel: 1;
    tANI_U8         repeated: 1;
    tANI_U8    BeaconPassive: 1;
    tANI_U8     BeaconActive: 1;
    tANI_U8      BeaconTable: 1;
    tANI_U8    BeaconRepCond: 1;
    tANI_U8 FrameMeasurement: 1;
    tANI_U8      ChannelLoad: 1;
    tANI_U8   NoiseHistogram: 1;
    tANI_U8       statistics: 1;
    tANI_U8   LCIMeasurement: 1;
    tANI_U8       LCIAzimuth: 1;
    tANI_U8    TCMCapability: 1;
    tANI_U8     triggeredTCM: 1;
    tANI_U8     APChanReport: 1;
    tANI_U8    RRMMIBEnabled: 1;
    tANI_U8 operatingChanMax: 3;
    tANI_U8 nonOperatinChanMax: 3;
    tANI_U8 MeasurementPilot: 3;
    tANI_U8 MeasurementPilotEnabled: 1;
    tANI_U8 NeighborTSFOffset: 1;
    tANI_U8  RCPIMeasurement: 1;
    tANI_U8  RSNIMeasurement: 1;
    tANI_U8 BssAvgAccessDelay: 1;
    tANI_U8 BSSAvailAdmission: 1;
    tANI_U8 AntennaInformation: 1;
    tANI_U8         reserved: 6;
} tDot11fIERRMEnabledCap;

#define DOT11F_EID_RRMENABLEDCAP ( 70 )

#define DOT11F_IE_RRMENABLEDCAP_MIN_LEN ( 5 )

#define DOT11F_IE_RRMENABLEDCAP_MAX_LEN ( 5 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeRRMEnabledCap(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIERRMEnabledCap*);

tANI_U32 dot11fPackIeRRMEnabledCap(tpAniSirGlobal, tDot11fIERRMEnabledCap*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIERRMEnabledCap(tpAniSirGlobal, tDot11fIERRMEnabledCap*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIERequestedInfo {
    tANI_U8      present;
    tANI_U8      num_requested_eids;
    tANI_U8      requested_eids[255];
} tDot11fIERequestedInfo;

#define DOT11F_EID_REQUESTEDINFO ( 10 )

#define DOT11F_IE_REQUESTEDINFO_MIN_LEN ( 0 )

#define DOT11F_IE_REQUESTEDINFO_MAX_LEN ( 255 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeRequestedInfo(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIERequestedInfo*);

tANI_U32 dot11fPackIeRequestedInfo(tpAniSirGlobal, tDot11fIERequestedInfo*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIERequestedInfo(tpAniSirGlobal, tDot11fIERequestedInfo*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIESSID {
    tANI_U8      present;
    tANI_U8      num_ssid;
    tANI_U8      ssid[32];
} tDot11fIESSID;

#define DOT11F_EID_SSID ( 0 )

#define DOT11F_IE_SSID_MIN_LEN ( 0 )

#define DOT11F_IE_SSID_MAX_LEN ( 32 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeSSID(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIESSID*);

tANI_U32 dot11fPackIeSSID(tpAniSirGlobal, tDot11fIESSID*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIESSID(tpAniSirGlobal, tDot11fIESSID*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIESchedule {
    tANI_U8      present;
    tANI_U16      aggregation: 1;
    tANI_U16             tsid: 4;
    tANI_U16        direction: 2;
    tANI_U16         reserved: 9;
    tANI_U32     service_start_time;
    tANI_U32     service_interval;
    tANI_U16     max_service_dur;
    tANI_U16     spec_interval;
} tDot11fIESchedule;

#define DOT11F_EID_SCHEDULE ( 15 )

#define DOT11F_IE_SCHEDULE_MIN_LEN ( 14 )

#define DOT11F_IE_SCHEDULE_MAX_LEN ( 14 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeSchedule(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIESchedule*);

tANI_U32 dot11fPackIeSchedule(tpAniSirGlobal, tDot11fIESchedule*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIESchedule(tpAniSirGlobal, tDot11fIESchedule*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETCLAS {
    tANI_U8      present;
    tANI_U8      user_priority;
    tANI_U8      classifier_type;
    tANI_U8      classifier_mask;
    union
    {
        struct
        {
            tANI_U8 source[6];
            tANI_U8 dest[6];
            tANI_U16 type;
        } EthParams; 
        struct
        {
            tANI_U8 version;
            union
            {
                struct
                {
                    tANI_U8 source[4];
                    tANI_U8 dest[4];
                    tANI_U16 src_port;
                    tANI_U16 dest_port;
                    tANI_U8 DSCP;
                    tANI_U8 proto;
                    tANI_U8 reserved;
                } IpV4Params; 
                struct
                {
                    tANI_U8 source[16];
                    tANI_U8 dest[16];
                    tANI_U16 src_port;
                    tANI_U16 dest_port;
                    tANI_U8 flow_label[3];
                } IpV6Params; 
            } params;
        } IpParams; 
        struct
        {
            tANI_U16 tag_type;
        } Params8021dq; 
    } info;
} tDot11fIETCLAS;

#define DOT11F_EID_TCLAS ( 14 )

#define DOT11F_IE_TCLAS_MIN_LEN ( 5 )

#define DOT11F_IE_TCLAS_MAX_LEN ( 43 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTCLAS(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETCLAS*);

tANI_U32 dot11fPackIeTCLAS(tpAniSirGlobal, tDot11fIETCLAS*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETCLAS(tpAniSirGlobal, tDot11fIETCLAS*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETCLASSPROC {
    tANI_U8      present;
    tANI_U8      processing;
} tDot11fIETCLASSPROC;

#define DOT11F_EID_TCLASSPROC ( 44 )

#define DOT11F_IE_TCLASSPROC_MIN_LEN ( 1 )

#define DOT11F_IE_TCLASSPROC_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTCLASSPROC(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETCLASSPROC*);

tANI_U32 dot11fPackIeTCLASSPROC(tpAniSirGlobal, tDot11fIETCLASSPROC*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETCLASSPROC(tpAniSirGlobal, tDot11fIETCLASSPROC*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETSDelay {
    tANI_U8      present;
    tANI_U32     delay;
} tDot11fIETSDelay;

#define DOT11F_EID_TSDELAY ( 43 )

#define DOT11F_IE_TSDELAY_MIN_LEN ( 4 )

#define DOT11F_IE_TSDELAY_MAX_LEN ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTSDelay(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETSDelay*);

tANI_U32 dot11fPackIeTSDelay(tpAniSirGlobal, tDot11fIETSDelay*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETSDelay(tpAniSirGlobal, tDot11fIETSDelay*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETSPEC {
    tANI_U8      present;
    tANI_U16     traffic_type: 1;
    tANI_U16             tsid: 4;
    tANI_U16        direction: 2;
    tANI_U16    access_policy: 2;
    tANI_U16      aggregation: 1;
    tANI_U16              psb: 1;
    tANI_U16    user_priority: 3;
    tANI_U16   tsinfo_ack_pol: 2;
    tANI_U8         schedule: 1;
    tANI_U8           unused: 7;
    tANI_U16             size: 15;
    tANI_U16            fixed: 1;
    tANI_U16     max_msdu_size;
    tANI_U32     min_service_int;
    tANI_U32     max_service_int;
    tANI_U32     inactivity_int;
    tANI_U32     suspension_int;
    tANI_U32     service_start_time;
    tANI_U32     min_data_rate;
    tANI_U32     mean_data_rate;
    tANI_U32     peak_data_rate;
    tANI_U32     burst_size;
    tANI_U32     delay_bound;
    tANI_U32     min_phy_rate;
    tANI_U16     surplus_bw_allowance;
    tANI_U16     medium_time;
} tDot11fIETSPEC;

#define DOT11F_EID_TSPEC ( 13 )

#define DOT11F_IE_TSPEC_MIN_LEN ( 55 )

#define DOT11F_IE_TSPEC_MAX_LEN ( 55 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTSPEC(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETSPEC*);

tANI_U32 dot11fPackIeTSPEC(tpAniSirGlobal, tDot11fIETSPEC*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETSPEC(tpAniSirGlobal, tDot11fIETSPEC*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWMMSchedule {
    tANI_U8      present;
    tANI_U8      version ;
    tANI_U16      aggregation: 1;
    tANI_U16             tsid: 4;
    tANI_U16        direction: 2;
    tANI_U16         reserved: 9;
    tANI_U32     service_start_time;
    tANI_U32     service_interval;
    tANI_U16     max_service_dur;
    tANI_U16     spec_interval;
} tDot11fIEWMMSchedule;

#define DOT11F_EID_WMMSCHEDULE ( 221 )

#define DOT11F_IE_WMMSCHEDULE_MIN_LEN ( 20 )

#define DOT11F_IE_WMMSCHEDULE_MAX_LEN ( 20 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWMMSchedule(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWMMSchedule*);

tANI_U32 dot11fPackIeWMMSchedule(tpAniSirGlobal, tDot11fIEWMMSchedule*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWMMSchedule(tpAniSirGlobal, tDot11fIEWMMSchedule*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWMMTCLAS {
    tANI_U8      present;
    tANI_U8      version ;
    tANI_U8      user_priority;
    tANI_U8      classifier_type;
    tANI_U8      classifier_mask;
    union
    {
        struct
        {
            tANI_U8 source[6];
            tANI_U8 dest[6];
            tANI_U16 type;
        } EthParams; 
        struct
        {
            tANI_U8 version;
            union
            {
                struct
                {
                    tANI_U8 source[4];
                    tANI_U8 dest[4];
                    tANI_U16 src_port;
                    tANI_U16 dest_port;
                    tANI_U8 DSCP;
                    tANI_U8 proto;
                    tANI_U8 reserved;
                } IpV4Params; 
                struct
                {
                    tANI_U8 source[16];
                    tANI_U8 dest[16];
                    tANI_U16 src_port;
                    tANI_U16 dest_port;
                    tANI_U8 flow_label[3];
                } IpV6Params; 
            } params;
        } IpParams; 
        struct
        {
            tANI_U16 tag_type;
        } Params8021dq; 
    } info;
} tDot11fIEWMMTCLAS;

#define DOT11F_EID_WMMTCLAS ( 221 )

#define DOT11F_IE_WMMTCLAS_MIN_LEN ( 11 )

#define DOT11F_IE_WMMTCLAS_MAX_LEN ( 49 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWMMTCLAS(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWMMTCLAS*);

tANI_U32 dot11fPackIeWMMTCLAS(tpAniSirGlobal, tDot11fIEWMMTCLAS*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWMMTCLAS(tpAniSirGlobal, tDot11fIEWMMTCLAS*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWMMTCLASPROC {
    tANI_U8      present;
    tANI_U8      version ;
    tANI_U8      processing;
} tDot11fIEWMMTCLASPROC;

#define DOT11F_EID_WMMTCLASPROC ( 221 )

#define DOT11F_IE_WMMTCLASPROC_MIN_LEN ( 7 )

#define DOT11F_IE_WMMTCLASPROC_MAX_LEN ( 7 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWMMTCLASPROC(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWMMTCLASPROC*);

tANI_U32 dot11fPackIeWMMTCLASPROC(tpAniSirGlobal, tDot11fIEWMMTCLASPROC*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWMMTCLASPROC(tpAniSirGlobal, tDot11fIEWMMTCLASPROC*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWMMTSDelay {
    tANI_U8      present;
    tANI_U8      version ;
    tANI_U32     delay;
} tDot11fIEWMMTSDelay;

#define DOT11F_EID_WMMTSDELAY ( 221 )

#define DOT11F_IE_WMMTSDELAY_MIN_LEN ( 10 )

#define DOT11F_IE_WMMTSDELAY_MAX_LEN ( 10 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWMMTSDelay(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWMMTSDelay*);

tANI_U32 dot11fPackIeWMMTSDelay(tpAniSirGlobal, tDot11fIEWMMTSDelay*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWMMTSDelay(tpAniSirGlobal, tDot11fIEWMMTSDelay*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWMMTSPEC {
    tANI_U8      present;
    tANI_U8      version ;
    tANI_U16     traffic_type: 1;
    tANI_U16             tsid: 4;
    tANI_U16        direction: 2;
    tANI_U16    access_policy: 2;
    tANI_U16      aggregation: 1;
    tANI_U16              psb: 1;
    tANI_U16    user_priority: 3;
    tANI_U16   tsinfo_ack_pol: 2;
    tANI_U8      tsinfo_rsvd: 7;
    tANI_U8  burst_size_defn: 1;
    tANI_U16             size: 15;
    tANI_U16            fixed: 1;
    tANI_U16     max_msdu_size;
    tANI_U32     min_service_int;
    tANI_U32     max_service_int;
    tANI_U32     inactivity_int;
    tANI_U32     suspension_int;
    tANI_U32     service_start_time;
    tANI_U32     min_data_rate;
    tANI_U32     mean_data_rate;
    tANI_U32     peak_data_rate;
    tANI_U32     burst_size;
    tANI_U32     delay_bound;
    tANI_U32     min_phy_rate;
    tANI_U16     surplus_bw_allowance;
    tANI_U16     medium_time;
} tDot11fIEWMMTSPEC;

#define DOT11F_EID_WMMTSPEC ( 221 )

#define DOT11F_IE_WMMTSPEC_MIN_LEN ( 61 )

#define DOT11F_IE_WMMTSPEC_MAX_LEN ( 61 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWMMTSPEC(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWMMTSPEC*);

tANI_U32 dot11fPackIeWMMTSPEC(tpAniSirGlobal, tDot11fIEWMMTSPEC*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWMMTSPEC(tpAniSirGlobal, tDot11fIEWMMTSPEC*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEAID {
    tANI_U8      present;
    tANI_U16     assocId;
} tDot11fIEAID;

#define DOT11F_EID_AID ( 197 )

#define DOT11F_IE_AID_MIN_LEN ( 2 )

#define DOT11F_IE_AID_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeAID(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEAID*);

tANI_U32 dot11fPackIeAID(tpAniSirGlobal, tDot11fIEAID*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEAID(tpAniSirGlobal, tDot11fIEAID*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEAirgo {
    tANI_U8                     present;
    tDot11fIEPropSuppRates      PropSuppRates;
    tDot11fIEAPName             APName;
    tDot11fIEHCF                HCF;
    tDot11fIEWDS                WDS;
    tDot11fIEBPIndicator        BPIndicator;
    tDot11fIELoadInfo           LoadInfo;
    tDot11fIELoadBalance        LoadBalance;
    tDot11fIEPropAssocType      PropAssocType;
    tDot11fIELLAttr             LLAttr;
    tDot11fIEPropCapability     PropCapability;
    tDot11fIEVersion            Version;
    tDot11fIEPropEDCAParams     PropEDCAParams;
    tDot11fIETitan              Titan;
    tDot11fIEPropChannSwitchAnn PropChannSwitchAnn;
    tDot11fIEPropQuietBSS       PropQuietBSS;
    tDot11fIETriggerStaBgScan   TriggerStaBgScan;
    tDot11fIETaurus             Taurus;
} tDot11fIEAirgo;

#define DOT11F_EID_AIRGO ( 221 )

#define DOT11F_IE_AIRGO_MIN_LEN ( 3 )

#define DOT11F_IE_AIRGO_MAX_LEN ( 230 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeAirgo(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEAirgo*);

tANI_U32 dot11fPackIeAirgo(tpAniSirGlobal, tDot11fIEAirgo*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEAirgo(tpAniSirGlobal, tDot11fIEAirgo*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIECCXCckmOpaque {
    tANI_U8      present;
    tANI_U8      num_data;
    tANI_U8      data[20];
} tDot11fIECCXCckmOpaque;

#define DOT11F_EID_CCXCCKMOPAQUE ( 156 )

#define DOT11F_IE_CCXCCKMOPAQUE_MIN_LEN ( 10 )

#define DOT11F_IE_CCXCCKMOPAQUE_MAX_LEN ( 24 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeCCXCckmOpaque(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIECCXCckmOpaque*);

tANI_U32 dot11fPackIeCCXCckmOpaque(tpAniSirGlobal, tDot11fIECCXCckmOpaque*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIECCXCckmOpaque(tpAniSirGlobal, tDot11fIECCXCckmOpaque*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIECCXRadMgmtCap {
    tANI_U8      present;
    tANI_U8      mgmt_state;
    tANI_U8      mbssid_mask: 3;
    tANI_U8         reserved: 5;
} tDot11fIECCXRadMgmtCap;

#define DOT11F_EID_CCXRADMGMTCAP ( 221 )

#define DOT11F_IE_CCXRADMGMTCAP_MIN_LEN ( 6 )

#define DOT11F_IE_CCXRADMGMTCAP_MAX_LEN ( 6 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeCCXRadMgmtCap(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIECCXRadMgmtCap*);

tANI_U32 dot11fPackIeCCXRadMgmtCap(tpAniSirGlobal, tDot11fIECCXRadMgmtCap*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIECCXRadMgmtCap(tpAniSirGlobal, tDot11fIECCXRadMgmtCap*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIECCXTrafStrmMet {
    tANI_U8      present;
    tANI_U8      tsid;
    tANI_U8      state;
    tANI_U16     msmt_interval;
} tDot11fIECCXTrafStrmMet;

#define DOT11F_EID_CCXTRAFSTRMMET ( 221 )

#define DOT11F_IE_CCXTRAFSTRMMET_MIN_LEN ( 8 )

#define DOT11F_IE_CCXTRAFSTRMMET_MAX_LEN ( 8 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeCCXTrafStrmMet(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIECCXTrafStrmMet*);

tANI_U32 dot11fPackIeCCXTrafStrmMet(tpAniSirGlobal, tDot11fIECCXTrafStrmMet*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIECCXTrafStrmMet(tpAniSirGlobal, tDot11fIECCXTrafStrmMet*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIECCXTrafStrmRateSet {
    tANI_U8      present;
    tANI_U8      tsid;
    tANI_U8      num_tsrates;
    tANI_U8      tsrates[8];
} tDot11fIECCXTrafStrmRateSet;

#define DOT11F_EID_CCXTRAFSTRMRATESET ( 221 )

#define DOT11F_IE_CCXTRAFSTRMRATESET_MIN_LEN ( 5 )

#define DOT11F_IE_CCXTRAFSTRMRATESET_MAX_LEN ( 13 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeCCXTrafStrmRateSet(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIECCXTrafStrmRateSet*);

tANI_U32 dot11fPackIeCCXTrafStrmRateSet(tpAniSirGlobal, tDot11fIECCXTrafStrmRateSet*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIECCXTrafStrmRateSet(tpAniSirGlobal, tDot11fIECCXTrafStrmRateSet*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIECCXTxmitPower {
    tANI_U8      present;
    tANI_U8      power_limit;
    tANI_U8      reserved;
} tDot11fIECCXTxmitPower;

#define DOT11F_EID_CCXTXMITPOWER ( 150 )

#define DOT11F_IE_CCXTXMITPOWER_MIN_LEN ( 6 )

#define DOT11F_IE_CCXTXMITPOWER_MAX_LEN ( 6 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeCCXTxmitPower(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIECCXTxmitPower*);

tANI_U32 dot11fPackIeCCXTxmitPower(tpAniSirGlobal, tDot11fIECCXTxmitPower*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIECCXTxmitPower(tpAniSirGlobal, tDot11fIECCXTxmitPower*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIECCXVersion {
    tANI_U8      present;
    tANI_U8      version;
} tDot11fIECCXVersion;

#define DOT11F_EID_CCXVERSION ( 221 )

#define DOT11F_IE_CCXVERSION_MIN_LEN ( 5 )

#define DOT11F_IE_CCXVERSION_MAX_LEN ( 5 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeCCXVersion(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIECCXVersion*);

tANI_U32 dot11fPackIeCCXVersion(tpAniSirGlobal, tDot11fIECCXVersion*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIECCXVersion(tpAniSirGlobal, tDot11fIECCXVersion*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIECFParams {
    tANI_U8      present;
    tANI_U8      cfp_count;
    tANI_U8      cfp_period;
    tANI_U16     cfp_maxduration;
    tANI_U16     cfp_durremaining;
} tDot11fIECFParams;

#define DOT11F_EID_CFPARAMS ( 4 )

#define DOT11F_IE_CFPARAMS_MIN_LEN ( 6 )

#define DOT11F_IE_CFPARAMS_MAX_LEN ( 6 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeCFParams(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIECFParams*);

tANI_U32 dot11fPackIeCFParams(tpAniSirGlobal, tDot11fIECFParams*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIECFParams(tpAniSirGlobal, tDot11fIECFParams*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEChallengeText {
    tANI_U8      present;
    tANI_U8      num_text;
    tANI_U8      text[253];
} tDot11fIEChallengeText;

#define DOT11F_EID_CHALLENGETEXT ( 16 )

#define DOT11F_IE_CHALLENGETEXT_MIN_LEN ( 1 )

#define DOT11F_IE_CHALLENGETEXT_MAX_LEN ( 253 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeChallengeText(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEChallengeText*);

tANI_U32 dot11fPackIeChallengeText(tpAniSirGlobal, tDot11fIEChallengeText*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEChallengeText(tpAniSirGlobal, tDot11fIEChallengeText*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEChanSwitchAnn {
    tANI_U8      present;
    tANI_U8      switchMode;
    tANI_U8      newChannel;
    tANI_U8      switchCount;
} tDot11fIEChanSwitchAnn;

#define DOT11F_EID_CHANSWITCHANN ( 37 )

#define DOT11F_IE_CHANSWITCHANN_MIN_LEN ( 3 )

#define DOT11F_IE_CHANSWITCHANN_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeChanSwitchAnn(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEChanSwitchAnn*);

tANI_U32 dot11fPackIeChanSwitchAnn(tpAniSirGlobal, tDot11fIEChanSwitchAnn*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEChanSwitchAnn(tpAniSirGlobal, tDot11fIEChanSwitchAnn*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIECountry {
    tANI_U8      present;
    tANI_U8      country[3];
    tANI_U8      num_triplets;
    tANI_U8      triplets[84][3];
} tDot11fIECountry;

#define DOT11F_EID_COUNTRY ( 7 )

#define DOT11F_IE_COUNTRY_MIN_LEN ( 3 )

#define DOT11F_IE_COUNTRY_MAX_LEN ( 255 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeCountry(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIECountry*);

tANI_U32 dot11fPackIeCountry(tpAniSirGlobal, tDot11fIECountry*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIECountry(tpAniSirGlobal, tDot11fIECountry*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEDSParams {
    tANI_U8      present;
    tANI_U8      curr_channel;
} tDot11fIEDSParams;

#define DOT11F_EID_DSPARAMS ( 3 )

#define DOT11F_IE_DSPARAMS_MIN_LEN ( 1 )

#define DOT11F_IE_DSPARAMS_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeDSParams(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEDSParams*);

tANI_U32 dot11fPackIeDSParams(tpAniSirGlobal, tDot11fIEDSParams*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEDSParams(tpAniSirGlobal, tDot11fIEDSParams*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEEDCAParamSet {
    tANI_U8      present;
    tANI_U8      qos;
    tANI_U8      reserved;
    tANI_U8       acbe_aifsn: 4;
    tANI_U8         acbe_acm: 1;
    tANI_U8         acbe_aci: 2;
    tANI_U8          unused1: 1;
    tANI_U8      acbe_acwmin: 4;
    tANI_U8      acbe_acwmax: 4;
    tANI_U16     acbe_txoplimit;
    tANI_U8       acbk_aifsn: 4;
    tANI_U8         acbk_acm: 1;
    tANI_U8         acbk_aci: 2;
    tANI_U8          unused2: 1;
    tANI_U8      acbk_acwmin: 4;
    tANI_U8      acbk_acwmax: 4;
    tANI_U16     acbk_txoplimit;
    tANI_U8       acvi_aifsn: 4;
    tANI_U8         acvi_acm: 1;
    tANI_U8         acvi_aci: 2;
    tANI_U8          unused3: 1;
    tANI_U8      acvi_acwmin: 4;
    tANI_U8      acvi_acwmax: 4;
    tANI_U16     acvi_txoplimit;
    tANI_U8       acvo_aifsn: 4;
    tANI_U8         acvo_acm: 1;
    tANI_U8         acvo_aci: 2;
    tANI_U8          unused4: 1;
    tANI_U8      acvo_acwmin: 4;
    tANI_U8      acvo_acwmax: 4;
    tANI_U16     acvo_txoplimit;
} tDot11fIEEDCAParamSet;

#define DOT11F_EID_EDCAPARAMSET ( 12 )

#define DOT11F_IE_EDCAPARAMSET_MIN_LEN ( 18 )

#define DOT11F_IE_EDCAPARAMSET_MAX_LEN ( 18 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeEDCAParamSet(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEEDCAParamSet*);

tANI_U32 dot11fPackIeEDCAParamSet(tpAniSirGlobal, tDot11fIEEDCAParamSet*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEEDCAParamSet(tpAniSirGlobal, tDot11fIEEDCAParamSet*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEERPInfo {
    tANI_U8      present;
    tANI_U8  non_erp_present: 1;
    tANI_U8         use_prot: 1;
    tANI_U8  barker_preamble: 1;
    tANI_U8           unused: 5;
} tDot11fIEERPInfo;

#define DOT11F_EID_ERPINFO ( 42 )

#define DOT11F_IE_ERPINFO_MIN_LEN ( 1 )

#define DOT11F_IE_ERPINFO_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeERPInfo(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEERPInfo*);

tANI_U32 dot11fPackIeERPInfo(tpAniSirGlobal, tDot11fIEERPInfo*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEERPInfo(tpAniSirGlobal, tDot11fIEERPInfo*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEExtCap {
    tANI_U8      present;
    tANI_U32 bssCoexistMgmtSupport: 1;
    tANI_U32        reserved1: 1;
    tANI_U32    extChanSwitch: 1;
    tANI_U32        reserved2: 1;
    tANI_U32          psmpCap: 1;
    tANI_U32        reserved3: 1;
    tANI_U32         spsmpCap: 1;
    tANI_U32            event: 1;
    tANI_U32      diagnostics: 1;
    tANI_U32 multiDiagnostics: 1;
    tANI_U32      locTracking: 1;
    tANI_U32              FMS: 1;
    tANI_U32  proxyARPService: 1;
    tANI_U32 coLocIntfReporting: 1;
    tANI_U32         civicLoc: 1;
    tANI_U32    geospatialLoc: 1;
    tANI_U32              TFS: 1;
    tANI_U32     wnmSleepMode: 1;
    tANI_U32     timBroadcast: 1;
    tANI_U32    bssTransition: 1;
    tANI_U32    qosTrafficCap: 1;
    tANI_U32         acStaCnt: 1;
    tANI_U32       multiBSSID: 1;
    tANI_U32       timingMeas: 1;
    tANI_U32        chanUsage: 1;
    tANI_U32         ssidList: 1;
    tANI_U32              DMS: 1;
    tANI_U32     UTCTSFOffset: 1;
    tANI_U32 TDLSPeerUAPSDBufferSTA: 1;
    tANI_U32  TDLSPeerPSMSupp: 1;
    tANI_U32 TDLSChannelSwitching: 1;
    tANI_U32 interworkingService: 1;
    tANI_U16           qosMap: 1;
    tANI_U16              EBR: 1;
    tANI_U16    sspnInterface: 1;
    tANI_U16        reserved4: 1;
    tANI_U16         msgCFCap: 1;
    tANI_U16      TDLSSupport: 1;
    tANI_U16   TDLSProhibited: 1;
    tANI_U16 TDLSChanSwitProhibited: 1;
    tANI_U16 rejectUnadmittedTraffic: 1;
    tANI_U16 serviceIntervalGranularity: 3;
    tANI_U16    identifierLoc: 1;
    tANI_U16 uapsdCoexistence: 1;
    tANI_U16  wnmNotification: 1;
    tANI_U16        reserved5: 1;
    tANI_U16         UTF8SSID: 1;
    tANI_U16        reserved6: 12;
    tANI_U16      TDLSWiderBW: 1;
    tANI_U16 operModeNotification: 1;
    tANI_U16        reserved7: 1;
} tDot11fIEExtCap;

#define DOT11F_EID_EXTCAP ( 127 )

#define DOT11F_IE_EXTCAP_MIN_LEN ( 8 )

#define DOT11F_IE_EXTCAP_MAX_LEN ( 8 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeExtCap(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEExtCap*);

tANI_U32 dot11fPackIeExtCap(tpAniSirGlobal, tDot11fIEExtCap*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEExtCap(tpAniSirGlobal, tDot11fIEExtCap*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEExtChanSwitchAnn {
    tANI_U8      present;
    tANI_U8      secondaryChannelOffset;
} tDot11fIEExtChanSwitchAnn;

#define DOT11F_EID_EXTCHANSWITCHANN ( 62 )

#define DOT11F_IE_EXTCHANSWITCHANN_MIN_LEN ( 1 )

#define DOT11F_IE_EXTCHANSWITCHANN_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeExtChanSwitchAnn(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEExtChanSwitchAnn*);

tANI_U32 dot11fPackIeExtChanSwitchAnn(tpAniSirGlobal, tDot11fIEExtChanSwitchAnn*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEExtChanSwitchAnn(tpAniSirGlobal, tDot11fIEExtChanSwitchAnn*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEExtSuppRates {
    tANI_U8      present;
    tANI_U8      num_rates;
    tANI_U8      rates[12];
} tDot11fIEExtSuppRates;

#define DOT11F_EID_EXTSUPPRATES ( 50 )

#define DOT11F_IE_EXTSUPPRATES_MIN_LEN ( 1 )

#define DOT11F_IE_EXTSUPPRATES_MAX_LEN ( 12 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeExtSuppRates(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEExtSuppRates*);

tANI_U32 dot11fPackIeExtSuppRates(tpAniSirGlobal, tDot11fIEExtSuppRates*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEExtSuppRates(tpAniSirGlobal, tDot11fIEExtSuppRates*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEFHParamSet {
    tANI_U8      present;
    tANI_U16     dwell_time;
    tANI_U8      hop_set;
    tANI_U8      hop_pattern;
    tANI_U8      hop_index;
} tDot11fIEFHParamSet;

#define DOT11F_EID_FHPARAMSET ( 2 )

#define DOT11F_IE_FHPARAMSET_MIN_LEN ( 5 )

#define DOT11F_IE_FHPARAMSET_MAX_LEN ( 5 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeFHParamSet(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEFHParamSet*);

tANI_U32 dot11fPackIeFHParamSet(tpAniSirGlobal, tDot11fIEFHParamSet*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEFHParamSet(tpAniSirGlobal, tDot11fIEFHParamSet*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEFHParams {
    tANI_U8      present;
    tANI_U8      radix;
    tANI_U8      nchannels;
} tDot11fIEFHParams;

#define DOT11F_EID_FHPARAMS ( 8 )

#define DOT11F_IE_FHPARAMS_MIN_LEN ( 2 )

#define DOT11F_IE_FHPARAMS_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeFHParams(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEFHParams*);

tANI_U32 dot11fPackIeFHParams(tpAniSirGlobal, tDot11fIEFHParams*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEFHParams(tpAniSirGlobal, tDot11fIEFHParams*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEFHPattTable {
    tANI_U8      present;
    tANI_U8      flag;
    tANI_U8      nsets;
    tANI_U8      modulus;
    tANI_U8      offset;
    tANI_U8      num_randtable;
    tANI_U8      randtable[251];
} tDot11fIEFHPattTable;

#define DOT11F_EID_FHPATTTABLE ( 9 )

#define DOT11F_IE_FHPATTTABLE_MIN_LEN ( 4 )

#define DOT11F_IE_FHPATTTABLE_MAX_LEN ( 255 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeFHPattTable(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEFHPattTable*);

tANI_U32 dot11fPackIeFHPattTable(tpAniSirGlobal, tDot11fIEFHPattTable*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEFHPattTable(tpAniSirGlobal, tDot11fIEFHPattTable*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEFTInfo {
    tANI_U8          present;
    tANI_U16             reserved: 8;
    tANI_U16              IECount: 8;
    tANI_U8          MIC[16];
    tANI_U8          Anonce[32];
    tANI_U8          Snonce[32];
    tDot11fIER1KH_ID R1KH_ID;
    tDot11fIEGTK     GTK;
    tDot11fIER0KH_ID R0KH_ID;
    tDot11fIEIGTK    IGTK;
} tDot11fIEFTInfo;

#define DOT11F_EID_FTINFO ( 55 )

#define DOT11F_IE_FTINFO_MIN_LEN ( 82 )

#define DOT11F_IE_FTINFO_MAX_LEN ( 220 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeFTInfo(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEFTInfo*);

tANI_U32 dot11fPackIeFTInfo(tpAniSirGlobal, tDot11fIEFTInfo*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEFTInfo(tpAniSirGlobal, tDot11fIEFTInfo*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEHTCaps {
    tANI_U8      present;
    tANI_U16     advCodingCap: 1;
    tANI_U16 supportedChannelWidthSet: 1;
    tANI_U16    mimoPowerSave: 2;
    tANI_U16       greenField: 1;
    tANI_U16     shortGI20MHz: 1;
    tANI_U16     shortGI40MHz: 1;
    tANI_U16           txSTBC: 1;
    tANI_U16           rxSTBC: 2;
    tANI_U16        delayedBA: 1;
    tANI_U16 maximalAMSDUsize: 1;
    tANI_U16 dsssCckMode40MHz: 1;
    tANI_U16             psmp: 1;
    tANI_U16 stbcControlFrame: 1;
    tANI_U16 lsigTXOPProtection: 1;
    tANI_U8 maxRxAMPDUFactor: 2;
    tANI_U8      mpduDensity: 3;
    tANI_U8        reserved1: 3;
    tANI_U8      supportedMCSSet[16];
    tANI_U16              pco: 1;
    tANI_U16   transitionTime: 2;
    tANI_U16        reserved2: 5;
    tANI_U16      mcsFeedback: 2;
    tANI_U16        reserved3: 6;
    tANI_U32             txBF: 1;
    tANI_U32 rxStaggeredSounding: 1;
    tANI_U32 txStaggeredSounding: 1;
    tANI_U32            rxZLF: 1;
    tANI_U32            txZLF: 1;
    tANI_U32     implicitTxBF: 1;
    tANI_U32      calibration: 2;
    tANI_U32  explicitCSITxBF: 1;
    tANI_U32 explicitUncompressedSteeringMatrix: 1;
    tANI_U32 explicitBFCSIFeedback: 3;
    tANI_U32 explicitUncompressedSteeringMatrixFeedback: 3;
    tANI_U32 explicitCompressedSteeringMatrixFeedback: 3;
    tANI_U32 csiNumBFAntennae: 2;
    tANI_U32 uncompressedSteeringMatrixBFAntennae: 2;
    tANI_U32 compressedSteeringMatrixBFAntennae: 2;
    tANI_U32        reserved4: 7;
    tANI_U8 antennaSelection: 1;
    tANI_U8 explicitCSIFeedbackTx: 1;
    tANI_U8 antennaIndicesFeedbackTx: 1;
    tANI_U8 explicitCSIFeedback: 1;
    tANI_U8 antennaIndicesFeedback: 1;
    tANI_U8             rxAS: 1;
    tANI_U8  txSoundingPPDUs: 1;
    tANI_U8        reserved5: 1;
    tANI_U8      num_rsvd;
    tANI_U8      rsvd[32];
} tDot11fIEHTCaps;

#define DOT11F_EID_HTCAPS ( 45 )

#define DOT11F_IE_HTCAPS_MIN_LEN ( 26 )

#define DOT11F_IE_HTCAPS_MAX_LEN ( 58 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeHTCaps(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEHTCaps*);

tANI_U32 dot11fPackIeHTCaps(tpAniSirGlobal, tDot11fIEHTCaps*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEHTCaps(tpAniSirGlobal, tDot11fIEHTCaps*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEHTInfo {
    tANI_U8      present;
    tANI_U8      primaryChannel;
    tANI_U8 secondaryChannelOffset: 2;
    tANI_U8 recommendedTxWidthSet: 1;
    tANI_U8         rifsMode: 1;
    tANI_U8 controlledAccessOnly: 1;
    tANI_U8 serviceIntervalGranularity: 3;
    tANI_U16           opMode: 2;
    tANI_U16 nonGFDevicesPresent: 1;
    tANI_U16 transmitBurstLimit: 1;
    tANI_U16 obssNonHTStaPresent: 1;
    tANI_U16         reserved: 11;
    tANI_U16     basicSTBCMCS: 7;
    tANI_U16 dualCTSProtection: 1;
    tANI_U16  secondaryBeacon: 1;
    tANI_U16 lsigTXOPProtectionFullSupport: 1;
    tANI_U16        pcoActive: 1;
    tANI_U16         pcoPhase: 1;
    tANI_U16        reserved2: 4;
    tANI_U8      basicMCSSet[16];
    tANI_U8      num_rsvd;
    tANI_U8      rsvd[32];
} tDot11fIEHTInfo;

#define DOT11F_EID_HTINFO ( 61 )

#define DOT11F_IE_HTINFO_MIN_LEN ( 22 )

#define DOT11F_IE_HTINFO_MAX_LEN ( 54 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeHTInfo(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEHTInfo*);

tANI_U32 dot11fPackIeHTInfo(tpAniSirGlobal, tDot11fIEHTInfo*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEHTInfo(tpAniSirGlobal, tDot11fIEHTInfo*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEIBSSParams {
    tANI_U8      present;
    tANI_U16     atim;
} tDot11fIEIBSSParams;

#define DOT11F_EID_IBSSPARAMS ( 6 )

#define DOT11F_IE_IBSSPARAMS_MIN_LEN ( 2 )

#define DOT11F_IE_IBSSPARAMS_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeIBSSParams(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEIBSSParams*);

tANI_U32 dot11fPackIeIBSSParams(tpAniSirGlobal, tDot11fIEIBSSParams*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEIBSSParams(tpAniSirGlobal, tDot11fIEIBSSParams*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIELinkIdentifier {
    tANI_U8      present;
    tANI_U8      bssid[6];
    tANI_U8      InitStaAddr[6];
    tANI_U8      RespStaAddr[6];
} tDot11fIELinkIdentifier;

#define DOT11F_EID_LINKIDENTIFIER ( 101 )

#define DOT11F_IE_LINKIDENTIFIER_MIN_LEN ( 18 )

#define DOT11F_IE_LINKIDENTIFIER_MAX_LEN ( 18 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeLinkIdentifier(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIELinkIdentifier*);

tANI_U32 dot11fPackIeLinkIdentifier(tpAniSirGlobal, tDot11fIELinkIdentifier*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIELinkIdentifier(tpAniSirGlobal, tDot11fIELinkIdentifier*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEMeasurementReport {
    tANI_U8      present;
    tANI_U8      token;
    tANI_U8             late: 1;
    tANI_U8        incapable: 1;
    tANI_U8          refused: 1;
    tANI_U8           unused: 5;
    tANI_U8      type;
    union
    {
        struct
        {
            tANI_U8 channel;
            tDOT11F_U64 meas_start_time;
            tANI_U16 meas_duration;
            tANI_U8            bss: 1;
            tANI_U8  ofdm_preamble: 1;
            tANI_U8    unid_signal: 1;
            tANI_U8          rader: 1;
            tANI_U8     unmeasured: 1;
            tANI_U8         unused: 3;
        } Basic; 
        struct
        {
            tANI_U8 channel;
            tDOT11F_U64 meas_start_time;
            tANI_U16 meas_duration;
            tANI_U8 cca_busy_fraction;
        } CCA; 
        struct
        {
            tANI_U8 channel;
            tDOT11F_U64 meas_start_time;
            tANI_U16 meas_duration;
            tANI_U8 rpi0_density;
            tANI_U8 rpi1_density;
            tANI_U8 rpi2_density;
            tANI_U8 rpi3_density;
            tANI_U8 rpi4_density;
            tANI_U8 rpi5_density;
            tANI_U8 rpi6_density;
            tANI_U8 rpi7_density;
        } RPIHistogram; 
        struct
        {
            tANI_U8 regClass;
            tANI_U8 channel;
            tDOT11F_U64 meas_start_time;
            tANI_U16 meas_duration;
            tANI_U8        condensed_PHY: 7;
            tANI_U8  reported_frame_type: 1;
            tANI_U8 RCPI;
            tANI_U8 RSNI;
            tANI_U8 BSSID[6];
            tANI_U8 antenna_id;
            tANI_U32 parent_TSF;
    tDot11fIEBeaconReportFrmBody BeaconReportFrmBody;
        } Beacon; 
    } report;
} tDot11fIEMeasurementReport;

#define DOT11F_EID_MEASUREMENTREPORT ( 39 )

#define DOT11F_IE_MEASUREMENTREPORT_MIN_LEN ( 3 )

#define DOT11F_IE_MEASUREMENTREPORT_MAX_LEN ( 29 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeMeasurementReport(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEMeasurementReport*);

tANI_U32 dot11fPackIeMeasurementReport(tpAniSirGlobal, tDot11fIEMeasurementReport*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEMeasurementReport(tpAniSirGlobal, tDot11fIEMeasurementReport*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEMeasurementRequest {
    tANI_U8      present;
    tANI_U8      measurement_token;
    tANI_U8         parallel: 1;
    tANI_U8           enable: 1;
    tANI_U8          request: 1;
    tANI_U8           report: 1;
    tANI_U8 durationMandatory: 1;
    tANI_U8           unused: 3;
    tANI_U8      measurement_type;
    union
    {
        struct
        {
            tANI_U8 channel_no;
            tANI_U8 meas_start_time[8];
            tANI_U16 meas_duration;
        } Basic; 
        struct
        {
            tANI_U8 channel_no;
            tANI_U8 meas_start_time[8];
            tANI_U16 meas_duration;
        } CCA; 
        struct
        {
            tANI_U8 channel_no;
            tANI_U8 meas_start_time[8];
            tANI_U16 meas_duration;
        } RPIHistogram; 
        struct
        {
            tANI_U8 regClass;
            tANI_U8 channel;
            tANI_U16 randomization;
            tANI_U16 meas_duration;
            tANI_U8 meas_mode;
            tANI_U8 BSSID[6];
    tDot11fIESSID SSID;
    tDot11fIEBeaconReporting BeaconReporting;
    tDot11fIEBcnReportingDetail BcnReportingDetail;
    tDot11fIERequestedInfo RequestedInfo;
    tANI_U16 num_APChannelReport;
    tDot11fIEAPChannelReport APChannelReport[2];
        } Beacon; 
    } measurement_request;
} tDot11fIEMeasurementRequest;

#define DOT11F_EID_MEASUREMENTREQUEST ( 38 )

#define DOT11F_IE_MEASUREMENTREQUEST_MIN_LEN ( 14 )

#define DOT11F_IE_MEASUREMENTREQUEST_MAX_LEN ( 16 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeMeasurementRequest(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEMeasurementRequest*);

tANI_U32 dot11fPackIeMeasurementRequest(tpAniSirGlobal, tDot11fIEMeasurementRequest*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEMeasurementRequest(tpAniSirGlobal, tDot11fIEMeasurementRequest*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEMobilityDomain {
    tANI_U8      present;
    tANI_U16     MDID;
    tANI_U8        overDSCap: 1;
    tANI_U8   resourceReqCap: 1;
    tANI_U8         reserved: 6;
} tDot11fIEMobilityDomain;

#define DOT11F_EID_MOBILITYDOMAIN ( 54 )

#define DOT11F_IE_MOBILITYDOMAIN_MIN_LEN ( 3 )

#define DOT11F_IE_MOBILITYDOMAIN_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeMobilityDomain(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEMobilityDomain*);

tANI_U32 dot11fPackIeMobilityDomain(tpAniSirGlobal, tDot11fIEMobilityDomain*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEMobilityDomain(tpAniSirGlobal, tDot11fIEMobilityDomain*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIENeighborReport {
    tANI_U8                      present;
    tANI_U8                      bssid[6];
    tANI_U8                   APReachability: 2;
    tANI_U8                         Security: 1;
    tANI_U8                         KeyScope: 1;
    tANI_U8                      SpecMgmtCap: 1;
    tANI_U8                           QosCap: 1;
    tANI_U8                             apsd: 1;
    tANI_U8                              rrm: 1;
    tANI_U8                        DelayedBA: 1;
    tANI_U8                            ImmBA: 1;
    tANI_U8                   MobilityDomain: 1;
    tANI_U8                         reserved: 5;
    tANI_U16                     reserved1;
    tANI_U8                      regulatoryClass;
    tANI_U8                      channel;
    tANI_U8                      PhyType;
    tDot11fIETSFInfo             TSFInfo;
    tDot11fIECondensedCountryStr CondensedCountryStr;
    tDot11fIEMeasurementPilot    MeasurementPilot;
    tDot11fIERRMEnabledCap       RRMEnabledCap;
    tDot11fIEMultiBssid          MultiBssid;
} tDot11fIENeighborReport;

#define DOT11F_EID_NEIGHBORREPORT ( 52 )

#define DOT11F_IE_NEIGHBORREPORT_MIN_LEN ( 13 )

#define DOT11F_IE_NEIGHBORREPORT_MAX_LEN ( 546 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeNeighborReport(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIENeighborReport*);

tANI_U32 dot11fPackIeNeighborReport(tpAniSirGlobal, tDot11fIENeighborReport*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIENeighborReport(tpAniSirGlobal, tDot11fIENeighborReport*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEOBSSScanParameters {
    tANI_U8      present;
    tANI_U16     obssScanPassiveDwell;
    tANI_U16     obssScanActiveDwell;
    tANI_U16     bssChannelWidthTriggerScanInterval;
    tANI_U16     obssScanPassiveTotalPerChannel;
    tANI_U16     obssScanActiveTotalPerChannel;
    tANI_U16     bssWidthChannelTransitionDelayFactor;
    tANI_U16     obssScanActivityThreshold;
} tDot11fIEOBSSScanParameters;

#define DOT11F_EID_OBSSSCANPARAMETERS ( 74 )

#define DOT11F_IE_OBSSSCANPARAMETERS_MIN_LEN ( 14 )

#define DOT11F_IE_OBSSSCANPARAMETERS_MAX_LEN ( 14 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeOBSSScanParameters(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEOBSSScanParameters*);

tANI_U32 dot11fPackIeOBSSScanParameters(tpAniSirGlobal, tDot11fIEOBSSScanParameters*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEOBSSScanParameters(tpAniSirGlobal, tDot11fIEOBSSScanParameters*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEOperatingMode {
    tANI_U8      present;
    tANI_U8        chanWidth: 2;
    tANI_U8         reserved: 2;
    tANI_U8            rxNSS: 3;
    tANI_U8        rxNSSType: 1;
} tDot11fIEOperatingMode;

#define DOT11F_EID_OPERATINGMODE ( 199 )

#define DOT11F_IE_OPERATINGMODE_MIN_LEN ( 1 )

#define DOT11F_IE_OPERATINGMODE_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeOperatingMode(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEOperatingMode*);

tANI_U32 dot11fPackIeOperatingMode(tpAniSirGlobal, tDot11fIEOperatingMode*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEOperatingMode(tpAniSirGlobal, tDot11fIEOperatingMode*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEOxygenNetwork {
    tANI_U8      present;
    tANI_U16     data;
} tDot11fIEOxygenNetwork;

#define DOT11F_EID_OXYGENNETWORK ( 221 )

#define DOT11F_IE_OXYGENNETWORK_MIN_LEN ( 5 )

#define DOT11F_IE_OXYGENNETWORK_MAX_LEN ( 5 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeOxygenNetwork(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEOxygenNetwork*);

tANI_U32 dot11fPackIeOxygenNetwork(tpAniSirGlobal, tDot11fIEOxygenNetwork*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEOxygenNetwork(tpAniSirGlobal, tDot11fIEOxygenNetwork*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PAssocReq {
    tANI_U8      present;
    tDot11fTLVP2PCapability P2PCapability;
    tDot11fTLVExtendedListenTiming ExtendedListenTiming;
    tDot11fTLVP2PDeviceInfo P2PDeviceInfo;
} tDot11fIEP2PAssocReq;

#define DOT11F_EID_P2PASSOCREQ ( 221 )

#define DOT11F_IE_P2PASSOCREQ_MIN_LEN ( 4 )

#define DOT11F_IE_P2PASSOCREQ_MAX_LEN ( 71 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PAssocReq(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PAssocReq*);

tANI_U32 dot11fPackIeP2PAssocReq(tpAniSirGlobal, tDot11fIEP2PAssocReq*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PAssocReq(tpAniSirGlobal, tDot11fIEP2PAssocReq*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PAssocRes {
    tANI_U8      present;
    tDot11fTLVP2PStatus P2PStatus;
    tDot11fTLVExtendedListenTiming ExtendedListenTiming;
} tDot11fIEP2PAssocRes;

#define DOT11F_EID_P2PASSOCRES ( 221 )

#define DOT11F_IE_P2PASSOCRES_MIN_LEN ( 4 )

#define DOT11F_IE_P2PASSOCRES_MAX_LEN ( 15 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PAssocRes(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PAssocRes*);

tANI_U32 dot11fPackIeP2PAssocRes(tpAniSirGlobal, tDot11fIEP2PAssocRes*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PAssocRes(tpAniSirGlobal, tDot11fIEP2PAssocRes*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PBeacon {
    tANI_U8      present;
    tDot11fTLVP2PCapability P2PCapability;
    tDot11fTLVP2PDeviceId P2PDeviceId;
    tDot11fTLVNoticeOfAbsence NoticeOfAbsence;
} tDot11fIEP2PBeacon;

#define DOT11F_EID_P2PBEACON ( 221 )

#define DOT11F_IE_P2PBEACON_MIN_LEN ( 4 )

#define DOT11F_IE_P2PBEACON_MAX_LEN ( 59 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PBeacon(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PBeacon*);

tANI_U32 dot11fPackIeP2PBeacon(tpAniSirGlobal, tDot11fIEP2PBeacon*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PBeacon(tpAniSirGlobal, tDot11fIEP2PBeacon*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PBeaconProbeRes {
    tANI_U8      present;
    tDot11fTLVP2PCapability P2PCapability;
    tDot11fTLVP2PDeviceId P2PDeviceId;
    tDot11fTLVExtendedListenTiming ExtendedListenTiming;
    tDot11fTLVNoticeOfAbsence NoticeOfAbsence;
    tDot11fTLVP2PDeviceInfo P2PDeviceInfo;
    tDot11fTLVP2PGroupInfo P2PGroupInfo;
} tDot11fIEP2PBeaconProbeRes;

#define DOT11F_EID_P2PBEACONPROBERES ( 221 )

#define DOT11F_IE_P2PBEACONPROBERES_MIN_LEN ( 4 )

#define DOT11F_IE_P2PBEACONPROBERES_MAX_LEN ( 1148 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PBeaconProbeRes(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PBeaconProbeRes*);

tANI_U32 dot11fPackIeP2PBeaconProbeRes(tpAniSirGlobal, tDot11fIEP2PBeaconProbeRes*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PBeaconProbeRes(tpAniSirGlobal, tDot11fIEP2PBeaconProbeRes*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PDeAuth {
    tANI_U8      present;
    tDot11fTLVMinorReasonCode MinorReasonCode;
} tDot11fIEP2PDeAuth;

#define DOT11F_EID_P2PDEAUTH ( 221 )

#define DOT11F_IE_P2PDEAUTH_MIN_LEN ( 4 )

#define DOT11F_IE_P2PDEAUTH_MAX_LEN ( 8 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PDeAuth(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PDeAuth*);

tANI_U32 dot11fPackIeP2PDeAuth(tpAniSirGlobal, tDot11fIEP2PDeAuth*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PDeAuth(tpAniSirGlobal, tDot11fIEP2PDeAuth*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PDeviceDiscoverabilityReq {
    tANI_U8      present;
    tDot11fTLVP2PDeviceId P2PDeviceId;
    tDot11fTLVP2PGroupId P2PGroupId;
} tDot11fIEP2PDeviceDiscoverabilityReq;

#define DOT11F_EID_P2PDEVICEDISCOVERABILITYREQ ( 221 )

#define DOT11F_IE_P2PDEVICEDISCOVERABILITYREQ_MIN_LEN ( 4 )

#define DOT11F_IE_P2PDEVICEDISCOVERABILITYREQ_MAX_LEN ( 54 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PDeviceDiscoverabilityReq(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PDeviceDiscoverabilityReq*);

tANI_U32 dot11fPackIeP2PDeviceDiscoverabilityReq(tpAniSirGlobal, tDot11fIEP2PDeviceDiscoverabilityReq*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PDeviceDiscoverabilityReq(tpAniSirGlobal, tDot11fIEP2PDeviceDiscoverabilityReq*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PDeviceDiscoverabilityRes {
    tANI_U8      present;
    tDot11fTLVP2PStatus P2PStatus;
} tDot11fIEP2PDeviceDiscoverabilityRes;

#define DOT11F_EID_P2PDEVICEDISCOVERABILITYRES ( 221 )

#define DOT11F_IE_P2PDEVICEDISCOVERABILITYRES_MIN_LEN ( 4 )

#define DOT11F_IE_P2PDEVICEDISCOVERABILITYRES_MAX_LEN ( 8 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PDeviceDiscoverabilityRes(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PDeviceDiscoverabilityRes*);

tANI_U32 dot11fPackIeP2PDeviceDiscoverabilityRes(tpAniSirGlobal, tDot11fIEP2PDeviceDiscoverabilityRes*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PDeviceDiscoverabilityRes(tpAniSirGlobal, tDot11fIEP2PDeviceDiscoverabilityRes*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PDisAssoc {
    tANI_U8      present;
    tDot11fTLVMinorReasonCode MinorReasonCode;
} tDot11fIEP2PDisAssoc;

#define DOT11F_EID_P2PDISASSOC ( 221 )

#define DOT11F_IE_P2PDISASSOC_MIN_LEN ( 4 )

#define DOT11F_IE_P2PDISASSOC_MAX_LEN ( 8 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PDisAssoc(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PDisAssoc*);

tANI_U32 dot11fPackIeP2PDisAssoc(tpAniSirGlobal, tDot11fIEP2PDisAssoc*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PDisAssoc(tpAniSirGlobal, tDot11fIEP2PDisAssoc*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PGONegCnf {
    tANI_U8      present;
    tDot11fTLVP2PStatus P2PStatus;
    tDot11fTLVP2PCapability P2PCapability;
    tDot11fTLVOperatingChannel OperatingChannel;
    tDot11fTLVChannelList ChannelList;
    tDot11fTLVP2PGroupId P2PGroupId;
} tDot11fIEP2PGONegCnf;

#define DOT11F_EID_P2PGONEGCNF ( 221 )

#define DOT11F_IE_P2PGONEGCNF_MIN_LEN ( 4 )

#define DOT11F_IE_P2PGONEGCNF_MAX_LEN ( 319 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PGONegCnf(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PGONegCnf*);

tANI_U32 dot11fPackIeP2PGONegCnf(tpAniSirGlobal, tDot11fIEP2PGONegCnf*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PGONegCnf(tpAniSirGlobal, tDot11fIEP2PGONegCnf*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PGONegReq {
    tANI_U8      present;
    tDot11fTLVP2PCapability P2PCapability;
    tDot11fTLVGOIntent GOIntent;
    tDot11fTLVConfigurationTimeout ConfigurationTimeout;
    tDot11fTLVListenChannel ListenChannel;
    tDot11fTLVExtendedListenTiming ExtendedListenTiming;
    tDot11fTLVIntendedP2PInterfaceAddress IntendedP2PInterfaceAddress;
    tDot11fTLVChannelList ChannelList;
    tDot11fTLVP2PDeviceInfo P2PDeviceInfo;
    tDot11fTLVOperatingChannel OperatingChannel;
} tDot11fIEP2PGONegReq;

#define DOT11F_EID_P2PGONEGREQ ( 221 )

#define DOT11F_IE_P2PGONEGREQ_MIN_LEN ( 4 )

#define DOT11F_IE_P2PGONEGREQ_MAX_LEN ( 362 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PGONegReq(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PGONegReq*);

tANI_U32 dot11fPackIeP2PGONegReq(tpAniSirGlobal, tDot11fIEP2PGONegReq*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PGONegReq(tpAniSirGlobal, tDot11fIEP2PGONegReq*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PGONegRes {
    tANI_U8      present;
    tDot11fTLVP2PStatus P2PStatus;
    tDot11fTLVP2PCapability P2PCapability;
    tDot11fTLVGOIntent GOIntent;
    tDot11fTLVConfigurationTimeout ConfigurationTimeout;
    tDot11fTLVOperatingChannel OperatingChannel;
    tDot11fTLVIntendedP2PInterfaceAddress IntendedP2PInterfaceAddress;
    tDot11fTLVChannelList ChannelList;
    tDot11fTLVP2PDeviceInfo P2PDeviceInfo;
    tDot11fTLVP2PGroupId P2PGroupId;
} tDot11fIEP2PGONegRes;

#define DOT11F_EID_P2PGONEGRES ( 221 )

#define DOT11F_IE_P2PGONEGRES_MIN_LEN ( 4 )

#define DOT11F_IE_P2PGONEGRES_MAX_LEN ( 392 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PGONegRes(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PGONegRes*);

tANI_U32 dot11fPackIeP2PGONegRes(tpAniSirGlobal, tDot11fIEP2PGONegRes*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PGONegRes(tpAniSirGlobal, tDot11fIEP2PGONegRes*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PGONegWPS {
    tANI_U8      present;
    tDot11fTLVVersion Version;
    tDot11fTLVDevicePasswordID DevicePasswordID;
} tDot11fIEP2PGONegWPS;

#define DOT11F_EID_P2PGONEGWPS ( 221 )

#define DOT11F_IE_P2PGONEGWPS_MIN_LEN ( 4 )

#define DOT11F_IE_P2PGONEGWPS_MAX_LEN ( 15 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PGONegWPS(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PGONegWPS*);

tANI_U32 dot11fPackIeP2PGONegWPS(tpAniSirGlobal, tDot11fIEP2PGONegWPS*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PGONegWPS(tpAniSirGlobal, tDot11fIEP2PGONegWPS*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PIEOpaque {
    tANI_U8      present;
    tANI_U8      num_data;
    tANI_U8      data[249];
} tDot11fIEP2PIEOpaque;

#define DOT11F_EID_P2PIEOPAQUE ( 221 )

#define DOT11F_IE_P2PIEOPAQUE_MIN_LEN ( 6 )

#define DOT11F_IE_P2PIEOPAQUE_MAX_LEN ( 253 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PIEOpaque(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PIEOpaque*);

tANI_U32 dot11fPackIeP2PIEOpaque(tpAniSirGlobal, tDot11fIEP2PIEOpaque*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PIEOpaque(tpAniSirGlobal, tDot11fIEP2PIEOpaque*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PInvitationReq {
    tANI_U8      present;
    tDot11fTLVConfigurationTimeout ConfigurationTimeout;
    tDot11fTLVInvitationFlags InvitationFlags;
    tDot11fTLVOperatingChannel OperatingChannel;
    tDot11fTLVP2PGroupBssid P2PGroupBssid;
    tDot11fTLVChannelList ChannelList;
    tDot11fTLVP2PGroupId P2PGroupId;
    tDot11fTLVP2PDeviceInfo P2PDeviceInfo;
} tDot11fIEP2PInvitationReq;

#define DOT11F_EID_P2PINVITATIONREQ ( 221 )

#define DOT11F_IE_P2PINVITATIONREQ_MIN_LEN ( 4 )

#define DOT11F_IE_P2PINVITATIONREQ_MAX_LEN ( 383 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PInvitationReq(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PInvitationReq*);

tANI_U32 dot11fPackIeP2PInvitationReq(tpAniSirGlobal, tDot11fIEP2PInvitationReq*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PInvitationReq(tpAniSirGlobal, tDot11fIEP2PInvitationReq*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PInvitationRes {
    tANI_U8      present;
    tDot11fTLVP2PStatus P2PStatus;
    tDot11fTLVConfigurationTimeout ConfigurationTimeout;
    tDot11fTLVOperatingChannel OperatingChannel;
    tDot11fTLVP2PGroupBssid P2PGroupBssid;
    tDot11fTLVChannelList ChannelList;
} tDot11fIEP2PInvitationRes;

#define DOT11F_EID_P2PINVITATIONRES ( 221 )

#define DOT11F_IE_P2PINVITATIONRES_MIN_LEN ( 4 )

#define DOT11F_IE_P2PINVITATIONRES_MAX_LEN ( 287 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PInvitationRes(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PInvitationRes*);

tANI_U32 dot11fPackIeP2PInvitationRes(tpAniSirGlobal, tDot11fIEP2PInvitationRes*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PInvitationRes(tpAniSirGlobal, tDot11fIEP2PInvitationRes*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PNoticeOfAbsence {
    tANI_U8      present;
    tDot11fTLVNoticeOfAbsence NoticeOfAbsence;
} tDot11fIEP2PNoticeOfAbsence;

#define DOT11F_EID_P2PNOTICEOFABSENCE ( 221 )

#define DOT11F_IE_P2PNOTICEOFABSENCE_MIN_LEN ( 4 )

#define DOT11F_IE_P2PNOTICEOFABSENCE_MAX_LEN ( 45 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PNoticeOfAbsence(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PNoticeOfAbsence*);

tANI_U32 dot11fPackIeP2PNoticeOfAbsence(tpAniSirGlobal, tDot11fIEP2PNoticeOfAbsence*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PNoticeOfAbsence(tpAniSirGlobal, tDot11fIEP2PNoticeOfAbsence*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PPresenceResponse {
    tANI_U8      present;
    tDot11fTLVP2PStatus P2PStatus;
    tDot11fTLVNoticeOfAbsence NoticeOfAbsence;
} tDot11fIEP2PPresenceResponse;

#define DOT11F_EID_P2PPRESENCERESPONSE ( 221 )

#define DOT11F_IE_P2PPRESENCERESPONSE_MIN_LEN ( 4 )

#define DOT11F_IE_P2PPRESENCERESPONSE_MAX_LEN ( 49 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PPresenceResponse(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PPresenceResponse*);

tANI_U32 dot11fPackIeP2PPresenceResponse(tpAniSirGlobal, tDot11fIEP2PPresenceResponse*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PPresenceResponse(tpAniSirGlobal, tDot11fIEP2PPresenceResponse*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PProbeReq {
    tANI_U8      present;
    tDot11fTLVP2PCapability P2PCapability;
    tDot11fTLVP2PDeviceId P2PDeviceId;
    tDot11fTLVListenChannel ListenChannel;
    tDot11fTLVExtendedListenTiming ExtendedListenTiming;
    tDot11fTLVOperatingChannel OperatingChannel;
} tDot11fIEP2PProbeReq;

#define DOT11F_EID_P2PPROBEREQ ( 221 )

#define DOT11F_IE_P2PPROBEREQ_MIN_LEN ( 4 )

#define DOT11F_IE_P2PPROBEREQ_MAX_LEN ( 41 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PProbeReq(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PProbeReq*);

tANI_U32 dot11fPackIeP2PProbeReq(tpAniSirGlobal, tDot11fIEP2PProbeReq*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PProbeReq(tpAniSirGlobal, tDot11fIEP2PProbeReq*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PProbeRes {
    tANI_U8      present;
    tDot11fTLVP2PCapability P2PCapability;
    tDot11fTLVExtendedListenTiming ExtendedListenTiming;
    tDot11fTLVNoticeOfAbsence NoticeOfAbsence;
    tDot11fTLVP2PDeviceInfo P2PDeviceInfo;
    tDot11fTLVP2PGroupInfo P2PGroupInfo;
} tDot11fIEP2PProbeRes;

#define DOT11F_EID_P2PPROBERES ( 221 )

#define DOT11F_IE_P2PPROBERES_MIN_LEN ( 4 )

#define DOT11F_IE_P2PPROBERES_MAX_LEN ( 1139 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PProbeRes(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PProbeRes*);

tANI_U32 dot11fPackIeP2PProbeRes(tpAniSirGlobal, tDot11fIEP2PProbeRes*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PProbeRes(tpAniSirGlobal, tDot11fIEP2PProbeRes*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PProvisionDiscoveryReq {
    tANI_U8      present;
    tDot11fTLVP2PCapability P2PCapability;
    tDot11fTLVP2PDeviceInfo P2PDeviceInfo;
    tDot11fTLVP2PGroupId P2PGroupId;
} tDot11fIEP2PProvisionDiscoveryReq;

#define DOT11F_EID_P2PPROVISIONDISCOVERYREQ ( 221 )

#define DOT11F_IE_P2PPROVISIONDISCOVERYREQ_MIN_LEN ( 4 )

#define DOT11F_IE_P2PPROVISIONDISCOVERYREQ_MAX_LEN ( 105 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PProvisionDiscoveryReq(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PProvisionDiscoveryReq*);

tANI_U32 dot11fPackIeP2PProvisionDiscoveryReq(tpAniSirGlobal, tDot11fIEP2PProvisionDiscoveryReq*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PProvisionDiscoveryReq(tpAniSirGlobal, tDot11fIEP2PProvisionDiscoveryReq*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEP2PWSCProvisionDiscoveryRes {
    tANI_U8      present;
    tDot11fTLVConfigMethods ConfigMethods;
} tDot11fIEP2PWSCProvisionDiscoveryRes;

#define DOT11F_EID_P2PWSCPROVISIONDISCOVERYRES ( 221 )

#define DOT11F_IE_P2PWSCPROVISIONDISCOVERYRES_MIN_LEN ( 4 )

#define DOT11F_IE_P2PWSCPROVISIONDISCOVERYRES_MAX_LEN ( 10 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeP2PWSCProvisionDiscoveryRes(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEP2PWSCProvisionDiscoveryRes*);

tANI_U32 dot11fPackIeP2PWSCProvisionDiscoveryRes(tpAniSirGlobal, tDot11fIEP2PWSCProvisionDiscoveryRes*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEP2PWSCProvisionDiscoveryRes(tpAniSirGlobal, tDot11fIEP2PWSCProvisionDiscoveryRes*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEPTIControl {
    tANI_U8      present;
    tANI_U8      tid;
    tANI_U16     sequence_control;
} tDot11fIEPTIControl;

#define DOT11F_EID_PTICONTROL ( 105 )

#define DOT11F_IE_PTICONTROL_MIN_LEN ( 3 )

#define DOT11F_IE_PTICONTROL_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIePTIControl(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEPTIControl*);

tANI_U32 dot11fPackIePTIControl(tpAniSirGlobal, tDot11fIEPTIControl*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEPTIControl(tpAniSirGlobal, tDot11fIEPTIControl*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEPUBufferStatus {
    tANI_U8      present;
    tANI_U8 ac_bk_traffic_aval: 1;
    tANI_U8 ac_be_traffic_aval: 1;
    tANI_U8 ac_vi_traffic_aval: 1;
    tANI_U8 ac_vo_traffic_aval: 1;
    tANI_U8         reserved: 4;
} tDot11fIEPUBufferStatus;

#define DOT11F_EID_PUBUFFERSTATUS ( 106 )

#define DOT11F_IE_PUBUFFERSTATUS_MIN_LEN ( 1 )

#define DOT11F_IE_PUBUFFERSTATUS_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIePUBufferStatus(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEPUBufferStatus*);

tANI_U32 dot11fPackIePUBufferStatus(tpAniSirGlobal, tDot11fIEPUBufferStatus*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEPUBufferStatus(tpAniSirGlobal, tDot11fIEPUBufferStatus*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEPowerCaps {
    tANI_U8      present;
    tANI_U8      minTxPower;
    tANI_U8      maxTxPower;
} tDot11fIEPowerCaps;

#define DOT11F_EID_POWERCAPS ( 33 )

#define DOT11F_IE_POWERCAPS_MIN_LEN ( 2 )

#define DOT11F_IE_POWERCAPS_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIePowerCaps(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEPowerCaps*);

tANI_U32 dot11fPackIePowerCaps(tpAniSirGlobal, tDot11fIEPowerCaps*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEPowerCaps(tpAniSirGlobal, tDot11fIEPowerCaps*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEPowerConstraints {
    tANI_U8      present;
    tANI_U8      localPowerConstraints;
} tDot11fIEPowerConstraints;

#define DOT11F_EID_POWERCONSTRAINTS ( 32 )

#define DOT11F_IE_POWERCONSTRAINTS_MIN_LEN ( 1 )

#define DOT11F_IE_POWERCONSTRAINTS_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIePowerConstraints(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEPowerConstraints*);

tANI_U32 dot11fPackIePowerConstraints(tpAniSirGlobal, tDot11fIEPowerConstraints*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEPowerConstraints(tpAniSirGlobal, tDot11fIEPowerConstraints*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEQBSSLoad {
    tANI_U8      present;
    tANI_U16     stacount;
    tANI_U8      chautil;
    tANI_U16     avail;
} tDot11fIEQBSSLoad;

#define DOT11F_EID_QBSSLOAD ( 11 )

#define DOT11F_IE_QBSSLOAD_MIN_LEN ( 5 )

#define DOT11F_IE_QBSSLOAD_MAX_LEN ( 5 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeQBSSLoad(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEQBSSLoad*);

tANI_U32 dot11fPackIeQBSSLoad(tpAniSirGlobal, tDot11fIEQBSSLoad*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEQBSSLoad(tpAniSirGlobal, tDot11fIEQBSSLoad*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEQOSCapsAp {
    tANI_U8      present;
    tANI_U8            count: 4;
    tANI_U8             qack: 1;
    tANI_U8             qreq: 1;
    tANI_U8          txopreq: 1;
    tANI_U8         reserved: 1;
} tDot11fIEQOSCapsAp;

#define DOT11F_EID_QOSCAPSAP ( 46 )

#define DOT11F_IE_QOSCAPSAP_MIN_LEN ( 1 )

#define DOT11F_IE_QOSCAPSAP_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeQOSCapsAp(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEQOSCapsAp*);

tANI_U32 dot11fPackIeQOSCapsAp(tpAniSirGlobal, tDot11fIEQOSCapsAp*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEQOSCapsAp(tpAniSirGlobal, tDot11fIEQOSCapsAp*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEQOSCapsStation {
    tANI_U8      present;
    tANI_U8       acvo_uapsd: 1;
    tANI_U8       acvi_uapsd: 1;
    tANI_U8       acbk_uapsd: 1;
    tANI_U8       acbe_uapsd: 1;
    tANI_U8             qack: 1;
    tANI_U8    max_sp_length: 2;
    tANI_U8    more_data_ack: 1;
} tDot11fIEQOSCapsStation;

#define DOT11F_EID_QOSCAPSSTATION ( 46 )

#define DOT11F_IE_QOSCAPSSTATION_MIN_LEN ( 1 )

#define DOT11F_IE_QOSCAPSSTATION_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeQOSCapsStation(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEQOSCapsStation*);

tANI_U32 dot11fPackIeQOSCapsStation(tpAniSirGlobal, tDot11fIEQOSCapsStation*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEQOSCapsStation(tpAniSirGlobal, tDot11fIEQOSCapsStation*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEQuiet {
    tANI_U8      present;
    tANI_U8      count;
    tANI_U8      period;
    tANI_U16     duration;
    tANI_U16     offset;
} tDot11fIEQuiet;

#define DOT11F_EID_QUIET ( 40 )

#define DOT11F_IE_QUIET_MIN_LEN ( 6 )

#define DOT11F_IE_QUIET_MAX_LEN ( 6 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeQuiet(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEQuiet*);

tANI_U32 dot11fPackIeQuiet(tpAniSirGlobal, tDot11fIEQuiet*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEQuiet(tpAniSirGlobal, tDot11fIEQuiet*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIERCPIIE {
    tANI_U8      present;
    tANI_U8      rcpi;
} tDot11fIERCPIIE;

#define DOT11F_EID_RCPIIE ( 53 )

#define DOT11F_IE_RCPIIE_MIN_LEN ( 1 )

#define DOT11F_IE_RCPIIE_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeRCPIIE(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIERCPIIE*);

tANI_U32 dot11fPackIeRCPIIE(tpAniSirGlobal, tDot11fIERCPIIE*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIERCPIIE(tpAniSirGlobal, tDot11fIERCPIIE*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIERICDataDesc {
    tANI_U8                present;
    tDot11fIERICData       RICData;
    tDot11fIERICDescriptor RICDescriptor;
    tDot11fIETSPEC         TSPEC;
    tANI_U16               num_TCLAS;
    tDot11fIETCLAS         TCLAS[2];
    tDot11fIETCLASSPROC    TCLASSPROC;
    tDot11fIETSDelay       TSDelay;
    tDot11fIESchedule      Schedule;
    tDot11fIEWMMTSPEC      WMMTSPEC;
    tANI_U16               num_WMMTCLAS;
    tDot11fIEWMMTCLAS      WMMTCLAS[2];
    tDot11fIEWMMTCLASPROC  WMMTCLASPROC;
    tDot11fIEWMMTSDelay    WMMTSDelay;
    tDot11fIEWMMSchedule   WMMSchedule;
} tDot11fIERICDataDesc;

#define DOT11F_EID_RICDATADESC ( 57 )

#define DOT11F_IE_RICDATADESC_MIN_LEN ( 0 )

#define DOT11F_IE_RICDATADESC_MAX_LEN ( 548 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeRICDataDesc(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIERICDataDesc*);

tANI_U32 dot11fPackIeRICDataDesc(tpAniSirGlobal, tDot11fIERICDataDesc*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIERICDataDesc(tpAniSirGlobal, tDot11fIERICDataDesc*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIERSN {
    tANI_U8      present;
    tANI_U16     version ;
    tANI_U8      gp_cipher_suite[4];
    tANI_U16     pwise_cipher_suite_count;
    tANI_U8      pwise_cipher_suites[4][4];
    tANI_U16     akm_suite_count;
    tANI_U8      akm_suites[4][4];
    tANI_U8      RSN_Cap[2];
    tANI_U16     pmkid_count;
    tANI_U8      pmkid[4][16];
    tANI_U8      gp_mgmt_cipher_suite[4];
} tDot11fIERSN;

#define DOT11F_EID_RSN ( 48 )

#define DOT11F_IE_RSN_MIN_LEN ( 6 )

#define DOT11F_IE_RSN_MAX_LEN ( 114 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeRSN(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIERSN*);

tANI_U32 dot11fPackIeRSN(tpAniSirGlobal, tDot11fIERSN*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIERSN(tpAniSirGlobal, tDot11fIERSN*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIERSNIIE {
    tANI_U8      present;
    tANI_U8      rsni;
} tDot11fIERSNIIE;

#define DOT11F_EID_RSNIIE ( 65 )

#define DOT11F_IE_RSNIIE_MIN_LEN ( 1 )

#define DOT11F_IE_RSNIIE_MAX_LEN ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeRSNIIE(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIERSNIIE*);

tANI_U32 dot11fPackIeRSNIIE(tpAniSirGlobal, tDot11fIERSNIIE*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIERSNIIE(tpAniSirGlobal, tDot11fIERSNIIE*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIERSNOpaque {
    tANI_U8      present;
    tANI_U8      num_data;
    tANI_U8      data[253];
} tDot11fIERSNOpaque;

#define DOT11F_EID_RSNOPAQUE ( 48 )

#define DOT11F_IE_RSNOPAQUE_MIN_LEN ( 6 )

#define DOT11F_IE_RSNOPAQUE_MAX_LEN ( 253 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeRSNOpaque(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIERSNOpaque*);

tANI_U32 dot11fPackIeRSNOpaque(tpAniSirGlobal, tDot11fIERSNOpaque*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIERSNOpaque(tpAniSirGlobal, tDot11fIERSNOpaque*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIESuppChannels {
    tANI_U8      present;
    tANI_U8      num_bands;
    tANI_U8      bands[48][2];
} tDot11fIESuppChannels;

#define DOT11F_EID_SUPPCHANNELS ( 36 )

#define DOT11F_IE_SUPPCHANNELS_MIN_LEN ( 2 )

#define DOT11F_IE_SUPPCHANNELS_MAX_LEN ( 96 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeSuppChannels(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIESuppChannels*);

tANI_U32 dot11fPackIeSuppChannels(tpAniSirGlobal, tDot11fIESuppChannels*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIESuppChannels(tpAniSirGlobal, tDot11fIESuppChannels*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIESuppOperatingClasses {
    tANI_U8      present;
    tANI_U8      num_classes;
    tANI_U8      classes[32];
} tDot11fIESuppOperatingClasses;

#define DOT11F_EID_SUPPOPERATINGCLASSES ( 59 )

#define DOT11F_IE_SUPPOPERATINGCLASSES_MIN_LEN ( 1 )

#define DOT11F_IE_SUPPOPERATINGCLASSES_MAX_LEN ( 32 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeSuppOperatingClasses(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIESuppOperatingClasses*);

tANI_U32 dot11fPackIeSuppOperatingClasses(tpAniSirGlobal, tDot11fIESuppOperatingClasses*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIESuppOperatingClasses(tpAniSirGlobal, tDot11fIESuppOperatingClasses*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIESuppRates {
    tANI_U8      present;
    tANI_U8      num_rates;
    tANI_U8      rates[12];
} tDot11fIESuppRates;

#define DOT11F_EID_SUPPRATES ( 1 )

#define DOT11F_IE_SUPPRATES_MIN_LEN ( 0 )

#define DOT11F_IE_SUPPRATES_MAX_LEN ( 12 )

#define DOT11F_IS_BG_RATE(_x)  (((_x) == 02) || \
                      ((_x) == 04) || \
                      ((_x) == 11) || \
                      ((_x) == 22) || \
                      ((_x) == 12) || \
                      ((_x) == 18) || \
                      ((_x) == 24) || \
                      ((_x) == 36) || \
                      ((_x) == 48) || \
                      ((_x) == 72) || \
                      ((_x) == 96) || \
                      ((_x) == 108))  

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeSuppRates(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIESuppRates*);

tANI_U32 dot11fPackIeSuppRates(tpAniSirGlobal, tDot11fIESuppRates*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIESuppRates(tpAniSirGlobal, tDot11fIESuppRates*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETIM {
    tANI_U8      present;
    tANI_U8      dtim_count;
    tANI_U8      dtim_period;
    tANI_U8      bmpctl;
    tANI_U8      num_vbmp;
    tANI_U8      vbmp[251];
} tDot11fIETIM;

#define DOT11F_EID_TIM ( 5 )

#define DOT11F_IE_TIM_MIN_LEN ( 4 )

#define DOT11F_IE_TIM_MAX_LEN ( 254 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTIM(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETIM*);

tANI_U32 dot11fPackIeTIM(tpAniSirGlobal, tDot11fIETIM*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETIM(tpAniSirGlobal, tDot11fIETIM*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETPCReport {
    tANI_U8      present;
    tANI_U8      tx_power;
    tANI_U8      link_margin;
} tDot11fIETPCReport;

#define DOT11F_EID_TPCREPORT ( 35 )

#define DOT11F_IE_TPCREPORT_MIN_LEN ( 2 )

#define DOT11F_IE_TPCREPORT_MAX_LEN ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTPCReport(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETPCReport*);

tANI_U32 dot11fPackIeTPCReport(tpAniSirGlobal, tDot11fIETPCReport*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETPCReport(tpAniSirGlobal, tDot11fIETPCReport*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETPCRequest {
    tANI_U8      present;
} tDot11fIETPCRequest;

#define DOT11F_EID_TPCREQUEST ( 34 )

#define DOT11F_IE_TPCREQUEST_MIN_LEN ( 0 )

#define DOT11F_IE_TPCREQUEST_MAX_LEN ( 0 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTPCRequest(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETPCRequest*);

tANI_U32 dot11fPackIeTPCRequest(tpAniSirGlobal, tDot11fIETPCRequest*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETPCRequest(tpAniSirGlobal, tDot11fIETPCRequest*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIETimeoutInterval {
    tANI_U8      present;
    tANI_U8      timeoutType;
    tANI_U32     timeoutValue;
} tDot11fIETimeoutInterval;

#define DOT11F_EID_TIMEOUTINTERVAL ( 56 )

#define DOT11F_IE_TIMEOUTINTERVAL_MIN_LEN ( 5 )

#define DOT11F_IE_TIMEOUTINTERVAL_MAX_LEN ( 5 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeTimeoutInterval(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIETimeoutInterval*);

tANI_U32 dot11fPackIeTimeoutInterval(tpAniSirGlobal, tDot11fIETimeoutInterval*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIETimeoutInterval(tpAniSirGlobal, tDot11fIETimeoutInterval*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEVHTCaps {
    tANI_U8      present;
    tANI_U32       maxMPDULen: 2;
    tANI_U32 supportedChannelWidthSet: 2;
    tANI_U32    ldpcCodingCap: 1;
    tANI_U32     shortGI80MHz: 1;
    tANI_U32 shortGI160and80plus80MHz: 1;
    tANI_U32           txSTBC: 1;
    tANI_U32           rxSTBC: 3;
    tANI_U32  suBeamFormerCap: 1;
    tANI_U32  suBeamformeeCap: 1;
    tANI_U32 csnofBeamformerAntSup: 3;
    tANI_U32   numSoundingDim: 3;
    tANI_U32  muBeamformerCap: 1;
    tANI_U32  muBeamformeeCap: 1;
    tANI_U32        vhtTXOPPS: 1;
    tANI_U32        htcVHTCap: 1;
    tANI_U32   maxAMPDULenExp: 3;
    tANI_U32  vhtLinkAdaptCap: 2;
    tANI_U32     rxAntPattern: 1;
    tANI_U32     txAntPattern: 1;
    tANI_U32        reserved1: 2;
    tANI_U16     rxMCSMap;
    tANI_U16 rxHighSupDataRate: 13;
    tANI_U16        reserved2: 3;
    tANI_U16     txMCSMap;
    tANI_U16    txSupDataRate: 13;
    tANI_U16        reserved3: 3;
} tDot11fIEVHTCaps;

#define DOT11F_EID_VHTCAPS ( 191 )

#define DOT11F_IE_VHTCAPS_MIN_LEN ( 12 )

#define DOT11F_IE_VHTCAPS_MAX_LEN ( 12 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeVHTCaps(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEVHTCaps*);

tANI_U32 dot11fPackIeVHTCaps(tpAniSirGlobal, tDot11fIEVHTCaps*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEVHTCaps(tpAniSirGlobal, tDot11fIEVHTCaps*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEVHTExtBssLoad {
    tANI_U8      present;
    tANI_U8      muMIMOCapStaCount;
    tANI_U8      ssUnderUtil;
    tANI_U8      FortyMHzUtil;
    tANI_U8      EightyMHzUtil;
    tANI_U8      OneSixtyMHzUtil;
} tDot11fIEVHTExtBssLoad;

#define DOT11F_EID_VHTEXTBSSLOAD ( 193 )

#define DOT11F_IE_VHTEXTBSSLOAD_MIN_LEN ( 5 )

#define DOT11F_IE_VHTEXTBSSLOAD_MAX_LEN ( 5 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeVHTExtBssLoad(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEVHTExtBssLoad*);

tANI_U32 dot11fPackIeVHTExtBssLoad(tpAniSirGlobal, tDot11fIEVHTExtBssLoad*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEVHTExtBssLoad(tpAniSirGlobal, tDot11fIEVHTExtBssLoad*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEVHTOperation {
    tANI_U8      present;
    tANI_U8      chanWidth;
    tANI_U8      chanCenterFreqSeg1;
    tANI_U8      chanCenterFreqSeg2;
    tANI_U16     basicMCSSet;
} tDot11fIEVHTOperation;

#define DOT11F_EID_VHTOPERATION ( 192 )

#define DOT11F_IE_VHTOPERATION_MIN_LEN ( 5 )

#define DOT11F_IE_VHTOPERATION_MAX_LEN ( 5 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeVHTOperation(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEVHTOperation*);

tANI_U32 dot11fPackIeVHTOperation(tpAniSirGlobal, tDot11fIEVHTOperation*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEVHTOperation(tpAniSirGlobal, tDot11fIEVHTOperation*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWAPI {
    tANI_U8      present;
    tANI_U16     version ;
    tANI_U16     akm_suite_count;
    tANI_U8      akm_suites[4][4];
    tANI_U16     unicast_cipher_suite_count;
    tANI_U8      unicast_cipher_suites[4][4];
    tANI_U8      multicast_cipher_suite[4];
    tANI_U16          preauth: 1;
    tANI_U16         reserved: 15;
    tANI_U16     bkid_count;
    tANI_U8      bkid[4][16];
} tDot11fIEWAPI;

#define DOT11F_EID_WAPI ( 68 )

#define DOT11F_IE_WAPI_MIN_LEN ( 12 )

#define DOT11F_IE_WAPI_MAX_LEN ( 110 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWAPI(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWAPI*);

tANI_U32 dot11fPackIeWAPI(tpAniSirGlobal, tDot11fIEWAPI*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWAPI(tpAniSirGlobal, tDot11fIEWAPI*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWAPIOpaque {
    tANI_U8      present;
    tANI_U8      num_data;
    tANI_U8      data[253];
} tDot11fIEWAPIOpaque;

#define DOT11F_EID_WAPIOPAQUE ( 68 )

#define DOT11F_IE_WAPIOPAQUE_MIN_LEN ( 6 )

#define DOT11F_IE_WAPIOPAQUE_MAX_LEN ( 253 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWAPIOpaque(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWAPIOpaque*);

tANI_U32 dot11fPackIeWAPIOpaque(tpAniSirGlobal, tDot11fIEWAPIOpaque*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWAPIOpaque(tpAniSirGlobal, tDot11fIEWAPIOpaque*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWFATPC {
    tANI_U8      present;
    tANI_U8      txPower;
    tANI_U8      linkMargin;
} tDot11fIEWFATPC;

#define DOT11F_EID_WFATPC ( 221 )

#define DOT11F_IE_WFATPC_MIN_LEN ( 7 )

#define DOT11F_IE_WFATPC_MAX_LEN ( 7 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWFATPC(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWFATPC*);

tANI_U32 dot11fPackIeWFATPC(tpAniSirGlobal, tDot11fIEWFATPC*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWFATPC(tpAniSirGlobal, tDot11fIEWFATPC*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWFDIEOpaque {
    tANI_U8      present;
    tANI_U8      num_data;
    tANI_U8      data[249];
} tDot11fIEWFDIEOpaque;

#define DOT11F_EID_WFDIEOPAQUE ( 221 )

#define DOT11F_IE_WFDIEOPAQUE_MIN_LEN ( 6 )

#define DOT11F_IE_WFDIEOPAQUE_MAX_LEN ( 253 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWFDIEOpaque(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWFDIEOpaque*);

tANI_U32 dot11fPackIeWFDIEOpaque(tpAniSirGlobal, tDot11fIEWFDIEOpaque*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWFDIEOpaque(tpAniSirGlobal, tDot11fIEWFDIEOpaque*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWMMCaps {
    tANI_U8      present;
    tANI_U8      version ;
    tANI_U8         reserved: 4;
    tANI_U8             qack: 1;
    tANI_U8    queue_request: 1;
    tANI_U8     txop_request: 1;
    tANI_U8         more_ack: 1;
} tDot11fIEWMMCaps;

#define DOT11F_EID_WMMCAPS ( 221 )

#define DOT11F_IE_WMMCAPS_MIN_LEN ( 7 )

#define DOT11F_IE_WMMCAPS_MAX_LEN ( 7 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWMMCaps(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWMMCaps*);

tANI_U32 dot11fPackIeWMMCaps(tpAniSirGlobal, tDot11fIEWMMCaps*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWMMCaps(tpAniSirGlobal, tDot11fIEWMMCaps*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWMMInfoAp {
    tANI_U8      present;
    tANI_U8      version;
    tANI_U8  param_set_count: 4;
    tANI_U8         reserved: 3;
    tANI_U8            uapsd: 1;
} tDot11fIEWMMInfoAp;

#define DOT11F_EID_WMMINFOAP ( 221 )

#define DOT11F_IE_WMMINFOAP_MIN_LEN ( 7 )

#define DOT11F_IE_WMMINFOAP_MAX_LEN ( 7 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWMMInfoAp(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWMMInfoAp*);

tANI_U32 dot11fPackIeWMMInfoAp(tpAniSirGlobal, tDot11fIEWMMInfoAp*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWMMInfoAp(tpAniSirGlobal, tDot11fIEWMMInfoAp*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWMMInfoStation {
    tANI_U8      present;
    tANI_U8      version;
    tANI_U8       acvo_uapsd: 1;
    tANI_U8       acvi_uapsd: 1;
    tANI_U8       acbk_uapsd: 1;
    tANI_U8       acbe_uapsd: 1;
    tANI_U8        reserved1: 1;
    tANI_U8    max_sp_length: 2;
    tANI_U8        reserved2: 1;
} tDot11fIEWMMInfoStation;

#define DOT11F_EID_WMMINFOSTATION ( 221 )

#define DOT11F_IE_WMMINFOSTATION_MIN_LEN ( 7 )

#define DOT11F_IE_WMMINFOSTATION_MAX_LEN ( 7 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWMMInfoStation(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWMMInfoStation*);

tANI_U32 dot11fPackIeWMMInfoStation(tpAniSirGlobal, tDot11fIEWMMInfoStation*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWMMInfoStation(tpAniSirGlobal, tDot11fIEWMMInfoStation*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWMMParams {
    tANI_U8      present;
    tANI_U8      version ;
    tANI_U8      qosInfo;
    tANI_U8      reserved2;
    tANI_U8       acbe_aifsn: 4;
    tANI_U8         acbe_acm: 1;
    tANI_U8         acbe_aci: 2;
    tANI_U8          unused1: 1;
    tANI_U8      acbe_acwmin: 4;
    tANI_U8      acbe_acwmax: 4;
    tANI_U16     acbe_txoplimit;
    tANI_U8       acbk_aifsn: 4;
    tANI_U8         acbk_acm: 1;
    tANI_U8         acbk_aci: 2;
    tANI_U8          unused2: 1;
    tANI_U8      acbk_acwmin: 4;
    tANI_U8      acbk_acwmax: 4;
    tANI_U16     acbk_txoplimit;
    tANI_U8       acvi_aifsn: 4;
    tANI_U8         acvi_acm: 1;
    tANI_U8         acvi_aci: 2;
    tANI_U8          unused3: 1;
    tANI_U8      acvi_acwmin: 4;
    tANI_U8      acvi_acwmax: 4;
    tANI_U16     acvi_txoplimit;
    tANI_U8       acvo_aifsn: 4;
    tANI_U8         acvo_acm: 1;
    tANI_U8         acvo_aci: 2;
    tANI_U8          unused4: 1;
    tANI_U8      acvo_acwmin: 4;
    tANI_U8      acvo_acwmax: 4;
    tANI_U16     acvo_txoplimit;
} tDot11fIEWMMParams;

#define DOT11F_EID_WMMPARAMS ( 221 )

#define DOT11F_IE_WMMPARAMS_MIN_LEN ( 24 )

#define DOT11F_IE_WMMPARAMS_MAX_LEN ( 24 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWMMParams(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWMMParams*);

tANI_U32 dot11fPackIeWMMParams(tpAniSirGlobal, tDot11fIEWMMParams*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWMMParams(tpAniSirGlobal, tDot11fIEWMMParams*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWPA {
    tANI_U8      present;
    tANI_U16     version ;
    tANI_U8      multicast_cipher_present;   
    tANI_U8      multicast_cipher[4];
    tANI_U16     unicast_cipher_count;
    tANI_U8      unicast_ciphers[4][4];
    tANI_U16     auth_suite_count;
    tANI_U8      auth_suites[4][4];
    tANI_U16     caps;
} tDot11fIEWPA;

#define DOT11F_EID_WPA ( 221 )

#define DOT11F_IE_WPA_MIN_LEN ( 6 )

#define DOT11F_IE_WPA_MAX_LEN ( 48 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWPA(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWPA*);

tANI_U32 dot11fPackIeWPA(tpAniSirGlobal, tDot11fIEWPA*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWPA(tpAniSirGlobal, tDot11fIEWPA*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWPAOpaque {
    tANI_U8      present;
    tANI_U8      num_data;
    tANI_U8      data[249];
} tDot11fIEWPAOpaque;

#define DOT11F_EID_WPAOPAQUE ( 221 )

#define DOT11F_IE_WPAOPAQUE_MIN_LEN ( 6 )

#define DOT11F_IE_WPAOPAQUE_MAX_LEN ( 253 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWPAOpaque(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWPAOpaque*);

tANI_U32 dot11fPackIeWPAOpaque(tpAniSirGlobal, tDot11fIEWPAOpaque*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWPAOpaque(tpAniSirGlobal, tDot11fIEWPAOpaque*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWSC {
    tANI_U8      present;
    tDot11fTLVVersion Version;
    tDot11fTLVWPSState WPSState;
    tDot11fTLVAPSetupLocked APSetupLocked;
    tDot11fTLVSelectedRegistrarConfigMethods SelectedRegistrarConfigMethods;
    tDot11fTLVUUID_E UUID_E;
    tDot11fTLVUUID_R UUID_R;
    tDot11fTLVRFBands RFBands;
    tDot11fTLVSelectedRegistrar SelectedRegistrar;
    tDot11fTLVConfigMethods ConfigMethods;
    tDot11fTLVAssociationState AssociationState;
    tDot11fTLVConfigurationError ConfigurationError;
    tDot11fTLVManufacturer Manufacturer;
    tDot11fTLVModelName ModelName;
    tDot11fTLVModelNumber ModelNumber;
    tDot11fTLVSerialNumber SerialNumber;
    tDot11fTLVDeviceName DeviceName;
    tDot11fTLVDevicePasswordID DevicePasswordID;
    tDot11fTLVPrimaryDeviceType PrimaryDeviceType;
    tDot11fTLVRequestType RequestType;
    tDot11fTLVResponseType ResponseType;
    tDot11fTLVVendorExtension VendorExtension;
    tDot11fTLVRequestDeviceType RequestDeviceType;
} tDot11fIEWSC;

#define DOT11F_EID_WSC ( 221 )

#define DOT11F_IE_WSC_MIN_LEN ( 4 )

#define DOT11F_IE_WSC_MAX_LEN ( 366 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWSC(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWSC*);

tANI_U32 dot11fPackIeWSC(tpAniSirGlobal, tDot11fIEWSC*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWSC(tpAniSirGlobal, tDot11fIEWSC*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWiderBWChanSwitchAnn {
    tANI_U8      present;
    tANI_U8      newChanWidth;
    tANI_U8      newCenterChanFreq0;
    tANI_U8      newCenterChanFreq1;
} tDot11fIEWiderBWChanSwitchAnn;

#define DOT11F_EID_WIDERBWCHANSWITCHANN ( 194 )

#define DOT11F_IE_WIDERBWCHANSWITCHANN_MIN_LEN ( 3 )

#define DOT11F_IE_WIDERBWCHANSWITCHANN_MAX_LEN ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWiderBWChanSwitchAnn(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWiderBWChanSwitchAnn*);

tANI_U32 dot11fPackIeWiderBWChanSwitchAnn(tpAniSirGlobal, tDot11fIEWiderBWChanSwitchAnn*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWiderBWChanSwitchAnn(tpAniSirGlobal, tDot11fIEWiderBWChanSwitchAnn*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWscAssocReq {
    tANI_U8      present;
    tDot11fTLVVersion Version;
    tDot11fTLVRequestType RequestType;
    tDot11fTLVVendorExtension VendorExtension;
} tDot11fIEWscAssocReq;

#define DOT11F_EID_WSCASSOCREQ ( 221 )

#define DOT11F_IE_WSCASSOCREQ_MIN_LEN ( 4 )

#define DOT11F_IE_WSCASSOCREQ_MAX_LEN ( 35 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWscAssocReq(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWscAssocReq*);

tANI_U32 dot11fPackIeWscAssocReq(tpAniSirGlobal, tDot11fIEWscAssocReq*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWscAssocReq(tpAniSirGlobal, tDot11fIEWscAssocReq*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWscAssocRes {
    tANI_U8      present;
    tDot11fTLVVersion Version;
    tDot11fTLVResponseType ResponseType;
    tDot11fTLVVendorExtension VendorExtension;
} tDot11fIEWscAssocRes;

#define DOT11F_EID_WSCASSOCRES ( 221 )

#define DOT11F_IE_WSCASSOCRES_MIN_LEN ( 4 )

#define DOT11F_IE_WSCASSOCRES_MAX_LEN ( 35 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWscAssocRes(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWscAssocRes*);

tANI_U32 dot11fPackIeWscAssocRes(tpAniSirGlobal, tDot11fIEWscAssocRes*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWscAssocRes(tpAniSirGlobal, tDot11fIEWscAssocRes*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWscBeacon {
    tANI_U8      present;
    tDot11fTLVVersion Version;
    tDot11fTLVWPSState WPSState;
    tDot11fTLVAPSetupLocked APSetupLocked;
    tDot11fTLVSelectedRegistrar SelectedRegistrar;
    tDot11fTLVDevicePasswordID DevicePasswordID;
    tDot11fTLVSelectedRegistrarConfigMethods SelectedRegistrarConfigMethods;
    tDot11fTLVUUID_E UUID_E;
    tDot11fTLVRFBands RFBands;
    tDot11fTLVVendorExtension VendorExtension;
} tDot11fIEWscBeacon;

#define DOT11F_EID_WSCBEACON ( 221 )

#define DOT11F_IE_WSCBEACON_MIN_LEN ( 4 )

#define DOT11F_IE_WSCBEACON_MAX_LEN ( 82 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWscBeacon(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWscBeacon*);

tANI_U32 dot11fPackIeWscBeacon(tpAniSirGlobal, tDot11fIEWscBeacon*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWscBeacon(tpAniSirGlobal, tDot11fIEWscBeacon*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWscBeaconProbeRes {
    tANI_U8      present;
    tDot11fTLVVersion Version;
    tDot11fTLVWPSState WPSState;
    tDot11fTLVAPSetupLocked APSetupLocked;
    tDot11fTLVSelectedRegistrar SelectedRegistrar;
    tDot11fTLVDevicePasswordID DevicePasswordID;
    tDot11fTLVSelectedRegistrarConfigMethods SelectedRegistrarConfigMethods;
    tDot11fTLVResponseType ResponseType;
    tDot11fTLVUUID_E UUID_E;
    tDot11fTLVManufacturer Manufacturer;
    tDot11fTLVModelName ModelName;
    tDot11fTLVModelNumber ModelNumber;
    tDot11fTLVSerialNumber SerialNumber;
    tDot11fTLVPrimaryDeviceType PrimaryDeviceType;
    tDot11fTLVDeviceName DeviceName;
    tDot11fTLVConfigMethods ConfigMethods;
    tDot11fTLVRFBands RFBands;
    tDot11fTLVVendorExtension VendorExtension;
} tDot11fIEWscBeaconProbeRes;

#define DOT11F_EID_WSCBEACONPROBERES ( 221 )

#define DOT11F_IE_WSCBEACONPROBERES_MIN_LEN ( 4 )

#define DOT11F_IE_WSCBEACONPROBERES_MAX_LEN ( 317 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWscBeaconProbeRes(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWscBeaconProbeRes*);

tANI_U32 dot11fPackIeWscBeaconProbeRes(tpAniSirGlobal, tDot11fIEWscBeaconProbeRes*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWscBeaconProbeRes(tpAniSirGlobal, tDot11fIEWscBeaconProbeRes*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWscIEOpaque {
    tANI_U8      present;
    tANI_U8      num_data;
    tANI_U8      data[249];
} tDot11fIEWscIEOpaque;

#define DOT11F_EID_WSCIEOPAQUE ( 221 )

#define DOT11F_IE_WSCIEOPAQUE_MIN_LEN ( 6 )

#define DOT11F_IE_WSCIEOPAQUE_MAX_LEN ( 253 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWscIEOpaque(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWscIEOpaque*);

tANI_U32 dot11fPackIeWscIEOpaque(tpAniSirGlobal, tDot11fIEWscIEOpaque*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWscIEOpaque(tpAniSirGlobal, tDot11fIEWscIEOpaque*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWscProbeReq {
    tANI_U8      present;
    tDot11fTLVVersion Version;
    tDot11fTLVRequestType RequestType;
    tDot11fTLVConfigMethods ConfigMethods;
    tDot11fTLVUUID_E UUID_E;
    tDot11fTLVPrimaryDeviceType PrimaryDeviceType;
    tDot11fTLVRFBands RFBands;
    tDot11fTLVAssociationState AssociationState;
    tDot11fTLVConfigurationError ConfigurationError;
    tDot11fTLVDevicePasswordID DevicePasswordID;
    tDot11fTLVManufacturer Manufacturer;
    tDot11fTLVModelName ModelName;
    tDot11fTLVModelNumber ModelNumber;
    tDot11fTLVDeviceName DeviceName;
    tDot11fTLVVendorExtension VendorExtension;
    tDot11fTLVRequestDeviceType RequestDeviceType;
} tDot11fIEWscProbeReq;

#define DOT11F_EID_WSCPROBEREQ ( 221 )

#define DOT11F_IE_WSCPROBEREQ_MIN_LEN ( 4 )

#define DOT11F_IE_WSCPROBEREQ_MAX_LEN ( 284 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWscProbeReq(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWscProbeReq*);

tANI_U32 dot11fPackIeWscProbeReq(tpAniSirGlobal, tDot11fIEWscProbeReq*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWscProbeReq(tpAniSirGlobal, tDot11fIEWscProbeReq*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWscProbeRes {
    tANI_U8      present;
    tDot11fTLVVersion Version;
    tDot11fTLVWPSState WPSState;
    tDot11fTLVAPSetupLocked APSetupLocked;
    tDot11fTLVSelectedRegistrar SelectedRegistrar;
    tDot11fTLVDevicePasswordID DevicePasswordID;
    tDot11fTLVSelectedRegistrarConfigMethods SelectedRegistrarConfigMethods;
    tDot11fTLVResponseType ResponseType;
    tDot11fTLVUUID_E UUID_E;
    tDot11fTLVManufacturer Manufacturer;
    tDot11fTLVModelName ModelName;
    tDot11fTLVModelNumber ModelNumber;
    tDot11fTLVSerialNumber SerialNumber;
    tDot11fTLVPrimaryDeviceType PrimaryDeviceType;
    tDot11fTLVDeviceName DeviceName;
    tDot11fTLVConfigMethods ConfigMethods;
    tDot11fTLVRFBands RFBands;
    tDot11fTLVVendorExtension VendorExtension;
} tDot11fIEWscProbeRes;

#define DOT11F_EID_WSCPROBERES ( 221 )

#define DOT11F_IE_WSCPROBERES_MIN_LEN ( 4 )

#define DOT11F_IE_WSCPROBERES_MAX_LEN ( 317 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWscProbeRes(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWscProbeRes*);

tANI_U32 dot11fPackIeWscProbeRes(tpAniSirGlobal, tDot11fIEWscProbeRes*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWscProbeRes(tpAniSirGlobal, tDot11fIEWscProbeRes*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 
typedef struct sDot11fIEWscReassocRes {
    tANI_U8      present;
    tDot11fTLVVersion Version;
    tDot11fTLVResponseType ResponseType;
    tDot11fTLVVendorExtension VendorExtension;
} tDot11fIEWscReassocRes;

#define DOT11F_EID_WSCREASSOCRES ( 221 )

#define DOT11F_IE_WSCREASSOCRES_MIN_LEN ( 4 )

#define DOT11F_IE_WSCREASSOCRES_MAX_LEN ( 35 )

#ifdef __cplusplus
extern "C" {
#endif 
tANI_U32 dot11fUnpackIeWscReassocRes(tpAniSirGlobal, tANI_U8*,tANI_U8, tDot11fIEWscReassocRes*);

tANI_U32 dot11fPackIeWscReassocRes(tpAniSirGlobal, tDot11fIEWscReassocRes*, tANI_U8*, tANI_U32, tANI_U32*);

tANI_U32 dot11fGetPackedIEWscReassocRes(tpAniSirGlobal, tDot11fIEWscReassocRes*, tANI_U32*);

#ifdef __cplusplus
}; 
#endif 

typedef struct sDot11fAddBAReq{
    tDot11fFfCategory                  Category;
    tDot11fFfAction                    Action;
    tDot11fFfDialogToken               DialogToken;
    tDot11fFfAddBAParameterSet         AddBAParameterSet;
    tDot11fFfBATimeout                 BATimeout;
    tDot11fFfBAStartingSequenceControl BAStartingSequenceControl;
} tDot11fAddBAReq;

#define DOT11F_ADDBAREQ ( 1 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackAddBAReq(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fAddBAReq *pFrm);
tANI_U32 dot11fPackAddBAReq(tpAniSirGlobal pCtx, tDot11fAddBAReq *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedAddBAReqSize(tpAniSirGlobal pCtx, tDot11fAddBAReq *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fAddBARsp{
    tDot11fFfCategory          Category;
    tDot11fFfAction            Action;
    tDot11fFfDialogToken       DialogToken;
    tDot11fFfStatus            Status;
    tDot11fFfAddBAParameterSet AddBAParameterSet;
    tDot11fFfBATimeout         BATimeout;
} tDot11fAddBARsp;

#define DOT11F_ADDBARSP ( 2 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackAddBARsp(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fAddBARsp *pFrm);
tANI_U32 dot11fPackAddBARsp(tpAniSirGlobal pCtx, tDot11fAddBARsp *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedAddBARspSize(tpAniSirGlobal pCtx, tDot11fAddBARsp *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fAddTSRequest{
    tDot11fFfCategory           Category;
    tDot11fFfAction             Action;
    tDot11fFfDialogToken        DialogToken;
    tDot11fIETSPEC              TSPEC;
    tANI_U16                    num_TCLAS;
    tDot11fIETCLAS              TCLAS[2];
    tDot11fIETCLASSPROC         TCLASSPROC;
    tDot11fIEWMMTSPEC           WMMTSPEC;
    tANI_U16                    num_WMMTCLAS;
    tDot11fIEWMMTCLAS           WMMTCLAS[2];
    tDot11fIEWMMTCLASPROC       WMMTCLASPROC;
    tDot11fIECCXTrafStrmRateSet CCXTrafStrmRateSet;
} tDot11fAddTSRequest;

#define DOT11F_ADDTSREQUEST ( 3 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackAddTSRequest(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fAddTSRequest *pFrm);
tANI_U32 dot11fPackAddTSRequest(tpAniSirGlobal pCtx, tDot11fAddTSRequest *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedAddTSRequestSize(tpAniSirGlobal pCtx, tDot11fAddTSRequest *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fAddTSResponse{
    tDot11fFfCategory       Category;
    tDot11fFfAction         Action;
    tDot11fFfDialogToken    DialogToken;
    tDot11fFfStatus         Status;
    tDot11fIETSDelay        TSDelay;
    tDot11fIETSPEC          TSPEC;
    tANI_U16                num_TCLAS;
    tDot11fIETCLAS          TCLAS[2];
    tDot11fIETCLASSPROC     TCLASSPROC;
    tDot11fIESchedule       Schedule;
    tDot11fIEWMMTSDelay     WMMTSDelay;
    tDot11fIEWMMSchedule    WMMSchedule;
    tDot11fIEWMMTSPEC       WMMTSPEC;
    tANI_U16                num_WMMTCLAS;
    tDot11fIEWMMTCLAS       WMMTCLAS[2];
    tDot11fIEWMMTCLASPROC   WMMTCLASPROC;
    tDot11fIECCXTrafStrmMet CCXTrafStrmMet;
} tDot11fAddTSResponse;

#define DOT11F_ADDTSRESPONSE ( 4 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackAddTSResponse(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fAddTSResponse *pFrm);
tANI_U32 dot11fPackAddTSResponse(tpAniSirGlobal pCtx, tDot11fAddTSResponse *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedAddTSResponseSize(tpAniSirGlobal pCtx, tDot11fAddTSResponse *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fAssocRequest{
    tDot11fFfCapabilities   Capabilities;
    tDot11fFfListenInterval ListenInterval;
    tDot11fIESSID           SSID;
    tDot11fIESuppRates      SuppRates;
    tDot11fIEExtSuppRates   ExtSuppRates;
    tDot11fIEPowerCaps      PowerCaps;
    tDot11fIESuppChannels   SuppChannels;
    tDot11fIERSNOpaque      RSNOpaque;
    tDot11fIEQOSCapsStation QOSCapsStation;
    tDot11fIERRMEnabledCap  RRMEnabledCap;
    tDot11fIEMobilityDomain MobilityDomain;
    tDot11fIEWPAOpaque      WPAOpaque;
    tDot11fIEHTCaps         HTCaps;
    tDot11fIEWMMCaps        WMMCaps;
    tDot11fIEWMMInfoStation WMMInfoStation;
    tDot11fIEAirgo          Airgo;
    tDot11fIEWscIEOpaque    WscIEOpaque;
    tDot11fIEWAPIOpaque     WAPIOpaque;
    tDot11fIECCXRadMgmtCap  CCXRadMgmtCap;
    tDot11fIECCXVersion     CCXVersion;
    tDot11fIEP2PIEOpaque    P2PIEOpaque;
    tDot11fIEWFDIEOpaque    WFDIEOpaque;
    tDot11fIEVHTCaps        VHTCaps;
    tDot11fIEExtCap         ExtCap;
    tDot11fIEOperatingMode  OperatingMode;
} tDot11fAssocRequest;

#define DOT11F_ASSOCREQUEST ( 5 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackAssocRequest(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fAssocRequest *pFrm);
tANI_U32 dot11fPackAssocRequest(tpAniSirGlobal pCtx, tDot11fAssocRequest *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedAssocRequestSize(tpAniSirGlobal pCtx, tDot11fAssocRequest *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fAssocResponse{
    tDot11fFfCapabilities       Capabilities;
    tDot11fFfStatus             Status;
    tDot11fFfAID                AID;
    tDot11fIESuppRates          SuppRates;
    tDot11fIEExtSuppRates       ExtSuppRates;
    tDot11fIEEDCAParamSet       EDCAParamSet;
    tDot11fIERCPIIE             RCPIIE;
    tDot11fIERSNIIE             RSNIIE;
    tDot11fIERRMEnabledCap      RRMEnabledCap;
    tDot11fIEMobilityDomain     MobilityDomain;
    tDot11fIEFTInfo             FTInfo;
    tANI_U16                    num_RICDataDesc;
    tDot11fIERICDataDesc        RICDataDesc[2];
    tDot11fIEWPA                WPA;
    tDot11fIETimeoutInterval    TimeoutInterval;
    tDot11fIEHTCaps             HTCaps;
    tDot11fIEHTInfo             HTInfo;
    tDot11fIEWMMParams          WMMParams;
    tDot11fIEWMMCaps            WMMCaps;
    tDot11fIECCXRadMgmtCap      CCXRadMgmtCap;
    tDot11fIECCXTrafStrmMet     CCXTrafStrmMet;
    tDot11fIECCXTxmitPower      CCXTxmitPower;
    tANI_U16                    num_WMMTSPEC;
    tDot11fIEWMMTSPEC           WMMTSPEC[4];
    tDot11fIEAirgo              Airgo;
    tDot11fIEWscAssocRes        WscAssocRes;
    tDot11fIEP2PAssocRes        P2PAssocRes;
    tDot11fIEVHTCaps            VHTCaps;
    tDot11fIEVHTOperation       VHTOperation;
    tDot11fIEExtCap             ExtCap;
    tDot11fIEOBSSScanParameters OBSSScanParameters;
} tDot11fAssocResponse;

#define DOT11F_ASSOCRESPONSE ( 6 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackAssocResponse(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fAssocResponse *pFrm);
tANI_U32 dot11fPackAssocResponse(tpAniSirGlobal pCtx, tDot11fAssocResponse *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedAssocResponseSize(tpAniSirGlobal pCtx, tDot11fAssocResponse *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fAuthentication{
    tDot11fFfAuthAlgo        AuthAlgo;
    tDot11fFfAuthSeqNo       AuthSeqNo;
    tDot11fFfStatus          Status;
    tDot11fIEChallengeText   ChallengeText;
    tDot11fIERSNOpaque       RSNOpaque;
    tDot11fIEMobilityDomain  MobilityDomain;
    tDot11fIEFTInfo          FTInfo;
    tDot11fIETimeoutInterval TimeoutInterval;
    tANI_U16                 num_RICDataDesc;
    tDot11fIERICDataDesc     RICDataDesc[2];
} tDot11fAuthentication;

#define DOT11F_AUTHENTICATION ( 7 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackAuthentication(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fAuthentication *pFrm);
tANI_U32 dot11fPackAuthentication(tpAniSirGlobal pCtx, tDot11fAuthentication *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedAuthenticationSize(tpAniSirGlobal pCtx, tDot11fAuthentication *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fBeacon{
    tDot11fFfTimeStamp            TimeStamp;
    tDot11fFfBeaconInterval       BeaconInterval;
    tDot11fFfCapabilities         Capabilities;
    tDot11fIESSID                 SSID;
    tDot11fIESuppRates            SuppRates;
    tDot11fIEFHParamSet           FHParamSet;
    tDot11fIEDSParams             DSParams;
    tDot11fIECFParams             CFParams;
    tDot11fIEIBSSParams           IBSSParams;
    tDot11fIETIM                  TIM;
    tDot11fIECountry              Country;
    tDot11fIEFHParams             FHParams;
    tDot11fIEFHPattTable          FHPattTable;
    tDot11fIEPowerConstraints     PowerConstraints;
    tDot11fIEChanSwitchAnn        ChanSwitchAnn;
    tDot11fIEQuiet                Quiet;
    tDot11fIETPCReport            TPCReport;
    tDot11fIEERPInfo              ERPInfo;
    tDot11fIEExtSuppRates         ExtSuppRates;
    tDot11fIERSN                  RSN;
    tDot11fIEQBSSLoad             QBSSLoad;
    tDot11fIEEDCAParamSet         EDCAParamSet;
    tDot11fIEQOSCapsAp            QOSCapsAp;
    tDot11fIEAPChannelReport      APChannelReport;
    tDot11fIERRMEnabledCap        RRMEnabledCap;
    tDot11fIEMobilityDomain       MobilityDomain;
    tDot11fIEWPA                  WPA;
    tDot11fIEHTCaps               HTCaps;
    tDot11fIEHTInfo               HTInfo;
    tDot11fIEExtChanSwitchAnn     ExtChanSwitchAnn;
    tDot11fIEWMMInfoAp            WMMInfoAp;
    tDot11fIEWMMParams            WMMParams;
    tDot11fIEWMMCaps              WMMCaps;
    tDot11fIEWAPI                 WAPI;
    tDot11fIECCXRadMgmtCap        CCXRadMgmtCap;
    tDot11fIECCXTrafStrmMet       CCXTrafStrmMet;
    tDot11fIECCXTxmitPower        CCXTxmitPower;
    tDot11fIEAirgo                Airgo;
    tDot11fIEWscBeacon            WscBeacon;
    tDot11fIEP2PBeacon            P2PBeacon;
    tDot11fIEVHTCaps              VHTCaps;
    tDot11fIEVHTOperation         VHTOperation;
    tDot11fIEVHTExtBssLoad        VHTExtBssLoad;
    tDot11fIEExtCap               ExtCap;
    tDot11fIEOperatingMode        OperatingMode;
    tDot11fIEWiderBWChanSwitchAnn WiderBWChanSwitchAnn;
    tDot11fIEOxygenNetwork        OxygenNetwork;
    tDot11fIEOBSSScanParameters   OBSSScanParameters;
} tDot11fBeacon;

#define DOT11F_BEACON ( 8 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackBeacon(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fBeacon *pFrm);
tANI_U32 dot11fPackBeacon(tpAniSirGlobal pCtx, tDot11fBeacon *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedBeaconSize(tpAniSirGlobal pCtx, tDot11fBeacon *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fBeacon1{
    tDot11fFfTimeStamp      TimeStamp;
    tDot11fFfBeaconInterval BeaconInterval;
    tDot11fFfCapabilities   Capabilities;
    tDot11fIESSID           SSID;
    tDot11fIESuppRates      SuppRates;
    tDot11fIEDSParams       DSParams;
    tDot11fIEIBSSParams     IBSSParams;
} tDot11fBeacon1;

#define DOT11F_BEACON1 ( 9 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackBeacon1(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fBeacon1 *pFrm);
tANI_U32 dot11fPackBeacon1(tpAniSirGlobal pCtx, tDot11fBeacon1 *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedBeacon1Size(tpAniSirGlobal pCtx, tDot11fBeacon1 *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fBeacon2{
    tDot11fIECountry              Country;
    tDot11fIEPowerConstraints     PowerConstraints;
    tDot11fIEChanSwitchAnn        ChanSwitchAnn;
    tDot11fIEQuiet                Quiet;
    tDot11fIETPCReport            TPCReport;
    tDot11fIEERPInfo              ERPInfo;
    tDot11fIEExtSuppRates         ExtSuppRates;
    tDot11fIERSNOpaque            RSNOpaque;
    tDot11fIEEDCAParamSet         EDCAParamSet;
    tDot11fIEAPChannelReport      APChannelReport;
    tDot11fIERRMEnabledCap        RRMEnabledCap;
    tDot11fIEMobilityDomain       MobilityDomain;
    tDot11fIEWPA                  WPA;
    tDot11fIEHTCaps               HTCaps;
    tDot11fIEHTInfo               HTInfo;
    tDot11fIEExtChanSwitchAnn     ExtChanSwitchAnn;
    tDot11fIEWMMInfoAp            WMMInfoAp;
    tDot11fIEWMMParams            WMMParams;
    tDot11fIEWMMCaps              WMMCaps;
    tDot11fIEAirgo                Airgo;
    tDot11fIEWscBeacon            WscBeacon;
    tDot11fIEWAPI                 WAPI;
    tDot11fIECCXRadMgmtCap        CCXRadMgmtCap;
    tDot11fIECCXTrafStrmMet       CCXTrafStrmMet;
    tDot11fIECCXTxmitPower        CCXTxmitPower;
    tDot11fIEP2PBeacon            P2PBeacon;
    tDot11fIEVHTCaps              VHTCaps;
    tDot11fIEVHTOperation         VHTOperation;
    tDot11fIEVHTExtBssLoad        VHTExtBssLoad;
    tDot11fIEExtCap               ExtCap;
    tDot11fIEOperatingMode        OperatingMode;
    tDot11fIEWiderBWChanSwitchAnn WiderBWChanSwitchAnn;
    tDot11fIEOxygenNetwork        OxygenNetwork;
} tDot11fBeacon2;

#define DOT11F_BEACON2 ( 10 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackBeacon2(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fBeacon2 *pFrm);
tANI_U32 dot11fPackBeacon2(tpAniSirGlobal pCtx, tDot11fBeacon2 *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedBeacon2Size(tpAniSirGlobal pCtx, tDot11fBeacon2 *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fBeaconIEs{
    tDot11fIESSID                 SSID;
    tDot11fIESuppRates            SuppRates;
    tDot11fIEFHParamSet           FHParamSet;
    tDot11fIEDSParams             DSParams;
    tDot11fIECFParams             CFParams;
    tDot11fIEIBSSParams           IBSSParams;
    tDot11fIETIM                  TIM;
    tDot11fIECountry              Country;
    tDot11fIEFHParams             FHParams;
    tDot11fIEFHPattTable          FHPattTable;
    tDot11fIEPowerConstraints     PowerConstraints;
    tDot11fIEChanSwitchAnn        ChanSwitchAnn;
    tDot11fIEQuiet                Quiet;
    tDot11fIETPCReport            TPCReport;
    tDot11fIEERPInfo              ERPInfo;
    tDot11fIEExtSuppRates         ExtSuppRates;
    tDot11fIERSN                  RSN;
    tDot11fIEQBSSLoad             QBSSLoad;
    tDot11fIEEDCAParamSet         EDCAParamSet;
    tDot11fIEQOSCapsAp            QOSCapsAp;
    tDot11fIEAPChannelReport      APChannelReport;
    tDot11fIERRMEnabledCap        RRMEnabledCap;
    tDot11fIEMobilityDomain       MobilityDomain;
    tDot11fIEWPA                  WPA;
    tDot11fIEHTCaps               HTCaps;
    tDot11fIEHTInfo               HTInfo;
    tDot11fIEExtChanSwitchAnn     ExtChanSwitchAnn;
    tDot11fIEWMMInfoAp            WMMInfoAp;
    tDot11fIEWMMParams            WMMParams;
    tDot11fIEWMMCaps              WMMCaps;
    tDot11fIEWAPI                 WAPI;
    tDot11fIECCXVersion           CCXVersion;
    tDot11fIECCXRadMgmtCap        CCXRadMgmtCap;
    tDot11fIECCXTrafStrmMet       CCXTrafStrmMet;
    tDot11fIECCXTxmitPower        CCXTxmitPower;
    tDot11fIEAirgo                Airgo;
    tDot11fIEWscBeaconProbeRes    WscBeaconProbeRes;
    tDot11fIEP2PBeaconProbeRes    P2PBeaconProbeRes;
    tDot11fIEVHTCaps              VHTCaps;
    tDot11fIEVHTOperation         VHTOperation;
    tDot11fIEVHTExtBssLoad        VHTExtBssLoad;
    tDot11fIEExtCap               ExtCap;
    tDot11fIEOperatingMode        OperatingMode;
    tDot11fIEWiderBWChanSwitchAnn WiderBWChanSwitchAnn;
    tDot11fIEOxygenNetwork        OxygenNetwork;
    tDot11fIEOBSSScanParameters   OBSSScanParameters;
} tDot11fBeaconIEs;

#define DOT11F_BEACONIES ( 11 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackBeaconIEs(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fBeaconIEs *pFrm);
tANI_U32 dot11fPackBeaconIEs(tpAniSirGlobal pCtx, tDot11fBeaconIEs *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedBeaconIEsSize(tpAniSirGlobal pCtx, tDot11fBeaconIEs *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fChannelSwitch{
    tDot11fFfCategory             Category;
    tDot11fFfAction               Action;
    tDot11fIEChanSwitchAnn        ChanSwitchAnn;
    tDot11fIEExtChanSwitchAnn     ExtChanSwitchAnn;
    tDot11fIEWiderBWChanSwitchAnn WiderBWChanSwitchAnn;
} tDot11fChannelSwitch;

#define DOT11F_CHANNELSWITCH ( 12 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackChannelSwitch(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fChannelSwitch *pFrm);
tANI_U32 dot11fPackChannelSwitch(tpAniSirGlobal pCtx, tDot11fChannelSwitch *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedChannelSwitchSize(tpAniSirGlobal pCtx, tDot11fChannelSwitch *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fDeAuth{
    tDot11fFfReason    Reason;
    tDot11fIEP2PDeAuth P2PDeAuth;
} tDot11fDeAuth;

#define DOT11F_DEAUTH ( 13 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackDeAuth(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fDeAuth *pFrm);
tANI_U32 dot11fPackDeAuth(tpAniSirGlobal pCtx, tDot11fDeAuth *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedDeAuthSize(tpAniSirGlobal pCtx, tDot11fDeAuth *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fDelBAInd{
    tDot11fFfCategory          Category;
    tDot11fFfAction            Action;
    tDot11fFfDelBAParameterSet DelBAParameterSet;
    tDot11fFfReason            Reason;
} tDot11fDelBAInd;

#define DOT11F_DELBAIND ( 14 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackDelBAInd(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fDelBAInd *pFrm);
tANI_U32 dot11fPackDelBAInd(tpAniSirGlobal pCtx, tDot11fDelBAInd *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedDelBAIndSize(tpAniSirGlobal pCtx, tDot11fDelBAInd *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fDelTS{
    tDot11fFfCategory Category;
    tDot11fFfAction   Action;
    tDot11fFfTSInfo   TSInfo;
    tDot11fFfReason   Reason;
} tDot11fDelTS;

#define DOT11F_DELTS ( 15 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackDelTS(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fDelTS *pFrm);
tANI_U32 dot11fPackDelTS(tpAniSirGlobal pCtx, tDot11fDelTS *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedDelTSSize(tpAniSirGlobal pCtx, tDot11fDelTS *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fDeviceDiscoverabilityReq{
    tDot11fFfCategory                    Category;
    tDot11fFfAction                      Action;
    tDot11fFfP2POUI                      P2POUI;
    tDot11fFfP2POUISubType               P2POUISubType;
    tDot11fFfDialogToken                 DialogToken;
    tDot11fIEP2PDeviceDiscoverabilityReq P2PDeviceDiscoverabilityReq;
} tDot11fDeviceDiscoverabilityReq;

#define DOT11F_DEVICEDISCOVERABILITYREQ ( 16 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackDeviceDiscoverabilityReq(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fDeviceDiscoverabilityReq *pFrm);
tANI_U32 dot11fPackDeviceDiscoverabilityReq(tpAniSirGlobal pCtx, tDot11fDeviceDiscoverabilityReq *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedDeviceDiscoverabilityReqSize(tpAniSirGlobal pCtx, tDot11fDeviceDiscoverabilityReq *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fDeviceDiscoverabilityRes{
    tDot11fFfCategory                    Category;
    tDot11fFfAction                      Action;
    tDot11fFfP2POUI                      P2POUI;
    tDot11fFfP2POUISubType               P2POUISubType;
    tDot11fFfDialogToken                 DialogToken;
    tDot11fIEP2PDeviceDiscoverabilityRes P2PDeviceDiscoverabilityRes;
} tDot11fDeviceDiscoverabilityRes;

#define DOT11F_DEVICEDISCOVERABILITYRES ( 17 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackDeviceDiscoverabilityRes(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fDeviceDiscoverabilityRes *pFrm);
tANI_U32 dot11fPackDeviceDiscoverabilityRes(tpAniSirGlobal pCtx, tDot11fDeviceDiscoverabilityRes *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedDeviceDiscoverabilityResSize(tpAniSirGlobal pCtx, tDot11fDeviceDiscoverabilityRes *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fDisassociation{
    tDot11fFfReason      Reason;
    tDot11fIEP2PDisAssoc P2PDisAssoc;
} tDot11fDisassociation;

#define DOT11F_DISASSOCIATION ( 18 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackDisassociation(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fDisassociation *pFrm);
tANI_U32 dot11fPackDisassociation(tpAniSirGlobal pCtx, tDot11fDisassociation *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedDisassociationSize(tpAniSirGlobal pCtx, tDot11fDisassociation *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fGODiscoverabilityReq{
    tDot11fFfCategory      Category;
    tDot11fFfP2POUI        P2POUI;
    tDot11fFfP2POUISubType P2POUISubType;
    tDot11fFfDialogToken   DialogToken;
} tDot11fGODiscoverabilityReq;

#define DOT11F_GODISCOVERABILITYREQ ( 19 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackGODiscoverabilityReq(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fGODiscoverabilityReq *pFrm);
tANI_U32 dot11fPackGODiscoverabilityReq(tpAniSirGlobal pCtx, tDot11fGODiscoverabilityReq *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedGODiscoverabilityReqSize(tpAniSirGlobal pCtx, tDot11fGODiscoverabilityReq *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fGONegCnf{
    tDot11fFfCategory      Category;
    tDot11fFfAction        Action;
    tDot11fFfP2POUI        P2POUI;
    tDot11fFfP2POUISubType P2POUISubType;
    tDot11fFfDialogToken   DialogToken;
    tDot11fIEP2PGONegCnf   P2PGONegCnf;
} tDot11fGONegCnf;

#define DOT11F_GONEGCNF ( 20 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackGONegCnf(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fGONegCnf *pFrm);
tANI_U32 dot11fPackGONegCnf(tpAniSirGlobal pCtx, tDot11fGONegCnf *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedGONegCnfSize(tpAniSirGlobal pCtx, tDot11fGONegCnf *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fGONegReq{
    tDot11fFfCategory      Category;
    tDot11fFfAction        Action;
    tDot11fFfP2POUI        P2POUI;
    tDot11fFfP2POUISubType P2POUISubType;
    tDot11fFfDialogToken   DialogToken;
    tDot11fIEP2PGONegWPS   P2PGONegWPS;
    tDot11fIEP2PGONegReq   P2PGONegReq;
} tDot11fGONegReq;

#define DOT11F_GONEGREQ ( 21 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackGONegReq(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fGONegReq *pFrm);
tANI_U32 dot11fPackGONegReq(tpAniSirGlobal pCtx, tDot11fGONegReq *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedGONegReqSize(tpAniSirGlobal pCtx, tDot11fGONegReq *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fGONegRes{
    tDot11fFfCategory      Category;
    tDot11fFfAction        Action;
    tDot11fFfP2POUI        P2POUI;
    tDot11fFfP2POUISubType P2POUISubType;
    tDot11fFfDialogToken   DialogToken;
    tDot11fIEP2PGONegWPS   P2PGONegWPS;
    tDot11fIEP2PGONegRes   P2PGONegRes;
} tDot11fGONegRes;

#define DOT11F_GONEGRES ( 22 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackGONegRes(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fGONegRes *pFrm);
tANI_U32 dot11fPackGONegRes(tpAniSirGlobal pCtx, tDot11fGONegRes *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedGONegResSize(tpAniSirGlobal pCtx, tDot11fGONegRes *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fInvitationReq{
    tDot11fFfCategory         Category;
    tDot11fFfAction           Action;
    tDot11fFfP2POUI           P2POUI;
    tDot11fFfP2POUISubType    P2POUISubType;
    tDot11fFfDialogToken      DialogToken;
    tDot11fIEP2PInvitationReq P2PInvitationReq;
} tDot11fInvitationReq;

#define DOT11F_INVITATIONREQ ( 23 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackInvitationReq(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fInvitationReq *pFrm);
tANI_U32 dot11fPackInvitationReq(tpAniSirGlobal pCtx, tDot11fInvitationReq *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedInvitationReqSize(tpAniSirGlobal pCtx, tDot11fInvitationReq *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fInvitationRes{
    tDot11fFfCategory         Category;
    tDot11fFfAction           Action;
    tDot11fFfP2POUI           P2POUI;
    tDot11fFfP2POUISubType    P2POUISubType;
    tDot11fFfDialogToken      DialogToken;
    tDot11fIEP2PInvitationRes P2PInvitationRes;
} tDot11fInvitationRes;

#define DOT11F_INVITATIONRES ( 24 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackInvitationRes(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fInvitationRes *pFrm);
tANI_U32 dot11fPackInvitationRes(tpAniSirGlobal pCtx, tDot11fInvitationRes *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedInvitationResSize(tpAniSirGlobal pCtx, tDot11fInvitationRes *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fLinkMeasurementReport{
    tDot11fFfCategory    Category;
    tDot11fFfAction      Action;
    tDot11fFfDialogToken DialogToken;
    tDot11fFfTPCEleID    TPCEleID;
    tDot11fFfTPCEleLen   TPCEleLen;
    tDot11fFfTxPower     TxPower;
    tDot11fFfLinkMargin  LinkMargin;
    tDot11fFfRxAntennaId RxAntennaId;
    tDot11fFfTxAntennaId TxAntennaId;
    tDot11fFfRCPI        RCPI;
    tDot11fFfRSNI        RSNI;
} tDot11fLinkMeasurementReport;

#define DOT11F_LINKMEASUREMENTREPORT ( 25 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackLinkMeasurementReport(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fLinkMeasurementReport *pFrm);
tANI_U32 dot11fPackLinkMeasurementReport(tpAniSirGlobal pCtx, tDot11fLinkMeasurementReport *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedLinkMeasurementReportSize(tpAniSirGlobal pCtx, tDot11fLinkMeasurementReport *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fLinkMeasurementRequest{
    tDot11fFfCategory    Category;
    tDot11fFfAction      Action;
    tDot11fFfDialogToken DialogToken;
    tDot11fFfTxPower     TxPower;
    tDot11fFfMaxTxPower  MaxTxPower;
} tDot11fLinkMeasurementRequest;

#define DOT11F_LINKMEASUREMENTREQUEST ( 26 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackLinkMeasurementRequest(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fLinkMeasurementRequest *pFrm);
tANI_U32 dot11fPackLinkMeasurementRequest(tpAniSirGlobal pCtx, tDot11fLinkMeasurementRequest *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedLinkMeasurementRequestSize(tpAniSirGlobal pCtx, tDot11fLinkMeasurementRequest *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fMeasurementReport{
    tDot11fFfCategory          Category;
    tDot11fFfAction            Action;
    tDot11fFfDialogToken       DialogToken;
    tDot11fIEMeasurementReport MeasurementReport;
} tDot11fMeasurementReport;

#define DOT11F_MEASUREMENTREPORT ( 27 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackMeasurementReport(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fMeasurementReport *pFrm);
tANI_U32 dot11fPackMeasurementReport(tpAniSirGlobal pCtx, tDot11fMeasurementReport *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedMeasurementReportSize(tpAniSirGlobal pCtx, tDot11fMeasurementReport *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fMeasurementRequest{
    tDot11fFfCategory           Category;
    tDot11fFfAction             Action;
    tDot11fFfDialogToken        DialogToken;
    tANI_U16                    num_MeasurementRequest;
    tDot11fIEMeasurementRequest MeasurementRequest[4];
} tDot11fMeasurementRequest;

#define DOT11F_MEASUREMENTREQUEST ( 28 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackMeasurementRequest(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fMeasurementRequest *pFrm);
tANI_U32 dot11fPackMeasurementRequest(tpAniSirGlobal pCtx, tDot11fMeasurementRequest *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedMeasurementRequestSize(tpAniSirGlobal pCtx, tDot11fMeasurementRequest *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fNeighborReportRequest{
    tDot11fFfCategory    Category;
    tDot11fFfAction      Action;
    tDot11fFfDialogToken DialogToken;
    tDot11fIESSID        SSID;
} tDot11fNeighborReportRequest;

#define DOT11F_NEIGHBORREPORTREQUEST ( 29 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackNeighborReportRequest(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fNeighborReportRequest *pFrm);
tANI_U32 dot11fPackNeighborReportRequest(tpAniSirGlobal pCtx, tDot11fNeighborReportRequest *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedNeighborReportRequestSize(tpAniSirGlobal pCtx, tDot11fNeighborReportRequest *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fNeighborReportResponse{
    tDot11fFfCategory       Category;
    tDot11fFfAction         Action;
    tDot11fFfDialogToken    DialogToken;
    tANI_U16                num_NeighborReport;
    tDot11fIENeighborReport NeighborReport[4];
} tDot11fNeighborReportResponse;

#define DOT11F_NEIGHBORREPORTRESPONSE ( 30 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackNeighborReportResponse(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fNeighborReportResponse *pFrm);
tANI_U32 dot11fPackNeighborReportResponse(tpAniSirGlobal pCtx, tDot11fNeighborReportResponse *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedNeighborReportResponseSize(tpAniSirGlobal pCtx, tDot11fNeighborReportResponse *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fNoticeOfAbs{
    tDot11fFfCategory           Category;
    tDot11fFfP2POUI             P2POUI;
    tDot11fFfP2POUISubType      P2POUISubType;
    tDot11fFfDialogToken        DialogToken;
    tDot11fIEP2PNoticeOfAbsence P2PNoticeOfAbsence;
} tDot11fNoticeOfAbs;

#define DOT11F_NOTICEOFABS ( 31 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackNoticeOfAbs(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fNoticeOfAbs *pFrm);
tANI_U32 dot11fPackNoticeOfAbs(tpAniSirGlobal pCtx, tDot11fNoticeOfAbs *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedNoticeOfAbsSize(tpAniSirGlobal pCtx, tDot11fNoticeOfAbs *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fOperatingMode{
    tDot11fFfCategory      Category;
    tDot11fFfAction        Action;
    tDot11fFfOperatingMode OperatingMode;
} tDot11fOperatingMode;

#define DOT11F_OPERATINGMODE ( 32 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackOperatingMode(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fOperatingMode *pFrm);
tANI_U32 dot11fPackOperatingMode(tpAniSirGlobal pCtx, tDot11fOperatingMode *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedOperatingModeSize(tpAniSirGlobal pCtx, tDot11fOperatingMode *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fPresenceReq{
    tDot11fFfCategory           Category;
    tDot11fFfP2POUI             P2POUI;
    tDot11fFfP2POUISubType      P2POUISubType;
    tDot11fFfDialogToken        DialogToken;
    tDot11fIEP2PNoticeOfAbsence P2PNoticeOfAbsence;
} tDot11fPresenceReq;

#define DOT11F_PRESENCEREQ ( 33 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackPresenceReq(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fPresenceReq *pFrm);
tANI_U32 dot11fPackPresenceReq(tpAniSirGlobal pCtx, tDot11fPresenceReq *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedPresenceReqSize(tpAniSirGlobal pCtx, tDot11fPresenceReq *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fPresenceRes{
    tDot11fFfCategory            Category;
    tDot11fFfP2POUI              P2POUI;
    tDot11fFfP2POUISubType       P2POUISubType;
    tDot11fFfDialogToken         DialogToken;
    tDot11fIEP2PPresenceResponse P2PPresenceResponse;
} tDot11fPresenceRes;

#define DOT11F_PRESENCERES ( 34 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackPresenceRes(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fPresenceRes *pFrm);
tANI_U32 dot11fPackPresenceRes(tpAniSirGlobal pCtx, tDot11fPresenceRes *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedPresenceResSize(tpAniSirGlobal pCtx, tDot11fPresenceRes *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fProbeRequest{
    tDot11fIESSID          SSID;
    tDot11fIESuppRates     SuppRates;
    tDot11fIERequestedInfo RequestedInfo;
    tDot11fIEExtSuppRates  ExtSuppRates;
    tDot11fIEDSParams      DSParams;
    tDot11fIEHTCaps        HTCaps;
    tDot11fIEWscProbeReq   WscProbeReq;
    tDot11fIEWFATPC        WFATPC;
    tDot11fIEP2PProbeReq   P2PProbeReq;
    tDot11fIEVHTCaps       VHTCaps;
} tDot11fProbeRequest;

#define DOT11F_PROBEREQUEST ( 35 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackProbeRequest(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fProbeRequest *pFrm);
tANI_U32 dot11fPackProbeRequest(tpAniSirGlobal pCtx, tDot11fProbeRequest *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedProbeRequestSize(tpAniSirGlobal pCtx, tDot11fProbeRequest *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fProbeResponse{
    tDot11fFfTimeStamp          TimeStamp;
    tDot11fFfBeaconInterval     BeaconInterval;
    tDot11fFfCapabilities       Capabilities;
    tDot11fIESSID               SSID;
    tDot11fIESuppRates          SuppRates;
    tDot11fIEFHParamSet         FHParamSet;
    tDot11fIEDSParams           DSParams;
    tDot11fIECFParams           CFParams;
    tDot11fIEIBSSParams         IBSSParams;
    tDot11fIECountry            Country;
    tDot11fIEFHParams           FHParams;
    tDot11fIEFHPattTable        FHPattTable;
    tDot11fIEPowerConstraints   PowerConstraints;
    tDot11fIEChanSwitchAnn      ChanSwitchAnn;
    tDot11fIEQuiet              Quiet;
    tDot11fIETPCReport          TPCReport;
    tDot11fIEERPInfo            ERPInfo;
    tDot11fIEExtSuppRates       ExtSuppRates;
    tDot11fIERSNOpaque          RSNOpaque;
    tDot11fIEQBSSLoad           QBSSLoad;
    tDot11fIEEDCAParamSet       EDCAParamSet;
    tDot11fIERRMEnabledCap      RRMEnabledCap;
    tDot11fIEAPChannelReport    APChannelReport;
    tDot11fIEMobilityDomain     MobilityDomain;
    tDot11fIEWPA                WPA;
    tDot11fIEHTCaps             HTCaps;
    tDot11fIEHTInfo             HTInfo;
    tDot11fIEExtChanSwitchAnn   ExtChanSwitchAnn;
    tDot11fIEWMMInfoAp          WMMInfoAp;
    tDot11fIEWMMParams          WMMParams;
    tDot11fIEWMMCaps            WMMCaps;
    tDot11fIEWAPI               WAPI;
    tDot11fIECCXRadMgmtCap      CCXRadMgmtCap;
    tDot11fIECCXTrafStrmMet     CCXTrafStrmMet;
    tDot11fIECCXTxmitPower      CCXTxmitPower;
    tDot11fIEAirgo              Airgo;
    tDot11fIEWscProbeRes        WscProbeRes;
    tDot11fIEP2PProbeRes        P2PProbeRes;
    tDot11fIEVHTCaps            VHTCaps;
    tDot11fIEVHTOperation       VHTOperation;
    tDot11fIEVHTExtBssLoad      VHTExtBssLoad;
    tDot11fIEExtCap             ExtCap;
    tDot11fIEOxygenNetwork      OxygenNetwork;
    tDot11fIEOBSSScanParameters OBSSScanParameters;
} tDot11fProbeResponse;

#define DOT11F_PROBERESPONSE ( 36 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackProbeResponse(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fProbeResponse *pFrm);
tANI_U32 dot11fPackProbeResponse(tpAniSirGlobal pCtx, tDot11fProbeResponse *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedProbeResponseSize(tpAniSirGlobal pCtx, tDot11fProbeResponse *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fProvisionDiscoveryReq{
    tDot11fFfCategory                 Category;
    tDot11fFfAction                   Action;
    tDot11fFfP2POUI                   P2POUI;
    tDot11fFfP2POUISubType            P2POUISubType;
    tDot11fFfDialogToken              DialogToken;
    tDot11fIEP2PProvisionDiscoveryReq P2PProvisionDiscoveryReq;
} tDot11fProvisionDiscoveryReq;

#define DOT11F_PROVISIONDISCOVERYREQ ( 37 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackProvisionDiscoveryReq(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fProvisionDiscoveryReq *pFrm);
tANI_U32 dot11fPackProvisionDiscoveryReq(tpAniSirGlobal pCtx, tDot11fProvisionDiscoveryReq *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedProvisionDiscoveryReqSize(tpAniSirGlobal pCtx, tDot11fProvisionDiscoveryReq *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fProvisionDiscoveryRes{
    tDot11fFfCategory                    Category;
    tDot11fFfAction                      Action;
    tDot11fFfP2POUI                      P2POUI;
    tDot11fFfP2POUISubType               P2POUISubType;
    tDot11fFfDialogToken                 DialogToken;
    tDot11fIEP2PWSCProvisionDiscoveryRes P2PWSCProvisionDiscoveryRes;
} tDot11fProvisionDiscoveryRes;

#define DOT11F_PROVISIONDISCOVERYRES ( 38 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackProvisionDiscoveryRes(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fProvisionDiscoveryRes *pFrm);
tANI_U32 dot11fPackProvisionDiscoveryRes(tpAniSirGlobal pCtx, tDot11fProvisionDiscoveryRes *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedProvisionDiscoveryResSize(tpAniSirGlobal pCtx, tDot11fProvisionDiscoveryRes *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fRMC{
    tDot11fFfCategory       Category;
    tDot11fFfRMCOUI         RMCOUI;
    tDot11fFfMagicCode      MagicCode;
    tDot11fFfRMCVersion     RMCVersion;
    tDot11fFfAction         Action;
    tDot11fFfRMCDialogToken RMCDialogToken;
    tDot11fFfLeader         Leader;
} tDot11fRMC;

#define DOT11F_RMC ( 39 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackRMC(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fRMC *pFrm);
tANI_U32 dot11fPackRMC(tpAniSirGlobal pCtx, tDot11fRMC *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedRMCSize(tpAniSirGlobal pCtx, tDot11fRMC *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fRadioMeasurementReport{
    tDot11fFfCategory          Category;
    tDot11fFfAction            Action;
    tDot11fFfDialogToken       DialogToken;
    tANI_U16                   num_MeasurementReport;
    tDot11fIEMeasurementReport MeasurementReport[4];
} tDot11fRadioMeasurementReport;

#define DOT11F_RADIOMEASUREMENTREPORT ( 40 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackRadioMeasurementReport(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fRadioMeasurementReport *pFrm);
tANI_U32 dot11fPackRadioMeasurementReport(tpAniSirGlobal pCtx, tDot11fRadioMeasurementReport *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedRadioMeasurementReportSize(tpAniSirGlobal pCtx, tDot11fRadioMeasurementReport *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fRadioMeasurementRequest{
    tDot11fFfCategory           Category;
    tDot11fFfAction             Action;
    tDot11fFfDialogToken        DialogToken;
    tDot11fFfNumOfRepetitions   NumOfRepetitions;
    tANI_U16                    num_MeasurementRequest;
    tDot11fIEMeasurementRequest MeasurementRequest[2];
} tDot11fRadioMeasurementRequest;

#define DOT11F_RADIOMEASUREMENTREQUEST ( 41 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackRadioMeasurementRequest(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fRadioMeasurementRequest *pFrm);
tANI_U32 dot11fPackRadioMeasurementRequest(tpAniSirGlobal pCtx, tDot11fRadioMeasurementRequest *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedRadioMeasurementRequestSize(tpAniSirGlobal pCtx, tDot11fRadioMeasurementRequest *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fReAssocRequest{
    tDot11fFfCapabilities       Capabilities;
    tDot11fFfListenInterval     ListenInterval;
    tDot11fFfCurrentAPAddress   CurrentAPAddress;
    tDot11fIESSID               SSID;
    tDot11fIESuppRates          SuppRates;
    tDot11fIEExtSuppRates       ExtSuppRates;
    tDot11fIEPowerCaps          PowerCaps;
    tDot11fIESuppChannels       SuppChannels;
    tDot11fIERSNOpaque          RSNOpaque;
    tDot11fIEQOSCapsStation     QOSCapsStation;
    tDot11fIERRMEnabledCap      RRMEnabledCap;
    tDot11fIEMobilityDomain     MobilityDomain;
    tDot11fIEFTInfo             FTInfo;
    tANI_U16                    num_RICDataDesc;
    tDot11fIERICDataDesc        RICDataDesc[2];
    tDot11fIEWPAOpaque          WPAOpaque;
    tDot11fIEHTCaps             HTCaps;
    tDot11fIEWMMCaps            WMMCaps;
    tDot11fIEWMMInfoStation     WMMInfoStation;
    tDot11fIEAirgo              Airgo;
    tDot11fIEWscIEOpaque        WscIEOpaque;
    tDot11fIEWAPIOpaque         WAPIOpaque;
    tDot11fIECCXRadMgmtCap      CCXRadMgmtCap;
    tDot11fIECCXVersion         CCXVersion;
    tDot11fIECCXCckmOpaque      CCXCckmOpaque;
    tANI_U16                    num_WMMTSPEC;
    tDot11fIEWMMTSPEC           WMMTSPEC[4];
    tDot11fIECCXTrafStrmRateSet CCXTrafStrmRateSet;
    tDot11fIEP2PIEOpaque        P2PIEOpaque;
    tDot11fIEWFDIEOpaque        WFDIEOpaque;
    tDot11fIEVHTCaps            VHTCaps;
    tDot11fIEExtCap             ExtCap;
    tDot11fIEOperatingMode      OperatingMode;
} tDot11fReAssocRequest;

#define DOT11F_REASSOCREQUEST ( 42 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackReAssocRequest(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fReAssocRequest *pFrm);
tANI_U32 dot11fPackReAssocRequest(tpAniSirGlobal pCtx, tDot11fReAssocRequest *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedReAssocRequestSize(tpAniSirGlobal pCtx, tDot11fReAssocRequest *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fReAssocResponse{
    tDot11fFfCapabilities       Capabilities;
    tDot11fFfStatus             Status;
    tDot11fFfAID                AID;
    tDot11fIESuppRates          SuppRates;
    tDot11fIEExtSuppRates       ExtSuppRates;
    tDot11fIEEDCAParamSet       EDCAParamSet;
    tDot11fIERCPIIE             RCPIIE;
    tDot11fIERSNIIE             RSNIIE;
    tDot11fIERRMEnabledCap      RRMEnabledCap;
    tDot11fIERSNOpaque          RSNOpaque;
    tDot11fIEMobilityDomain     MobilityDomain;
    tDot11fIEFTInfo             FTInfo;
    tANI_U16                    num_RICDataDesc;
    tDot11fIERICDataDesc        RICDataDesc[2];
    tDot11fIEWPA                WPA;
    tDot11fIETimeoutInterval    TimeoutInterval;
    tDot11fIEHTCaps             HTCaps;
    tDot11fIEHTInfo             HTInfo;
    tDot11fIEWMMParams          WMMParams;
    tDot11fIECCXRadMgmtCap      CCXRadMgmtCap;
    tDot11fIECCXTrafStrmMet     CCXTrafStrmMet;
    tDot11fIECCXTxmitPower      CCXTxmitPower;
    tANI_U16                    num_WMMTSPEC;
    tDot11fIEWMMTSPEC           WMMTSPEC[4];
    tDot11fIECCXTrafStrmRateSet CCXTrafStrmRateSet;
    tDot11fIEAirgo              Airgo;
    tDot11fIEWscReassocRes      WscReassocRes;
    tDot11fIEP2PAssocRes        P2PAssocRes;
    tDot11fIEVHTCaps            VHTCaps;
    tDot11fIEVHTOperation       VHTOperation;
    tDot11fIEExtCap             ExtCap;
    tDot11fIEOBSSScanParameters OBSSScanParameters;
} tDot11fReAssocResponse;

#define DOT11F_REASSOCRESPONSE ( 43 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackReAssocResponse(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fReAssocResponse *pFrm);
tANI_U32 dot11fPackReAssocResponse(tpAniSirGlobal pCtx, tDot11fReAssocResponse *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedReAssocResponseSize(tpAniSirGlobal pCtx, tDot11fReAssocResponse *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fSMPowerSave{
    tDot11fFfCategory       Category;
    tDot11fFfAction         Action;
    tDot11fFfSMPowerModeSet SMPowerModeSet;
} tDot11fSMPowerSave;

#define DOT11F_SMPOWERSAVE ( 44 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackSMPowerSave(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fSMPowerSave *pFrm);
tANI_U32 dot11fPackSMPowerSave(tpAniSirGlobal pCtx, tDot11fSMPowerSave *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedSMPowerSaveSize(tpAniSirGlobal pCtx, tDot11fSMPowerSave *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fSaQueryReq{
    tDot11fFfCategory      Category;
    tDot11fFfAction        Action;
    tDot11fFfTransactionId TransactionId;
} tDot11fSaQueryReq;

#define DOT11F_SAQUERYREQ ( 45 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackSaQueryReq(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fSaQueryReq *pFrm);
tANI_U32 dot11fPackSaQueryReq(tpAniSirGlobal pCtx, tDot11fSaQueryReq *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedSaQueryReqSize(tpAniSirGlobal pCtx, tDot11fSaQueryReq *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fSaQueryRsp{
    tDot11fFfCategory      Category;
    tDot11fFfAction        Action;
    tDot11fFfTransactionId TransactionId;
} tDot11fSaQueryRsp;

#define DOT11F_SAQUERYRSP ( 46 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackSaQueryRsp(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fSaQueryRsp *pFrm);
tANI_U32 dot11fPackSaQueryRsp(tpAniSirGlobal pCtx, tDot11fSaQueryRsp *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedSaQueryRspSize(tpAniSirGlobal pCtx, tDot11fSaQueryRsp *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fTDLSDisReq{
    tDot11fFfCategory       Category;
    tDot11fFfAction         Action;
    tDot11fFfDialogToken    DialogToken;
    tDot11fIELinkIdentifier LinkIdentifier;
} tDot11fTDLSDisReq;

#define DOT11F_TDLSDISREQ ( 47 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackTDLSDisReq(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fTDLSDisReq *pFrm);
tANI_U32 dot11fPackTDLSDisReq(tpAniSirGlobal pCtx, tDot11fTDLSDisReq *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedTDLSDisReqSize(tpAniSirGlobal pCtx, tDot11fTDLSDisReq *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fTDLSDisRsp{
    tDot11fFfCategory             Category;
    tDot11fFfAction               Action;
    tDot11fFfDialogToken          DialogToken;
    tDot11fFfCapabilities         Capabilities;
    tDot11fIESuppRates            SuppRates;
    tDot11fIEExtSuppRates         ExtSuppRates;
    tDot11fIESuppChannels         SuppChannels;
    tDot11fIESuppOperatingClasses SuppOperatingClasses;
    tDot11fIERSN                  RSN;
    tDot11fIEExtCap               ExtCap;
    tDot11fIEFTInfo               FTInfo;
    tDot11fIETimeoutInterval      TimeoutInterval;
    tDot11fIERICData              RICData;
    tDot11fIEHTCaps               HTCaps;
    tDot11fIELinkIdentifier       LinkIdentifier;
    tDot11fIEVHTCaps              VHTCaps;
} tDot11fTDLSDisRsp;

#define DOT11F_TDLSDISRSP ( 48 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackTDLSDisRsp(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fTDLSDisRsp *pFrm);
tANI_U32 dot11fPackTDLSDisRsp(tpAniSirGlobal pCtx, tDot11fTDLSDisRsp *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedTDLSDisRspSize(tpAniSirGlobal pCtx, tDot11fTDLSDisRsp *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fTDLSPeerTrafficInd{
    tDot11fFfCategory       Category;
    tDot11fFfAction         Action;
    tDot11fFfDialogToken    DialogToken;
    tDot11fIELinkIdentifier LinkIdentifier;
    tDot11fIEPTIControl     PTIControl;
    tDot11fIEPUBufferStatus PUBufferStatus;
} tDot11fTDLSPeerTrafficInd;

#define DOT11F_TDLSPEERTRAFFICIND ( 49 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackTDLSPeerTrafficInd(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fTDLSPeerTrafficInd *pFrm);
tANI_U32 dot11fPackTDLSPeerTrafficInd(tpAniSirGlobal pCtx, tDot11fTDLSPeerTrafficInd *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedTDLSPeerTrafficIndSize(tpAniSirGlobal pCtx, tDot11fTDLSPeerTrafficInd *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fTDLSPeerTrafficRsp{
    tDot11fFfCategory       Category;
    tDot11fFfAction         Action;
    tDot11fFfDialogToken    DialogToken;
    tDot11fIELinkIdentifier LinkIdentifier;
} tDot11fTDLSPeerTrafficRsp;

#define DOT11F_TDLSPEERTRAFFICRSP ( 50 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackTDLSPeerTrafficRsp(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fTDLSPeerTrafficRsp *pFrm);
tANI_U32 dot11fPackTDLSPeerTrafficRsp(tpAniSirGlobal pCtx, tDot11fTDLSPeerTrafficRsp *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedTDLSPeerTrafficRspSize(tpAniSirGlobal pCtx, tDot11fTDLSPeerTrafficRsp *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fTDLSSetupCnf{
    tDot11fFfCategory        Category;
    tDot11fFfAction          Action;
    tDot11fFfStatus          Status;
    tDot11fFfDialogToken     DialogToken;
    tDot11fIERSN             RSN;
    tDot11fIEEDCAParamSet    EDCAParamSet;
    tDot11fIEFTInfo          FTInfo;
    tDot11fIETimeoutInterval TimeoutInterval;
    tDot11fIEHTInfo          HTInfo;
    tDot11fIELinkIdentifier  LinkIdentifier;
    tDot11fIEWMMParams       WMMParams;
    tDot11fIEVHTOperation    VHTOperation;
    tDot11fIEOperatingMode   OperatingMode;
} tDot11fTDLSSetupCnf;

#define DOT11F_TDLSSETUPCNF ( 51 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackTDLSSetupCnf(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fTDLSSetupCnf *pFrm);
tANI_U32 dot11fPackTDLSSetupCnf(tpAniSirGlobal pCtx, tDot11fTDLSSetupCnf *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedTDLSSetupCnfSize(tpAniSirGlobal pCtx, tDot11fTDLSSetupCnf *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fTDLSSetupReq{
    tDot11fFfCategory             Category;
    tDot11fFfAction               Action;
    tDot11fFfDialogToken          DialogToken;
    tDot11fFfCapabilities         Capabilities;
    tDot11fIESuppRates            SuppRates;
    tDot11fIECountry              Country;
    tDot11fIEExtSuppRates         ExtSuppRates;
    tDot11fIESuppChannels         SuppChannels;
    tDot11fIERSN                  RSN;
    tDot11fIEExtCap               ExtCap;
    tDot11fIESuppOperatingClasses SuppOperatingClasses;
    tDot11fIEQOSCapsStation       QOSCapsStation;
    tDot11fIEFTInfo               FTInfo;
    tDot11fIETimeoutInterval      TimeoutInterval;
    tDot11fIERICData              RICData;
    tDot11fIEHTCaps               HTCaps;
    tDot11fIELinkIdentifier       LinkIdentifier;
    tDot11fIEWMMInfoStation       WMMInfoStation;
    tDot11fIEAID                  AID;
    tDot11fIEVHTCaps              VHTCaps;
} tDot11fTDLSSetupReq;

#define DOT11F_TDLSSETUPREQ ( 52 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackTDLSSetupReq(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fTDLSSetupReq *pFrm);
tANI_U32 dot11fPackTDLSSetupReq(tpAniSirGlobal pCtx, tDot11fTDLSSetupReq *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedTDLSSetupReqSize(tpAniSirGlobal pCtx, tDot11fTDLSSetupReq *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fTDLSSetupRsp{
    tDot11fFfCategory             Category;
    tDot11fFfAction               Action;
    tDot11fFfStatus               Status;
    tDot11fFfDialogToken          DialogToken;
    tDot11fFfCapabilities         Capabilities;
    tDot11fIESuppRates            SuppRates;
    tDot11fIECountry              Country;
    tDot11fIEExtSuppRates         ExtSuppRates;
    tDot11fIESuppChannels         SuppChannels;
    tDot11fIERSN                  RSN;
    tDot11fIEExtCap               ExtCap;
    tDot11fIESuppOperatingClasses SuppOperatingClasses;
    tDot11fIEQOSCapsStation       QOSCapsStation;
    tDot11fIEFTInfo               FTInfo;
    tDot11fIETimeoutInterval      TimeoutInterval;
    tDot11fIERICData              RICData;
    tDot11fIEHTCaps               HTCaps;
    tDot11fIELinkIdentifier       LinkIdentifier;
    tDot11fIEWMMInfoStation       WMMInfoStation;
    tDot11fIEAID                  AID;
    tDot11fIEVHTCaps              VHTCaps;
    tDot11fIEOperatingMode        OperatingMode;
} tDot11fTDLSSetupRsp;

#define DOT11F_TDLSSETUPRSP ( 53 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackTDLSSetupRsp(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fTDLSSetupRsp *pFrm);
tANI_U32 dot11fPackTDLSSetupRsp(tpAniSirGlobal pCtx, tDot11fTDLSSetupRsp *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedTDLSSetupRspSize(tpAniSirGlobal pCtx, tDot11fTDLSSetupRsp *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fTDLSTeardown{
    tDot11fFfCategory       Category;
    tDot11fFfAction         Action;
    tDot11fFfReason         Reason;
    tDot11fIEFTInfo         FTInfo;
    tDot11fIELinkIdentifier LinkIdentifier;
} tDot11fTDLSTeardown;

#define DOT11F_TDLSTEARDOWN ( 54 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackTDLSTeardown(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fTDLSTeardown *pFrm);
tANI_U32 dot11fPackTDLSTeardown(tpAniSirGlobal pCtx, tDot11fTDLSTeardown *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedTDLSTeardownSize(tpAniSirGlobal pCtx, tDot11fTDLSTeardown *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fTPCReport{
    tDot11fFfCategory    Category;
    tDot11fFfAction      Action;
    tDot11fFfDialogToken DialogToken;
    tDot11fIETPCReport   TPCReport;
} tDot11fTPCReport;

#define DOT11F_TPCREPORT ( 55 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackTPCReport(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fTPCReport *pFrm);
tANI_U32 dot11fPackTPCReport(tpAniSirGlobal pCtx, tDot11fTPCReport *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedTPCReportSize(tpAniSirGlobal pCtx, tDot11fTPCReport *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fTPCRequest{
    tDot11fFfCategory    Category;
    tDot11fFfAction      Action;
    tDot11fFfDialogToken DialogToken;
    tDot11fIETPCRequest  TPCRequest;
} tDot11fTPCRequest;

#define DOT11F_TPCREQUEST ( 56 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackTPCRequest(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fTPCRequest *pFrm);
tANI_U32 dot11fPackTPCRequest(tpAniSirGlobal pCtx, tDot11fTPCRequest *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedTPCRequestSize(tpAniSirGlobal pCtx, tDot11fTPCRequest *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fVHTGidManagementActionFrame{
    tDot11fFfCategory                 Category;
    tDot11fFfAction                   Action;
    tDot11fFfVhtMembershipStatusArray VhtMembershipStatusArray;
    tDot11fFfVhtUserPositionArray     VhtUserPositionArray;
} tDot11fVHTGidManagementActionFrame;

#define DOT11F_VHTGIDMANAGEMENTACTIONFRAME ( 57 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackVHTGidManagementActionFrame(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fVHTGidManagementActionFrame *pFrm);
tANI_U32 dot11fPackVHTGidManagementActionFrame(tpAniSirGlobal pCtx, tDot11fVHTGidManagementActionFrame *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedVHTGidManagementActionFrameSize(tpAniSirGlobal pCtx, tDot11fVHTGidManagementActionFrame *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fWMMAddTSRequest{
    tDot11fFfCategory           Category;
    tDot11fFfAction             Action;
    tDot11fFfDialogToken        DialogToken;
    tDot11fFfStatusCode         StatusCode;
    tDot11fIEWMMTSPEC           WMMTSPEC;
    tDot11fIECCXTrafStrmRateSet CCXTrafStrmRateSet;
} tDot11fWMMAddTSRequest;

#define DOT11F_WMMADDTSREQUEST ( 58 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackWMMAddTSRequest(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fWMMAddTSRequest *pFrm);
tANI_U32 dot11fPackWMMAddTSRequest(tpAniSirGlobal pCtx, tDot11fWMMAddTSRequest *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedWMMAddTSRequestSize(tpAniSirGlobal pCtx, tDot11fWMMAddTSRequest *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fWMMAddTSResponse{
    tDot11fFfCategory       Category;
    tDot11fFfAction         Action;
    tDot11fFfDialogToken    DialogToken;
    tDot11fFfStatusCode     StatusCode;
    tDot11fIEWMMTSPEC       WMMTSPEC;
    tDot11fIECCXTrafStrmMet CCXTrafStrmMet;
} tDot11fWMMAddTSResponse;

#define DOT11F_WMMADDTSRESPONSE ( 59 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackWMMAddTSResponse(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fWMMAddTSResponse *pFrm);
tANI_U32 dot11fPackWMMAddTSResponse(tpAniSirGlobal pCtx, tDot11fWMMAddTSResponse *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedWMMAddTSResponseSize(tpAniSirGlobal pCtx, tDot11fWMMAddTSResponse *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

typedef struct sDot11fWMMDelTS{
    tDot11fFfCategory    Category;
    tDot11fFfAction      Action;
    tDot11fFfDialogToken DialogToken;
    tDot11fFfStatusCode  StatusCode;
    tDot11fIEWMMTSPEC    WMMTSPEC;
} tDot11fWMMDelTS;

#define DOT11F_WMMDELTS ( 60 )

#ifdef __cplusplus
extern "C" {
#endif 

tANI_U32 dot11fUnpackWMMDelTS(tpAniSirGlobal pCtx, tANI_U8 *pBuf, tANI_U32 nBuf, tDot11fWMMDelTS *pFrm);
tANI_U32 dot11fPackWMMDelTS(tpAniSirGlobal pCtx, tDot11fWMMDelTS *pFrm, tANI_U8 *pBuf, tANI_U32 nBuf, tANI_U32 *pnConsumed);
tANI_U32 dot11fGetPackedWMMDelTSSize(tpAniSirGlobal pCtx, tDot11fWMMDelTS *pFrm, tANI_U32 *pnNeeded);

#ifdef __cplusplus
} 
#endif 

#endif 
