#include <iostream>
#include "Kazachkova_MathTask.h"

using namespace std;

int main() {
    double x, y, z;
    EnterDigit(x, "input x");
    EnterDigit(y, "input y");
    EnterDigit(z, "input z");
    int IntegerSumm = IntSum(x, y, z);
    double F_P = FractPart(x, y, z);
    cout << "IntegerSumm: " << IntegerSumm << endl;
    cout << "FractPart: " << F_P << endl;
}
