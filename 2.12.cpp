#include "stdafx.h"
#include <iostream>
#include <math.h>
const double eps = 1e-6;
using namespace std;

double sum1(double x) {
	double s = 0; //сумма
	double n = 1; // конечный член
	double a = 1; // первый член
	double b = 1;
	while (true) {
		a = 1 / (sqrt(n * n * n + x));
		b = 1 / (sqrt(n * n * n - x));
		if (abs(a) <= eps || abs(b) <= eps) break;
		s += (a - b);
		n++;
	}
	return n;
}

double sum2(double x) {
	double s = 0; //сумма
	double n = 1; // конечный член
	double a = 1; // первый член
	double b = 1;
	while (true) {
		a = (1 / (sqrt(n * n * n + x))) - (1 / (sqrt(n * n * n - x)));
		if (abs(a) <= eps) break;
		s += a;
		n++;
	}
	return n;
}

int main()
{
	setlocale(0, "");
	double x;
	cin >> x;
	cout <<"Кол-во итераций для первоначального ряда: "<< sum1(x) << endl;
	cout <<"Кол-во итераций для преобразованного ряда: "<< sum2(x) << endl;
	system("pause");
	return 0;
}
