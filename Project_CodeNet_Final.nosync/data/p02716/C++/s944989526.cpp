#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(v) for (auto itr = v.begin(), itr != v.end(); ++itr)
#define LB(v, x) lower_bound(v.begin(), v.end(), x) - v.begin()
#define UB(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    vector<map<int, ll>> dp(N + 1);
    dp[0][0] = 0;
    REP(i, N) {
        if (i == 0) {
            dp[i + 1][0] = 0;
            dp[i + 1][1] = A[i];
            continue;
        }
        FOR(j, i / 2, i / 2 + 2) {
            dp[i + 1][j] = -(ll)1e18;
            if (dp[i].count(j)) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (dp[i - 1].count(j - 1))
                dp[i + 1][j] = max(dp[i + 1][j], dp[i - 1][j - 1] + A[i]);
        }
    }
    cout << dp[N][N / 2] << endl;

    return 0;
}
