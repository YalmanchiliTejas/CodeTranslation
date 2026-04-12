#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
long long modpow(long long x,long long n,long long mod){
    long long res = 1;
    while(n > 0) {
        if(n & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        n>>=1;
    }
    return res;
}

long long modinv(long long x, long long mod){
    return modpow(x, mod - 2, mod); }
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll tmp = 0;
    for (ll i = 0; i < n; i++) {
        tmp += a[i];
        tmp %= MOD;
    }
    tmp = modpow(tmp, 2, MOD);
    for (ll i = 0; i < n;i++){
        if (a[i] == 0) continue;
        tmp -= modpow(a[i], 2, MOD);
        while (tmp < 0) tmp += MOD;
        tmp %= MOD;
    }
    ll ans = tmp * modinv(2, MOD);
    ans %= MOD;
    cout << ans << endl;
}