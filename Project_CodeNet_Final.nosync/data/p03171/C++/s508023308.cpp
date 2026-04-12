#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll dp[3001][3001][2];
ll sol(ll a[],ll i,ll j,ll turn)
{
    if(i>j)
        return 0;
    if(dp[i][j][turn]!=-1)
        return dp[i][j][turn];
    if(turn==1)
    {
        dp[i][j][turn]=max(a[i]+sol(a,i+1,j,0),a[j]+sol(a,i,j-1,0));
    }
    else
        dp[i][j][turn]=min(sol(a,i+1,j,1),sol(a,i,j-1,1));
    return dp[i][j][turn];
}
int main()
{
    ll n;
    cin>>n;
    ll a[n+1];
    ll sum=0;
    memset(dp,-1,sizeof(dp));
    for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
    ll p1=sol(a,1,n,1);
    ll p2=sum-p1;
    ll ans=p1-p2;
    cout<<ans<<endl;
    return 0;
}
