#include<bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int sum=0;
    for(auto u:v) sum+=u;

    vector<vector<int>> dp(n,vector<int> (n,-1));
    
    for(int i=0;i<n;i++) dp[i][i]=v[i];
    for(int i=0;i<n-1;i++) dp[i][i+1]=max(v[i],v[i+1]);

    for(int d=2;d<n;d++)
    {
        for(int i=0;i+d<n;i++)
        {
            int j=i+d;
            dp[i][j]=max(v[i]+min(dp[i+2][j],dp[i+1][j-1]),v[j]+min(dp[i+1][j-1],dp[i][j-2]));
        }
    }

    int ans=dp[0][n-1]-(sum-dp[0][n-1]);
    cout<<ans<<"\n";
    return 0;
}