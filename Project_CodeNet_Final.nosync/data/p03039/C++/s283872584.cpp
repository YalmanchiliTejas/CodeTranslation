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
#include <assert.h>
#include <unordered_set>
#include <random>



using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)



















const ll table_size = 200005;
ll fact[table_size], finv[table_size], inv[table_size];

// 前処理
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

ll comb(ll n, ll r, ll mod){
    if(n < r || n < 0 || r < 0) return 0;
    return fact[n] * (finv[r] * finv[n - r] % mod) % mod;
}



int main(){
    make_table(MOD);
    
    ll n, m, k;
    cin >> n >> m >> k;
    
    ll a = comb(n * m - 2, k - 2, MOD);
    
    ll ans = 0;
    for(ll d = 1; d < n; d++){
        ans += ((((((d * (n - d) % MOD) * m) % MOD) * m) % MOD) * a) % MOD;
        ans %= MOD;
    }
    for(ll d = 1; d < m; d++){
        ans += ((((((d * (m - d) % MOD) * n) % MOD) * n) % MOD) * a) % MOD;
        ans %= MOD;
    }
    
    cout << ans << endl;
}