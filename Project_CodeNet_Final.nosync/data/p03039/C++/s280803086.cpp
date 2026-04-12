#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define MSVC_UNKO(x) x
#define rep(...) MSVC_UNKO(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c) c.begin(),c.end()
#define mp make_pair
#define write(x) cout<<(x)<<"\n"
using namespace std; typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vll; template<class T>using vv = vector<vector<T>>;
template<class T>vv<T> vvec(size_t n, size_t m, T v) { return vv<T>(n, vector<T>(m, v)); }
template<class T>bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T>bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
constexpr int INF = 1 << 28, MOD = 1e9 + 7; constexpr ll LINF = 1ll << 60;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); }; }aaaa;

ll mpow(ll x, int n) { ll y = 1; for (; n > 0; n /= 2) { y = n % 2 ? y * x % MOD : y; x = x * x % MOD; } return y; }
struct Combination {
    vector<ll> fact, ifact;
    Combination(int n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (int i = 0; i < n; ++i) fact[i + 1] = fact[i] * (i + 1) % MOD;
        ifact[n] = mpow(fact[n], MOD - 2);
        for (int i = n; i > 0; --i) ifact[i - 1] = ifact[i] * i % MOD;
    }
    ll operator()(int n, int k) { return fact[n] * ifact[n - k] % MOD * ifact[k] % MOD; }
} C(2e5 + 5);

int N, M, K;

int main() {
    cin >> N >> M >> K;

    ll ans = 0;
    rep(d, 1, N) {
        ans = (ans + (ll)d * (N - d) % MOD * M % MOD * M % MOD * C(N * M - 2, K - 2) % MOD) % MOD;
    }
    rep(d, 1, M) {
        ans = (ans + (ll)d * (M - d) % MOD * N % MOD * N % MOD * C(N * M - 2, K - 2) % MOD) % MOD;
    }
    write(ans);
}