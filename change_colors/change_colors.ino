const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

void setup() {
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  
  for (int blueValue = 128; blueValue < 256 ; blueValue ++) {
    for (int greenValue = 128 ; greenValue < 256 ; greenValue ++) {
      for (int redValue = 0; redValue < 256 ; redValue ++) {
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, 0);
        analogWrite(blueLEDPin, redValue);
        delay(10);
        Serial.println("This is the console");
      }
    }
  }
}


