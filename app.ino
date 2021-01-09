void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
}

// epsilon = delta time tick
int epsilon = 1;

void pwmWrite(int pin, float fract, int dur) {
  int PREV_STATE = LOW;
  int STATE = LOW;
  for(int tick = 0; tick < dur; tick += epsilon) {
    int prog = tick;

    int STATE = 0;

    if(prog % 6 < 6.0f * fract) {
      STATE = HIGH;
    } else {
      STATE = LOW;
    }

    if(PREV_STATE != STATE) {
      digitalWrite(pin, STATE);
      digitalWrite(LED_BUILTIN, STATE);

      PREV_STATE = STATE;
    }

    delay(epsilon);
  }

}

// linear function from (min,0)->(max,1.0f)
float sampleFnLinear(float min, float max, float point) {
  float y_1 = (max - min) / max;
  float y_0 = min;
  float y_x = (y_1 - y_0) * point;

  return y_0 + (y_x);
}


void linearRamp(int pin, float min, float max, float dur, int step) {
  for(float tick = 0; tick < dur; tick += step) {

    float prog = tick / dur;

    pwmWrite(pin, sampleFnLinear(min, max, prog), step);

  }
}


void loop()
{
	// digitalWrite(LED_BUILTIN, HIGH);
  
  // delay(1000);
  // digitalWrite(LED_BUILTIN, LOW);
  // digitalWrite(2, LOW);
  // pwmWrite(2, 0, 200);
  // pwmWrite(2, 0.05, 100);
  // pwmWrite(2, 0.25, 100);
  // pwmWrite(2, 0.6, 200);
  // pwmWrite(2, 1, 100);
  // pwmWrite(2, 0.6, 200);
  // pwmWrite(2, 0.25, 100);
  // pwmWrite(2, 0.05, 100);

  linearRamp(2, 0, 1.0f, 500, 12);

  linearRamp(2, 1.0f, 0.0f, 500, 12);

  pwmWrite(2, 0, 1000);

  delay(1000);
  
  
  for(int i = 0;  i < 3; i++) {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(2, LOW);

    delay(1000);

    digitalWrite(2, LOW);
    pwmWrite(2, 0, 200);
    pwmWrite(2, 0.05, 100);
    pwmWrite(2, 0.25, 100);
    pwmWrite(2, 0.6, 200);
    pwmWrite(2, 1, 100);
    pwmWrite(2, 0.6, 200);
    pwmWrite(2, 0.25, 100);
    pwmWrite(2, 0.05, 100);
  }

  for(int i = 0;  i < 3; i++) {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(2, LOW);

    delay(2000);

    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(2, HIGH);

    delay(2000);

  }

}
