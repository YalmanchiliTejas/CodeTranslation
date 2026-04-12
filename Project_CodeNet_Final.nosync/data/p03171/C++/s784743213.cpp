#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    vector<vector<int>>dp(3000, vector<int>(3000));
    int n;
    cin>>n;
    vector<int>a(n, 0);
    for(auto &ai:a) cin>>ai;

    for(int l=0; l<n; ++l)
    {
        dp[l][l]=a[l];
    }

    for(int d=1; d<=n-1; ++d)
    {
        for(int l=0; l<n-d; ++l)
        {
            int r=l+d;
            dp[l][r]=max(-dp[l][r-1]+a[r], -dp[l+1][r]+a[l]);
        }
    }
    cout<<dp[0][n-1];
}