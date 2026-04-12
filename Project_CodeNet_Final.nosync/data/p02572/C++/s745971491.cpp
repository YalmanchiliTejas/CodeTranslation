#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    int n;
    cin>>n;
    ll ans = 0;
    ll mod = 1e9+7;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<ll> sum(n+1);
    sum[0]=0;
    for(int i=0; i<n; i++) sum[i+1] = sum[i]+a[i];
    for(int i=0; i<n-1; i++){
        ll tmp1 = sum[n]-sum[i+1];
        tmp1 %= mod;
        ll tmp = a[i]*tmp1;
        tmp %= mod;
        ans += tmp;
        ans %= mod;
    }
    cout<<ans%mod<<endl;
}