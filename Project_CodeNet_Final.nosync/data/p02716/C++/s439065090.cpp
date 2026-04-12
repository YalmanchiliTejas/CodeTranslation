#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 2e5 + 10;
int a[M];
ll dp[M][3];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            dp[i][j] = -1e18;
        }
    }
    dp[1][0] = a[1], dp[2][1] = a[2], dp[3][0] = a[1] + a[3], dp[3][2] = a[3];
    for(int i = 4; i <= n; i++) {
        dp[i][0] = dp[i - 2][0] + a[i];
        dp[i][1] = max(dp[i - 2][1], dp[i - 3][0]) + a[i];
        dp[i][2] = max(dp[i - 2][2], max(dp[i - 3][1], dp[i - 4][0])) + a[i];
    }
    ll ans;
    if(n & 1) ans = max(dp[n][2], max(dp[n - 1][1], dp[n - 2][0]));
    else ans = max(dp[n][1], dp[n - 1][0]);
    printf("%lld\n", ans);
    return 0;
}
