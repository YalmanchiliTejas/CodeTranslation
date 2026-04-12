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
    ll n, k, cnt = 0;
    cin >> n >> k;
    if (k == 0) {
        cout << n * n << endl;
    } else {
        // 割る数を固定
        for (int i = k + 1; i <= n; i++) {
            ll group = (n + 1) / i;
            ll rem = (n + 1) - (group * i);
            ll add = max(rem - k, 0LL);
            cnt += (i - k) * group + add;
        }
        cout << cnt << endl;
    }

    return 0;
}
