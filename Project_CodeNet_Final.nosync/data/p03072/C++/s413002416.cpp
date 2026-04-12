// https://atcoder.jp/contests/abc124/tasks/abc124_b
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define CEIL(a, b) ((a - 1) / b + 1)

void solve() {
    int N;
    cin >> N;
    vector<int> H(N);
    REP(i, N) { cin >> H[i]; }
    int ans = 1, maxv = H[0];
    FOR(i, 1, N) {
        if (H[i] >= maxv) {
            ans++;
        }
        maxv = max(maxv, H[i]);
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
}
