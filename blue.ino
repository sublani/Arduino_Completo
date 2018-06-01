// MODELOS PRUEBA

#include <Servo.h>

Servo servoMotor6;
Servo servoMotor9;
Servo servoMotor10;
Servo servoMotor11;

const int LED_IZQ=7;
const int LED_DER=8;
const int Servo_Motor_6=6;
const int Servo_Motor_9=9;
const int Servo_Motor_10=10;
const int Servo_Motor_11=11;

void setup()  
{
  // Monitor Serie
  Serial.begin(9600);

  // Led
  pinMode(LED_IZQ,OUTPUT);  
  pinMode(LED_DER,OUTPUT);

  // Servo Motor
  servoMotor6.attach(Servo_Motor_6);
  servoMotor9.attach(Servo_Motor_9);
  servoMotor10.attach(Servo_Motor_10);
  servoMotor11.attach(Servo_Motor_11);
}

void loop() 
{
  
  if (Serial.available())
  {
    char dato=Serial.read();
    char c;
    
    String estado = null;
    
    Serial.print("Dato recibido: ");
    Serial.println(dato);

    switch(dato){
      
      // LED_IZQ => ON
      case 'q':
        delay(30);
        digitalWrite(LED_IZQ, 1);
        Serial.println("Se enciende el LED_IZQ");
        break;
            
      // LED_IZQ => OFF
      case 'w':
        delay(30);
        digitalWrite(LED_IZQ, 0);
        Serial.println("Se apaga el LED_IZQ");
        break;

      // LED_DER => ON
      case 'e':
        delay(30);
        digitalWrite(LED_DER, 1);
        Serial.println("Se enciende el LED_DER");
        break;
            
      // LED_DER => OFF
      case 'r':
        delay(30);
        digitalWrite(LED_DER, 0);
        Serial.println("Se apaga el LED_DER");
        break;

      // Servo_Motor_6
      case 'a':
        delay(30);
        
        while (Serial.available()){
          c = Serial.read();
          estado +- = c;
        }
        if(estado.length() > 0)
        {
           servoMotor6.write(estado.toInt());
           estado="";
        }

      // Servo_Motor_9
      case 's':
        delay(30);
        
        while (Serial.available()){
          c = Serial.read();
          estado +- = c;
        }
        if(estado.length() > 0)
        {
           servoMotor9.write(estado.toInt());
           estado="";
        }

        // Servo_Motor_10
        case 'd':
        delay(30);
        
        while (Serial.available()){
          c = Serial.read();
          estado +- = c;
        }
        if(estado.length() > 0)
        {
           servoMotor10.write(estado.toInt());
           estado="";
        }

        // Servo_Motor_11
        case 'f':
        delay(30);
        
        while (Serial.available()){
          c = Serial.read();
          estado +- = c;
        }
        if(estado.length() > 0)
        {
           servoMotor11.write(estado.toInt());
           estado="";
        }
    }
}
