#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n,mod=pow(10,9)+7;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> v(n);
    v[n-1]=a[n-1];
    for(ll i=n-2;i>=0;i--)  v[i]=(v[i+1]+a[i])%mod;
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        ans += ((a[i]%mod) * (v[i+1]%mod))%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
