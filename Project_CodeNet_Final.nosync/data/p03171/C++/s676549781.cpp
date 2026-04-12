#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll dp[n+1][n+1][2];
    memset(dp,0,sizeof(dp));
    for(ll x=0;x<n;x++)
    {
      cin>>a[x];
      dp[x][1][0]=a[x];
      dp[x][1][1]=-a[x];
    }
    for(ll x=2;x<=n;x++)
    {for(ll y=0;y<=n-x;y++)
    {dp[y][x][0]=max(a[y]+dp[y+1][x-1][1],a[y+x-1]+dp[y][x-1][1]);
     dp[y][x][1]=min(-a[y]+dp[y+1][x-1][0],-a[y+x-1]+dp[y][x-1][0]);}}
     cout<<dp[0][n][0]<<endl;
}
