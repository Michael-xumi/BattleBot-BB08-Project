// Battlebot BB008
// Team IT-1D
// Michael O. Boeteng Student ID.5598168
// Jenjira Huaisai Student ID.5681502
// ======================================
// Assignment Week 3.1 Blink (Fast/Slow)
// ======================================
// Blink once a second,
// Press one button and then blink twice a second,
// Press an other button and blink once every 2 seconds
// ======================================

// LED
#define RED_LED LED_BUILTIN

// BUTTON PINS
#define BUTTON_1 2
#define BUTTON_2 3

int blinkDelay = 1000;                  

// SET UP
void setup()
{
    pinMode(RED_LED, OUTPUT);
    pinMode(BUTTON_1, INPUT);
    pinMode(BUTTON_2, INPUT);
}

// LOOP
void loop()
{
    if (digitalRead(BUTTON_1) == LOW)   
    {
        blinkDelay = 500;               
    }

    if (digitalRead(BUTTON_2) == LOW)   
    {
        blinkDelay = 2000;              
    }

    digitalWrite(RED_LED, LOW);         
    delay(blinkDelay);

    digitalWrite(RED_LED, HIGH);        
    delay(blinkDelay);
}