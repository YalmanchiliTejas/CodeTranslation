#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll>dp(1<<19,-2e18);
vector<ll>buf(1<<19);
ll n,m,ans;
void up(ll v, ll l, ll r) {
    dp[v]+=buf[v];
    if (l<r-1)
	{
        buf[2*v+1]+=buf[v];
        buf[2*v+2]+=buf[v];
    }
    buf[v]=0;
}
void add(ll v,ll l,ll r,ll L,ll R,ll x)
{
    up(v,l,r);
    if(r<=L||R<=l)return;
    if(L<=l&&r<=R)
	{
        buf[v]+=x;
        up(v,l,r);
        return;
    }
    ll m=(l+r)/2;
    add(2*v+1,l,m,L,R,x);
    add(2*v+2,m,r,L,R,x);
    dp[v]=max(dp[2*v+1],dp[2*v+2]);
}
void se(ll v,ll l,ll r,ll i,ll x)
{
    up(v,l,r);
    if(l==r-1)
	{
        dp[v]=x;
        return;
    }
    ll m=(l+r)/2;
    if(i<m)
	{
        se(2*v+1,l,m,i,x);
        up(2*v+2,m,r);
    }
	else
	{
        up(2*v+1,l,m);
        se(2*v+2,m,r,i,x);
    }
    dp[v]=max(dp[2*v+1],dp[2*v+2]);
}
int main()
{
    cin>>n>>m;
    vector<ll>l(n,0);
    vector<vector<pair<ll,ll> > >vec(n + 1);
    for(ll i=0;i<m;i++)
	{
        ll L,R,a;
        cin>>L>>R>>a;
        L--;
        l[L]+=a;
		vec[R].push_back(make_pair(L,a));
    }
    se(0,-1,n,-1,0);
    for(ll i=0;i<n;i++)
	{
        add(0,-1,n,-1,i,l[i]);
        for(ll j=0;j<vec[i].size();j++)
		{
			pair<ll,ll>x=vec[i][j];
            add(0,-1,n,-1,x.first,-x.second);
        }
        ans=max(ans,dp[0]);
        se(0,-1,n,i,dp[0]);
    }
    cout<<ans;
    return 0;
}