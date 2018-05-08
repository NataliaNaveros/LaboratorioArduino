/*Natalia Isabel Hernandez Naveros
  Leidy Yuliana Quintero Jaramillo
  Jhon Anderson Sanchez Buritica
  Proyecto Simulacion sensor de temperatura*/
//Libreria y definicion de pines lcd 
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Constantes
const int sensorlm35 = A0;

 // Variables
int milivolts;
 
// Inicialización
void setup() {
 Serial.begin(9600);
 lcd.begin(16,2); //dimensiones del lcd 
 delay(400);
 lcd.setCursor(0,2);
 lcd.print("Temperatura");
 lcd.setCursor(13,2);
 lcd.print((char)223);
 lcd.setCursor(14,2);
 lcd.print("C");
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
}
 
// Ciclo infinito
void loop() {
// Lectura del sensor de temperatura
  milivolts = analogRead(sensorlm35);
  float temperatura = (milivolts*500.0)/1023;
  Serial.print(temperatura); 
  delay(400);

//Impresión en LCD temperatura
 lcd.setCursor(0,0);
 lcd.print(temperatura);
 lcd.setCursor(7,0);
 lcd.print( "Grados");
   
 // Condiciones para encendido de leds 
 if (temperatura < 27){ // Menor a 27° encendido led azul 
  digitalWrite(8,HIGH);  
} 
 else
 digitalWrite(8,LOW); 
  
 if (temperatura > 29){ // Mayor a 29° encendido led rojo 
  digitalWrite(9,HIGH);  
} 
 else
  digitalWrite(9,LOW); 
} 
