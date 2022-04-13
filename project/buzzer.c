#include <msp430.h>
#include "libtimer.h"
#include "buzzer.h"

void buzzer_init()
{
  //The timer A output "ta0.1" to p2.6 according to the table 21 from the data sheet:
  // P2SELZ.6, P2SELZ.7, and 2Sel.7 must be a zero P2Sel.6 must be 1 such that P2.6 direction must be output
  timerAUpmode(); //used to drive speaker

  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6; // enable output to speaker(P2.6)
  
}

void buzzer_set_period(short cycles)//buzer clock = 2MHz.period of 1k results in 2kHz tone
{
  CCR0 = cycles;
  CCR1 = cycles >> 1; //onehalf cycle
}
