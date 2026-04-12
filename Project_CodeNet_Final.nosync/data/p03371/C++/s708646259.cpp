#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a, b, c, x, y, tmp = 1e9, ans = 0;
    cin >> a >> b >> c >> x >> y;
    if (x > y) {
        ans = min({a * x + y * b, c * 2 * y + (x - y) * a, 2 * c * x});

    } else
        ans = min({a * x + y * b, 2 * c * x + (y - x) * b, 2 * c * y});

    cout << ans << endl;
}