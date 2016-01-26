// -----------------------------------------------------------------------------
// Copyright (C)  qbrobotics. All rights reserved.
// www.qbrobotics.com
// -----------------------------------------------------------------------------

/**
* \file         utils.h
*
* \brief        Definition of utility functions.
* \date         Feb 16, 2014
* \author       qbrobotics
* \copyright    (C)  qbrobotics. All rights reserved.
*/

#include <utils.h>
#include <math.h>

//--------------------------------------------------------------     DEFINITIONS

#define ALPHA 8     // current filters
#define BETA  300   // velocity filters

//==============================================================================
//                                                               CURRENT FILTERS
//==============================================================================

int32 filter_i1(int32 new_value) {

    static int32 old_value, aux;

    aux = (old_value * (1024 - ALPHA) + new_value * (ALPHA)) >> 10;

    old_value = aux;

    return aux;
}

int32 filter_i2(int32 new_value) {

    static int32 old_value, aux;

    aux = (old_value * (1024 - ALPHA) + new_value * (ALPHA)) >> 10;

    old_value = aux;

    return aux;
}

//==============================================================================
//                                                              VELOCITY FILTERS
//==============================================================================

int32 filter_vel_1(int32 new_value) {

    static int32 old_value, aux;

    aux = (old_value * (1024 - BETA) + new_value * (BETA)) / 1024;

    old_value = aux;

    return aux;
}

int32 filter_vel_2(int32 new_value) {

    static int32 old_value, aux;

    aux = (old_value * (1024 - BETA) + new_value * (BETA)) / 1024;

    old_value = aux;

    return aux;
}

int32 filter_vel_3(int32 new_value) {

    static int32 old_value, aux;

    aux = (old_value * (1024 - BETA) + new_value * (BETA)) / 1024;

    old_value = aux;

    return aux;
}

//==============================================================================
//                                                                COUNTERS RESET
//==============================================================================

void reset_counters()
{
    uint8 i;
    for(i = 0; i < sizeof(g_count); i++)
       ((uint16*) &g_count.activ)[i] = 0;
}


//==============================================================================
//                                                                CHECK ENC DATA
//==============================================================================

// Returns 1 if the encoder data is correct, 0 otherwise

uint8 check_enc_data(uint32 *value) {

    const uint8* p = (const uint8*)value;
    uint8 a = *p;

    a = a ^ *(++p);
    a = a ^ *(++p);
    a = a ^ *(++p);
    a = (a & 0x0F) ^ (a>>4);

    return (0x9669 >> a) & 0x01;
    //0x9669 is a bit vector representing the !(bitwise XOR) of 4bits
}


//==============================================================================
//                                                             CHECKSUM FUNCTION
//==============================================================================

// Performs a XOR byte by byte on the entire vector

uint8 LCRChecksum(uint8 *data_array, uint8 data_length) {
    static uint8 i;
    static uint8 checksum;

    checksum = 0x00;
    for(i = 0; i < data_length; i++)
    {
       checksum = checksum ^ data_array[i];
    }
    return checksum;
}

/* [] END OF FILE */