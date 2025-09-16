#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    double x_start, x_end, dx;

    // Ввод данных
    cout << "Введите a, b, c: ";
    cin >> a >> b >> c;
    cout << "Введите Xнач, Xкон и dX: ";
    cin >> x_start >> x_end >> dx;

    // Заголовок таблицы
    cout << setw(10) << "X" << setw(20) << "F(X)" << endl;
    cout << "-----------------------------------" << endl;

    for (double x = x_start; x <= x_end; x += dx) {
        double F;
        int Ac = static_cast<int>(a);
        int Bc = static_cast<int>(b);
        int Cc = static_cast<int>(c);

        bool conditionBitwise = ((Ac | Bc) & Cc) != 0;

        // Определяем F в зависимости от условий
        if (x < 0.6 && (b + c != 0)) {
            F = a * x * x + b * b + c;
        } else if (x > 0.6 && (b + c == 0)) {
            F = a + b + c;
        } else {
            F = a * b + c;
        }

        // Если побитовое условие не выполнено, выводим как целое
        if (!conditionBitwise) {
            cout << setw(10) << x << setw(20) << static_cast<int>(F) << endl;
        } else {
            cout << setw(10) << x << setw(20) << fixed << setprecision(4) << F << endl;
        }
    }

    return 0;
}