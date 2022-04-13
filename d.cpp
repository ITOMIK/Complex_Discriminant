#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

struct Complex
{
	double Re;
	double Im;
};


void Print(const Complex &a)
{

	printf("%.2f", a.Re);
	if (a.Im != 0)
		printf("%+.2fi", a.Im);
}
void Println(const Complex &a)
{
	Print(a); 
	cout << endl;
}

Complex Input()
{
	Complex a;
	cin >> a.Re >> a.Im;
	char filler;
	cin >> filler;
	return a;
} 

Complex Add(const Complex &a, const Complex &b)
{
	Complex c;
	c.Re = a.Re + b.Re;
	c.Im = a.Im + b.Im;
	return c;
}

const Complex operator +(const Complex &a, const Complex &b)
{
	Complex c;
	c.Re = a.Re + b.Re;
	c.Im = a.Im + b.Im;
	return c;
}

const Complex operator -(const Complex &a, const Complex &b)
{
	Complex c;
	c.Re = a.Re - b.Re;
	c.Im = a.Im - b.Im;
	return c;
}

const Complex operator *(const Complex &a, const Complex &b)
{
	Complex c;
	c.Re = a.Re * b.Re - a.Im * b.Im;
	c.Im = b.Re * a.Im + a.Re * b.Im ;
	return c;
}

const Complex operator *(double a, const Complex &b)
{
	Complex c;
	c.Re = b.Re * a;
	c.Im = b.Im * a;
	return c;
}

const Complex operator *(const Complex& a, double b)
{
	return b*a;
}

const Complex operator /(const Complex &a, const Complex &b)
{
	Complex c;
	c.Re = (a.Re * b.Re + a.Im * b.Im) / (b.Re*b.Re + b.Im*b.Im);
	c.Im = (b.Re * a.Im - a.Re * b.Im) / (b.Re*b.Re + b.Im*b.Im);
	return c;
}

void PrintComplexRoots(Complex a, Complex b, Complex d)
{
	const char root = 251;
	cout << "x1 = ";
	Print(b / (2 * a));
	cout << " + " << root << "(";
	Print(d);
	cout << ")/(";
	Print(2 * a);
	cout << ")" << endl;

	cout << "x2 = ";
	Print(b / (2 * a));
	cout << " - " << root << "(";
	Print(d);
	cout << ")/(";
	Print(2 * a);
	cout << ")" << endl;
}

void CalcRealRoots(double a, double b, double c)
{
	const char root = 251;
	double d, x1, x2;
	x1 = 0;
	x2 = 0;

	d = b * b - 4 * a * c;

	if ((a > 0) && (b > 0) && (c > 0) && (d > 0))
	{
		x1 = ((-b) + sqrt(d)) / (2 * a);
		x2 = ((-b) - sqrt(d)) / (2 * a);
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	else if (d == 0)
	{
		x1 = -(b / (2 * a));
		cout << "x1 = x2 = " << x1 << endl;
	}
	else if (d < 0)
	{
		x1 =  abs(d) / (2 * a);
		cout << "x2 = " << -b << "+"  << root << x1 << "i" << "/"<< 2*a  << endl;
		cout << "x2 = " << -b << "-" << root << x1 << "i" << "/" << 2 * a  << endl;
	}
	else if (b == 0 && c < 0)
	{
		x1 = -(a / abs(c));
		x2 = a / abs(c);
		cout << "x1 =" << x1 << " x2 = " << x2 << endl;
	}
	else if (b == 0 && c > 0)
	{
		x1 = a / abs(c);
		cout << "x1 =" << " x2 = " << x1 << "i" << endl;
	}
	else if (b == 0 && c == 0)
	{
		cout << "x1 =" << " x2 = " << 0 << endl;
	}
	else if (c == 0)
	{
		cout << "x1 =" << -(b / a) << " x2 = " << 0 << endl;
	}
}

int main()
{

/*	Complex a;
	a.Re = 52;
	a.Im = -231.7777;
	Print(a);
	cout << endl;*/
	/*Complex a, b;
	a = Input();
	b = Input();
	Println(a + b);
	Println(a - b);
	Println(a * b);
	Println(3* b);
	Println(a *3);
	Println(a / b);*/
	
	Complex a, b, c, d;
	cout << "print a" << endl;
	a = Input();
	cout << "print b" << endl;
	b = Input();
	cout << "print c" << endl;
	c = Input();
	if (a.Im == 0 && b.Im == 0 && c.Im == 0)
		CalcRealRoots(a.Re, b.Re, c.Re);
	else
	{
		d = b * b - 4 * a * c;
		PrintComplexRoots(a, b, d);
	}
}