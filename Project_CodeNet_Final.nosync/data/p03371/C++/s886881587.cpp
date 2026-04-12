#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; i++)
using ll = long long;
using namespace std;

int main() {

    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = 0;
    if (X > Y) {
        ans = min(A * X + B * Y, (X - Y) * A + Y * 2 * C);
        ans = min(ans, (X - Y) * 2 * C + Y * 2 * C);
    } else {
        ans = min(A * X + B * Y, (Y - X) * B + X * 2 * C);
        ans = min(ans, (Y - X) * 2 * C + X * 2 * C);
    }

    cout << ans << endl;

    return 0;
}