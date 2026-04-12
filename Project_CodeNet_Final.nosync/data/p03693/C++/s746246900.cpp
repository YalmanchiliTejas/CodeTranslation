#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    int r;
    int g;
    int b;
    cin >> r >> g >> b;
    int number = r * 100 + g * 10 + b;
    if (number % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
