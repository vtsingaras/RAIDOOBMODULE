//
// This file contains an 'Intel Peripheral Driver' and is
// licensed for Intel CPUs and chipsets under the terms of your
// license agreement with Intel or your vendor.  This file may
// be modified by the user, subject to additional terms of the
// license agreement
//
/**

Copyright (c)  1999 - 2016 Intel Corporation. All rights reserved
This software and associated documentation (if any) is furnished
under a license and may only be used or copied in accordance
with the terms of the license. Except as permitted by such
license, no part of this software or documentation may be
reproduced, stored in a retrieval system, or transmitted in any
form or by any means without the express written consent of
Intel Corporation.


  @file IioUniveralData.h

  Data format for Universal Data Structure

**/

#ifndef _IIO_UNIVERSAL_DATA_
#define _IIO_UNIVERSAL_DATA_

#define IIO_UNIVERSAL_DATA_GUID { 0x7FF396A1, 0xEE7D, 0x431E, 0xBA, 0x53, 0x8F, 0xCA, 0x12, 0x7C, 0x44, 0xC0 }
#include "SysHost.h"
#include "UncoreCommonIncludes.h"
#include <Guid/SocketVariable.h>

//--------------------------------------------------------------------------------------//
// Structure definitions for Universal Data Store (UDS)
//--------------------------------------------------------------------------------------//
#define UINT64  unsigned long long

#pragma pack(1)


typedef struct {
  UINT8                     Valid;         // TRUE, if the link is valid (i.e reached normal operation)
  UINT8                     PeerSocId;     // Socket ID
  UINT8                     PeerSocType;   // Socket Type (0 - CPU; 1 - IIO)
  UINT8                     PeerPort;      // Port of the peer socket
}QPI_PEER_DATA;

typedef struct {
  UINT8                     Valid;
  UINT8                     SocketFirstBus;
  UINT8                     SocketLastBus;
  UINT8                     segmentSocket;
  UINT8                     PcieSegment;
  UINT64_STRUCT             SegMmcfgBase;
  UINT8                     stackPresentBitmap;
  UINT8                     StackBus[MAX_IIO_STACK];
  UINT8                     M2PciePresentBitmap;
  UINT8                     TotM3Kti;   
  UINT8                     TotCha;
  UINT32                    ChaList;
  UINT32                    SocId;
  QPI_PEER_DATA             PeerInfo[MAX_KTI_PORTS];    // QPI LEP info
} QPI_CPU_DATA;

typedef struct {
  UINT8                     Valid;
  UINT8                     SocId;
  QPI_PEER_DATA             PeerInfo[MAX_SOCKET];    // QPI LEP info
} QPI_IIO_DATA;

typedef struct {
    IIO_PORT_INFO           PortInfo[NUMBER_PORTS_PER_SOCKET];
} IIO_DMI_PCIE_INFO;

typedef struct _STACK_RES {
  UINT8                   Personality;
  UINT8                   BusBase;
  UINT8                   BusLimit;
  UINT16                  PciResourceIoBase;
  UINT16                  PciResourceIoLimit;
  UINT32                  IoApicBase;
  UINT32                  IoApicLimit;
  UINT32                  PciResourceMem32Base;
  UINT32                  PciResourceMem32Limit;
  UINT64                  PciResourceMem64Base;
  UINT64                  PciResourceMem64Limit;
  UINT32                  VtdBarAddress;
} STACK_RES;

typedef struct {
    UINT8                   Valid;
    UINT8                   SocketID;            // Socket ID of the IIO (0..3)
    UINT8                   BusBase;
    UINT8                   BusLimit;
    UINT16                  PciResourceIoBase;
    UINT16                  PciResourceIoLimit;
    UINT32                  IoApicBase;
    UINT32                  IoApicLimit;
    UINT32                  PciResourceMem32Base;
    UINT32                  PciResourceMem32Limit;
    UINT64                  PciResourceMem64Base;
    UINT64                  PciResourceMem64Limit;
    STACK_RES               StackRes[MAX_IIO_STACK];
    UINT32                  RcBaseAddress;
    IIO_DMI_PCIE_INFO       PcieInfo;
    UINT8                   DmaDeviceCount;
} IIO_RESOURCE_INSTANCE;

typedef struct {
    UINT16                  PlatGlobalIoBase;       // Global IO Base
    UINT16                  PlatGlobalIoLimit;      // Global IO Limit
    UINT32                  PlatGlobalMmiolBase;    // Global Mmiol base
    UINT32                  PlatGlobalMmiolLimit;   // Global Mmiol limit
    UINT64                  PlatGlobalMmiohBase;    // Global Mmioh Base [43:0]
    UINT64                  PlatGlobalMmiohLimit;   // Global Mmioh Limit [43:0]
    QPI_CPU_DATA            CpuQpiInfo[MAX_SOCKET]; // QPI related info per CPU
    QPI_IIO_DATA            IioQpiInfo[MAX_SOCKET]; // QPI related info per IIO
    UINT32                  MemTsegSize;
    UINT32                  MemIedSize;
    UINT64                  PciExpressBase;
    UINT32                  PciExpressSize;
    UINT32                  MemTolm;
    IIO_RESOURCE_INSTANCE   IIO_resource[MAX_SOCKET];
    UINT8                   numofIIO;
    UINT8                   MaxBusNumber;
    UINT32                  packageBspApicID[MAX_SOCKET]; // This data array is valid only for SBSP, not for non-SBSP CPUs. <AS> for CpuSv
    UINT8                   MaxCoreToBusRatio[MAX_SOCKET]; // Package Max Non-turbo Ratio (per socket).
    UINT8                   MinCoreToBusRatio[MAX_SOCKET]; // Package Maximum Efficiency Ratio (per socket).
    UINT8                   EVMode;
    UINT8                   Pci64BitResourceAllocation;
    UINT8                   SkuPersonality[MAX_SOCKET];
    UINT8                   VMDStackEnable[MaxIIO][MAX_IIO_STACK];
    UINT16                  IoGranularity;
    UINT32                  MmiolGranularity;
    UINT64_STRUCT           MmiohGranularity;
    UINT8                   RemoteRequestThreshold;
} PLATFORM_DATA;

typedef struct {
    UINT8                   CurrentCsiLinkSpeed;// Current programmed CSI Link speed (Slow/Full speed mode)
    UINT8                   CurrentCsiLinkFrequency; // Current requested CSI Link frequency (in GT)
    UINT32                  OutKtiPerLinkL1En[MAX_SOCKET];    // output kti link enabled status for PM 
    UINT8                   IsocEnable;
    UINT32                  meRequestedSize; // Size of the memory range requested by ME FW, in MB
    UINT8                   DmiVc1;
    UINT8                   DmiVcm;
    UINT32                  CpuPCPSInfo;
    UINT8                   MinimumCpuStepping;
    UINT8                   LtsxEnable;
    UINT8                   MctpEn;
    UINT8                   cpuType;
    UINT8                   cpuSubType;
    UINT8                   SystemRasType;
    UINT8                   numCpus;                // 1,..4. Total number of CPU packages installed and detected (1..4)by QPI RC
    UINT32                  socketPresentBitMap;    // bitmap of sockets with CPUs present detected by QPI RC
    UINT32                  FpgaPresentBitMap;      // bitmap of NID w/ fpga  present detected by QPI RC
    UINT16                  tolmLimit;
    UINT32                  tohmLimit;
    UINT32                  mmCfgBase;
    UINT32                  RcVersion;
    UINT8                   DdrXoverMode;           // DDR 2.2 Mode
    // For RAS
    UINT8                   bootMode;
    UINT8                   OutClusterOnDieEn; // Whether RC enabled COD support
    UINT8                   OutSncEn;
    UINT8                   OutNumOfCluster;
    UINT8                   imcEnabled[MAX_SOCKET][MAX_IMC];
    UINT8                   numChPerMC;
    UINT8                   maxCh;
    UINT8                   maxIMC;
    UINT16                  LlcSizeReg;
    UINT8                   chEnabled[MAX_SOCKET][MAX_CH];
    UINT8                   mcId[MAX_SOCKET][MAX_CH];
    UINT8                   memNode[MC_MAX_NODE];
    UINT8                   IoDcMode;
    UINT8                   CpuAccSupport;
	UINT8                   SmbusErrorRecovery;
} SYSTEM_STATUS;

typedef struct {
    PLATFORM_DATA           PlatformData;
    SYSTEM_STATUS           SystemStatus;
    UINT32                  OemValue;
} IIO_UDS;
#pragma pack()

#endif
