#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
const int mod=1e9+7;
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
        sum%=mod;
    }
    ll ans=0;
    ll q=0;
    ll p=0;
    rep(i,n-1){
        sum-=a[i];
        if(sum<0)sum+=mod;
        ans+=(a[i]*sum)%mod;
    }
    cout<<ans%mod;
    }