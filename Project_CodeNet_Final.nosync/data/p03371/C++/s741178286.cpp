#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int p = 0, q = 0;
    int r = max(x, y) * 2;
    int ans = 1001001001;
    while (r >= 0) {
        p = max(0, x - r / 2);
        q = max(0, y - r / 2);
        ans = min(ans, a * p + b * q + c * r);
        r -= 2;
    }
    cout << ans << endl;
}
