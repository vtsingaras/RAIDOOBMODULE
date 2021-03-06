//
// This file contains 'Framework Code' and is licensed as such
// under the terms of your license agreement with Intel or your
// vendor.  This file may not be modified, except as allowed by
// additional terms of your license agreement.
//
/** @file
  Unified Silicon Register Access (USRA) Ppi

  Copyright (c) 2011 - 2015, Intel Corporation. All rights reserved.<BR>
  This software and associated documentation (if any) is furnished
  under a license and may only be used or copied in accordance
  with the terms of the license. Except as permitted by such
  license, no part of this software or documentation may be
  reproduced, stored in a retrieval system, or transmitted in any
  form or by any means without the express written consent of
  Intel Corporation.
**/

#ifndef __SILICON_REG_ACCESS_PPI_H__
#define __SILICON_REG_ACCESS_PPI_H__

#include <UsraAccessType.h>

extern EFI_GUID gUsraPpiGuid;

/**
  This API Perform 8-bit, 16-bit, 32-bit or 64-bit silicon register read operations. 
  It transfers data from a register into a naturally aligned data buffer.
  
  @param[in] Address              A pointer of the address of the USRA Address Structure to be read out
  @param[in] Buffer               A pointer of buffer for the value read from the register

  @retval NULL                    The function completed successfully.
  @retval <>NULL                  Return Error
**/
typedef 
INTN
(EFIAPI *USRA_PPI_REG_READ)(
  IN USRA_ADDRESS             *Address,
  OUT VOID                    *Buffer
  );

/**
  This API Perform 8-bit, 16-bit, 32-bit or 64-bit silicon register write operations. 
  It transfers data from a naturally aligned data buffer into a silicon register.
  
  @param[in] Address              A pointer of the address of the USRA Address Structure to be written
  @param[in] Buffer               A pointer of buffer for the value write to the register

  @retval NULL                    The function completed successfully.
  @retval <>NULL                  Return Error
**/
typedef 
INTN
(EFIAPI *USRA_PPI_REG_WRITE)(
  IN USRA_ADDRESS             *Address,
  IN VOID                     *Buffer
  );

/**
  This API Perform 8-bit, 16-bit, 32-bit or 64-bit silicon register AND then OR operations. It read data from a
  register, And it with the AndBuffer, then Or it with the OrBuffer, and write the result back to the register
  
  @param[in] Address              A pointer of the address of the silicon register to be written
  @param[in] AndBuffer            A pointer of buffer for the value used for AND operation
                                  A NULL pointer means no AND operation. RegisterModify() equivalents to RegisterOr()
  @param[in] OrBuffer             A pointer of buffer for the value used for OR operation
                                  A NULL pointer means no OR operation. RegisterModify() equivalents to RegisterAnd()

  @retval NULL                    The function completed successfully.
  @retval <>NULL                  Return Error
**/
typedef
INTN
(EFIAPI *USRA_PPI_REG_MODIFY)(
  IN USRA_ADDRESS             *Address,
  IN VOID                     *AndBuffer,
  IN VOID                     *OrBuffer
  );

/**
  This API get the flat address from the given USRA Address.
  
  @param[in] Address              A pointer of the address of the USRA Address Structure to be read out

  @retval                         The flat address
**/
typedef
INTN
(EFIAPI *USRA_PPI_GET_ADDR)(
  IN USRA_ADDRESS              *Address
  );

///
/// This service abstracts the ability to read/write silicon register.
///
typedef struct {
  USRA_PPI_REG_READ            RegRead;
  USRA_PPI_REG_WRITE           RegWrite;

  USRA_PPI_REG_MODIFY          RegModify;
  USRA_PPI_GET_ADDR            GetRegAddr;
} USRA_PPI;

/**
  This API Perform 8-bit, 16-bit, 32-bit or 64-bit silicon register read operations. 
  It transfers data from a register into a naturally aligned data buffer.
  
  @param[in] Address              A pointer of the address of the USRA Address Structure to be read out
  @param[in] Buffer               A pointer of buffer for the value read from the register

  @retval NULL                    The function completed successfully.
  @retval <>NULL                  Return Error
**/
INTN
EFIAPI
PeiRegRead (
  IN USRA_ADDRESS             *Address,
  IN VOID                     *Buffer
  );

/**
  This API Perform 8-bit, 16-bit, 32-bit or 64-bit silicon register write operations. 
  It transfers data from a naturally aligned data buffer into a silicon register.
  
  @param[in] Address              A pointer of the address of the USRA Address Structure to be written
  @param[in] Buffer               A pointer of buffer for the value write to the register

  @retval NULL                    The function completed successfully.
  @retval <>NULL                  Return Error
**/
INTN
EFIAPI
PeiRegWrite (
  IN USRA_ADDRESS             *Address,
  IN VOID                     *Buffer
  );

/**
  This API Perform 8-bit, 16-bit, 32-bit or 64-bit Pcie silicon register AND then OR operations. It read data from a
  register, And it with the AndBuffer, then Or it with the OrBuffer, and write the result back to the register
  
  @param[in] Address              A pointer of the address of the silicon register to be written
  @param[in] AndBuffer            A pointer of buffer for the value used for AND operation
                                  A NULL pointer means no AND operation. RegisterModify() equivalents to RegisterOr()
  @param[in] OrBuffer             A pointer of buffer for the value used for OR operation
                                  A NULL pointer means no OR operation. RegisterModify() equivalents to RegisterAnd()

  @retval NULL                    The function completed successfully.
  @retval <>NULL                  Return Error
**/
INTN
EFIAPI
PeiRegModify (
  IN USRA_ADDRESS             *Address,
  IN VOID                     *AndBuffer,
  IN VOID                     *OrBuffer
  );

/**
  This API get the flat address from the given USRA Address.
  
  @param[in] Address              A pointer of the address of the USRA Address Structure to be read out

  @retval                         The flat address
**/
INTN
EFIAPI
PeiGetRegAddr (
  IN USRA_ADDRESS             *Address
  );

#endif
