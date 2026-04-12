#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = A * X + B * Y;

    ll tmp = C * 2 * X;
    chmin(ans, tmp + C * 2 * max(0LL, Y - X));
    chmin(ans, tmp + B * max(0LL, Y - X));

    tmp = C * 2 * Y;
    chmin(ans, tmp + C * 2 * max(0LL, X - Y));
    chmin(ans, tmp + A * max(0LL, X - Y));

    cout << ans << endl;
}
