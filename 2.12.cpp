#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

double sum1(double x, double eps) {
	double s = 0; //сумма
	double n = 1; // конечный член
	double a = 1; // первый член
	double b = 1;
	while (true) {
		a = 1 / (sqrt(n*n*n + x));
		b = 1 / (sqrt(n*n*n- x));
		if (abs(a) <= eps || abs(b) <= eps) break;
		s += (a - b);
		n++;
	}
	return n;
}

double sum2(double x, double eps) {
	double s = 0; //сумма
	double n = 1; // конечный член
	double a = 1; // первый член
	double b = 1;
	while (true) {
		a = (1 / (sqrt(n*n*n + x)))- (1 / (sqrt(n*n*n - x)));
		if (abs(a) <= eps) break;
		s += a;
		n++;
	}
	return n;
}

int main()
{
	double x;
	cin >> x;
	cout << sum1(x, 1e-6) << endl;
	cout << sum2(x, 1e-6) << endl;
	system("pause");
	return 0;
}