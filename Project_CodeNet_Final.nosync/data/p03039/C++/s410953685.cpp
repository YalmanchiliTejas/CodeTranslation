#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pair<ll, ll>>> vvpll;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 300010;  // デフォルトでnの最大値は300000

// aのn乗を求める。計算量はO(logn)
ll modpow(ll a, ll n) {
    if(n == 0) {
        return 1;
    }
    if(n%2 == 1) {
        return (a * modpow(a, n-1))%mod;
    }
    return (modpow(a, n/2) * modpow(a, n/2))%mod;
}

ll inv(ll a) {
    return modpow(a, mod-2);
}

ll fact[MAX_N];
ll invfact[MAX_N];

// main関数でinit()を呼び出してからComb()を使用する
void init() {
    fact[0] = 1;
    invfact[0] = 1;
    for(ll i = 1; i < MAX_N; i++) {
        fact[i] = (i*fact[i-1])%mod;
        invfact[i] = inv(fact[i]);
    }
}
 
ll Comb(ll n, ll r) {
    if(r < 0 || n < 0 || n < r) {
        return 0;
    }
    ll res = fact[n];
    res = (res * invfact[r])%mod;
    res = (res * invfact[n-r])%mod;
    return res;
}

ll f(ll x, ll y) {
    ll A = (x-1)*x*(x+1)/6;
    ll B = y*y;
    A %= mod;  
    B %= mod;
    return A*B%mod;
}

//--- main関数でinit()を呼び出すのを忘れるな ---//
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    init();
    out( Comb(n*m-2, k-2) * (f(n, m) + f(m, n)) % mod );
    re0;
}