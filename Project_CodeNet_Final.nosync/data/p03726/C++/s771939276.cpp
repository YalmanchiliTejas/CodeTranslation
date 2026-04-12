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
// #include "../debug/debug.cpp"
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

ll dfs(ll cur, ll pre, const VV<ll> &edges, bool *color) {
    ll sum = 1;
    for(ll nxt : edges[cur]) if(nxt != pre) sum += dfs(nxt, cur, edges, color);
    if(sum & 1) color[cur] = true;
    return sum;
}

bool check(bool *color, const VV<ll> &edges) {
    ll cnt = 0;
    for(ll i = 0; i < edges.size(); i++) {
        cnt += color[i];
        if(color[i]) continue;
        bool ok = true;
        for(ll nxt : edges[i]) if(color[nxt]) ok = false;
        if(ok) return true;
    }
    if(edges.size() / 2 < cnt) return true;
    return false;
}

bool solve() {
    ll N;
    cin >> N;
    VV<ll> edges(N);
    for(ll i = 1; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    bool leaves[N] = {};
    for(ll i = 0; i < N; i++) if(edges[i].size() == 1) leaves[i] = true;

    for(ll i = 0; i < N; i++) {
        ll cnt = 0;
        for(ll nxt : edges[i]) if(leaves[nxt]) cnt++;
        if(2 <= cnt) return true;
    }

    bool color[N] = {};
    dfs(0, -1, edges, color);
    return check(color, edges);
}

int main() {
    cout << (solve() ? "First" : "Second") << endl;
    return 0;
}
