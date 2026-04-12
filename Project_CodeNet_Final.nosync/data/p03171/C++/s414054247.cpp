#include <bits/stdc++.h>
using namespace std;
int a[3010], n;
long long dp[3010][3010], sum;
long long solve(int l, int r){
    //printf("%d %d\n", l, r);
    if (dp[l][r] != 0)
        return dp[l][r];
    if (l > r)
        return 0;
    /*if (l == r)
        return dp[l][r] = a[l];
    if (l + 1 == r)
        return dp[l][r] = max(a[l], a[r]);
    */
    dp[l][r] = a[l] + min(solve(l + 1, r - 1), solve(l + 2, r));
    dp[l][r] = max(dp[l][r], a[r] + min(solve(l + 1, r - 1), solve(l, r - 2)));
    //!!not maxxxxxx opponent want to minimize what player 1 gets
    //printf("%d %d %lld!\n", l, r, dp[l][r]);
    return dp[l][r];
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    //memset(dp, 0, sizeof(dp));
    solve(1, n);
    //printf("%lld\n", dp[1][n]);
    printf("%lld\n", 2 * dp[1][n] - sum);
    return 0;
}