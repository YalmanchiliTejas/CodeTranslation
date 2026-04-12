#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n),sa(n,0);
    rep(i,n) cin>>a[i];
    rep(i,n){
        if(i==0) sa[n-1-i]=a[n-1-i];
        else sa[n-1-i]=(sa[n-i]+a[n-1-i])%mod;
    }
    ll ans=0;
    rep(i,n-1) ans+=a[i]*sa[i+1],ans%=mod;
    cout<<ans<<endl;
    return 0;
}