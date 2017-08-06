const int sensorPin = A0;
int baselineTemp = 20.0;

void setup() {
  Serial.begin(9600);

  for (int pinNumber = 2; pinNumber < 5 ; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

  baselineTemp = getEnvTemp();
}

float getEnvTemp() {
  Serial.println("INITIALIZING ENV TEMP");
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.println(sensorVal);
  float voltage = (sensorVal/1024.0) * 5.0; 
  return (voltage - 0.5) * 100;
}

void loop() {
  int sensorVal = analogRead(sensorPin);

  Serial.print("Baseline temp: ");
  Serial.println(baselineTemp);

  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");

  float temperature = (voltage - 0.5) * 100;

  Serial.println(temperature);

  if (temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  else if(temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW); 
  } 
  else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1);
}








