#include <math.h>
int temp1Pin = A0; //Temp1 node              
int temp2Pin = A1; 

// outside leads to ground and +5V

int Vout = 0;  // variable to store the value read
double temp;
double volt;
double resist;

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  float v1 = analogRead(temp1Pin);  // read the input pin    
  float v2 = analogRead(temp2Pin);  
  v1 = v1 *  5.0 / 1024.0 ;
  v2 = v2 *  5.0 / 1024.0 ;
  Vout = v1 - v2;

  resist = (10000/(Vout/5.0000 + 0.5)) - 10000;

  Serial.print("\nVout is ");
  Serial.print(v1); 
  delay(2000);


  
}
