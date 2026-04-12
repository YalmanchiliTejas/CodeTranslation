#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    ll sum = 0;
    ll res = 0;
    rep1(i, n){
        cin >> a[i];
        res += a[i]*a[i]%MOD;
        res %= MOD;
        sum += a[i];
        sum %= MOD;
    }
    ll ans = (sum * sum - res) % MOD;
    cout << (ans * modinv(2, MOD)%MOD) << endl;
    //printf("%.12f", ans);
}