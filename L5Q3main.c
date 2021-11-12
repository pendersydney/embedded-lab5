#include <msp430.h> 

void main(void) {
  
	WDTCTL = WDTPW + WDTHOLD;	                // Stop watchdog timer
	
	P1DIR |= BIT6;                            // Sets Port 1.6 to output
	TA0CTL = TASSEL_2 + MC_1 + ID_3;          // Sets SMCLK and Up Mode
	                                        
	TA0CCR0 = 31250-1;                        // Set to max count 
	TA0CCR1 = 6250;                           // Initialize counter 

	TA0CCTL0 |= CCIE;                         // Enables capture/compare interrupt 
	TA0CCTL1 |= CCIE;                         // Enables capture/compare interrupt 

	TA0CCTL0 &=~CCIFG;                        // Sets capture/compare flag to NOT
	TA0CCTL1 &=~CCIFG;                        // Sets capture/compare flag to NOT

	_enable_interrupts(); 
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void TA0_ISR(void) {    

    P1OUT |= BIT6;                           // Enables red LED
    TA0CCTL0 &=~CCIFG;                       // Resets
}

#pragma vector = TIMER0_A1_VECTOR     
__interrupt void TA1_ISR (void) {   
  
    P1OUT &=~BIT6;                           // Disables LED
    TA0CCTL1 &=~CCIFG;                       // Resets
}
