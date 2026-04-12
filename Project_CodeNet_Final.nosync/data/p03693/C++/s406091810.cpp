#include <iostream>

using namespace std;

int main() {
    int r, g, b;
    cin >> r;
    cin >> g;
    cin >> b;
    int num = r * 100 + g * 10 + b;
    //cout << num;
    if (num % 4 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
