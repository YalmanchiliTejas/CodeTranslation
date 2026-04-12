#include<bits/stdc++.h>
using namespace std;

#define mx 3005
typedef long long int ll;
ll a[mx];
ll dp[mx][mx][2];
ll cal(ll l,ll r,ll ok)
{
    if(l>r) return 0;
    if(dp[l][r][ok]!=-1) return dp[l][r][ok];
    if(ok==0){

        ll ans=max(a[l]+cal(l+1,r,!ok),cal(l,r-1,!ok)+a[r]);
        //cout<<l<<" "<<r<<" "<<ans<<endl;
        return dp[l][r][ok]=ans;
    }
    else{
        ll ans=min(cal(l+1,r,!ok)-a[l],cal(l,r-1,!ok)-a[r]);
        //cout<<l<<" "<<r<<" "<<ans<<endl;
        return dp[l][r][ok]=ans;
    }
}
int main()
{
    ll n,m;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<cal(1,n,0)<<endl;
}
