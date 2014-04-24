/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const byte ROW[] = { 8, 5, 10, 4, A3, 11, A5, A0 };
const byte COL[] = { A4, 6, 7, A1, 9, A2, 12, 13 };

// the setup routine runs once when you press reset:
void setup() {                

//  for (int i = 0; i < 8; ++i) {
//    pinMode(ROW[i], OUTPUT);
//    digitalWrite(ROW[i], LOW);
//  }
/*
  for (byte i = 0; i < 8; ++i) {
    pinMode(COL[i], OUTPUT);
    digitalWrite(COL[i], LOW);
  }
*/
}



void scan(const byte aScreen[8], const int aDelay = 1000) {
  
static const unsigned D = 50;

  const unsigned long time = millis(); 

  while (millis() - time < aDelay) {

    for (char i = 7; i >= 0; --i) {
  
      byte mask = 0b01;
  
      byte n = 0;  // compteur de leds allumées
      for (byte j = 0; j < 8; ++j) {
        if (aScreen[i] & mask) {
          pinMode(ROW[j], OUTPUT);
          ++n;
        } else {
          pinMode(ROW[j], INPUT);
        }
        mask *= 2;
      }
  
      pinMode(COL[i], OUTPUT);
      digitalWrite(COL[i], HIGH);
      delayMicroseconds(n > 4 ? 2 * D : D);
      digitalWrite(COL[i], LOW);
      pinMode(COL[i], INPUT);
    }


  }
}


void loop() {
  const byte A[] = {0x3F, 0x48, 0x88, 0x48, 0x3F}; 
  const byte M[] = {0xFF, 0x40, 0x20, 0x40, 0xFF}; 
  const byte S[] = {0x64, 0x92, 0x92, 0x92, 0x4C}; 
  const byte o[] = {0x1C, 0x22, 0x22, 0x22, 0x1C}; 
  const byte l[] = {0x00, 0x82, 0xFE, 0x02, 0x00}; 

#if 0
  scan(S, 1000);
  for (byte i = 0; i < 15 ; ++i) {
      scan(A, i);
      scan(S, 14 - i);
  }
  scan(A, 1000);
  for (byte i = 0; i < 15 ; ++i) {
      scan(A, 14 - i);
      scan(S, i);
  }

#elif 1

  byte E[50];
  for (byte i = 0 ; i < 50; ++i) E[i] = 0;

  for (byte i = 0; i < 6; ++i) {
    E[i+8] = i < 5 ? S[i] : 0;
    E[i+14] = i < 5 ? o[i] : 0;
    E[i+20] = i < 5 ? l[i] : 0;
  }


  const byte L = 20;
  for (byte i = 0; i < 24; ++i) {
#if 1
    for (byte j = 0 ; j < 10; ++j) {
      scan(E + i, 10-j);
      scan(E + i + 1, j);
    }
#endif
    scan(E + i + 1, 20);
    
  }
  delay(5000);

#endif
}
