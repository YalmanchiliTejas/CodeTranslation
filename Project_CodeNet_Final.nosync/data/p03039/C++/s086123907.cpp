#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll mod = 1000000007;

ll modinv(ll a){
    ll b = mod, u = 1, v = 0;
    while(b){
        ll t = a/ b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if(u < 0) u+=mod;
    return u;
}

ll comb(ll a, ll b){
    if(a==b||b==0)return 1;
    if(b*2>a)b = a - b;
    ll x = 1;
    rep(i, b){
        x *= a-i;
        x %= mod;
        x *= modinv(b-i);
        x %= mod;
    }
    return x;
}

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll nm = n * m;
    ll memo = 0, ans = 0;
    rep(i, m){
        memo += (i+1)*(m-1-i);
        memo %= mod;
    }
    memo *= n; memo %= mod;
    memo *= n; memo %= mod;
    memo *= comb(nm-2, k-2); memo %= mod;
    ans += memo;
    memo = 0;
    rep(i, n){
        memo += (i+ 1) * (n-1-i);
        memo %= mod;
    }
    memo *= m; memo %= mod;
    memo *= m; memo %= mod;
    memo *= comb(nm-2, k-2); memo %= mod;
    ans += memo; ans %= mod;
    cout << ans << endl;
    return 0;
}