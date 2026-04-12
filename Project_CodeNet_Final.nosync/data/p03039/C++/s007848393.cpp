#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
const ll INF = 1e14;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (int i = (l); i < (r); i++)
#define reper(i, l, r) for (int i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//
ll modpow(ll a, ll n, ll mod_) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod_;
        a = a * a % mod_;
        n >>= 1;
    }
    return res;
}

// ll mod = 998244353;
ll mod = 1e9 + 7;
vector<ll> fac(1e6 + 1, 1), inv(1e6 + 1, 1), finv(1e6 + 1, 1);
ll fac_init() {
    // combination init
    for (ll i = 1; i < 1e6+1 + 1; i++) fac[i] = fac[i - 1] * i % mod;
    finv[0] = modpow(fac[fac.end() - fac.begin() - 1], mod - 2, mod);
    repe(i, 1, 1e6 + 1) finv[i] = finv[i - 1] * (ll)(1e6 - i + 1) % mod;
    reverse(all(finv));

    //inv init
    repe(i, 1, 1e6 + 1) inv[i] = modpow(i, mod - 2, mod);
}

ll perm(ll a, ll b) { return fac[a] * finv[a - b] % mod; }

ll comb(ll a, ll b) { return fac[a] * finv[b] % mod * finv[a - b] % mod; }

int main() {
    init();
    ll N, M, K;
    cin >> N >> M >> K;
    ll S = N * M;
    fac_init();
    ll ans = 0;
    vl sum(S + 1, 0);
    rep(i,S)
        sum[i + 1] = sum[i] + i + 1;

    ll C = comb(S - 2, K - 2);
    rep(i,N)rep(j,M){
        ll tmp = 0;
        ll l, r;
        // 探索点の右で縦にわって２つの四角形の累積和を考える, l=探索点を含む列のマンハッタン距離, r=探索点の右隣
        l = sum[i] + sum[N - i - 1];
        r = l + N;
        l = (j + 1) * l % mod + N * (j + 1) * j % mod * inv[2] % mod;
        r = (M - j - 1) * r % mod + N * (M - j - 1) * (M - j - 2) % mod * inv[2] % mod;
        ans = (ans + l * C % mod + r * C % mod) % mod;
    }
    ans = ans * inv[2] % mod;
    cout << ans << endl;
    return 0;
}