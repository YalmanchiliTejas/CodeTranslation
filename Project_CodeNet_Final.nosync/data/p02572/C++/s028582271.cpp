#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main(){
    ll n; cin >> n; 
    vector<ll> a(n);
    for(ll i=0; i<n; ++i){cin >> a[i];}
    vector<ll> sum(n, 0); sum[0] = 0;  
    for(ll i=0; i<n-1; ++i){
        sum[i+1] = (sum[i]+a[n-1-i])%mod; 
    }

    ll res = 0;
    for(ll i=1; i<n; ++i){
        res += (sum[i]*a[n-1-i])%mod;
    }
    res %= mod;
    cout << res << endl;
    return 0;
}