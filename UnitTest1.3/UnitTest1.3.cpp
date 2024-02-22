#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1.3/Rational.h"
#include "../lab1.3/Rational.cpp"
#include "Assert.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest13
{
    TEST_CLASS(UnitTest13)
    {
    public:

        TEST_METHOD(Mul) {
            Rational rational{};
            rational.Init(1, 1);
            Assert::AreEqual(rational.value(), 1., 0.0001);
        }
    };
}
