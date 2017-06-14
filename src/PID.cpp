#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    last_cte = 0;
}

void PID::UpdateError(double cte) {
    p_error = cte;
    
    d_error = cte - last_cte;

    last_cte = cte;

    i_error += cte;

}

double PID::TotalError() {
    return - Kp * p_error - Ki * i_error - Kd * d_error;
}

