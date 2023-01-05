#include <Servo.h> // biblioteca do servo
int sensor_ultrassonico = 0; //variável do sensor
int pos = 180; //variável da posição inicial do servo
long read Ultrasonic Distance(int triggerPin, int echoPin)//declaração das variáveis dos pinos
onde o sensor está conectado(entrada digital)
{
pinMode(trigPin, OUTPUT); //configura o pino TRIG como saída
digitalWrite(trigPin, LOW); // configura pino TRIG como desligado
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
sensor_ultrassonico = 0.01723 * read Ultrasonic Distance(9, 8); //lê os pinos digitais do
sensor ultrassônico
servo.write(0); //posição inicial do servo em 0 graus
if (sensor ultrassônico <= 10) { //se a distância entre a mão e o sensor for menor ou igual a
10cm
servo.write(pos - 90); //servo virá em 90 graus
delay(500); // aguarda 0,5 segundos e volta à posição inicial
servo.write(pos); //volta à posição inicial
delay(2000); // aguarda 2 segundo para poder ser acionado novamente
}
}
