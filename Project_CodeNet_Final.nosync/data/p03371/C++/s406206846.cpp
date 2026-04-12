// https://atcoder.jp/contests/abc095/tasks/arc096_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    // A, Bのみ買う
    int ans = A * X + B * Y;
    // ABピザのみ買う
    ans = min(ans, 2 * C * max(X, Y));
    // ABピザでA, Bの最小個数のみ買って、足りない分を買う
    if (X < Y) {
        ans = min(ans, 2 * C * min(X, Y) + B * (Y - X));
    } else {
        ans = min(ans, 2 * C * min(X, Y) + A * (X - Y));
    }
    cout << ans << endl;

    return 0;
}
