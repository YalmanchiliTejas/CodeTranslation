#include<bits/stdc++.h>
#define int int64_t
using namespace std;

const int M = 1e9+7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n , k;
    cin >> n;
    k = n/2;
    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int dp[n+1][2];
    dp[1][0] = dp[0][0] = dp[0][1] = 0;
    dp[1][1] = a[1];
    for(int i = 2; i <= n; i++) {
        if(i & 1) {
            dp[i][0] = max(a[i] + dp[i-2][0] , max(a[i] + dp[i-3][0] , dp[i-1][0]));
            dp[i][1] = a[i] + dp[i-2][1];
        }
        else {
            dp[i][0] = max(a[i] + dp[i-2][0] , dp[i-1][1]);
        }
    }
    cout << dp[n][0] << "\n";

    return 0;
}
