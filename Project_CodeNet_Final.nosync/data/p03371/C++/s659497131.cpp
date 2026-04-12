#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = A * X + B * Y;
    ll max_cnt = max(X, Y) + 1;
    rep(i, max_cnt) {
        ll now = A * max(0LL, X - i) + B * max(0LL, Y - i) + C * 2 * i;
        chmin(ans, now);
    }
    cout << ans << endl;
}
