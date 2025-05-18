#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"

#include "Kazachkova_MathTask.h"

using namespace cute;

void testCalcIntSum() //Тест, проверяющий IntSum(целочисленная сумма)
{
    double x = 12.6;
    double y = 13.6;
    double z = 24.6;
    int expected = 50;
    int actual = IntSum(x, y, z);
    ASSERT_EQUAL(expected, actual);
}
void testCalcFractPart() //Тест, проверяющий FractPart(дробная часть среднего геометрического)
{
    double x = 12.6;
    double y = 13.6;
    double z = 24.6;
    double xyz = x * y * z;
    double expected = pow(xyz, 1/3.0) - int(pow(xyz, 1/3.0));
    double actual = FractPart(x, y, z);
    ASSERT_EQUAL(expected, actual);
}
void testUserInput_Empty() //тест, проверяющий отсев пустых значений
{
    string str = "";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}
//тест, проверяющий отсев нецифровых символов
void testUserInput_Letter()
{
    string str = "a";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}
//тест, проверяющий отсев цифро-буквенных значений
void testUserInput_DigitLetterValue() {
    string str = "5a";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}

int main() {
    suite s;

    s.push_back(CUTE(testCalcIntSum));
    s.push_back(CUTE(testCalcFractPart));
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testUserInput_DigitLetterValue));

    // Создает listener и runner
    ide_listener<> listener;
    makeRunner(listener)(s, "All tests");

    return 0;
}
