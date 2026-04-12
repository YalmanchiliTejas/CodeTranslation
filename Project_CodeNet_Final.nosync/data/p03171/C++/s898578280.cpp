
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[3003],dp[3009][3009][2];

ll solve(ll l,ll r,bool turn){
   if(l>r)
        return 0;
    ll &ret=dp[l][r][turn];
    if(ret!=-1)
        return ret;
    if(!turn)
        ret=max(solve(l+1,r,!turn)+a[l],a[r]+solve(l,r-1,!turn));

    else
        ret=min(solve(l+1,r,!turn),solve(l,r-1,!turn));

    return ret;
}
int main(){
    ll n,sum=0;
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i],sum+=a[i];

    memset(dp,-1,sizeof(dp));
    ll ans=solve(1,n,0);
    cout<<ans-(sum-ans)<<endl;
}