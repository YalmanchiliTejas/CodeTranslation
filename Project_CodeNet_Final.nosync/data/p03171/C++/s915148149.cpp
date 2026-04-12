#include <bits/stdc++.h>

using namespace std;
#define ll long long int
ll n,ara[3005],dp[3005][3005][2];
bool vis[3005][3005][2];
ll func(ll l, ll r, ll turn)
{
    if(l>r) return 0;
    if(vis[l][r][turn]) return dp[l][r][turn];
    vis[l][r][turn]=true;
    if(!turn)
    {
        ll p1=ara[l]+func(l+1,r,1-turn);
        ll p2=ara[r]+func(l,r-1,1-turn);
        return dp[l][r][turn]=max(p1,p2);
    }
    else
    {
        ll p1=-ara[l]+func(l+1,r,1-turn);
        ll p2=-ara[r]+func(l,r-1,1-turn);
        return dp[l][r][turn]=min(p1,p2);
    }
}

int main()
{
    ll i,j;
    cin>>n;
    for(i=1; i<=n; i++) cin>>ara[i];
    ll ans=func(1,n,0);
    cout<<ans<<endl;
    return 0;


}


