#ifdef _DEBUG
#include "MyLib.h"
#else
#define main_E main
#include "bits/stdc++.h" 
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
#define FOR(i,s,e) for (int i = int(s); i < int(e); ++i)
#define REP(i,e) FOR(i,0,e)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LONG_MAX/2)
const int MGN = 8;
const int ARY_SZ_MAX = 10000000;
using namespace std;
using ll = long long; using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using vb = vector<bool>; using vvb = vector<vb>; using vvvb = vector<vvb>;
using vl = vector<ll>; using vvl = vector<vl>;
using vd = vector<double>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
// functions
ll pow_mod(ll a, ll n, ll MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 0x01) { 
            res *= a;
            res %= MOD;
        }
        a = a*a;
        a %= MOD;
        n >>= 1;
    }
    return res;
}

ll recipro_mod(ll num, ll MOD) {
    return pow_mod(num, MOD - 2, MOD);
}

void fact_mod(vl& fact, vl& rFact, int size, ll MOD) {
    fact = vl(size + MGN, 0);
    rFact = vl(size + MGN, 0);

    fact[0] = 1;
    FOR(i, 1, size+1) fact[i] = fact[i-1 ] * (i) % MOD;

    rFact[size] = recipro_mod(fact[size], MOD);
    for (int i = size; i > 0; i--) rFact[i - 1] = rFact[i] * i % MOD;
}

ll combi_mod(vl fact, vl rFact, ll n, ll k, ll MOD){
    return fact[n] % MOD * rFact[k] % MOD * rFact[n - k] % MOD;
}
#endif



int main_E() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    const ll MOD = (ll)1e9 + 7;
    ll N, M, K;  cin >> N >> M >> K;


    ll tx = 0;
    FOR(i, 1, M) {
        tx += i * (M - i) % MOD;
    }
    tx *= N % MOD;
    tx *= N % MOD;

    ll ty = 0;
    FOR(i, 1, N) {
        ty += i * (N - i) % MOD;
    }
    ty *= M % MOD; 
    ty *= M % MOD;
    
    vl fact, rFact;
    fact_mod(fact, rFact, N*M, MOD);    
    ll ans = combi_mod(fact, rFact, N*M-2, K-2, MOD) * (tx % MOD + ty % MOD);
    ans %= MOD;

    cout << ans << endl;

    return 0;
}