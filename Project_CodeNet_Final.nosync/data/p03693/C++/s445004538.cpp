#include <iostream>

using namespace std;

int main(void) {
    long long r, g, b;
    cin >> r >> g >> b;
    if ((r * 100 + g * 10 + b) % 4 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}