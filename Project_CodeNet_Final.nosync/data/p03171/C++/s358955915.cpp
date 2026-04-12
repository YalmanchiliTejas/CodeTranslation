#include <bits/stdc++.h>

using namespace std;
#define int long long
using ld = long double;

signed main() {
    int n;
    cin >> n;
    int arr[n+1];
    int i, j;
    for(i=1;i<=n;i++)
        cin >> arr[i];
    int dp[n+1][n+1][2];
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j][0] = dp[i][j][1] = 0;
    for(i=1;i<=n;i++)
    {
        dp[i][i][0] = arr[i], dp[i][i][1] = -arr[i];
    }
    for(i=1;i<n;i++)
        dp[i][i+1][0] = max(arr[i] - arr[i+1], arr[i+1] - arr[i]), dp[i][i+1][1] = min(arr[i]-arr[i+1], arr[i+1]-arr[i]);
    for(int len = 2;len < n;len++)
    {
        for(i=1;i<=(n-len);i++)
        {
            int j = i + len;
            dp[i][j][0] = max(dp[i][j-1][1] + arr[j], dp[i+1][j][1] + arr[i]);
            dp[i][j][1] = min(dp[i][j-1][0] - arr[j], dp[i+1][j][0] - arr[i]);
        }
    }
    cout << dp[1][n][0] << '\n';
}