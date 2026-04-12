#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;
    if (a + b <= 2 * c)
        cout << a * x + b * y << endl;
    else {
        int n = min(x, y), m = max(x, y);
        cout << min(2 * n * c + a * (x - n) + b * (y - n), 2 * m * c) << endl;
    }

    return 0;
}
