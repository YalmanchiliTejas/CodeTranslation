#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];
    ll ans = 0;
    ll s = 0;
    rep(i, n-1){
        s = (s + a[i+1])%mod;
    }
    rep(i, n-1){
        ans += (s*a[i])%mod;
        s -= a[i+1];
        if(s < 0) s += mod;
    }
    ans %= mod;
    cout << ans << endl;
}