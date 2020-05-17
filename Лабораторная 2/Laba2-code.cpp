#include <iostream>
#include <math.h>

using namespace std;

double a, b, xna4, xend, dx;

bool kindaEqual(double a, double b, double eps)
{
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * eps);
}

double f(double x) {
	if (x < a || kindaEqual(x, a, 0.01)) {
		return exp(x);
	}
	else if (x < b && x > a) {
		return exp(x) + cos(x);
	}
	else if (x > b || kindaEqual(x, b, 0.01)) {
		return tan(x);
	}
}

int main()
{
	cout << "a = ";
	cin >> a;

	cout << "b = ";
	cin >> b;

	cout << "xna4 = ";
	cin >> xna4;

	cout << "xend = ";
	cin >> xend;

	cout << "dx = ";
	cin >> dx;

	double firstval = f(xna4);
	cout << "f(" << xna4 << ") = " << firstval << endl;
	double max = firstval;
	double min = firstval;

	for (double i = xna4 + dx; i <= xend + dx; i += dx) {
		double val = f(i);
		cout << "f(" << i << ") = " << val << endl;
		if (val > max) max = val;
		if (val < min) min = val;
	}



	cout << endl;
	cout << "max= " << max << endl;
	cout << "min= " << min << endl;

	return 0;
}