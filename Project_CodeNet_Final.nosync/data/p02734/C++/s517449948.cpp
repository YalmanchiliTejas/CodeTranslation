#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

const int MOD = 998244353;
int N, S;
int A[3000];
int dp[3010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    REP (i, N) cin >> A[i];
    dp[0] = 0;
    int ans = 0;
    REP (i, N) {
        for (int j = S; j - A[i] >= 0; --j) {
            if (j == A[i]) (dp[j] += i + 1) %= MOD;
            else (dp[j] += dp[j - A[i]]) %= MOD;
        }
        (ans += dp[S]) %= MOD;
    }
    cout << ans << endl;
}