#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if (a + b <= 2 * c) cout << a * x + b * y << endl;
    else {
        if (x >= y) cout << min(2 * c * x, 2 * c * y + a * (x - y)) << endl;
        else cout << min(2 * c * y, 2 * c * x + b * (y - x)) << endl;
    }
}