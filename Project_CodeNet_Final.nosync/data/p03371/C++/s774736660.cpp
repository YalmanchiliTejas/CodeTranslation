#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

int main() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    if (a + b <= 2 * c) {
        cout << a * x + b * y << endl;
    } else {
        int ans = 2 * c * min(x, y);
        if (x > y) {
            ans += (x - y) * min(a, 2 * c);
        } else {
            ans += (y - x) * min(b, 2 * c);
        }
        cout << ans << endl;
    }
}