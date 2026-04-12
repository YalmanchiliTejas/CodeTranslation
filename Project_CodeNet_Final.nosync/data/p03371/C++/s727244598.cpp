#ifdef LOCAL
//#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //    freopen("out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    ll ans = 0;
    ll z = min(x, y);
    
    if (a + b > 2 * c) {
        ans += 2 * c * z;
        x -= z;
        y -= z;
    } else {
        ans += a * z;
        ans += b * z;
        x -= z;
        y -= z;
    }
    
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    
    if (a > 2 * c) {
        ans += 2 * c * x;
    } else {
        ans += a * x;
    }
    
    cout << ans << endl;
    
    return 0;
}
