/*Natalia Isabel Hernandez Naveros
  Leidy Yuliana Quintero Jaramillo
  Jhon Anderson Sanchez Buritica
  Proyecto Simulacion de peaje*/
#include <Servo.h>
#define Pecho 11
#define Ptrig 12
long duracion, distancia; 
int ledrojo= 6;
int ledverde= 7;

// Declaramos la variable para controlar el servo
Servo servoMotor;
 
void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
  pinMode(ledrojo, OUTPUT);
  pinMode(ledverde, OUTPUT);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(9);
  servoMotor.write(0);

  //ultrasonico
   pinMode (Pecho, INPUT);
   pinMode (Ptrig, OUTPUT);
}

void loop() {
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);

  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2)/29;
  Serial.print(distancia);
  Serial.println("cm");
  if ((distancia >5 ) or (distancia<0)){
    servoMotor.write(0);
    digitalWrite(ledrojo, HIGH);
    digitalWrite(ledverde, LOW);
    // Esperamos 1 segundo
    delay(1000);
  
  }
  else
  {
    // Desplazamos a la posición 180º
    servoMotor.write(180);
    digitalWrite(ledverde, HIGH);
    digitalWrite(ledrojo, LOW);
    // Esperamos 1 segundo
    delay(1000);
  }

}
