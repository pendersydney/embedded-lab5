#include <msp430.h> 

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;         // Stop watchdog timer
  
    P1DIR |= BIT6;             
    P1OUT = 0x00;                     // Sets initial output to 0x00
    P1SEL |= BIT6;                    // Sets red LED
  
    TACCR0 = 62500-1;                 // Sets to 62499
    TACCTL1 = OUTMOD_7;               // Sets mode 7 for output signal
    TACCR1 = 6250-1;                  // PWM Duty Cycle 10%
    TACTL = TASSEL_2 + MC_1 + ID_3;   // SMCLK and Up Mode

     while(1){
         P1OUT ^= BIT6;                // Red LED toggle
     }
}
