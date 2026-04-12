#include <bits/stdc++.h>

#define MAXN 3005
#define MAXK 1000000
#define int long long
#define LL long long
#define pii pair<long, long>
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int N;
int mod = 1e9+7;
int a[MAXN];
int sum[MAXN];
int dp[MAXN][MAXN];

signed main() {
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i], dp[i][i] = a[i], sum[i] = sum[i-1] + a[i];
    for (int len = 2; len <= N; len++) {
        for (int i = 1; i+len-1 <= N; i++) {
            int j = i + len - 1;
            dp[i][j] = sum[j] - sum[i-1] - min(dp[i+1][j], dp[i][j-1]);
        }
    }
    cout << dp[1][N] - (sum[N ] - dp[1][N]) << endl; 
    return 0;
}