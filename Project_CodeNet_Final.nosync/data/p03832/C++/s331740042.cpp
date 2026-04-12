#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)




const ll table_size = 100005;
ll fact[table_size], finv[table_size], inv[table_size];

void make_table(ll mod) {
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < table_size; i++){
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

ll nPr(ll n, ll r, ll mod){
    return fact[n] * finv[n - r] % mod;
}

ll POW(ll n, ll m, ll p){
    ll res = 1, x = n;
    for(ll i = m; i > 0; i >>= 1){
        if(i & 1){
            res *= x;
            res %= p;
        }
        x *= x;
        x %= p;
    }
    return res;
}

ll Fermat(ll a, ll x, ll p){
    return POW(a, p - 1 - x, p);
}


int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    
    make_table(MOD);
    
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for(ll i = 0; i <= b; i++){
        dp[i][0] = 1;
    }
    for(ll i = a; i <= b; i++){
        for(ll j = 0; j <= n; j++){
            dp[i][j] = dp[i - 1][j];
            for(ll k = c; k <= d && j - i * k >= 0; k++){
                dp[i][j] += ((dp[i - 1][j - i * k] * nPr(n - j + i * k, i * k, MOD) % MOD)
                            * Fermat((POW(fact[i], k, MOD) * fact[k]) % MOD, 1, MOD)) % MOD;
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[b][n] << endl;
}
