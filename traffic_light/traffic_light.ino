const int pinRed = 2;
const int pinYellow = 3;
const int pinGreen = 4;
const int pinPiezo = 5;
const int pinSwitch = 6;

int status = 0; //stop = 0, stop_to_go = 1, go = 2, go_to_stop = 3
int switchState = 0;
int delayInMillis = 2000;


void setup() {
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, INPUT);

    stop();
}

void loop() {
    switchState = digitalRead(pinSwitch);

    Serial.print("switchState: ");
    Serial.println(switchState);

    if (switchState) {
        Serial.println("Executing ....");
        stopToGo();
        go();
        goToStop();
        stop();
    }
}

void stop() {
    digitalWrite(pinRed, HIGH);
    digitalWrite(pinYellow, LOW);
    digitalWrite(pinGreen, LOW);
    noTone(pinPiezo);
    delay(delayInMillis);
}


void stopToGo() {
    digitalWrite(pinRed, HIGH);
    digitalWrite(pinYellow, HIGH);
    digitalWrite(pinGreen, LOW);
    noTone(pinPiezo);
    delay(delayInMillis);
}

void go() {
    digitalWrite(pinRed, LOW);
    digitalWrite(pinYellow, LOW);
    digitalWrite(pinGreen, HIGH);
    tone(pinPiezo, 100);
    delay(delayInMillis * 5);
}

void goToStop() {
    digitalWrite(pinRed, LOW);
    digitalWrite(pinYellow, HIGH);
    digitalWrite(pinGreen, LOW);
    noTone(pinPiezo);
    delay(delayInMillis);
}