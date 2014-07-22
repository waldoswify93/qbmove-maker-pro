// -----------------------------------------------------------------------------
// Copyright (C)  qbrobotics. All rights reserved.
// www.qbrobotics.com
// -----------------------------------------------------------------------------

/** 
* \file 		utils.h
*
* \brief 		Declaration of utility functions.
* \date 		Feb 16, 2014
* \author 		qbrobotics
* \copyright	(C)  qbrobotics. All rights reserved.
*/


#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <globals.h>

//-------------------------------------------------------------     DECLARATIONS

int32 filter_i1(int32 value);
int32 filter_i2(int32 value);

uint8 BITChecksum(uint32);
uint8 LCRChecksum(uint8 *data_array, uint8 data_length);

#endif

/* [] END OF FILE */