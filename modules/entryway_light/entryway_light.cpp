//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "entryway_light.h"

#include "ldr_sensor.h"

//=====[Declaration of private defines]========================================


//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut entrywayLight(LED2);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================


void entrywayLightInit()
{
    entrywayLight = OFF;
    ldrSensorInit();
}

void entrywayLightUpdate()
{
   entrywayLight = ldrSensorUpdate();
}