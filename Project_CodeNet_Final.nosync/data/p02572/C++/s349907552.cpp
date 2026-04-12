#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
ll MOD = 1e9 + 7;
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    vector<ll>a(n);
    ll s = 0;
    rep(i, n ){
        cin >> a[i];
        s+= a[i];
    }
    rep(i, n) {
        s -= a[i];
        ans += ((s%MOD)*a[i])%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}

