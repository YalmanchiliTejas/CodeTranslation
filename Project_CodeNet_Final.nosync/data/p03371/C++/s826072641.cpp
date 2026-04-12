#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;
    if (A + B >= 2 * C) {
        int mi = min(X, Y);
        ans += mi * 2 * C;
        X -= mi;
        Y -= mi;

        if (!(X == Y && X == 0)) {
            if (X == 0) {
                if (B <= 2 * C)
                    ans += B * Y;
                else
                    ans += 2 * C * Y;
            } else {
                if (A <= 2 * C)
                    ans += A * X;
                else
                    ans += 2 * C * X;
            }
        }
    } else {
        ans += A * X + B * Y;
    }

    cout << ans << endl;

    return 0;
}
