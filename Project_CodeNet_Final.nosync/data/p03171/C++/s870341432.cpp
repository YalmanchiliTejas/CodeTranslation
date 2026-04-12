#include<bits/stdc++.h>
#define ll long long
ll dp[3001][3001];
using namespace std;
ll solve(ll ar[],ll i,ll j)
{
    if(i>j){return 0;}
    if(i==j){return ar[i];}
    if(dp[i][j]!=-1){return dp[i][j];}
    return dp[i][j]=max(ar[i]+min(solve(ar,i+2,j),solve(ar,i+1,j-1)),ar[j]+min(solve(ar,i,j-2),solve(ar,i+1,j-1)));
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin>>n;
    ll ar[n],sum=0;
    for(ll i=0;i<n;++i){cin>>ar[i];sum+=ar[i];}
    memset(dp,-1,sizeof(dp));
    ll ans=solve(ar,0,n-1);
    ans=ans-sum+ans;
    cout<<ans;
}