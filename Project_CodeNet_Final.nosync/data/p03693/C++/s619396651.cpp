#include <iostream>

using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int value = r * 100 + g * 10 + b;
    cout << (value >= 4 && value % 4 == 0 ? "YES" : "NO") << endl;
    return 0;
};
