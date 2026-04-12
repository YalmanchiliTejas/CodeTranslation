#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++)
    cin>>a[i];
    vector<vector<vector<ll> >  > dp(n+3,vector<vector<ll> > (n+3,vector<ll> (3,0)));
    // let dp[i][j] denotes that we have found the answer for i,i+1....j-1,j and we want to expand our answer. the answer will be dp[1][n];
    for(ll i=n;i>=1;i--)
    {
        for(ll j=i;j<=n;j++)
        {
            dp[i][j][0]=max(dp[i][j-1][1]+a[j],dp[i+1][j][1]+a[i]);
            dp[i][j][1]=min(dp[i][j-1][0]-a[j],dp[i+1][j][0]-a[i]);
        }
    }
    cout<<dp[1][n][0]<<endl;

    
    
}