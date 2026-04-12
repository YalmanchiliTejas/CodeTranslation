#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    c *= 2;
    ll ans = 1e11;
    for (int i = 0, n = max(x, y); i <= n; i++) {
        ll t = i * c + max(0, x - i) * a + max(0, y - i) * b;
        ans = min(ans, t);
    }
    cout << ans << endl;
}