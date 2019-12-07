// This program solves for parameters of slider-crank mechanism
// Written 06-Dec-2019 by Tony Scarcia
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using std::showpoint;
int main() {
	double r1, r2, r3, r4, w2, theta2, theta3, r4dot, w3, a3, r4dotdot, pi = 3.14159, incr;
	int cont = 1, choice1;
	cout << "Slider-Crank Calculator\n";
	cout << "Given the input angle, the output position, angular velocities and accelerations are calculated\n\n";
	while (cont) {
		cout << fixed;
		cout << "Slider-Crank Geometry" << endl;
		// define geometry here
		r1 = 0;
		r2 = 5;
		r3 = 10;
		w2 = -2;
		cout << "R1 = " << setprecision(1) << r1 << endl;
		cout << "R2 = " << setprecision(1) << r2 << endl;
		cout << "R3 = " << setprecision(1) << r3 << endl;
		cout << "w2 = " << setprecision(1) << w2 << endl;
		cout << "Change geometry?" << endl;
		cout << "Press 1 to change, 0 to to continue with these values :";
		cin >> choice1;
		while (choice1) {
			cout << "R1: "; cin >> r1;
			cout << "R2: "; cin >> r2;
			cout << "R3: "; cin >> r3;
			cout << "w2: "; cin >> w2;
			choice1 = 0;
		}
		cout << "Enter increment for theta2: ";
		cin >> incr;
		cout << "theta2 increment = " << setprecision(1) << incr << endl;
		cout << endl;
		// output the table headings here
		cout << "theta2	theta3	  r4	omega3	 r4dot	  a3	r4dotdot" << endl;
		cout << "------	------	------	------	------	------	--------" << endl;
		for (theta2 = 0; theta2 <= 360; theta2 += incr) {
			// here are the kinematic equations
			theta3 = -asin((r1 + r2 * sin(theta2 * pi / 180)) / r3) * 180 / pi;
			r4 = r2 * cos(theta2 * pi / 180) + r3 * cos(theta3 * pi / 180);
			w3 = -(w2 * r2 * cos(theta2 * pi / 180)) / (r3 * cos(theta3 * pi / 180));
			r4dot = -(w2 * r2 * sin(theta2 * pi / 180)) - (w3 * r3 * sin(theta3 * pi / 180));
			a3 = (pow(w2, 2) * r2 * sin(theta2 * pi / 180) + pow(w3, 2) * r3 * sin(theta3 * pi / 180)) / (r3 * cos(theta3 * pi / 180));
			r4dotdot = -(a3 * r3 * sin(theta3 * pi / 180) + pow(w2, 2) * r2 * cos(theta2 * pi / 180) + pow(w3, 2) * r3 * cos(theta2 * pi / 180));
			// output the table data here
			cout << setw(6) << setprecision(1) << theta2 << setw(8) << setprecision(2) << theta3 << setw(8) << setprecision(2) << r4 << setw(8) << setprecision(2) << w3 << setw(8) << setprecision(2) << r4dot << setw(8) << setprecision(2) << a3 << setw(10) << setprecision(2) << r4dotdot << endl;
		}
	cout << endl << "Press 1 to Continue, 0 to to Quit" << endl;
	cin >> cont;
	}
}
