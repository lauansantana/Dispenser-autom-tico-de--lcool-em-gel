#include <Servo.h> // biblioteca do servo

int sensor_ultrassonico = 0; //variável do sensor
int pos = 180; //variável posiçao inicial do servo

long readUltrasonicDistance(int triggerPin, int echoPin)//declaração das variaveis dos pinos onde o sensor está conectado(entrada digital)
{
  pinMode(triggerPin, OUTPUT); //configura o pino TRIG como saída
  digitalWrite(triggerPin, LOW); // configura pino TRIG como desligado
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // lê o pino echo e retorna o tempo de viagem
  return pulseIn(echoPin, HIGH);
}

Servo servo;

void setup()
{
  servo.attach(2);
}

void loop()
{
  sensor_ultrassonico = 0.01723 * readUltrasonicDistance(9, 8); //lê os pinos digitais do sensor ultrassonico
  servo.write(0); //posição inicial do servo em 0 graus
  if (sensor_ultrassonico <= 10) { //se a distancia entre a mão e o sensor for menor ou igual a 10cm
    servo.write(pos - 90); //servo vira em 90 graus
    delay(500); // aguarda 0,5 segundos para poder voltar a posição inicial
    servo.write(pos); //volta a posição inicial
    delay(2000); // aguarda 3 segundo para poder ser acionado novamente
  }
}
