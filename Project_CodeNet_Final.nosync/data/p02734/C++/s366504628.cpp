#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MOD = 998244353;

int N, S;
int A[3010];
int dp[3010][3010];

signed main() {
    //cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> S;
    rep(i, N) cin >> A[i];
    dp[0][0] = 1;
    rep(i, N+1) rep(j, S) {
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= MOD;
        if (j+A[i]<=S) {
            if (j==0) dp[i+1][A[i]] = i+1;
            else {
                dp[i+1][j+A[i]] += dp[i][j];
                dp[i+1][j+A[i]] %= MOD;
            }
        }
    }
    int ans = 0;
    rep(i, N+1) {
        ans += dp[i][S]*(N-i+1);
        ans %= MOD;
    }
    cout << ans << endl;
}