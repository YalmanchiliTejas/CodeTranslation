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

namespace init__ {

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

ll calc(ll h0, ll w0, ll h1, ll w1) { return abs(h0 - h1) + abs(w0 - w1); }

int main() {
    ll H, W;
    cin >> H >> W;
    V<PLL> lr(H);
    const PLL invalid(-1, -1);
    for(ll i = 0; i < H; i++) {
        string S;
        cin >> S;
        PLL p = invalid;
        for(ll j = 0; j < W; j++) if(S[j] == 'B') {
            p.first = j;
            break;
        }
        for(ll j = W - 1; 0 <= j; j--) if(S[j] == 'B') {
            p.second = j;
            break;
        }
        lr[i] = p;
    }

    ll ans = 0;
    for(ll i = 0; i < H; i++) {
        if(lr[i] == invalid) continue;
        ll hi = i, li, ri;
        tie(li, ri) = lr[i];
        for(ll j = i; j < H; j++) {
            if(lr[j] == invalid) continue;
            ll hj = j, lj, rj;
            tie(lj, rj) = lr[j];
            chmax(ans,
                  calc(hi, li, hj, rj),
                  calc(hi, ri, hj, lj));
        }
    }

    cout << ans << endl;
    return 0;
}

