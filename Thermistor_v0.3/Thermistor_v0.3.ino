#include <math.h>
int temp1Pin = A0; //Temp1 node              
int temp2Pin = A1; 

// outside leads to ground and +5V

float Vout = 0;  // variable to store the value read
double temp;
double resist;

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  float v1 = analogRead(temp1Pin);  // read the input pin    
  float v2 = analogRead(temp2Pin);  
  v1 = v1 *  5.0 / 1023.0 ;
  v2 = v2 *  5.0 / 1023.0 ;
  Vout = v1 - v2;

  resist = (10000/((Vout/5.0000) + 0.5)) - 10000;

  
  //temp = 3455.00 / (11.588 + log(resist));
  temp = 1 / ((log(resist/10000.000)/3428) + (1/298.15));
  
  temp = temp - 273.15;
  

  Serial.print("\nV1 is ");
  Serial.print(v1);
  Serial.print("\nV2 is ");
  Serial.print(v2);
  Serial.print("\nVout is ");
  Serial.print(Vout);
  Serial.print("\nResistance is ");
  Serial.print(resist);
  Serial.print("\nTemp is ");
  Serial.print(temp);
  delay(2000);


  
}
