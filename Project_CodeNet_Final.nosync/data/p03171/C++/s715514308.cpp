#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[3000];
ll dp[3000][3000][2];
ll solve(ll i,ll j,ll t)
{
    if(i>j)
        return 0;
    if(i==j)
        return (t==0)?a[i]:(-a[i]);
    if(dp[i][j][t]!=0)
        return dp[i][j][t];
    if(t==0)
        dp[i][j][t]=max(a[i]+solve(i+1,j,1-t),a[j]+solve(i,j-1,1-t));
    else
        dp[i][j][t]=min(solve(i+1,j,1-t)-a[i],solve(i,j-1,1-t)-a[j]);
    return dp[i][j][t];
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll v=solve(0,n-1,0);
    cout<<(v)<<endl;

    return 0;
}
