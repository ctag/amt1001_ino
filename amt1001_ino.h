/*
 * AMT1001_INO
 * 
 * copyright (c) Davide Gironi, 2013
 * Modified for sketch use by Christopher Bero, 2015
 *
 * Released under GPLv3.
 * Please refer to LICENSE file for licensing information.
 */

#ifndef AMT1001_H_
#define AMT1001_H_

#include <Arduino.h>

//define min and max valid voltage to measure humidity
#define AMT1001_HUMIDITYVMIN 0.0
#define AMT1001_HUMIDITYVMAX 3.0

//slope factor to calculate humidity
#define AMT1001_HUMIDITYSLOPE 33.33

//define min and max valid adc to measure temperature
#define AMT1001_TEMPERATUREVMIN 0.0
#define AMT1001_TEMPERATUREVMAX 0.8

//slope factor to calculate temperature
#define AMT1001_TEMPERATURESLOPE 100.0

//define lookup method variables for temperature
#define amt1001_lookupadcfirst 1 //adc first value of lookup table
#define amt1001_lookupadcstep 10 //step between every table point
#define amt1001_lookuptablesize 103 //size of the lookup table
const float PROGMEM amt1001_lookuptable[amt1001_lookuptablesize] = {
		-86.99 , -59.05 , -49.91 , -43.96 , -39.45 , -35.76 , -32.61 , -29.84 , -27.37 , -25.11 , -23.03 , -21.1 , -19.29 , -17.58 , -15.95 , -14.41 , -12.92 , -11.5 , -10.12 , -8.79 , -7.5 , -6.25 , -5.03 , -3.83 , -2.66 , -1.52 , -0.4 , 0.71 , 1.8 , 2.87 , 3.93 , 4.97 , 6.01 , 7.03 , 8.05 , 9.05 , 10.06 , 11.05 , 12.04 , 13.03 , 14.02 , 15 , 15.98 , 16.96 , 17.95 , 18.93 , 19.92 , 20.9 , 21.9 , 22.89 , 23.89 , 24.9 , 25.91 , 26.93 , 27.96 , 29 , 30.05 , 31.11 , 32.19 , 33.27 , 34.37 , 35.49 , 36.63 , 37.78 , 38.95 , 40.14 , 41.36 , 42.6 , 43.87 , 45.17 , 46.5 , 47.86 , 49.26 , 50.7 , 52.18 , 53.71 , 55.29 , 56.92 , 58.62 , 60.38 , 62.22 , 64.14 , 66.15 , 68.26 , 70.49 , 72.84 , 75.34 , 78.01 , 80.87 , 83.95 , 87.3 , 90.96 , 95 , 99.52 , 104.62 , 110.48 , 117.36 , 125.67 , 136.09 , 149.94 , 170.2 , 206.11 , 330.42
};

//functions
int16_t amt1001_gethumidity(double voltage);
int16_t amt1001_gettemperature(uint16_t adcvalue);

#endif
