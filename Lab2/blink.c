/*
 * blink.c
 *
 *  Created on: Oct 18, 2023
 *      Author: loay_negm
 */

//----------------------------------------------- Include Files ------------------------------------
#include "stdint.h"
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include <Pin.h>

//---------------------------------------------- Macros --------------------------------------------
#define DELAY_TIME 500

//---------------------------------------------- Variables -----------------------------------------
pin_t red_led ={
                .port=PORT_F,
                .pinNumber = PIN_1,
                .direction = PIN_OUT,
                .current = CURRENT_2MA,
                .pinType = PIN_STD,
};
pin_t blue_led ={
                .port=PORT_F,
                .pinNumber = PIN_2,
                .direction = PIN_OUT,
                .current = CURRENT_2MA,
                .pinType = PIN_STD,
};

//-------------------------------------- Function Decelerations ------------------------------------
void DelayMS(uint32_t delayValueMs);


void main(void){
    SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_2_5 );
    Pin_Init(&red_led);
    Pin_Init(&blue_led);
    Std_Return retVal = R_NOK;
    while(1){
     Pin_Write(&red_led, HIGH, &retVal);
     Pin_Toggle(&blue_led);
     DelayMS(500);
     Pin_Write(&red_led, LOW, &retVal);
     Pin_Toggle(&blue_led);
     DelayMS(500);
    }


}


void DelayMS(uint32_t delayValueMs){
    SysCtlDelay(((float)80000000.0 * (float)delayValueMs)/6000.0);
}
