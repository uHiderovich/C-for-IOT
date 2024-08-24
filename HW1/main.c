#define BUTTON_PIN 2
#define GREEN_LED_PIN 13
#define YELLOW_LED_PIN 12
#define RED_LED_PIN 11
#define NUMBER_BLINKS 3

void setup()
{
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
}

void blink(int pin)
{
  int numberBlinks = NUMBER_BLINKS;

  while (numberBlinks--)
  {
    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
    delay(1000);
  }

  numberBlinks = NUMBER_BLINKS;
}

void turnOnLed(int pin)
{
  digitalWrite(pin, HIGH);
  delay(5000);
  digitalWrite(pin, LOW);
}

void loop()
{
  // Основное задание
  _Bool isStarted = 0;

  if (digitalRead(BUTTON_PIN) == HIGH && !isStarted)
  {
    isStarted = 1;

    delay(1000);

    blink(YELLOW_LED_PIN);

    turnOnLed(GREEN_LED_PIN);

    blink(GREEN_LED_PIN);

    turnOnLed(RED_LED_PIN);

    isStarted = 0;
  }

  // Задание под *
  int monitorValue = 0;

  if (Serial.available() > 0)
  {
    monitorValue = Serial.read();
    Serial.write(monitorValue);
  }

  switch (monitorValue)
  {
  case '1':
    turnOnLed(GREEN_LED_PIN);
    break;
  case '2':
    turnOnLed(YELLOW_LED_PIN);
    break;
  case '3':
    turnOnLed(RED_LED_PIN);
    break;
  }

  monitorValue = 0;
}