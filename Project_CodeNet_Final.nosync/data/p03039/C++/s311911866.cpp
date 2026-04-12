
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
    os << "{ ";
    REP(i, vec.size()) {
        os << vec[i] << " ";
    }
    os << "}";

    return os;
}

ll pow_mod(ll a, ll p) {
    ll res = 1;
    while(p) {
        if (p & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        p >>= 1;
    }

    return res;
}


ll mod_inv(ll a, ll m) {
    ll b = m, u = 0, v = 1;
    while(a) {
        ll t = b / a;
        swap(b -= t * a, a);
        swap(u -= t * v, v);
    }

    return (u % m + m) % m;
}

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

#ifdef LOCAL
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

const int NM = int(2e5);
ll fact[NM+1], finv[NM+1], inv[NM+1];

void comb_init(int N) {
    // init
    REP(i, 2) {
        fact[i] = 1;
        finv[i] = 1;
        inv[i] = 1;
    }

    FOR(i, 2, N+1) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll comb(int n, int k) {
    if (n < k || n < 0 || k < 0) return 0;

    return (fact[n] * finv[k] % MOD) * finv[n-k] % MOD;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll N, M, K;
    cin >> N >> M >> K;

    comb_init(N*M-2);
    ll c = comb(N*M-2, K-2);

    ll ans = 0;

    // x
    REP(d, M) {
        ans = (ans + (N * N * (M - d) % MOD) * c % MOD * d % MOD) % MOD;
    }

    // y
    REP(d, N) {
        ans = (ans + (M * M * (N - d) % MOD) * c % MOD * d % MOD) % MOD;
    }
    
    cout << fixed << setprecision(20);
    cout << ans << endl;

}
