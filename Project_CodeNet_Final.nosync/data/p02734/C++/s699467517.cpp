#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll mod = 998244353;
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    vector<vector<ll>> dp(N+1, vector<ll>(S+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        if (S >= A[i-1]) dp[i][A[i-1]] += i;
        for (int j = 1; j <= S; j++) {
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
            if (j+A[i-1] <= S) {
                dp[i][j+A[i-1]] += dp[i-1][j];
                dp[i][j+A[i-1]] %= mod;
            }
        }
    }
    
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += (dp[i][S] - dp[i-1][S] + mod) * (N+1-i);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}