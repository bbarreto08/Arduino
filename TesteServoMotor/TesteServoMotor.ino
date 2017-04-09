/*
 * Inclusão de blibiotecas
 */

// Biblioteca bluthu para comunicação
#include  <SoftwareSerial.h>
// Biblioteca para o controle de rotação dos motores
#include <Servo.h>

SoftwareSerial serial1(8, 7); // RX , TX
int pinPortas[8] = {2,3,4,5,6,7,8,9}; 

Servo servoEsq;  // create servo object to control a servo
Servo servoDir;  // create servo object to control a servo

void setup() {
  // put your setup code here, to run once:
  serial1.begin(9600);
  Serial.begin(9600);

  servoEsq.attach(12);  // attaches the servo on pin 9 to the servo object
  servoDir.attach(13);  // attaches the servo on pin 9 to the servo object
  
  for (int np=0; np < 8; np++) {
    pinMode(pinPortas[np], OUTPUT);

    byte byteEnviar = np + 1; // 
    byteEnviar = bitSet(bitSet(byteEnviar, 6), 5);
    serial1.println(byteEnviar);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (serial1.available()) {
    char byteRecebido = (char)serial1.read();

    Serial.println(byteRecebido);  

      if (byteRecebido = 'F') {
          servoEsq.write(180);              
          servoDir.write(-180); 
      }
            
      if (byteRecebido = 'T') {
          servoEsq.write(-180);              
          servoDir.write(180);  
      }      
    }      
}
