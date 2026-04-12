#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int A, B, C;
    ll X, Y;
    cin >> A >> B >> C >> X >> Y;

    if (A + B < C * 2) {
        cout << A * X + B * Y << endl;
        return 0;
    }

    ll ans = 0;

    const auto tmp_min = std::min(X, Y);
    ans += tmp_min * C * 2;
    X -= tmp_min;
    Y -= tmp_min;

    if (X == 0) {
        ans += B > C * 2 ? Y * C * 2 : Y * B;
    } else {
        ans += A > C * 2 ? X * C * 2 : X * A;
    }

    cout << ans << endl;

    return 0;
}
