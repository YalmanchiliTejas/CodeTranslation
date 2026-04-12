#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long  ans = 0;
    while(x > 0 || y > 0) {
        long long  f = min(x, y);
        if(f <= 0) {
            f = max(x, y);
        }
        long long  q = c * f * 2;
        long long  w = (a * min(f, x)) + (min(f, y) * b);
        ans += min(q, w);
        x = max(0ll, x - f);
        y = max(0ll, y - f);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
