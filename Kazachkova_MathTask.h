#ifndef _KAZACHKOVA_MATHTASK_H_
#define _KAZACHKOVA_MATHTASK_H_

#include <string>
#include <math.h>

using namespace std;

// Функция контроля вводимых данных
bool UserInput(string input) {
    if (input.empty()) return false;
    try {
        double number = stod(input);
} 
    catch (...) 
    { return false; }
    return true;
}

void EnterDigit(double& varLink, const string& label) {
    string raw_input;
    cout << label << " = ";
    getline(cin, raw_input);
    while (!UserInput(raw_input)) {
        cout << label << " = ";
        getline(cin, raw_input);
    }
    varLink = stod(raw_input);
}

int IntSum(double x, double y, double z)
{
    double w = x + y + z;
    return w;
}

double FractPart(double x, double y, double z) {
    double xyz = x * y * z;
    int geo_mean1 = pow(xyz, 1/3.0);
    double geo_mean2 = pow(xyz, 1/3.0);
    double fractpart = geo_mean2 - geo_mean1;
    return fractpart;
}
#endif
