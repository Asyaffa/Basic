#define PULSEPIN 35

bool status;
int beat, bpm;
int beatThreshold   = 600;
int noBeatThreshold = 500;
unsigned long previousMillis;

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  int sensorValue = analogRead (PULSEPIN);
  // Serial.println (sensorValue);

  if (status == 0) 
  {
    if (sensorValue > beatThreshold) 
    {
      status = 1;
      beat++;
      Serial.print("Beat : ");
      Serial.println(beat);
    }
  } 
  else
  {
    if (sensorValue < noBeatThreshold) 
    {
      status = 0;
    }
  }

  if (millis() - previousMillis > 15000)
  {
    bpm   = beat*4;
    beat  = 0;

    Serial.print("BPM : ");
    Serial.println(bpm);

    previousMillis = millis();
  }

  delay(1);
}