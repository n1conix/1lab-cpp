#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    double x_start, x_end, dx;

    cout << "Введите a, b, c: ";
    cin >> a >> b >> c;

    cout << "Введите начало интервала xн, конец xк и шаг dx: ";
    cin >> x_start >> x_end >> dx;

    for (double x = x_start; x <= x_end; x += dx) {
        double F;

        if (c + b < 0 && a != 0) {
            F = a * pow(cos(x), 2) + c;
        } 
        else if (c + b > 0 && a == 0) {
            if (a * x - log(b * x) != 0) // защита от деления на 0
                F = (pow(b, 2) - x) / (a * x - log(b * x));
            else {
                cout << "Деление на 0 при x=" << x << endl;
                continue;
            }
        } 
        else {
            if (3 * sin(x) + 4 * log(2 * x) != 0)
                F = (pow(b, 2) - c * x) / (3 * sin(x) + 4 * log(2 * x));
            else {
                cout << "Деление на 0 при x=" << x << endl;
                continue;
            }
        }

        cout << "x = " << x << "  F(x) = " << F << endl;
    }

    return 0;
}