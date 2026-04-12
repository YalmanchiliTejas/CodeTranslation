#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define FORR(i, a, b) for(ll i = (a); i > (b); --i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define mp make_pair
#define bitcnt __builtin_popcount
#define SZ(x) ((ll)(x).size())
#define All(a) (a).begin(), (a).end()
template <typename T = long long> inline T IN() {
    T x;
    cin >> x;
    return (x);
}
inline void CIN() {}
template <class Head, class... Tail>
inline void CIN(Head &&head, Tail &&... tail) {
    cin >> head;
    CIN(move(tail)...);
}
#define CINT(...)                                                              \
    int __VA_ARGS__;                                                           \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    ll __VA_ARGS__;                                                            \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Yes(a) cout << (a ? "Yes" : "No") << "\n"
#define YES(a) cout << (a ? "YES" : "NO") << "\n"
#define Printv(v)                                                              \
    {                                                                          \
        FOREACH(x, v) { cout << x << " "; }                                    \
        cout << "\n";                                                          \
    }

typedef long long ll;
typedef unsigned long long ul;
typedef vector<ll> VL;
typedef pair<ll, ll> PL;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll, VL, greater<ll>> PQG;

const int INF = 1e9;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const ll LINF = 1e18;
const ll dx[] = {1, -1, 0, 0};
const ll dy[] = {0, 0, 1, -1};

ll N, M, K;
const ll NMAX = 1e6;
ll fac[NMAX + 1], inv[NMAX + 1], finv[NMAX + 1];

ll modmul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

ll modsub(ll a, ll b) { return (a - b + MOD) % MOD; }

ll mod_pow(ll base, ll index, ll mod) {
    if(index == 0) return 1LL;
    ll res = mod_pow((base * base) % mod, index / 2, mod);
    if(index & 1) (res *= base) %= mod;
    return res;
}

ll modinv(ll a) { return mod_pow(a, MOD - 2, MOD); }

void cominit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    FOR(i, 2, NMAX + 1) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll comb(ll n, ll k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return (fac[n] * (finv[k] * finv[n - k] % MOD) % MOD) % MOD;
}

int main() {
    cin >> N >> M >> K;
    cominit();
    ll xsum = modmul(N, (N * N) % MOD - 1);
    xsum *= modinv(6);
    xsum = modmul(xsum, comb(N * M - 2, K - 2));
    xsum = modmul(xsum, modmul(M, M));
    ll ysum = modmul(M, (M * M) % MOD - 1);
    ysum *= modinv(6);
    ysum = modmul(ysum, comb(M * N - 2, K - 2));
    ysum = modmul(ysum, modmul(N, N));
    cout << (xsum + ysum) % MOD << "\n";
}