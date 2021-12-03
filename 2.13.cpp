#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

double eps = 1e-10;

#define PI 3.14159265358979323846

int sum1() {
	double s = 0; //сумма
	double n = 1; // конечный член
	double a = 1; // первый член
	while (abs(a) >= eps) {
		a = 1 / (double(n * n) + 1);
		s += a;
		n++;
	}

	cout << "Сумма первоначального ряда: " << s << "\n";

	return n;
}

int sum2() {
	double s = 0; //сумма
	double n = 1; // конечный член
	double a = 1; // первый член
	while (abs(a) >= eps) {
		a = 1 / (double(n * n * n * n) * (double(n * n) + 1));
		s += a;
		n++;
	}

	s += (PI * PI / 6) - (PI * PI * PI * PI / 90);

	cout << "Сумма преобразованного ряда: " << s << "\n";

	return n;
}

int main() {
	setlocale(0, "");
	double x1, x2;
	x1 = sum1();
	x2 = sum2();
	cout << "Кол-во итераций для первоначального ряда: " << x1 << endl;
	cout << "Кол-во итераций для преобразованного ряда: " << x2 << endl;
	system("pause");
}
