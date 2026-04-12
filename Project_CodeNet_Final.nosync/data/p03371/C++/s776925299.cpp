#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    if (A + B >= 2 * C) {
        ans += min(X, Y) * 2 * C;
        ans += A >= 2 * C ? (X - min(X, Y)) * 2 * C : (X - min(X, Y)) * A;
        ans += B >= 2 * C ? (Y - min(X, Y)) * 2 * C : (Y - min(X, Y)) * B;
    } else
        ans += X * A + Y * B;
    cout << ans << endl;
}