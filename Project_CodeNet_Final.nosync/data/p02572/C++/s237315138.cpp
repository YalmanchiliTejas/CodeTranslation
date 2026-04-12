#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
const ll mod=1e9+7;
ll mpow(ll x,ll n){
    if(n==0)return 1;
    if(n%2==0) return mpow(x*x%mod,n/2);
    else return x*mpow(x,n-1)%mod;
}
int main(void){
    ll n;
    cin>>n;
    vector<ll>a(n);
    ll tmp1=0,tmp2=0;
    rep(0,i,n){
        cin>>a[i];
        tmp1=(a[i]+tmp1)%mod;
        tmp2=(tmp2+a[i]*a[i]%mod)%mod;
    }
    cout<<(tmp1*tmp1%mod-tmp2+mod)%mod*mpow(2,mod-2)%mod;
}
