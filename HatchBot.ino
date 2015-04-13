/*
*
*  HatchBot v0.02a 17/03/2015
*  for New Zealand DOC Kākāpō Recovery program
*  by David McGahan
*  HatchBot v0.03a 12/04/2015
*  for the New Zealand Department of Conservation 
*  Kākāpō Recovery program
*  David McGahan
*  @dizymac
*
*  For more information on Kākāpō please see below:
*  http://en.wikipedia.org/wiki/Kakapo
*
*  This work is licensed under the Creative Commons 
*  Attribution-NonCommercial-ShareAlike 4.0 International License. 
*  To view a copy of this license, visit 
*  http://creativecommons.org/licenses/by-nc-sa/4.0/.
*
*
*
*/

// constants
const int speaker = 8;

//variables
int randNumber;
int chirpCount;
int i = 0;
#include <LowPower.h>
const int speakerPin = 8;
const int motorPin = 9;

void setup() {
  pinMode(motorPin, OUTPUT);
}
void loop() {
  randNumber = random(4000, 8000);
  chirpCount = random(5);
  int randNumber = random(8000); // Define random variable time. in this case, 10 minutes or 600000ms is required.
  int chirpCount = random(5); // Define a random number of times to chirp.
  int i = 0;
  while (i < chirpCount){
    i++;
    chirp();
    delay(randNumber);
    delay(random(4000)); // Allow a random and non-uniform time between chirps.
  }
  delay(randNumber);    
  for (byte motorSpeed = 0; 
    motorSpeed <= 255; 
    motorSpeed +=5 
    ) // DC motor PWM control 0 - 255
    {
      analogWrite(motorPin, motorSpeed);
      delay(500);
    }
  delay(randNumber);
  // LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_OFF, TWI_OFF); // Power down mode to preserve battery until next loop starts up.
}

// Below is from Adafruit, to be replaced by WAV recordings of the Kakapo egg.
void chirp() {  // Bird chirp
  for(uint8_t i=200; i>180; i--)
     playTone(i,9);
}
void playTone(uint16_t tone1, uint16_t duration) {
  if(tone1 < 50 || tone1 > 15000) return;  // these do not play on a piezo
  for (long i = 0; i < duration * 1000L; i += tone1 * 2) {
     digitalWrite(speakerPin, HIGH);
     delayMicroseconds(tone1);
     digitalWrite(speakerPin, LOW);
     delayMicroseconds(tone1);
  }     
}
void scale() {
  for(uint16_t i=50; i<15000; i++)  {
     playTone(i,20);
  }
}
