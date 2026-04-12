// https://atcoder.jp/contests/arc091/tasks/arc091_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = m + 1; i <= n; i++) {
        ll mok = n / i;
        ans += mok * (i - m);
        if ((n % i) >= m) {
            ans += (n % i) - m + 1;
        }
    }
    if (m == 0)
        ans -= n;
    cout << ans << endl;

    return 0;
}
