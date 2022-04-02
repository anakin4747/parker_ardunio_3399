#include <math.h>
int analogPin = A0; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read
double temp;
double volt;
double resist;

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  float val = analogRead(analogPin);  // read the input pin
  volt = val *  5.0 / 1024.0 ;
  resist = ((5.00 / volt) - 1.00) ;
  temp = 3455.00 / (11.588 + log(resist));
  temp = temp - 273.15;

  Serial.print("The temperature is ");
  Serial.print(temp);    
  Serial.println(" degrees Celcius.");
  delay(4000);
}
