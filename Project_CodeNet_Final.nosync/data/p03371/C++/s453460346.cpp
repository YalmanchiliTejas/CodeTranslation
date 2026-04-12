#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = A * X + B * Y;
    ans = min(ans, 2 * C * X + max(0ll, (Y - X) * B));
    ans = min(ans, 2 * C * Y + max(0ll, (X - Y) * A));
    cout << ans << endl;
}
