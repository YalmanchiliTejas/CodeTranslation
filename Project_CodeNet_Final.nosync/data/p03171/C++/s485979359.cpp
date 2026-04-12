#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const ll sz=3010;
ll dp[sz][sz][3];
ll vis[sz][sz][3];

ll n, ara[sz];

ll cholo(ll l,ll r,ll mark)
{
    if(l>r) return 0ll;
    ll &ret=dp[l][r][mark];

    if(vis[l][r][mark] != -1) return ret;
    vis[l][r][mark]=1;

    if(mark==1){
        ll mx1=ara[l]+cholo(l+1,r,2);
        ll mx2=ara[r]+cholo(l,r-1,2);
        ret=max(mx1, mx2);
    }
    else{
        ll mx1=cholo(l+1,r,1)-ara[l];
        ll mx2=cholo(l,r-1,1)-ara[r];
        ret=min(mx1, mx2);
    }

    return ret;
}


int main()
{
    ll m,p,q,i,j,k,l;
    cin>>n;

    for(i=1;i<=n;i++) cin>>ara[i];
    memset(vis,-1,sizeof vis);
    ll ans=cholo(1,n,1);
    cout<<ans<<'\n';
}
