#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    //dp[i + 1][j] A[i]までで和がjにできるような場合の数
    ll N, S, MOD = 998244353;
    cin >> N >> S;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<vector<ll>> dp(N + 1, vector<ll>(3001, 0));
    rep(i, N) {
        dp[i + 1][A[i]] += i + 1;
        dp[i + 1][A[i]] %= MOD;
        rep(j, S + 1) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
            if (j + A[i] <= S) {
                dp[i + 1][j + A[i]] += dp[i][j];
                dp[i + 1][j + A[i]] %= MOD;
            }
        }
    }
    int ans = 0;
    rep(i, N + 1) {
        ans += dp[i][S];
        ans %= MOD;
    }
    cout << ans << "\n";
    /*
    rep(i, N + 1) {
        rep(j, S + 1) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
}