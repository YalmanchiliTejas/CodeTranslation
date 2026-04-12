#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
const ll MOD = 1000000007;
template <bool Directed, typename TEdge, bool Index> struct graph {
    using EType = TEdge;
    vector<TEdge> edges;
    vector<vector<int>> adj;
    graph(int n) : adj(n + Index) {}
    graph(int n, int m) : graph(n) { edges.reserve(m << not Directed); }
    TEdge& operator()(int e) { return edges[e]; }
    vector<int>& operator[](int u) { return adj[u]; }
    int size() { return adj.size() - Index; }
    void append(int u, const TEdge& e) {
        adj[u].push_back(edges.size());
        edges.push_back(e);
    }
    void add_edge(const TEdge& e) {
        append(e.u, e);
        if(not Directed) append(e.v, e.reverse());
    }
};
template <typename T> struct wedge {
    int u, v; T w;
    wedge reverse() const { return {v, u, w}; }
    friend ostream& operator<<(ostream& os, const wedge& e) {
        return os << "{u: " << e.u << ", v: " << e.v << ", w: " << e.w << "}";
    }
};
#ifndef __FASTPOW_INCLUDED_
#define __FASTPOW_INCLUDED_
template <typename T> constexpr T fpow_eq(T& x, long long y, T identity = 1) {
    for(; y > 0; x *= x, y >>= 1) if(y & 1) identity *= x;
    return x = identity;
}
template <typename T> constexpr T fpow(T x, long long y, T identity = 1) { return fpow_eq(x, y, identity); }
#endif
#ifndef __FASTPOW_INCLUDED_
#include "Math - Fast Pow.cpp"
#endif
#ifdef __TOTIENT_INCLUDED_
template <int M, int PHI_M = phi(M)> struct modint {
#else
template <int M, int PHI_M> struct modint {
#endif
    static constexpr int MOD = M;
    int val;
    constexpr modint() : val(0) {}
    constexpr modint(int x) : val(x % M) { val += val < 0 ? M : 0; }
    constexpr modint(long long x) : modint(int(x % M)) {}
    constexpr explicit operator int() const { return val; }
    constexpr bool operator==(const modint& y) const { return val == y.val; }
    constexpr bool operator!=(const modint& y) const { return val != y.val; }
    constexpr modint& operator=(const modint& y) { val = y.val; return *this; }
    constexpr modint& operator+=(const modint& y) { val += y.val; val -= val >= M ? M : 0; return *this; }
    constexpr modint& operator-=(const modint& y) { val -= y.val; val += val <  0 ? M : 0; return *this; }
    constexpr modint& operator*=(const modint& y) { val = ll(val) * y.val % M; return *this; }
    constexpr modint& operator/=(const modint& y) { val = ll(val) * fpow(y, PHI_M - 1).val % M; return *this; }
    constexpr modint& operator^=(ll y) { fpow_eq(*this, y); return *this; }
    constexpr modint operator+(const modint& y) const { return modint(*this) += y; }
    constexpr modint operator-(const modint& y) const { return modint(*this) -= y; }
    constexpr modint operator*(const modint& y) const { return modint(*this) *= y; }
    constexpr modint operator/(const modint& y) const { return modint(*this) /= y; }
    constexpr modint operator^(ll y) const { return modint(*this) ^= y; }
    constexpr modint operator-() const { return modint(0) -= *this; }
    constexpr modint operator~() const { return modint(1) /= *this; }
    constexpr modint& operator++() { val = val == M - 1 ? 0 : val + 1; return *this; }
    constexpr modint& operator--() { val = val == 0 ? M - 1 : val - 1; return *this; }
    constexpr modint operator++(int) { modint m = *this; ++(*this); return m; }
    constexpr modint operator--(int) { modint m = *this; --(*this); return m; }
    friend constexpr modint operator+(long long x, const modint& y) { return modint(x) + y; }
    friend constexpr modint operator*(long long x, const modint& y) { return modint(x) * y; }
    friend constexpr modint operator-(long long x, const modint& y) { return modint(x) - y; }
    friend constexpr modint operator/(long long x, const modint& y) { return modint(x) / y; }
    friend ostream& operator<<(ostream& os, const modint& m) { return os << m.val; }
    friend istream& operator>>(istream& is, modint& m) { ll val; is >> val; m = modint(val); return is; }
};
constexpr int M = 1'000'000'007;
using mint = modint<M, M - 1>;
mint operator""_m(unsigned long long int x) { return mint(ll(x)); }
template <typename TCount = mint, bool Directed, typename T, bool Index>
pair<vector<T>, vector<TCount>> sssp_count(graph<Directed, wedge<T>, Index>& g, const vector<int>& s) {
    vector<int> vis(g.adj.size());
    vector<T> d(g.adj.size(), lim<T>::max());
    vector<TCount> c(g.adj.size(), 0);
    priority_queue<pair<T, int>> pq;
    for(int u : s) {
        pq.push({d[u] = 0, u});
        c[u] = 1;
    }
    while(not pq.empty()) {
        int u = pq.top().second; pq.pop();
        if(not vis[u]) {
            vis[u] = true;
            for(int e : g[u]) {
                if(d[g(e).v] > d[u] + g(e).w) {
                    pq.push({-(d[g(e).v] = d[u] + g(e).w), g(e).v});
                    c[g(e).v] = c[u];
                } else if(d[g(e).v] == d[u] + g(e).w) {
                    c[g(e).v] += c[u];
                }
            }
        }
    }
    return {d, c};
}
void solve(long long N, long long M, long long S, long long T, std::vector<long long> U, std::vector<long long> V, std::vector<long long> D) {
    graph<0, wedge<ll>, 1> g(N, M);
    for(int i = 0; i < M; i++) {
        g.add_edge({U[i], V[i], D[i]});
    }
    auto ps = sssp_count(g, {(int) S});
    auto pt = sssp_count(g, {(int) T});
    auto ds = ps.first, dt = pt.first;
    auto cs = ps.second, ct = pt.second;
    mint ans = cs[T] * ct[S];
    for(int i = 1; i <= N; i++) {
        if(ds[i] == dt[i] and ds[i] + dt[i] == ds[T]) {
            ans -= cs[i] * ct[i] * ct[i] * cs[i];
        }
    }
    for(int i = 0; i < M; i++) {
        if(ds[U[i]] + D[i] > dt[V[i]] and dt[V[i]] + D[i] > ds[U[i]] and ds[U[i]] + D[i] + dt[V[i]] == ds[T]) {
            ans -= cs[U[i]] * ct[V[i]] * ct[V[i]] * cs[U[i]];
        }
        if(ds[V[i]] + D[i] > dt[U[i]] and dt[U[i]] + D[i] > ds[V[i]] and ds[V[i]] + D[i] + dt[U[i]] == ds[T]) {
            ans -= cs[V[i]] * ct[U[i]] * ct[U[i]] * cs[V[i]];
        }
    }
    cout << ans << endl;
}
int main() {
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    long long S;
    scanf("%lld",&S);
    long long T;
    scanf("%lld",&T);
    std::vector<long long> U(M);
    std::vector<long long> V(M);
    std::vector<long long> D(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&U[i]);
        scanf("%lld",&V[i]);
        scanf("%lld",&D[i]);
    }
    solve(N, M, S, T, std::move(U), std::move(V), std::move(D));
    return 0;
}
