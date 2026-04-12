#include <iostream>
#include <string>

using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int ful = r * 100 + g * 10 + b * 1;
    if (ful % 4 == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}