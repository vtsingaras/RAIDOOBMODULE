//**********************************************************************
//**********************************************************************
//**                                                                  **
//**        (C)Copyright 1985-2016, American Megatrends, Inc.         **
//**                                                                  **
//**                       All Rights Reserved.                       **
//**                                                                  **
//**      5555 Oakbrook Parkway, Suite 200, Norcross, GA 30093        **
//**                                                                  **
//**                       Phone: (770)-246-8600                      **
//**                                                                  **
//**********************************************************************
//**********************************************************************

/** @file PlatformVideoInit.h
    Definitions used by PlatformVideoInit.

**/

#ifndef _PEI_VIDEO_INIT_H__
#define _PEI_VIDEO_INIT_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------

#include <Token.h>
#include <AmiPeiLib.h>
#include <Library/PrintLib.h>
#include <Library/DebugLib.h>
#include <Library/PlatformHooksLib.h>
#include <FastVideo.h>
//---------------------------------------------------------------------------

//Purley Porting
#if PLATFORM_TYPE == 0 //Platform is Neon City
DEV_PATH mVideoVidPath [] = {
		{0x0,0x1C,0x5},		//PCIe-PCI bridge
		{0x1,0x00,0x0},		//Video Bridge
		{0x2,0x00,0x0} 		//Video Controller
};
#else			//Platform is Lightning Ridge
DEV_PATH mVideoVidPath [] = {
		{0x0,0x1D,0x3},		//PCIe-PCI bridge
		{0x1,0x00,0x0},		//Video Bridge
		{0x2,0x00,0x0} 		//Video Controller
};
#endif


DEV_PATH mSimulatedVideoVidPath [] = {
		{0x0,0x0F,0x0}      //Simics Video Controller
};

UINT8 mVideoFontData[] = {
//0x20, ' '
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//0x21, '!'
0x00, 0x00, 0x18, 0x3c, 0x3c, 0x3c, 0x18, 0x18,
0x18, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
//0x22, '"'
0x00, 0x66, 0x66, 0x66, 0x24, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//0x23, '#'
0x00, 0x00, 0x00, 0x6c, 0x6c, 0xfe, 0x6c, 0x6c,
0x6c, 0xfe, 0x6c, 0x6c, 0x00, 0x00, 0x00, 0x00,
//0x24, '$'
0x18, 0x18, 0x7c, 0xc6, 0xc2, 0xc0, 0x7c, 0x06,
0x06, 0x86, 0xc6, 0x7c, 0x18, 0x18, 0x00, 0x00,
//0x25, '%'
0x00, 0x00, 0x00, 0x00, 0xc2, 0xc6, 0x0c, 0x18,
0x30, 0x60, 0xc6, 0x86, 0x00, 0x00, 0x00, 0x00,
//0x26, '&'
0x00, 0x00, 0x38, 0x6c, 0x6c, 0x38, 0x76, 0xdc,
0xcc, 0xcc, 0xcc, 0x76, 0x00, 0x00, 0x00, 0x00,
//0x27, '''
0x00, 0x30, 0x30, 0x30, 0x60, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//0x28, '('
0x00, 0x00, 0x0c, 0x18, 0x30, 0x30, 0x30, 0x30,
0x30, 0x30, 0x18, 0x0c, 0x00, 0x00, 0x00, 0x00,
//0x29, ')'
0x00, 0x00, 0x30, 0x18, 0x0c, 0x0c, 0x0c, 0x0c,
0x0c, 0x0c, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00,
//0x2a, '*'
0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x3c, 0xff,
0x3c, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//0x2b, '+'
0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x7e,
0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//0x2c, ','
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x18, 0x18, 0x18, 0x30, 0x00, 0x00, 0x00,
//0x2d, '-'
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//0x2e, '.'
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
//0x2f, '/'
0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x0c, 0x18,
0x30, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
//0x30, '0'
0x00, 0x00, 0x3c, 0x66, 0xc3, 0xc3, 0xdb, 0xdb,
0xc3, 0xc3, 0x66, 0x3c, 0x00, 0x00, 0x00, 0x00,
//0x31, '1'
0x00, 0x00, 0x18, 0x38, 0x78, 0x18, 0x18, 0x18,
0x18, 0x18, 0x18, 0x7e, 0x00, 0x00, 0x00, 0x00,
//0x32, '2'
0x00, 0x00, 0x7c, 0xc6, 0x06, 0x0c, 0x18, 0x30,
0x60, 0xc0, 0xc6, 0xfe, 0x00, 0x00, 0x00, 0x00,
//0x33, '3'
0x00, 0x00, 0x7c, 0xc6, 0x06, 0x06, 0x3c, 0x06,
0x06, 0x06, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x34, '4'
0x00, 0x00, 0x0c, 0x1c, 0x3c, 0x6c, 0xcc, 0xfe,
0x0c, 0x0c, 0x0c, 0x1e, 0x00, 0x00, 0x00, 0x00,
//0x35, '5'
0x00, 0x00, 0xfe, 0xc0, 0xc0, 0xc0, 0xfc, 0x06,
0x06, 0x06, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x36, '6'
0x00, 0x00, 0x38, 0x60, 0xc0, 0xc0, 0xfc, 0xc6,
0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x37, '7'
0x00, 0x00, 0xfe, 0xc6, 0x06, 0x06, 0x0c, 0x18,
0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00,
//0x38, '8'
0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0x7c, 0xc6,
0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x39, '9'
0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0x7e, 0x06,
0x06, 0x06, 0x0c, 0x78, 0x00, 0x00, 0x00, 0x00,
//0x3a, ':'
0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00,
0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
//0x3b, ';'
0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00,
0x00, 0x18, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00,
//0x3c, '<'
0x00, 0x00, 0x00, 0x06, 0x0c, 0x18, 0x30, 0x60,
0x30, 0x18, 0x0c, 0x06, 0x00, 0x00, 0x00, 0x00,
//0x3d, '='
0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00,
0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//0x3e, '>'
0x00, 0x00, 0x00, 0x60, 0x30, 0x18, 0x0c, 0x06,
0x0c, 0x18, 0x30, 0x60, 0x00, 0x00, 0x00, 0x00,
//0x3f, '?'
0x00, 0x00, 0x7c, 0xc6, 0xc6, 0x0c, 0x18, 0x18,
0x18, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
//0x40, '@'
0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xde, 0xde,
0xde, 0xdc, 0xc0, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x41, 'A'
0x00, 0x00, 0x10, 0x38, 0x6c, 0xc6, 0xc6, 0xfe,
0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, 0x00, 0x00,
//0x42, 'B'
0x00, 0x00, 0xfc, 0x66, 0x66, 0x66, 0x7c, 0x66,
0x66, 0x66, 0x66, 0xfc, 0x00, 0x00, 0x00, 0x00,
//0x43, 'C'
0x00, 0x00, 0x3c, 0x66, 0xc2, 0xc0, 0xc0, 0xc0,
0xc0, 0xc2, 0x66, 0x3c, 0x00, 0x00, 0x00, 0x00,
//0x44, 'D'
0x00, 0x00, 0xf8, 0x6c, 0x66, 0x66, 0x66, 0x66,
0x66, 0x66, 0x6c, 0xf8, 0x00, 0x00, 0x00, 0x00,
//0x45, 'E'
0x00, 0x00, 0xfe, 0x66, 0x62, 0x68, 0x78, 0x68,
0x60, 0x62, 0x66, 0xfe, 0x00, 0x00, 0x00, 0x00,
//0x46, 'F'
0x00, 0x00, 0xfe, 0x66, 0x62, 0x68, 0x78, 0x68,
0x60, 0x60, 0x60, 0xf0, 0x00, 0x00, 0x00, 0x00,
//0x47, 'G'
0x00, 0x00, 0x3c, 0x66, 0xc2, 0xc0, 0xc0, 0xde,
0xc6, 0xc6, 0x66, 0x3a, 0x00, 0x00, 0x00, 0x00,
//0x48, 'H'
0x00, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xfe, 0xc6,
0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, 0x00, 0x00,
//0x49, 'I'
0x00, 0x00, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18,
0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00, 0x00,
//0x4a, 'J'
0x00, 0x00, 0x1e, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
0xcc, 0xcc, 0xcc, 0x78, 0x00, 0x00, 0x00, 0x00,
//0x4b, 'K'
0x00, 0x00, 0xe6, 0x66, 0x66, 0x6c, 0x78, 0x78,
0x6c, 0x66, 0x66, 0xe6, 0x00, 0x00, 0x00, 0x00,
//0x4c, 'L'
0x00, 0x00, 0xf0, 0x60, 0x60, 0x60, 0x60, 0x60,
0x60, 0x62, 0x66, 0xfe, 0x00, 0x00, 0x00, 0x00,
//0x4d, 'M'
0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xc3,
0xc3, 0xc3, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00,
//0x4e, 'N'
0x00, 0x00, 0xc6, 0xe6, 0xf6, 0xfe, 0xde, 0xce,
0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, 0x00, 0x00,
//0x4f, 'O'
0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6,
0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x50, 'P'
0x00, 0x00, 0xfc, 0x66, 0x66, 0x66, 0x7c, 0x60,
0x60, 0x60, 0x60, 0xf0, 0x00, 0x00, 0x00, 0x00,
//0x51, 'Q'
0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6,
0xc6, 0xd6, 0xde, 0x7c, 0x0c, 0x0e, 0x00, 0x00,
//0x52, 'R'
0x00, 0x00, 0xfc, 0x66, 0x66, 0x66, 0x7c, 0x6c,
0x66, 0x66, 0x66, 0xe6, 0x00, 0x00, 0x00, 0x00,
//0x53, 'S'
0x00, 0x00, 0x7c, 0xc6, 0xc6, 0x60, 0x38, 0x0c,
0x06, 0xc6, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x54, 'T'
0x00, 0x00, 0xff, 0xdb, 0x99, 0x18, 0x18, 0x18,
0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00, 0x00,
//0x55, 'U'
0x00, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6,
0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x56, 'V'
0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
0xc3, 0x66, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x00,
//0x57, 'W'
0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb,
0xdb, 0xff, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00,
//0x58, 'X'
0x00, 0x00, 0xc3, 0xc3, 0x66, 0x3c, 0x18, 0x18,
0x3c, 0x66, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00,
//0x59, 'Y'
0x00, 0x00, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18,
0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00, 0x00,
//0x5a, 'Z'
0x00, 0x00, 0xff, 0xc3, 0x86, 0x0c, 0x18, 0x30,
0x60, 0xc1, 0xc3, 0xff, 0x00, 0x00, 0x00, 0x00,
//0x5b, '['
0x00, 0x00, 0x3c, 0x30, 0x30, 0x30, 0x30, 0x30,
0x30, 0x30, 0x30, 0x3c, 0x00, 0x00, 0x00, 0x00,
//0x5c, '\'
0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x38,
0x1c, 0x0e, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00,
//0x5d, ']'
0x00, 0x00, 0x3c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
0x0c, 0x0c, 0x0c, 0x3c, 0x00, 0x00, 0x00, 0x00,
//0x5e, '^'
0x10, 0x38, 0x6c, 0xc6, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//0x5f, '_'
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
//0x60, '`'
0x30, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//0x61, 'a'
0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x0c, 0x7c,
0xcc, 0xcc, 0xcc, 0x76, 0x00, 0x00, 0x00, 0x00,
//0x62, 'b'
0x00, 0x00, 0xe0, 0x60, 0x60, 0x78, 0x6c, 0x66,
0x66, 0x66, 0x66, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x63, 'c'
0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc0,
0xc0, 0xc0, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x64, 'd'
0x00, 0x00, 0x1c, 0x0c, 0x0c, 0x3c, 0x6c, 0xcc,
0xcc, 0xcc, 0xcc, 0x76, 0x00, 0x00, 0x00, 0x00,
//0x65, 'e'
0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xfe,
0xc0, 0xc0, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x66, 'f'
0x00, 0x00, 0x38, 0x6c, 0x64, 0x60, 0xf0, 0x60,
0x60, 0x60, 0x60, 0xf0, 0x00, 0x00, 0x00, 0x00,
//0x67, 'g'
0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0xcc, 0xcc,
0xcc, 0xcc, 0xcc, 0x7c, 0x0c, 0xcc, 0x78, 0x00,
//0x68, 'h'
0x00, 0x00, 0xe0, 0x60, 0x60, 0x6c, 0x76, 0x66,
0x66, 0x66, 0x66, 0xe6, 0x00, 0x00, 0x00, 0x00,
//0x69, 'i'
0x00, 0x00, 0x18, 0x18, 0x00, 0x38, 0x18, 0x18,
0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00, 0x00,
//0x6a, 'j'
0x00, 0x00, 0x06, 0x06, 0x00, 0x0e, 0x06, 0x06,
0x06, 0x06, 0x06, 0x06, 0x66, 0x66, 0x3c, 0x00,
//0x6b, 'k'
0x00, 0x00, 0xe0, 0x60, 0x60, 0x66, 0x6c, 0x78,
0x78, 0x6c, 0x66, 0xe6, 0x00, 0x00, 0x00, 0x00,
//0x6c, 'l'
0x00, 0x00, 0x38, 0x18, 0x18, 0x18, 0x18, 0x18,
0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00, 0x00,
//0x6d, 'm'
0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0xff, 0xdb,
0xdb, 0xdb, 0xdb, 0xdb, 0x00, 0x00, 0x00, 0x00,
//0x6e, 'n'
0x00, 0x00, 0x00, 0x00, 0x00, 0xdc, 0x66, 0x66,
0x66, 0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00,
//0x6f, 'o'
0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc6,
0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x70, 'p'
0x00, 0x00, 0x00, 0x00, 0x00, 0xdc, 0x66, 0x66,
0x66, 0x66, 0x66, 0x7c, 0x60, 0x60, 0xf0, 0x00,
//0x71, 'q'
0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0xcc, 0xcc,
0xcc, 0xcc, 0xcc, 0x7c, 0x0c, 0x0c, 0x1e, 0x00,
//0x72, 'r'
0x00, 0x00, 0x00, 0x00, 0x00, 0xdc, 0x76, 0x66,
0x60, 0x60, 0x60, 0xf0, 0x00, 0x00, 0x00, 0x00,
//0x73, 's'
0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0x60,
0x38, 0x0c, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00,
//0x74, 't'
0x00, 0x00, 0x10, 0x30, 0x30, 0xfc, 0x30, 0x30,
0x30, 0x30, 0x36, 0x1c, 0x00, 0x00, 0x00, 0x00,
//0x75, 'u'
0x00, 0x00, 0x00, 0x00, 0x00, 0xcc, 0xcc, 0xcc,
0xcc, 0xcc, 0xcc, 0x76, 0x00, 0x00, 0x00, 0x00,
//0x76, 'v'
0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0xc3, 0xc3,
0xc3, 0x66, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x00,
//0x77, 'w'
0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0xc3, 0xc3,
0xdb, 0xdb, 0xff, 0x66, 0x00, 0x00, 0x00, 0x00,
//0x78, 'x'
0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0x66, 0x3c,
0x18, 0x3c, 0x66, 0xc3, 0x00, 0x00, 0x00, 0x00,
//0x79, 'y'
0x00, 0x00, 0x00, 0x00, 0x00, 0xc6, 0xc6, 0xc6,
0xc6, 0xc6, 0xc6, 0x7e, 0x06, 0x0c, 0xf8, 0x00,
//0x7a, 'z'
0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xcc, 0x18,
0x30, 0x60, 0xc6, 0xfe, 0x00, 0x00, 0x00, 0x00,
};

FONT_MAP_INFO mVideoFontMapInfo = {
    mVideoFontData,
    0x20, //start character ' ' (space)
    0x5b, //character count -- includes all characters from ' ' to 'z' (see below)
    0x10, //16-bits per character.
    0x00, //use the first font table.
};

/****** DO NOT WRITE BELOW THIS LINE *******/
#ifdef __cplusplus
}
#endif
#endif

//**********************************************************************
//**********************************************************************
//**                                                                  **
//**        (C)Copyright 1985-2016, American Megatrends, Inc.         **
//**                                                                  **
//**                       All Rights Reserved.                       **
//**                                                                  **
//**      5555 Oakbrook Parkway, Suite 200, Norcross, GA 30093        **
//**                                                                  **
//**                       Phone: (770)-246-8600                      **
//**                                                                  **
//**********************************************************************
//**********************************************************************