// Definimos los pines de los leds - defines led pins
#define ROJO1 4
#define AMARILLO1 3
#define VERDE1 2
#define ROJO2 6 
#define VERDE2 7
#define AVISADOR 11
#include <Ultrasonic.h> // LIBRARY --> Ultrasonic by Erick Simoes https://github.com/ErickSimoes/Ultrasonic


// Definimos los pines del ultrasonidos - Defines pins numbers for the lultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Definimos variables - Defines variables
Ultrasonic ultrasonic(9, 10);
int distance;
int safetyDistance;
int lightChange = 1500; // Tiempo entre cambio de color del mismo semaforo - Time between color change of the same traffic light
int trafficWait = 6000; // Tiempo entre cambio de color de semaforos distintos - Time between color change of the diferent traffic light
int parpadeo = 500;

void setup() {
  pinMode(trigPin, OUTPUT); // Inicializamos trigPin como Output - Sets  echoPin as an Input
  pinMode(echoPin, INPUT); // Inicializamos echoPin como Input - Sets  echoPin as an Input
  // Inicializamos leds como Output - Sets led as an Output
  pinMode(ROJO1, OUTPUT);
  pinMode(AMARILLO1, OUTPUT);
  pinMode(VERDE1, OUTPUT);
  pinMode(ROJO2, OUTPUT);
  pinMode(VERDE2, OUTPUT);
  Serial.begin(9600); // Inizializamos el monitor - Start the monitor communication

  // Apagamos todos los leds - Turn off all leds
  digitalWrite(VERDE1, LOW);
  digitalWrite(AMARILLO1, LOW);
  digitalWrite(ROJO1, LOW);
  digitalWrite(VERDE2, LOW);
  digitalWrite(ROJO2, LOW);

  // Estado inicial: semáforo 1 verde, semáforo 2 rojo - Initial state: traffilight 1 green, traffilight 2 red 
  digitalWrite(VERDE1, HIGH);
  digitalWrite(ROJO2, HIGH);
}


void loop() {

// Calculando la distancia - Calculating the distance
distance= ultrasonic.read();

safetyDistance = distance;

if (safetyDistance <= 10){
  encenderpeaton();
  
}
else{
  encendertrafico();
  
}

// Mostramos la distancia en el monitor - Prints the distance on the monitor
Serial.print("Distance in CM: ");
Serial.println(distance);
delay(1000);

}

void encenderpeaton()
{
  digitalWrite(AVISADOR, HIGH);
  
  delay(trafficWait);

  // Encendemos luz amarilla - Turn on yellow led
  digitalWrite(VERDE1, LOW);
  digitalWrite(AMARILLO1, HIGH);

  // Esperamos - Wait
  delay(lightChange);

  // Encendemos luz roja - Turn on red led
  digitalWrite(AMARILLO1, LOW);
  digitalWrite(ROJO1, HIGH);

  // Esperamos - Wait
  delay(lightChange);

  // Encendemos luz amarilla - Turn on yellow led
  digitalWrite(ROJO2, LOW);
  digitalWrite(VERDE2, HIGH);

 // Esperamos
  delay(trafficWait);

  // Encendemos luz amarilla - Turn on yellow led
  digitalWrite(VERDE2, LOW);
  delay(parpadeo);
  digitalWrite(VERDE2,HIGH); 
   delay(parpadeo);
  digitalWrite(VERDE2, LOW);
  delay(parpadeo);
  digitalWrite(VERDE2,HIGH); 
   delay(parpadeo);
  digitalWrite(VERDE2, LOW);
  delay(parpadeo);
  digitalWrite(VERDE2,HIGH); 
   delay(parpadeo);
  digitalWrite(VERDE2, LOW);
  delay(parpadeo);
  digitalWrite(VERDE2,HIGH); 
   delay(parpadeo);
  digitalWrite(VERDE2, LOW);

  // Encendemos luz roja - Turn on red led
 
  digitalWrite(ROJO2, HIGH);

  // Esperamos
  delay(lightChange);
  
}
void encendertrafico()
{
 
  // Encendemos luz amarilla - Turn on yellow led
  digitalWrite(ROJO1, LOW);
  digitalWrite(VERDE1, HIGH);
  digitalWrite(AVISADOR, LOW);
  
}
