// #define DEBUGGING
#include <bits/stdc++.h>
#define endl '\n'
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
template <typename T> using V = std::vector<T>;
template <typename T> using VV = V<V<T>>;
using ll = std::int64_t;
using ull = std::uint64_t;
using PLL = std::pair<ll, ll>;
using TLL = std::tuple<ll, ll, ll>;
template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename T, typename... Tail> const T& var_min(const T &t, const Tail&... tail) { return std::min(t, var_min(tail...)); }
template <typename T, typename... Tail> const T& var_max(const T &t, const Tail&... tail) { return std::max(t, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }
template <typename T> const T& clamp(const T &t, const T &low, const T &high) { return std::max(low, std::min(high, t)); }
template <typename T> void chclamp(T &t, const T &low, const T &high) { return t = clamp(t, low, high); }
namespace init__ { struct InitIO { InitIO() { std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); std::cout << std::fixed << std::setprecision(30); } } init_io; }
#define mv_rec make_v(init, tail...)
template <typename T> T make_v(T init) { return init; }
template <typename T, typename... Tail> auto make_v(T init, size_t s, Tail... tail) { return V<decltype(mv_rec)>(s, mv_rec); }
#undef mv_rec
using namespace std;
#ifdef DEBUGGING
#include "../../debug/debug.cpp"
#else
#define DEBUG(...) 0
#define DEBUG_SEPARATOR_LINE 0
#endif

void dfs(ll cur, ll pre, const VV<ll> &edges, V<ll> &pars, V<ll> &depth, ll d = 0) {
    pars[cur] = pre;
    depth[cur] = d;
    for(ll nxt : edges[cur]) if(nxt != pre) dfs(nxt, cur, edges, pars, depth, d + 1);
}

bool solve() {
    ll N;
    cin >> N;
    VV<ll> edges(N);
    V<ll> digits(N);
    for(ll i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
        digits[a]++;
        digits[b]++;
    }

    V<ll> parents(N);
    V<ll> depth(N);
    for(ll i = 0; i < N; i++) if(digits[i] != 1) {
        dfs(i, -1, edges, parents, depth);
        break;
    }
    
    set<ll> leaves;
    for(ll i = 0; i < N; i++) if(digits[i] == 1) leaves.insert(i);
    V<ll> cnts(N);
    V<ll> ord(N);
    iota(ALL(ord), 0ll);
    sort(ALL(ord), [&](ll a, ll b) { return depth[a] > depth[b]; });
    for(ll ele : ord) {
        if(cnts[ele] == 1) continue;
        if(2 <= cnts[ele]) return true;
        ll par = parents[ele];
        if(par != -1) cnts[par]++;
        else return true;
    }

    return false;
}

int main() {
    cout << (solve() ? "First" : "Second") << endl;
    return 0;
}
