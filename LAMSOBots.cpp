#include "Arduino.h"
#include "LAMSOBots.h"

/*Once again, VS Code will comaplain about it being unable to find the path*/

TwoWheeler::TwoWheeler(int L, int R)
    : _motorL(L), _motorR(R){
}

void TwoWheeler::coast()
{
    _motorL.run(RELEASE);
    _motorR.run(RELEASE);
}

void TwoWheeler::stop() 
{
    _motorL.run(BRAKE); // Para os motores
    _motorR.run(BRAKE);
}

void TwoWheeler::setSpeed(int speedL, int speedR)
{
    _motorL.setSpeed(speedL);
    _motorR.setSpeed(speedR);
}


void TwoWheeler::forward()
{
    _motorL.run(FORWARD);
    _motorR.run(FORWARD);
}

void TwoWheeler::forwardFor(unsigned long ms) 
{
    _motorL.run(FORWARD);
    _motorR.run(FORWARD);

    delay(ms); // Espera o tempo especificado

    _motorL.run(RELEASE); // Para os motores
    _motorR.run(RELEASE);
}

void TwoWheeler::backward() 
{
    _motorL.run(BACKWARD);
    _motorR.run(BACKWARD);
}

void TwoWheeler::backwardFor(unsigned long ms) 
{
    _motorL.run(BACKWARD);
    _motorR.run(BACKWARD);


    delay(ms); // Espera o tempo especificado

    _motorL.run(RELEASE); // Para os motores
    _motorR.run(RELEASE);
}

void TwoWheeler::spinLeft()
{
    _motorL.run(BACKWARD);
    _motorR.run(FORWARD);
}

void TwoWheeler::spinLeftFor(unsigned long ms)
{
    _motorL.run(BACKWARD);
    _motorR.run(FORWARD);

    delay(ms); // Espera o tempo especificado

    _motorL.run(RELEASE); // Para os motores
    _motorR.run(RELEASE);
}

void TwoWheeler::spinRight()
{
    _motorL.run(FORWARD);
    _motorR.run(BACKWARD);
}

void TwoWheeler::spinRightFor(unsigned long ms)
{
    _motorL.run(FORWARD);
    _motorR.run(BACKWARD);

    delay(ms); // Espera o tempo especificado

    _motorL.run(RELEASE); // Para os motores
    _motorR.run(RELEASE);
}

void TwoWheeler::turnLeftFor(unsigned long ms)
{

    _motorL.run(BRAKE); // Para o motor
    _motorR.run(FORWARD);

    delay(ms);

    _motorR.run(RELEASE);

}

void TwoWheeler::turnLeft()
{
    _motorL.run(BRAKE); // Para o motor
    _motorR.run(FORWARD);
}

void TwoWheeler::turnRightFor(unsigned long ms)
{
    _motorR.run(BRAKE);
    _motorL.run(FORWARD);

    delay(ms);

    _motorL.run(RELEASE); // Para os motores
}

void TwoWheeler::turnRight()
{
    _motorR.run(BRAKE);
    _motorL.run(FORWARD);
}

void TwoWheeler::move(int speedL, int speedR)
{
    _motorL.setSpeed(abs(speedL));
    _motorR.setSpeed(abs(speedR));

    _motorL.run(speedL >= 0 ? FORWARD : BACKWARD);
    _motorR.run(speedR >= 0 ? FORWARD : BACKWARD);
}

FourWheeler::FourWheeler(int FL, int FR, int BL, int BR)
    : _motorFL(FL), _motorFR(FR), _motorBL(BL), _motorBR(BR) {
    _speed = 255;  // Default speed to max
}

void FourWheeler::coast() 
{
    _motorFL.run(RELEASE); // Para os motores
    _motorFR.run(RELEASE);
    _motorBL.run(RELEASE);
    _motorBR.run(RELEASE);
}

void FourWheeler::stop() 
{
    _motorFL.run(BRAKE); // Para os motores
    _motorFR.run(BRAKE);
    _motorBL.run(BRAKE);
    _motorBR.run(BRAKE);
}

void FourWheeler::setSpeed(int speed)
{
    _motorFL.setSpeed(speedFL);
    _motorFR.setSpeed(speedFR);
    _motorBL.setSpeed(speedBL);
    _motorBR.setSpeed(speedBR);
}

void FourWheeler::forward()
{
    _motorFL.run(FORWARD);
    _motorFR.run(FORWARD);
    _motorBL.run(FORWARD);
    _motorBR.run(FORWARD);
}

void FourWheeler::forwardFor(unsigned long ms) 
{
    _motorFL.run(FORWARD);
    _motorFR.run(FORWARD);
    _motorBL.run(FORWARD);
    _motorBR.run(FORWARD);

    delay(ms); // Espera o tempo especificado

    _motorFL.run(RELEASE); // Para os motores
    _motorFR.run(RELEASE);
    _motorBL.run(RELEASE);
    _motorBR.run(RELEASE);
}

void FourWheeler::backward() 
{
    _motorFL.run(BACKWARD);
    _motorFR.run(BACKWARD);
    _motorBL.run(BACKWARD);
    _motorBR.run(BACKWARD);
}

void FourWheeler::backwardFor(unsigned long ms) 
{
    _motorFL.run(BACKWARD);
    _motorFR.run(BACKWARD);
    _motorBL.run(BACKWARD);
    _motorBR.run(BACKWARD);

    delay(ms); // Espera o tempo especificado

    _motorFL.run(RELEASE); // Para os motores
    _motorFR.run(RELEASE);
    _motorBL.run(RELEASE);
    _motorBR.run(RELEASE);
}

void FourWheeler::spinLeft()
{
    _motorFL.run(BACKWARD);
    _motorBL.run(BACKWARD);
    _motorFR.run(FORWARD);
    _motorBR.run(FORWARD);
}

void FourWheeler::spinLeftFor(unsigned long ms)
{
    _motorFL.run(BACKWARD);
    _motorBL.run(BACKWARD);
    _motorFR.run(FORWARD);
    _motorBR.run(FORWARD);

    delay(ms); // Espera o tempo especificado

    _motorFL.run(RELEASE); // Para os motores
    _motorFR.run(RELEASE);
    _motorBL.run(RELEASE);
    _motorBR.run(RELEASE);
}

void FourWheeler::spinRight()
{
    _motorFL.run(FORWARD);
    _motorBL.run(FORWARD);
    _motorFR.run(BACKWARD);
    _motorBR.run(BACKWARD);
}

void FourWheeler::spinRightFor(unsigned long ms)
{
    _motorFL.run(FORWARD);
    _motorBL.run(FORWARD);
    _motorFR.run(BACKWARD);
    _motorBR.run(BACKWARD);

    delay(ms); // Espera o tempo especificado

    _motorFL.run(RELEASE); // Para os motores
    _motorFR.run(RELEASE);
    _motorBL.run(RELEASE);
    _motorBR.run(RELEASE);
}

void FourWheeler::turnLeftFor(unsigned long ms)
{
    _motorFL.run(BRAKE);
    _motorBL.run(BRAKE);
    _motorFR.run(FORWARD);
    _motorBR.run(FORWARD);

    delay(ms);

    _motorFR.run(RELEASE); // Para os motores
    _motorBR.run(RELEASE);

}

void FourWheeler::turnLeft()
{
    _motorFL.run(BRAKE);
    _motorBL.run(BRAKE);
    _motorFR.run(FORWARD);
    _motorBR.run(FORWARD);
}

void FourWheeler::turnRightFor(unsigned long ms)
{
    
    _motorFR.run(BRAKE);
    _motorBR.run(BRAKE);
    _motorFL.run(FORWARD);
    _motorBL.run(FORWARD);

    delay(ms);

    _motorFL.run(RELEASE); // Para os motores
    _motorBL.run(RELEASE);
}

void FourWheeler::turnRight()
{
    _motorFR.run(BRAKE);
    _motorBR.run(BRAKE);
    _motorFL.run(FORWARD);
    _motorBL.run(FORWARD);
}

// In FourWheeler.cpp
void FourWheeler::move(int speedL, int speedR)
{
    _motorFL.setSpeed(abs(speedL));
    _motorFR.setSpeed(abs(speedR));
    _motorBL.setSpeed(abs(speedL));
    _motorBR.setSpeed(abs(speedR));

    _motorFL.run(speedL >= 0 ? FORWARD : BACKWARD);
    _motorFR.run(speedR >= 0 ? FORWARD : BACKWARD);
    _motorBL.run(speedL >= 0 ? FORWARD : BACKWARD);
    _motorBR.run(speedR >= 0 ? FORWARD : BACKWARD);
}
