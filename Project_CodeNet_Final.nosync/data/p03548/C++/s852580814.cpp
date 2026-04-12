#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    x -= z * 2;

    int a = y + z;

    int b = x / a;

    if (x - b * (y + z) >= y) {
        cout << b + 1 << endl;
    } else {
        cout << b << endl;
    }
}