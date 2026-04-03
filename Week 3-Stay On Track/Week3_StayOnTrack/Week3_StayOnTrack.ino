// Battlebot BB008
// Team IT-1D
// Michael O. Boeteng Student ID.5598168
// Jenjira Huaisai Student ID.5681502
// ======================================
// Assignment Week 3 Stay on track (arrays)
// ======================================
// Follow the black line on the track
// ======================================

// SENSOR PINS
#define SENSOR_0 A0
#define SENSOR_1 A1
#define SENSOR_2 A2
#define SENSOR_3 A3
#define SENSOR_4 A4
#define SENSOR_5 A5
#define SENSOR_6 A6
#define SENSOR_7 A7

const int SENSOR_PINS[8] =
{
    SENSOR_0, SENSOR_1, SENSOR_2, SENSOR_3,
    SENSOR_4, SENSOR_5, SENSOR_6, SENSOR_7
};

int sensorValues[8];

int weights[8] =
{
    -3500, -2500, -1500, -500,
     500,  1500,  2500,  3500
};

// MOTOR CONTROL
#define MOTOR_LEFT_FORWARD  5
#define MOTOR_LEFT_BACK     3
#define MOTOR_RIGHT_BACK    11
#define MOTOR_RIGHT_FORWARD 6

// THRESHOLD
#define BLACK_THRESHOLD 800

// SETUP
void setup()
{
    Serial.begin(9600);

    pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
    pinMode(MOTOR_LEFT_BACK, OUTPUT);
    pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);
    pinMode(MOTOR_RIGHT_BACK, OUTPUT);
}

// LOOP
void loop()
{
    long position = 0;
    int total = 0;

    for (int i = 0; i < 8; i++)
    {
        sensorValues[i] = analogRead(SENSOR_PINS[i]);

        if (sensorValues[i] > BLACK_THRESHOLD)
        {
            position += weights[i];
            total++;
        }
    }

    if (total == 0)
    {
        stopMotors();
        return;
    }

    int error = position / total;

    int baseSpeed;

    if (abs(error) < 400)
    {
        baseSpeed = 255;
    }
    else if (abs(error) < 1200)
    {
        baseSpeed = 200;
    }
    else
    {
        baseSpeed = 150;
    }

    int correction = error / 16;

    // CURVE ANTICIPATION
    if (sensorValues[0] > BLACK_THRESHOLD || sensorValues[1] > BLACK_THRESHOLD)
    {
        correction -= 25;
    }

    if (sensorValues[6] > BLACK_THRESHOLD || sensorValues[7] > BLACK_THRESHOLD)
    {
        correction += 25;
    }

    int leftSpeed = baseSpeed - correction;
    int rightSpeed = baseSpeed + correction;

    leftSpeed = constrain(leftSpeed, 0, 255);
    rightSpeed = constrain(rightSpeed, 0, 255);

    analogWrite(MOTOR_LEFT_FORWARD, leftSpeed);
    analogWrite(MOTOR_LEFT_BACK, 0);

    analogWrite(MOTOR_RIGHT_FORWARD, rightSpeed);
    analogWrite(MOTOR_RIGHT_BACK, 0);
}

// FUNCTIONS
void stopMotors()
{
    analogWrite(MOTOR_LEFT_FORWARD, 0);
    analogWrite(MOTOR_LEFT_BACK, 0);
    analogWrite(MOTOR_RIGHT_FORWARD, 0);
    analogWrite(MOTOR_RIGHT_BACK, 0);
}