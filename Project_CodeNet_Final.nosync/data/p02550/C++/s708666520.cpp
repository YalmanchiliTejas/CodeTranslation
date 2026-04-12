#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
const ll sz=5e5+100;
 
 
ll sum[sz];
ll mod;
ll ans=0;

map<ll,ll> mp;
 
ll Fun(ll x)
{
    ll p=((sum[x-1])*(sum[x-1]))%mod;
    sum[x]=p;
    ans+=p;
    return p;
}
 
 
int main()
{
     
    ll  x,n;
 
    cin>>n>>x>>mod;
 
    sum[1]=x;

    ll siz=1;

    mp[x]=1;
    ans+=x;
    ll id=0;
    
 
    for(ll i=2;i<=min(n, sz-1);i++){
        x=Fun(i);
        if(x==0){
            cout<<ans<<'\n';
            return 0;
        }

        if(mp.count(x)==1){
            ans-=x;
            siz=(i-mp[x]), id=mp[x];
            n-=(i-1);
            break;
        }

        mp[x]=i;

        if(i==n){
            cout<<ans<<'\n';
            return 0;
        }
    }

    ll tot=0;

    for(ll i=1;i<=siz;i++) tot=(tot+ sum[i+id-1]);
    
    ans+=((n/siz)*tot);
    ll m=(n % siz);

    for(int i=1;i<=m;i++) ans+=sum[i+id-1];
    cout<<ans<<'\n';
}
 