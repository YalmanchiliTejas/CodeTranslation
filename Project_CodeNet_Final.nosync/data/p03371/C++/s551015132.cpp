#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

int A, B, C, X, Y;

int main() {
    cin >> A >> B >> C >> X >> Y;

    long long ans = 1e10;
    for (int i = 0; i <= 1e5; i++) {
        long long tmp = (i * 2 * C) + A * max(X - i, 0) + B * max(Y - i, 0);
        ans = min(tmp, ans);
    }

    cout << ans << endl;
}