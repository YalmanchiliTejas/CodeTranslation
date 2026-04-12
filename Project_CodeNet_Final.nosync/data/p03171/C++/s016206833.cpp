#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,0)));
    for(int i=0;i<n;i++)
    {
        dp[i][i][0]=a[i];
        dp[i][i][1]=-a[i];
    }
    for(int i=2;i<=n;i++)
    {
        for(int l=0;l+i-1<n;l++)
        {
            int r=l+i-1;
            dp[l][r][0]=max(a[l]+dp[l+1][r][1],a[r]+dp[l][r-1][1]);
            dp[l][r][1]=min(-a[l]+dp[l+1][r][0],-a[r]+dp[l][r-1][0]);
        }
    }
    cout << dp[0][n-1][0] << "\n";
    return 0;
}
