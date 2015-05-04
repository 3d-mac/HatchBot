/*
*
*  HatchBot v0.04a 27/04/2015
*  for the New Zealand Department of Conservation 
*  Kākāpō Recovery program
*  David McGahan
*  @dizymac
*
*  For more information on Kākāpō birds please see below:
*  http://en.wikipedia.org/wiki/Kakapo
*
*  This work is licensed under the Creative Commons 
*  Attribution-NonCommercial-ShareAlike 4.0 International License. 
*  To view a copy of this license, visit 
*  http://creativecommons.org/licenses/by-nc-sa/4.0/.
*
*
*/
#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <SPI.h>
#include <SD.h>
#include <LowPower.h>

#define SD_ChipSelectPin 10
#define motorPin 3

TMRpcm chirp;

void setup() {
  chirp.speakerPin = 9;
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {}
}
void loop() {
  int randNumber = random(8000); // Define random variable time. in this case, 10 minutes or 600000ms is required.
  int chirpCount = random(2); // Define a random number of times to chirp.
  int i = 0;
  while (i < chirpCount){
    i++;
    chirp.play("K2.WAV");
    delay(random(4000)); // Allow a random and non-uniform time between chirps.
  }
  motor();
  delay(randNumber);
  //LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_OFF, TWI_OFF); // Power down mode to preserve battery until next loop starts up.
}

void motor() {
  byte speed = 18;
  analogWrite(motorPin, speed);
  byte maxSpeed = random(30, 41);
    while (speed < maxSpeed) 
     { 
       analogWrite(motorPin, speed);
       {
         speed++;
         for (int i=8; i>6; i--){
           delay(1);
         }
       }
     }
     if (speed == maxSpeed) 
     { 
       analogWrite(motorPin, 0); 
       delay(random(500, 5000));
     }
}
