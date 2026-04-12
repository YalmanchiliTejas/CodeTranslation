#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define CEIL(a, b) ((a - 1) / b + 1)

void solve() {
    int N, X, M;
    cin >> N >> X >> M;
    int sum = 0;
    unordered_map<int, pair<int, int>> mp;
    REP(i, N) {
        // 循環した初回のみループ変数iを最終ループへ飛ばす
        if (mp.count(X) > 0) {
            // 循環する長さ
            int len = i - mp[X].first;
            // 循環する回数 (加算後は最大でもN-1)
            int cnt = (N - 1 - i) / len;
            sum += (sum - mp[X].second) * cnt;
            i += len * cnt;
        } else {
            mp[X] = {i, sum};
        }
        sum += X;
        X = X * X % M;
    }
    cout << sum << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
}
