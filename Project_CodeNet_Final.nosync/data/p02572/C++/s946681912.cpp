#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)cin>>v[i];
    vector<ll>sum(n);
    sum[n-1]=v[n-1];
    for(ll i=n-2;i>=0;i--){
        sum[i]=(sum[i+1]%mod)+v[i]%mod;
        sum[i]%=mod;
    }
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        ans+=(v[i]%mod)*(sum[i+1]%mod);
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}

