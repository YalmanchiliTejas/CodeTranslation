// #define DEBUGGING
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()

template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
template <typename T, typename U> using P = pair<T, U>;
using ll = int64_t;
using PLL = P<ll, ll>;

template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename T, typename... Tail> const T& var_min(const T &t, const Tail&... tail) { return min(t, var_min(tail...)); }
template <typename T, typename... Tail> const T& var_max(const T &t, const Tail&... tail) { return max(t, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }
template <typename T> const T& clamp(const T &t, const T &low, const T &high) { return max(low, min(high, t)); }
template <typename T> void chclamp(T &t, const T &low, const T &high) { t = clamp(t, low, high); }

namespace __init {

struct InitIO {
    InitIO() {
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        cout << fixed << setprecision(30);
    }
} init_io;

}

#ifdef DEBUGGING
#include "../debug.cpp"
#else
#define DEBUG(...) 0
#define DEBUG_SEPARATOR_LINE 0
#endif

template <typename T>
T make_v(T init) { return init; }

template <typename T, typename... Tail>
auto make_v(T init, size_t s, Tail... tail) {
#define rec make_v(init, tail...)
    return V<decltype(rec)>(s, rec);
#undef rec
}

template <ll MOD>
class Combination {
private:
    template <typename T> using V = vector<ll>;
    ll N;
    V<ll> factv, rfactv;

public:
    /*
     * MOD must be a prime number.
     */
    Combination<MOD> (ll N)
        : N(N), 
          factv(N + 1, 1),
          rfactv(N + 1)
    {
        for(ll i = 1; i <= N; i++) {
            factv[i] = factv[i - 1] * i % MOD;
        }
        for(ll i = 0; i <= N; i++) {
            rfactv[i] = pow(factv[i], MOD - 2);
        }
    }

    ll fact(ll n) {
        return factv[n];
    }

    ll rfact(ll n) {
        return rfactv[n];
    }

    ll pow(ll a, ll b) {
        return b ? (b & 1 ? a : 1) * pow(a * a % MOD, b / 2) % MOD : 1;
    }

    ll comb(ll n, ll k) {
        return factv[n] * rfactv[n - k] % MOD * rfactv[k] % MOD;
    }
};

const ll mod = 1e9 + 7;

ll calc_sum(ll n) { return n * (n + 1) / 2; }
Combination<mod> comb(3e5 + 10);

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    ll rsum = 0;
    for(ll i = 0; i < N; i++) {
        ll up = i;
        ll down = N - i - 1;
        (rsum += calc_sum(up) + calc_sum(down)) %= mod;
    }
    ll ans = 0;
    for(ll col = 0; col < M; col++) {
        ll left = col;
        ll right = M - col - 1;
        ll csum = calc_sum(left) + calc_sum(right);
        DEBUG(rsum, csum);
        (ans += csum * N % mod * N % mod) %= mod;
    }
    ans += (rsum * M % mod * M % mod);
    ans %= mod;
    ans *= comb.pow(2, mod - 2);
    ans %= mod;
    DEBUG(ans);
    (ans *= comb.comb(N * M - 2, K - 2)) %= mod;
    cout << ans << endl;
    return 0;
}
