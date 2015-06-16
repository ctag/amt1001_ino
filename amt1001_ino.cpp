/*
 * AMT1001_INO
 * 
 * copyright (c) Davide Gironi, 2013
 * Modified for sketch use by Christopher Bero, 2015
 * 
 * Released under GPLv3.
 * Please refer to LICENSE file for licensing information.
 */

#include "amt1001_ino.h"

/*
 * get humidity based on read voltage
 */
int16_t amt1001_gethumidity(double voltage) {
	if(voltage > AMT1001_HUMIDITYVMIN && voltage < AMT1001_HUMIDITYVMAX)
		return (int16_t)(AMT1001_HUMIDITYSLOPE*voltage);
	else
		return -1;
}

/*
 * get temperature based on read voltage
 */
int16_t amt1001_gettemperature(uint16_t adcvalue) {
	float t = 0.0;
	float mint = 0;
	float maxt = 0;

	//return error for invalid adcvalues
	if(adcvalue<amt1001_lookupadcfirst || adcvalue>amt1001_lookupadcfirst+amt1001_lookupadcstep*(amt1001_lookuptablesize-1)) {
		return -1;
	}

	uint8_t i = 0;
	uint16_t a = amt1001_lookupadcfirst;
	for(i=0; i<amt1001_lookuptablesize; i++) {
		if(adcvalue < a)
			break;
		a += amt1001_lookupadcstep;
	}

	maxt = pgm_read_float(&amt1001_lookuptable[i]); //highest interval value
	if(i==0)
		mint = maxt;
	else
		mint = pgm_read_float(&amt1001_lookuptable[i-1]); //smallest interval value

	//do interpolation
	a = a-amt1001_lookupadcstep;
	t = mint + ((maxt-mint)/amt1001_lookupadcstep) * (adcvalue-a);

	return t;

}
