///////////////////////// Rational.cpp
#include "Rational.h"
#include <iostream>
#include <sstream>

using namespace std;
Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int a, int b) : numerator(a), denominator(b) {
    Reduce();
}
/// скорочення дробу
void Rational::Reduce() {
    int gcd = 1;
    int smaller = (numerator < denominator) ? numerator : denominator;

    for (int i = 2; i <= smaller; ++i) {
        if (numerator % i == 0 && denominator % i == 0) {
            gcd = i;
        }
    }

    if (gcd > 1) {
        numerator /= gcd;
        denominator /= gcd;
    }
}

void Rational::SetA(int value)  {
    numerator = value;
}

void  Rational::SetB(int value)  {
   denominator = value;
}

bool Rational::Init(int a, int b) {
    numerator = a;
    denominator = b;

    if (b == 0) {
        return false;
    }
    else {
        Reduce();
        return true;
    }
}


void Rational::Read()
{
    do
    {
        cout << "Помилка: знаменник не може дорівнювати нулю. Введіть дійсне значення для b." << endl;
        cout << "Введіть a: ";cin >> numerator;
        cout << "Введіть b: ";cin >> denominator;
         Reduce();
    }while (!Init(numerator, denominator));
}

void Rational::Display() const {
    cout << numerator << "/" << denominator;
}

const char* Rational::toString() const {
    stringstream sout;
    sout << numerator << "/" << denominator;
    return sout.str().c_str();
}

double Rational::value() const {
    return static_cast<double>(numerator) / denominator;
}
//додавання
Rational Rational::add(const Rational& r) {
    Rational result(numerator * r.denominator + denominator * r.numerator, denominator * r.denominator);
    result.Reduce();
    return result;
}
/// віднімання
Rational Rational::sub(const Rational& r) {
    Rational result(numerator * r.denominator - denominator * r.numerator, denominator * r.denominator);
    result.Reduce();
    return result;
}
/// множення
Rational Rational::mul(const Rational& r) {
    Rational result(numerator * r.numerator, denominator * r.denominator);
    result.Reduce();
    return result;
}

// Дружня функція для додавання
Rational add(const Rational& l, const Rational& r) {
    Rational tmp(l.numerator * r.denominator + l.denominator * r.numerator, l.denominator * r.denominator);
    tmp.Reduce();
    return tmp;
}
