// #define DEBUGGING
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()

template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
using ll = int64_t;
using ull = uint64_t;
using PLL = pair<ll, ll>;

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
#include "../../debug/debug.cpp"
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

ll query(ll u, ll v) {
    cout << "? " << u << ' ' << v << endl << flush;
    ll ret;
    cin >> ret;
    return ret;
}

int main() {
    ll N, S, T;
    cin >> N >> S >> T;
    V<PLL> nodes;
    ll dist = query(S, T);
    for(ll i = 1; i <= N; i++) {
        if(i == S || i == T) continue;
        ll d1 = query(S, i);
        ll d2 = query(i, T);
        if(d1 + d2 == dist) nodes.emplace_back(d1, i);
    }
    sort(ALL(nodes));
    nodes.emplace_back(dist, T);
    ll cur = S;
    ll cur_dist = 0;
    V<ll> ans = { S };
    for(auto &&ele : nodes) {
        ll d, n;
        tie(d, n) = ele;
        ll diff = d - cur_dist;
        if(query(cur, n) != diff) continue;
        cur = n;
        cur_dist = d;
        ans.push_back(cur);
    }

    cout << '!';
    for(auto &&ele : ans) cout << ' ' << ele;
    cout << endl << flush;
    return 0;
}

