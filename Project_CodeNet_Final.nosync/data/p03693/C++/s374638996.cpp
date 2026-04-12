#include <bits/stdc++.h>

using namespace std;

int main() {
    int r = 0, g = 0, b = 0, sum = 0;
    cin >> r >> g >> b;

    sum = 100 * r + 10 * g + b;

    if (sum % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}