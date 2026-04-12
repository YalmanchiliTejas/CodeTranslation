#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    int M = N % 2 == 0 ? 2 : 3;
    vector<vector<ll>> dp(N+1,vector<ll>(M)); // dp[i][j]:空きをj個使用

    for ( int i = 1; i <= N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( i > 2 ) {
                dp[i][j] = -1e15;
            } else {
                dp[i][j] = 0;
            }
        }
        for ( int j = 0; j < M; j++ ) {
            if ( i-2 >= 0 ) dp[i][j] = max(dp[i][j], dp[i-2][j]);
        }
        for ( int j = 1; j < M; j++ ) {
            if ( i-3 >= 0 ) dp[i][j] = max(dp[i][j], dp[i-3][j-1]);
        }
        for ( int j = 2; j < M; j++ ) {
            if ( i-4 >= 0 ) dp[i][j] = max(dp[i][j], dp[i-4][j-2]);
        }
        for ( int j = 0; j < M; j++ ) {
            dp[i][j] += A[i-1];
        }
    }
    ll ans = -1e15;
    for ( int j = 0; j < M; j++ ) {
        ans = max(ans, dp[N-j][M-1-j]);
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}