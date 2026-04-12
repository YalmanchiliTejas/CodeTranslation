#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define UNIQUE(v) { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); }
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return 1;} return 0; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) (q ? "Yes" : "No")
#define YES(q) (q ? "YES" : "NO")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) { cerr << "[DEBUG] " #q ": ["; REP(dumpall_i, (q).size()) { cerr << q[dumpall_i] << (dumpall_i == (q).size() - 1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl; }

// gcc拡張マクロ
#define gcd __gcd
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
using  ll = long long;
using ull = unsigned long long;
using  ld = long double;
using namespace std;

// モジュール
// 剰余演算
constexpr ll p = 1000000007LL; // prime
ll powll(ll a, ll n) { // a^n mod p
    if (n == 0) {
        return 1LL;
    } else if (n == 1) {
        return a % p;
    } else {
        ll temp = powll(a, n/2);
        temp *= temp;
        temp %= p;
        if (n % 2) {
            temp *= a;
            temp %= p;
        }
        return temp;
    }
}

ll invll(ll a) { // a^p == a, so a^(p-2) == a^(-1) if a != 0 mod p, O(loga)
    return powll(a, p-2);
}

vector<ll> fac_cache = {1}, invfac_cache = {1};
void make_fac_cache(ll a) { // prepare for 1! ~ a! by O(aloga). execute this at the beginning
    ll old_size = fac_cache.size();
    if (a >= old_size) {
        fac_cache   .resize(a+1);
        invfac_cache.resize(a+1);
        for (ll i = old_size; i <= a; i++) {
               fac_cache[i] = fac_cache[i-1] * i % p;
            invfac_cache[i] = invll(fac_cache[i]);
        }
    }
}
ll facll(ll a) { // a!
    make_fac_cache(a);
    return fac_cache[a];
}
ll invfacll(ll a) { // (a!)^(-1)
    make_fac_cache(a);
    return invfac_cache[a];
}
ll nCr(ll n, ll r) {
    if (n < 0 || r < 0 || n < r) return 0;
    return facll(n) * invfacll(n-r) % p * invfacll(r) % p;
}
ll nPr(ll n, ll r) {
    if (n < 0 || r < 0 || n < r) return 0;
    return facll(n) * invfacll(r) % p;
}

// 処理内容
int main() {
    
    ll n, m, k; cin >> n >> m >> k;

    vector<vector<ll>> dist(n, vector<ll>(m));
    vector<vector<ll>> imos(n+1, vector<ll>(m+1, 0));
    REP(i, n) REP(j, m) dist[i][j] = (i + j) % p;
    REP(i, n) REP(j, m) {
        imos[i+1][j+1] += imos[i][j+1] + imos[i+1][j] - imos[i][j] + dist[i][j];
        imos[i+1][j+1] %= p;
    }

    make_fac_cache(200010);
    
    ll ans = 0;
    REP(i, n) REP(j, m) {
        
        ll term = 0;
        ll w1 = m-j, w2 = j+1;
        ll h1 = n-i, h2 = i+1;
        
        term += imos[h1][w1] % p;
        term %= p;
        term += imos[h1][w2] % p;
        term %= p;
        term += imos[h2][w1] % p;
        term %= p;
        term += imos[h2][w2] % p;
        term %= p;
        term += p - imos[1][w1];
        term %= p;
        term += p - imos[1][w2];
        term %= p;
        term += p - imos[h1][1];
        term %= p;
        term += p - imos[h2][1];
        term %= p;

        ans += term;
        ans %= p;

    }

    ans *= nPr(n * m - 2, n * m - k);
    ans %= p;
    ans *= nCr(k, 2);
    ans %= p;
    ans *= invfacll(k);
    ans %= p;

    cout << ans << endl;
    
}