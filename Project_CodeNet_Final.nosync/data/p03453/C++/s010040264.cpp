#include <bits/stdc++.h>
#define endl codeforces
#define ALL(v) std::begin(v), std::end(v)
#define ALLR(v) std::rbegin(v), std::rend(v)
using ll = std::int64_t;
using ull = std::uint64_t;
using pii = std::pair<int, int>;
using tii = std::tuple<int, int, int>;
using pll = std::pair<ll, ll>;
using tll = std::tuple<ll, ll, ll>;
template <typename T> using vec = std::vector<T>;
template <typename T> using vvec = vec<vec<T>>;
template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename T, typename... Tail> const T& var_min(const T &t, const Tail&... tail) { return std::min(t, var_min(tail...)); }
template <typename T, typename... Tail> const T& var_max(const T &t, const Tail&... tail) { return std::max(t, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }
template <typename T> const T& clamp(const T &t, const T &low, const T &high) { return std::max(low, std::min(high, t)); }
template <typename T> void chclamp(T &t, const T &low, const T &high) { return t = clamp(t, low, high); }
template <typename T> T make_v(T init) { return init; }
template <typename T, typename... Tail> auto make_v(T init, std::size_t s, Tail... tail) { auto v = std::move(make_v(init, tail...)); return vec<decltype(v)>(s, v); }
template <typename T, std::size_t Head, std::size_t ...Tail> struct multi_dem_array { using type = std::array<typename multi_dem_array<T, Tail...>::type, Head>; };
template <typename T, std::size_t Head> struct multi_dem_array<T, Head> { using type = std::array<T, Head>; };
template <typename T, std::size_t ...Args> using mdarray = typename multi_dem_array<T, Args...>::type;
namespace init__ { struct InitIO { InitIO() { std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); std::cout << std::fixed << std::setprecision(30); } } init_io; }

namespace math {

template <typename T>
constexpr T pow(const T &n, ll k) {
    T ret = n.mul_id_ele();
    T cur = n;
    while (k) {
        if (k & 1) ret *= cur;
        cur *= cur;
        k /= 2;
    }
    return ret;
}

}

namespace math {

template <ll Mod>
struct Modint {

    constexpr Modint(ll x) : x((Mod + x % Mod) % Mod) { }
    
    constexpr Modint() : Modint(0) { }
    
    constexpr Modint<Mod> add_id_ele() const { 
        return Modint<Mod>(0); 
    }
    
    constexpr Modint<Mod> mul_id_ele() const {
        return Modint<Mod>(1); 
    }
    
    constexpr ll& value() { 
        return x; 
    }
    
    constexpr ll value() const {
        return x; 
    }

    constexpr Modint& operator +=(const Modint &oth) {
        x += oth.value();
        if (Mod <= x) x -= Mod;
        return *this;
    }

    constexpr Modint& operator -=(const Modint &oth) {
        x += Mod - oth.value();
        if (Mod <= x) x -= Mod;
        return *this;
    }

    constexpr Modint& operator *=(const Modint &oth) {
        x *= oth.value();
        x %= Mod;
        return *this;
    }

    constexpr Modint& operator /=(const Modint &oth) {
        x *= oth.inv();
        x %= Mod;
        return *this;
    }

    constexpr Modint operator +(const Modint &oth) const {
        return Modint(x) += oth;
    }

    constexpr Modint operator -(const Modint &oth) const {
        return Modint(x) -= oth;
    }

    constexpr Modint operator *(const Modint &oth) const {
        return Modint(x) *= oth;
    }

    constexpr Modint operator /(const Modint &oth) const {
        return Modint(x) /= oth;
    }

    constexpr Modint operator -() const {
        return Modint((x != 0) * (Mod - x)); 
    }

    template <typename T>
    constexpr typename std::enable_if<std::is_integral<T>::value, const Modint&>::type
    operator =(T t) {
        (*this) = Modint(std::forward<T>(t)); 
        return *this;
    }

    constexpr Modint inv() const {
        return ::math::pow(*this, Mod - 2);
    }

    constexpr ll mod() const {
        return Mod;
    }

private:
    ll x;
};

}

namespace graph {

using Node = ll;
using Weight = ll;
using Edge = std::pair<Node, Weight>;

template <bool Directed>
struct Graph : public vvec<Edge> {
    using vvec<Edge>::vvec;

    void add_edge(Node f, Node t, Weight w = 1) {
        (*this)[f].emplace_back(t, w);
        if (!Directed) (*this)[t].emplace_back(f, w);
    }

    Graph<Directed> build_inv() const {
        Graph<Directed> ret(this->size());
        for (Node i = 0; i < this->size(); i++) {
            for (const Edge &e : (*this)[i]) {
                Node j;
                Weight w;
                std::tie(j, w) = e;
                if (!Directed && j < i) continue;
                ret.add_edge(j, i, w);
            }
        }

        return ret;
    }
};

template <typename Iterator>
class dst_iterator {
    Iterator ite;

public:
    dst_iterator(Iterator ite) : ite(ite) { }

    bool operator ==(const dst_iterator<Iterator> &oth) const {
        return ite == oth.ite;
    }

    bool operator !=(const dst_iterator<Iterator> &oth) const {
        return !(*this == oth);
    }

    bool operator <(const dst_iterator<Iterator> &oth) const {
        return ite < oth.ite;
    }

    bool operator >(const dst_iterator<Iterator> &oth) const {
        return ite > oth.ite;
    }

    bool operator <=(const dst_iterator<Iterator> &oth) const {
        return ite <= oth.ite;
    }

    bool operator >=(const dst_iterator<Iterator> &oth) const {
        return ite >= oth.ite;
    }

    const Node& operator *() {
        return ite->first;
    }

    const Node& operator *() const {
        return ite->first;
    }

    dst_iterator operator ++() {
        ++ite;
        return ite;
    }
};

class dst_iteration {
    using ite_type = vec<Edge>::const_iterator;
    const vec<Edge> &edges;

public:
    dst_iteration(const vec<Edge> &edges) : edges(edges) { }

    auto begin() const {
        return dst_iterator<ite_type>(edges.cbegin());
    }

    auto end() const {
        return dst_iterator<ite_type>(edges.cend());
    }
};

dst_iteration dst(const vec<Edge> &edges) {
    return dst_iteration(edges);
}

}

const ll mod = 1e9 + 7;
const ll inf = 5e15;
using mint = math::Modint<mod>;

vec<ll> dijk(const graph::Graph<false> &g, ll start) {
    vec<ll> dists(g.size(), inf);
    dists[start] = 0;
    std::priority_queue<pll, vec<pll>, std::greater<pll>> pq;
    pq.emplace(0, start);
    while (pq.size()) {
        ll d, cur;
        std::tie(d, cur) = pq.top();
        pq.pop();
        if (dists[cur] < d) continue;
        for (auto &&e : g[cur]) {
            ll nxt, cost;
            std::tie(nxt, cost) = e;
            ll nd = d + cost;
            if (dists[nxt] <= nd) continue;
            dists[nxt] = nd;
            pq.emplace(nd, nxt);
        }
    }
    return dists;
}

vec<mint> calc_perm(const graph::Graph<false> &g, const vec<ll> &dists) {
    vec<ll> ord(g.size());
    std::iota(ALL(ord), 0);
    std::sort(ALL(ord), [&](ll i, ll j) { return dists[i] < dists[j]; });
    vec<mint> ret(g.size());
    ret[ord[0]] = 1;
    for (ll i = 0; i < g.size(); i++) {
        ll cur = ord[i];
        for (auto &&e : g[cur]) {
            ll nxt, cost;
            std::tie(nxt, cost) = e;
            if (dists[nxt] == dists[cur] + cost) ret[nxt] += ret[cur];
        }
    }
    return ret;
}

int main() {
    ll n, m, s, t;
    std::cin >> n >> m >> s >> t;
    s--; t--;
    vec<tll> edges(m);
    graph::Graph<false> g(n);
    for (auto &&e : edges) {
        ll u, v, d;
        std::cin >> u >> v >> d;
        u--; v--;
        e = tll(u, v, d);
        g.add_edge(u, v, d);
    }

    auto from_s = dijk(g, s);
    auto from_t = dijk(g, t);
    auto from_s_p = calc_perm(g, from_s);
    auto from_t_p = calc_perm(g, from_t);
    mint ans = from_s_p[t] * from_t_p[s];
    for (auto &&e : edges) {
        ll a, b, c;
        std::tie(a, b, c) = e;
        if (from_s[a] > from_s[b]) std::swap(a, b);
        if (from_s[a] + c + from_t[b] != from_s[t]) continue;
        if (from_s[a] + c != from_s[b]) continue;
        if (from_t[b] + c != from_t[a]) continue;
        if (from_s[a] == from_t[a]) continue;
        if (from_s[b] == from_t[b]) continue;
        if ((from_s[a] <= from_t[b] && from_t[b] < from_s[b]) ||
            (from_t[b] <= from_s[a] && from_s[a] < from_t[a])) {
            mint p = from_s_p[a] * from_t_p[b];
            ans -= p * p;
        }
    }

    for (ll i = 0; i < n; i++) {
        ll d1 = from_s[i], d2 = from_t[i];
        if (d1 == d2) {
            mint p = from_s_p[i] * from_t_p[i];
            ans -= p * p;
        }
    }

    std::cout << ans.value() << '\n';
    return 0;
}

