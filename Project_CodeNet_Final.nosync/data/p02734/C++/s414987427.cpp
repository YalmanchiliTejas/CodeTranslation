#include<bits/stdc++.h>
using namespace std;
long long arr[3005];
long long dp[3005][3005];
long long cdp[3005][3005];
int main()
{
   /* #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    int n,s;
    cin>>n>>s;
    for (int i = 1; i <= n; i++) 
    cin >> arr[i];
    long long ans=0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][arr[i]] = i;
        for (int j = arr[i] + 1; j < 3005; j++)
        dp[i][j] = dp[i - 1][j - arr[i]];
        ans += (dp[i][s] * (n - i + 1))%998244353;
        ans%=998244353;
        for (int j = 0; j < 3005; j++) 
        dp[i][j] = (dp[i - 1][j] + dp[i][j])%998244353;
    }
    cout << ans << endl;
    return 0;
}
