// Defining LEDs and buttons.
int leds[] = {12, 10, 7, 4};
int buttons[] = {11, 9, 6, 3};

const int max = 40;
int lightArr[max];      // Array with full patterns of LEDs.
int currArr[max];
int gameState = 0;
int level = 1;
int correct = 1;
int buttonPressed = -1;

void setup() {
  pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
  pinMode(leds[3], OUTPUT);
  pinMode(buttons[0], INPUT);
  pinMode(buttons[1], INPUT);
  pinMode(buttons[2], INPUT);
  pinMode(buttons[3], INPUT);
  
  Serial.begin(9600);
  
  randomSeed(analogRead(0));
  allOn();
}



void loop() {
  if (gameState == 0) {
    resetGame();
  } else if (gameState == 1) {
    play();
  } else if (gameState == 2) {
    gameOver(); 
    level = 1;
    gameState = 0;
    correct = 1;
    allOn();
  } 
}


  
void resetGame() {
  if (level == 1) {
    // Setting up a sequence of random lights.
    for (int i = 0; i < 40; i++) {
      lightArr[i] = random(0,4);
    }
  }
  level = 1; 
  gameState = 1;
}


void play() {
  while (correct == 1) {
    showPattern();
    correct = userInput();
    level++;
  }
}
  

void showPattern() {
  delay(500);
  for (int i = 0; i < level; i++) {
    digitalWrite(leds[lightArr[i]], 1);
    delay(500);               
    digitalWrite(leds[lightArr[i]], 0);
    delay(500);
    
  }
}

int userInput() {
  delay(500);
  for (int i = 0; i < level; i++) {
    int buttonPressed = readOneButton();
    if (buttonPressed >= 0) {
      if (lightArr[i] != buttonPressed) {
        gameState = 2;
        return 0;
      }
    }
  }
  return 1;
}

  


void gameOver() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[0], 1);
    delay(150);
    digitalWrite(leds[0], 0);  
    delay(150);
    digitalWrite(leds[1], 1);
    delay(150);
    digitalWrite(leds[1], 0);
    delay(150);
    digitalWrite(leds[2], 1);
    delay(150);
    digitalWrite(leds[2], 0);
    delay(150);
    digitalWrite(leds[3], 1);
    delay(150);
    digitalWrite(leds[3], 0);
    delay(150);
  }
  delay(1000);
  
}
  
int readOneButton() {
  while (buttonPressed == -1) {
    if (digitalRead(buttons[0])) {
      digitalWrite(leds[0], 1); 
      delay(500);
      digitalWrite(leds[0], 0);
      delay(500);
      return 0;

    } else if (digitalRead(buttons[1])) {
      digitalWrite(leds[1], 1);
      delay(500);
      digitalWrite(leds[1], 0);
      delay(500);
      return 1;

    } else if (digitalRead(buttons[2])) {
      digitalWrite(leds[2], 1);
      delay(500);
      digitalWrite(leds[2], 0);
      delay(500);
      return 2;

    } else if (digitalRead(buttons[3])) {
      digitalWrite(leds[3], 1);
      delay(500);
      digitalWrite(leds[3], 0);
      delay(500);
      return 3;

    }
  }
}

void allOn() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[0], 1);
    digitalWrite(leds[1], 1);
    digitalWrite(leds[2], 1);
    digitalWrite(leds[3], 1);
    delay(500);               
    digitalWrite(leds[0], 0);       
    digitalWrite(leds[1], 0);        
    digitalWrite(leds[2], 0);         
    digitalWrite(leds[3], 0);
    delay(500);
  }
}
  
  
  
  
  
  
  
  
  
  
