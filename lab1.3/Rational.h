////////////////////// Rational.h

#include <string>

class Rational {
private:
    int numerator; 
    int denominator;
    void Reduce();

public:
    Rational();
    Rational(int a, int b);

    double GetA() const { return numerator; }
    double  GetB() const { return denominator; }
    void SetA(int value);
    void SetB(int value);

    bool Init(int, int);
    void Read();
    void Display() const;
    const char* toString() const;


    double value() const;

    Rational add(const Rational& r);
    Rational sub(const Rational& r);
    Rational mul(const Rational& r);

    friend Rational add(const Rational& l, const Rational& r);
};

