// This program solves for parameters of slider-crank mechanism
// Written 06-Dec-2019 by Tony Scarcia
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using std::showpoint;
int main() {
	double r1 = 0, r2 = 5, r3 = 10, r4, w2 = -2, theta2, theta3, r4dot, w3, a3, r4dotdot, pi = 3.14159, incr = 30;
	int cont = 1;
	cout << "Slider-Crank Calculator\n";
	cout << "Given the input angle, the output position, angular velocities and accelerations are calculated\n\n";
	cout << fixed;
	cout << "Slider-Crank Geometry" << endl;
	cout << "R1 = " << setprecision(1) << r1 << endl;
	cout << "R2 = " << setprecision(1) << r2 << endl;
	cout << "R3 = " << setprecision(1) << r3 << endl;
	cout << "w2 = " << setprecision(1) << w2 << endl;
	cout << "incr = " << setprecision(1) << incr << endl;
	cout << endl;
	//cout << "Enter increment for theta2: ";
	//cin >> incr;
	// output the table headings here
	cout << "theta2	theta3	  r4	omega3	r4dot	  a3	r4dotdot" << endl;
	cout << "------	------	------	------	------	------	--------" << endl;
	for (theta2 = 0; theta2 <= 360; theta2 += incr ) {
		// here are the equations
		theta3 = -asin((r1+r2*sin(theta2*pi/180))/r3)*180/pi;
		r4 = r2 * cos(theta2*pi/180)+r3*cos(theta3*pi/180);
		w3 = -(w2*r2*cos(theta2*pi/180))/(r3*cos(theta3*pi/180));
		r4dot = -(w2*r2*sin(theta2*pi/180))-(w3*r3*sin(theta3*pi/180));
		a3 = (pow(w2,2)*r2*sin(theta2*pi/180)+pow(w3,2)*r3*sin(theta3*pi/180))/(r3*cos(theta3*pi/180));
		r4dotdot = -(a3*r3*sin(theta3*pi/180)+pow(w2,2)*r2*cos(theta2*pi/180)+pow(w3,2)*r3*cos(theta2*pi/180));
		// output the table data here
		cout << setw(5) << setprecision(1) << theta2 << setw(8) << setprecision(1) << theta3 << setw(7) << setprecision(1) << r4 << setw(8) << setprecision(1) << w3 << setw(9) << setprecision(1) << r4dot << setw(7) << setprecision(1) << a3 << setw(9) << setprecision(1) << r4dotdot << endl;




	}
}
