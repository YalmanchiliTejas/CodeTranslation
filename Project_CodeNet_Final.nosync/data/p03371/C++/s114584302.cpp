#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long ans = 0;
    if (2 * c <= a + b) {
        ans += 2 * c * min(x, y);
        long z = min(x, y);
        x -= z;
        y -= z;
        if (x > 0) {
            if (a <= 2 * c) {
                ans += a * x;
            } else {
                ans += 2 * c * x;
            }
        } else if (y > 0) {
            if (b <= 2 * c) {
                ans += b * y;
            } else {
                ans += 2 * c * y;
            }
        }
    } else {
        ans += a * x + b * y;
    }
    cout << ans << endl;
}