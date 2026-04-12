
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=3e3+9;
ll a[inf],n;
pair<ll,ll> dp[inf][inf][2];

pair<ll,ll> solve(ll l,ll r,bool player){
    if(l>r)
        return make_pair(0,0);

    pair<ll,ll> &ret=dp[l][r][player];
    if(ret.first!=-1)
        return ret;

    if(player){
        pair<ll,ll>d=solve(l+1,r,0);
        d.first+=a[l];
        pair<ll,ll> f=solve(l,r-1,0);
        f.first+=a[r];
        if(f>d || (f.first==d.first && f.second<d.second))
            ret=f;
       else ret=d;
    }

    else{
        pair<ll,ll>d=solve(l+1,r,1);
        d.second+=a[l];
        pair<ll,ll> f=solve(l,r-1,1);
        f.second+=a[r];
        if(f<d || (f.first==d.first && f.second>d.second))
            ret=f;
       else ret=d;
    }

    return ret;
}

int main(){

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    memset(dp,-1,sizeof(dp));
    pair<ll,ll> p=solve(1,n,1);
    cout<<p.first-p.second<<endl;
}
