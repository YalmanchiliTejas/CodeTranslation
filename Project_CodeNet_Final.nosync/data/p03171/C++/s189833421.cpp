#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=100010;

ll n;
ll ar[N];
ll dp[3001][3001][2];
ll func(ll st,ll en,ll t)
{
    if(st>en){return 0;}
    if(dp[st][en][t]==-1){
    ll ans;
    if(t==0)
    {
        ans=max(ar[st]+func(st+1,en,1),ar[en]+func(st,en-1,1));
    }
    else
    {
        ans=min(func(st+1,en,0),func(st,en-1,0));
    }
    dp[st][en][t]=ans;
    }
    return dp[st][en][t];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll sum=0;
    cin>>n;
    for(ll i=0;i<n;++i){cin>>ar[i];sum+=ar[i];}
    memset(dp,-1,sizeof(dp));
    ll ans=func(0,n-1,0);

    ans=2*ans-sum;

    cout<<ans<<endl;

    return (0);
}
