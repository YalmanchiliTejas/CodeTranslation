#include <iostream>

using namespace std;

bool f(int r, int g, int b) {
    return (r * 100 + g * 10 + b) % 4 == 0; 
}

int main() {

    int r, g, b;
    cin >> r >> g >> b;

    if (f(r, g, b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
