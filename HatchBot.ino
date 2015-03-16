/*
*
*  HatchBot v0.02a 17/03/2015
*  for New Zealand DOC Kākāpō Recovery program
*  by David McGahan
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
*/

// constants
const int speaker = 8;

//variables
int randNumber;
int chirpCount;
int i = 0;

void setup() {
}
void loop() {
  randNumber = random(4000, 8000);
  chirpCount = random(5);
  int i = 0;
  while (i < chirpCount){
    i++;
    chirp();
    delay(randNumber);
  }
  delay(randNumber);    
}
void chirp() {  // Bird chirp
  for(uint8_t i=200; i>180; i--)
     playTone(i,9);
}
void playTone(uint16_t tone1, uint16_t duration) {
  if(tone1 < 50 || tone1 > 15000) return;  // these do not play on a piezo
  for (long i = 0; i < duration * 1000L; i += tone1 * 2) {
     digitalWrite(speaker, HIGH);
     delayMicroseconds(tone1);
     digitalWrite(speaker, LOW);
     delayMicroseconds(tone1);
  }     
}
void scale() {
  for(uint16_t i=50; i<15000; i++)  {
     playTone(i,20);
  }
}
