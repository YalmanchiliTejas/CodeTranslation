#include <bits/stdc++.h>

#define MAXN 10005
#define MAXD 105
#define int long long
#define LL long long
#define pii pair<long, long>
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string K;
int N[MAXN];
int D;
int n;
int mod = 1e9+7;
int dp[11][MAXN][MAXD];

signed main() {
    fastio;
    cin >> K;
    cin >> D;
    for (char c: K) {
        N[++n] = c - '0';
    }
    for (int i = 0; i < 10; i++) {
        dp[i][1][i%D] = 1 % mod;
        dp[10][1][i%D] = (dp[10][1][i%D] + 1) % mod;
    }
    
    for (int j = 2; j <= n; j++) {
        for (int i = 0; i < 10; i++) {
            for (int d = 0; d < D; d++) {
                dp[i][j][(d+i)%D] = (dp[i][j][(d+i)%D] + dp[10][j-1][d]) % mod;
            }
            for (int d = 0; d < D; d++) {
                dp[10][j][d] = (dp[10][j][d] + dp[i][j][d]) % mod;
            }
        }
    }

    int ans = 0;
    int d = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < N[i]; j++) {
            ans = (ans + dp[j][n-i+1][(D-d)%D]) % mod;
        }
        
        d = (d + N[i]) % D;
        if (i == n && d == 0) ans = (ans + 1) % mod;
    }
    ans = (ans - 1 + mod) % mod;
    cout << ans << endl;
    return 0;
}