#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

double eps = 0.5 * 1e-8;
double n1;
double n2;

double sum1(double x) {
	double s = 1; //сумма
	n1 = 1; // конечный член
	double a = 1; // первый член
	while (true) {
		a = 1 / (n1 * (n1 + x));
		if (abs(a) <= eps) break;
		s += a;
		n1++;
	}

	return s;
}

double sum2(double x) {
	double s = 1; //сумма
	n2 = 1; // конечный член
	double a = 1; // первый член
	while (true) {
		a = 1 / (n2 * (n2 + x) * (n2 + 1));
		if (abs(a) <= eps) break;
		s += a;
		n2++;
	}
	s *= (1 - x);
	s += sum1(1);

	return s;
}

int main()
{
	double n = 0;
	cout << "x\tsum1\tsum2\titr1\titr2\n";
	for (double x = 0.0; x < 1.0; x += 0.1) {
		n += sum1(x);
		cout << x << "\t" << sum1(x) << "\t" << sum2(x) << "\t" << n1 << "\t" << n2 << "\n";
	}
	system("pause");
	return 0;
}
