/*
 * num_set_bits.c
 *
 *  Created on: Apr 12, 2016
 *      Author: wenda
 */


#include <stdio.h>
#include <stdint.h>

#define BIT_SHIFT   4
const static int bits_num[256] = {
        0,  // 0
        1,  // 1
        1,  // 2
        2,
        1,  // 4
        2,
        2,
        3,
        1,  // 8
        2,
        2,  // 10
        3,
        2,
        3,
        3,  // 14
        4,

        [ 1 << BIT_SHIFT] = 1,
        [ 2 << BIT_SHIFT] = 1,
        [ 3 << BIT_SHIFT] = 2,
        [ 4 << BIT_SHIFT] = 1,
        [ 5 << BIT_SHIFT] = 2,
        [ 6 << BIT_SHIFT] = 2,
        [ 7 << BIT_SHIFT] = 3,
        [ 8 << BIT_SHIFT] = 1,
        [ 9 << BIT_SHIFT] = 2,
        [10 << BIT_SHIFT] = 2,
        [11 << BIT_SHIFT] = 3,
        [12 << BIT_SHIFT] = 2,
        [13 << BIT_SHIFT] = 3,
        [14 << BIT_SHIFT] = 3,
        [15 << BIT_SHIFT] = 4
};

int bits_speed(unsigned char v)
{
    return bits_num[v & 0x0f] + bits_num[v & 0xf0];
}


int set_bits_count(unsigned char v)
{
    int cnt = 0;

    while (v) {
        cnt++;

        v &= v - 1;
    }

    return cnt;
}
