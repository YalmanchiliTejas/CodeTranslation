#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1000000007;
ll mod(ll x){
        return ((x%M + M)%M);
    }
ll add(ll a, ll b){
        return mod(mod(a)+mod(b));
    }
ll mul(ll a, ll b){
        return mod(mod(a)*mod(b));
    }
ll minu(ll a, ll b){
        return mod(mod(a)-mod(b));
    }
ll power(ll a, ll b){
    ll res=1;
    while(b>0){
        if(b&1) res=mul(res,a);
        b = b>>1;
        a=mul(a,a);
    }
    return res;
}
int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll s=0;
    for(ll i=0;i<n;++i){
        cin>>a[i];
        s=add(s,a[i]);
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        s=minu(s,a[i]);
        ll val=mul(a[i],s);
        ans=add(ans,val);
    }
    cout<<ans;
    return 0;
}