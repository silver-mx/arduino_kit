const int switchPin = 8;
const int piezoPin = 9;

unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int direction = 0; // 0 = left, 1 = right

int led = 2;

long interval = 100; // millis

void setup() {

  Serial.begin(9600);

  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }

  pinMode(switchPin, INPUT);
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval) {
    previousTime = currentTime;

    Serial.print("Turning led: ");
    Serial.println(led);

    digitalWrite(led, HIGH);
    tone(piezoPin, 1000, 10); // beep when turning on another LED
    
    if (direction == 0) {
      led++;
    } else {
      led--;
    }

    if (led == 8 || led == 1) {
      direction = ~direction;
      interval += interval;
      delay(interval);
      turnOffLeds();

      if (led == 8) {
        led = 7;
      } else {
        led = 2;
      }
    }
  }

  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {

    Serial.print("switchState: ");
    Serial.println(switchState);

    turnOffLeds();

    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;
}

void turnOffLeds() {
  for (int x = 2; x < 8; x++) {
    digitalWrite(x, LOW);
  }
}