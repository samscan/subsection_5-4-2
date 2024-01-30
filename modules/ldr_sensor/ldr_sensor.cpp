//=====[Libraries]=============================================================

#include "mbed.h"

#include "ldr_sensor.h"

#include "smart_home_system.h"

//=====[Declaration of private defines]========================================

#define LDR_NUMBER_OF_AVG_SAMPLES    10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn ldrSensor(A3);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============


float ldrSensorReadingsArray[LDR_NUMBER_OF_AVG_SAMPLES];

//=====[Declarations (prototypes) of private functions]========================
static bool entrywayLightState(float ldrReadingsAverage);

//=====[Implementations of public functions]===================================

void ldrSensorInit()
{
    int i;
    
    for( i=0; i<LDR_NUMBER_OF_AVG_SAMPLES ; i++ ) {
        ldrSensorReadingsArray[i] = 0;
    }
}

bool ldrSensorUpdate()
{
    static int ldrSampleIndex = 0;
    float ldrReadingsSum = 0.0;
    float ldrReadingsAverage = 0.0;

    int i = 0;

    ldrSensorReadingsArray[ldrSampleIndex] = ldrSensor.read();
       ldrSampleIndex++;
    if ( ldrSampleIndex >= LDR_NUMBER_OF_AVG_SAMPLES) {
        ldrSampleIndex = 0;
    }
    
   ldrReadingsSum = 0.0;
    for (i = 0; i < LDR_NUMBER_OF_AVG_SAMPLES; i++) {
        ldrReadingsSum = ldrReadingsSum + ldrSensorReadingsArray[i];
    }
    ldrReadingsAverage = ldrReadingsSum / LDR_NUMBER_OF_AVG_SAMPLES;
    return entrywayLightState(ldrReadingsAverage);
}

bool entrywayLightState(float ldrReadingsAverage)
{
    if (ldrReadingsAverage >= 0.7) {
        return false;
    }
    return true;
}