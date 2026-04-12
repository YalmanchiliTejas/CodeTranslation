#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < n; i++)

void solve();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(void) {
    init();
    solve();
    return 0;
}

void solve() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll buyAB = max(x, y);
    ll minPrice = INT64_MAX;
    rep (i, buyAB + 1) {
        ll price = 0;
        if (x - i > 0) {
            price += (x - i) * a;
        }
        if (y - i > 0) {
            price += (y - i) * b;
        }
        price += i * 2 * c;
        minPrice = min(price, minPrice);
    }
    cout << minPrice << "\n";
}
