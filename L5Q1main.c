#include <msp430.h> 
#define RedLED BIT6 
#define GreenLED BIT0
#define ToggleLeds (P1OUT ^= RedLED|GreenLED)
#define Button BIT3


void main(void)
{
    BCSCTL2 |= DIVS_3;           // Clock frequency/8 
    WDTCTL = WDT_MDLY_32;        // Clock frequency/32465
    IE1 |= WDTIE;
    P1DIR = 0x41;                // Sets to red or green LED
    P1OUT = 0x40;                // Sets initial output as red LED
    _enable_interrupts();        // Enables interrupt

    LPM1;                        // Low power mode
}
#pragma vector = WDT_VECTOR
__interrupt void WDT(void)
    {
     P1OUT = ToggleLeds;          // Outputs alternate between green and red LEDs
        }
