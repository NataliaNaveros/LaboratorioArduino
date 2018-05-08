/*Natalia Isabel Hernandez Naveros
  Leidy Yuliana Quintero Jaramillo
  Jhon Anderson Sanchez Buritica
  Proyecto Simulacion de semaforo inteligente*/

// Pines utilizados en la placa arduino
#define LEDGREEN1 2
#define LEDYELLOW1 3
#define LEDRED1 4
#define LEDVERDE2 5
#define LEDAMARILLO2 6
#define LEDROJO2 7
#define PULSADOR1 8
#define PULSADOR2 9

// Definimos Variables 
bool activo1 = true; // Indica si el semáforo 1 está activo, de lo contrario será el semáforo 2
int tiempoCambio = 1500; // Tiempo de espera entre transición de LEDs
int tiempoEspera = 5000; // Tiempo de espera hasta comenzar transición

void setup() {
  // Iniciamos el monitor serie
  Serial.begin(9600);

  // Salida de los pines
  pinMode(LEDGREEN1, OUTPUT);
  pinMode(LEDYELLOW1, OUTPUT);
  pinMode(LEDRED1, OUTPUT);
  pinMode(LEDVERDE2, OUTPUT);
  pinMode(LEDAMARILLO2, OUTPUT);
  pinMode(LEDROJO2, OUTPUT);
//Entrada de los pines
  pinMode(PULSADOR1, INPUT);
  pinMode(PULSADOR2, INPUT);

  // Apagamos todos los LEDs
  digitalWrite(LEDGREEN1, LOW);
  digitalWrite(LEDYELLOW1, LOW);
  digitalWrite(LEDRED1, LOW);
  digitalWrite(LEDVERDE2, LOW);
  digitalWrite(LEDAMARILLO2, LOW);
  digitalWrite(LEDROJO2, LOW);

  // Estado inicial: semáforo 1 abierto o encendido, semáforo 2 cerrado o en espera
  digitalWrite(LEDGREEN1, HIGH);
  digitalWrite(LEDROJO2, HIGH);
}

void loop() {
  // Definimos semáforo que tengamos activo
  if (activo1)
  {
    // Encendido el semáforo 1, comprobamos con el pulsador 2
    int valor2 = digitalRead(PULSADOR2);

    // Si hay un carro o un automovil esperando, ejercemos presión en el pulsador
    if (valor2 == HIGH)
    {
      // Encender semáforo 2
      encendersemaforo2();

      // Semáforo 2 activo
      activo1 = false;
    }
  }
  else
  {
    // Está encendido el semáforo 1, comprobamos el pulsador 1
    int valor1 = digitalRead(PULSADOR1);

    // Si hay un coche esperando, pulsador pulsado
    if (valor1 == HIGH)
    {
      // Encender semáforo 1
      encendersemaforo1();

      // Semáforo 1 activo
      activo1 = true;
    }
  }
}

void encendersemaforo2()
{
  // Apagamos semáforo 1
  // Esperamos
  delay(tiempoEspera);

  // Pasamos a luz amarilla
  digitalWrite(LEDGREEN1, LOW);
  digitalWrite(LEDYELLOW1, HIGH);

  // Esperamos
  delay(tiempoCambio);

  // Pasamos a luz roja
  digitalWrite(LEDYELLOW1, LOW);
  digitalWrite(LEDRED1, HIGH);

  // Encendemos semáforo 2
  // Esperamos
  delay(tiempoCambio);

  // Pasamos a luz amarilla
  digitalWrite(LEDROJO2, LOW);
  digitalWrite(LEDVERDE2, HIGH);
}

void encendersemaforo1()
{
  // Apagamos semáforo 2
  // Esperamos
  delay(tiempoEspera);

  // Pasamos a luz amarilla
  digitalWrite(LEDVERDE2, LOW);
  digitalWrite(LEDAMARILLO2, HIGH);

  // Esperamos
  delay(tiempoCambio);

  // Pasamos a luz roja
  digitalWrite(LEDAMARILLO2, LOW);
  digitalWrite(LEDROJO2, HIGH);

  // Encendemos semáforo 1
  // Esperamos
  delay(tiempoCambio);

  // Pasamos a luz amarilla
  digitalWrite(LEDRED1, LOW);
  digitalWrite(LEDGREEN1, HIGH);
}

