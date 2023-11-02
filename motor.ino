
int motores[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const int triggerPin = 13;
const int echoPin = 12;


int tamanhoArray;
void setup()
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  tamanhoArray = sizeof(motores) / sizeof(motores[0]);
  for (int i = 0; i < tamanhoArray; i++) {
    pinMode(motores[i], OUTPUT);
  }
  
  
}
void loop()
{
  
 digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 100) {
    for (int i = 0; i < 3; i++) {
  digitalWrite(motores[i], 150);
}
}
  if (distance > 200) {
  for (int i = 0; i < 6; i++) {
  digitalWrite(motores[i], 170);
}
  }
  if (distance > 300) {
  for (int i = 0; i < 9; i++) {
  digitalWrite(motores[i], 200);
}
    }
  
  if (distance < 100) {
  for (int i = 0; i < 9; i++) {
  digitalWrite(motores[i], 0);
}
    }
  
}