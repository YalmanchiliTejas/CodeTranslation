#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const long long MOD = 1000000007;

struct Segment {
    ll l, r;

    bool overlap(const Segment &s) {
        ll L = max(s.l, l);
        ll R = min(s.r, r);
        return R - L > 0;
    }
};


namespace sub {
    template<typename T>
    constexpr typename std::enable_if<std::is_integral<T>::value, T>::type
    inf_sub() {
        return std::numeric_limits<T>::max() / 2 - 1000;
    }

    template<typename T>
    constexpr typename std::enable_if<std::is_floating_point<T>::value, T>::type
    inf_sub() {
        return std::min(std::numeric_limits<T>::max() / 2 - 1000, T(1e50));
    }
}  // namespace sub

template<typename T>
constexpr T inf() {
    static_assert(std::is_arithmetic<T>::value, "T must be arithmetic value");
    return sub::inf_sub<T>();
}

template<typename T>
constexpr T zero() {
    static_assert(std::is_arithmetic<T>::value, "T must be arithmetic value");
    return T(0);
}

const long double pi = acos(-1.0);

template<class edge_t>
class graph_t {
    std::vector<std::vector<edge_t>> g;

public:
    using reference = std::vector<edge_t> &;
    using const_reference = const std::vector<edge_t> &;
    using iterator = typename std::vector<edge_t>::iterator;

    graph_t() : g(0) { ; }

    graph_t(int n) : g(n) { ; }

    int size() const { return g.size(); }

    void push_back(const std::vector<edge_t> &es) { g.push_back(es); }

    reference operator[](int x) { return g[x]; }

    const_reference operator[](int x) const { return g[x]; }

    iterator &begin() { return begin(g); }

    iterator &end() { return end(g); }
};

template<typename edge_t, typename cost_type = typename edge_t::cost_type>
std::vector<cost_type> dijkstra(const graph_t<edge_t> &g, int s) {
    std::vector<cost_type> d(g.size(), inf<cost_type>());
    d[s] = zero<cost_type>();
    using P = std::pair<cost_type, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> que;
    que.push(P(zero<cost_type>(), s));
    while (!que.empty()) {
        cost_type dist = que.top().first;
        int v = que.top().second;
        que.pop();
        if (d[v] < dist) continue;
        for (const auto &e : g[v]) {
            if (d[e.to] <= d[v] + e.cost) continue;
            d[e.to] = d[v] + e.cost;
            que.push(P(d[e.to], e.to));
        }
    }
    return d;
}


template<typename Cost>
class WeightedEdge {
public:
    using cost_type = Cost;
    int src;
    int to;
    cost_type cost;

    WeightedEdge(int s, int t, cost_type c) : src(s), to(t), cost(c) { ; }
};

template<typename Cost> using WeightedGraph = graph_t<WeightedEdge<Cost>>;

template<typename Cost>
void add_edge(WeightedGraph<Cost> &g, int from, int to, Cost cost) {
    g[from].emplace_back(from, to, cost);
}


const int onlyA = 0;
const int onlyB = 1;
const int both = 2;
const int either = 3;


template<int M, bool IsPrime = false>
class Modulo {
    int n;

    static typename std::enable_if<IsPrime, ll>::type inv(ll a, ll p) {
        return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
    }

public:
    Modulo() : n(0) { ; }

    Modulo(int m) : n(m) {
        if (n >= M)
            n %= M;
        else if (n < 0)
            n = (n % M + M) % M;
    }

    Modulo(ll m) {
        if (m >= M)
            m %= M;
        else if (m < 0)
            m = (m % M + M) % M;
        n = m;
    }

    explicit operator int() const { return n; }

    explicit operator ll() const { return n; }

    bool operator==(const Modulo &a) const { return n == a.n; }

    Modulo &operator+=(const Modulo &a) {
        n += a.n;
        if (n >= M) n -= M;
        return *this;
    }

    Modulo &operator-=(const Modulo &a) {
        n -= a.n;
        if (n < 0) n += M;
        return *this;
    }

    Modulo &operator*=(const Modulo &a) {
        n = (ll(n) * a.n) % M;
        return *this;
    }

    Modulo operator+(const Modulo &a) const {
        Modulo res = *this;
        return res += a;
    }

    Modulo operator-(const Modulo &a) const {
        Modulo res = *this;
        return res -= a;
    }

    Modulo operator-() const { return Modulo(0) - *this; }

    Modulo operator*(const Modulo &a) const {
        Modulo res = *this;
        return res *= a;
    }

    Modulo operator^(ll m) const {
        if (m == 0) return Modulo(1);
        const Modulo a = *this;
        Modulo res = (a * a) ^(m / 2);
        return m % 2 ? res * a : res;
    }

    typename std::enable_if<IsPrime, Modulo>::type
    operator/(const Modulo &a) const {
        return *this * inv(ll(a), M);
    }

    typename std::enable_if<IsPrime, Modulo>::type operator/=(const Modulo &a) {
        return *this *= inv(ll(a), M);
    }

    friend bool is_zero(const Modulo &x) { return int(x) == 0; }

    friend int abs(const Modulo &x) { return int(x); }

    static Modulo fact(int n, bool sw = true) {
        static std::vector<Modulo> v1 = {1}, v2 = {1};
        if (n >= (int) v1.size()) {
            const int from = v1.size(), to = n + 1024;
            v1.reserve(to);
            v2.reserve(to);
            for (int i = from; i < to; ++i) {
                v1.push_back(v1.back() * Modulo<M, true>(i));
                v2.push_back(v2.back() / Modulo<M, true>(i));
            }
        }
        return sw ? v1[n] : v2[n];
    }

    static Modulo comb(int a, int b) {
        if (b < 0 || b > a) return 0;
        return Modulo::fact(a, true) * Modulo::fact(b, false) *
               Modulo::fact(a - b, false);
    }
};

typedef Modulo<1000000007, true> mInt;


void solve(long long N, long long M, long long S, long long T,
           std::vector<long long> U, std::vector<long long> V,
           std::vector<long long> D) {
    --S, --T;

    WeightedGraph<ll> g(N);

    vector<WeightedEdge<ll>> es;

    for (int i = 0; i < M; i++) {
        U[i]--;
        V[i]--;
        g[U[i]].emplace_back(U[i], V[i], D[i]);
        g[V[i]].emplace_back(V[i], U[i], D[i]);
        es.push_back(g[U[i]].back());
        es.push_back(g[V[i]].back());
    }


    auto X = dijkstra(g, S);
    auto Y = dijkstra(g, T);


    mInt ans = 0;


    auto calc = [N](int st, int gl, vector<ll> dist1, vector<ll> dist2, vector<WeightedEdge<ll>> ee) {
        WeightedGraph<ll> gg(N);
        for (auto e : ee) {
            if (e.cost + dist1[e.src] + dist2[e.to] == dist1[gl]) {
                gg[e.src].push_back(e);
            }
        }
        vector<pair<ll, ll> > ids;
        for (int i = 0; i < dist1.size(); i++)
            ids.push_back({dist1[i], i});
        sort(ids.begin(), ids.end());
        vector<mInt> dp(N);
        dp[st] = 1;
        for (auto p : ids) {
            int i = p.second;
            for (auto e : gg[i]) {
                dp[e.to] += dp[e.src];
            }
        }
        return dp;
    };


    vector<WeightedEdge<ll>> es2;

    mInt allAnswer = calc(S, T, X, Y, es)[T] * calc(T, S, Y, X, es)[S];
//    cout <<  (int)calc(S, X, es)[T]  << " " << (int) calc(T, Y, es)[S] << endl;

    vector<WeightedEdge<ll>> safe, danger;

    for (auto e : es) {
        bool okA = X[e.to] == X[e.src] + e.cost;
        bool okB = Y[e.src] == Y[e.to] + e.cost;
        bool d = false;
        if (okA && okB) {
            if (Segment{X[e.src], X[e.to]}.overlap(Segment{Y[e.to], Y[e.src]})) {
                d = true;
            }
        }
        if (d) {
            danger.push_back(e);
        } else {
            safe.push_back(e);
        }
    }

    auto ONE = calc(S, T, X, Y, safe);
    auto TWO = calc(T, S, Y, X, safe);


    for (int i = 0; i < N; i++) {

        if (X[i] == Y[i]) {
            allAnswer -= ONE[i] * TWO[i] * ONE[i] * TWO[i];
        }

    }

    for (auto e : danger) {
        allAnswer -= (ONE[e.src] * TWO[e.to]) * (ONE[e.src] * TWO[e.to]);
    }
    cout << (int) allAnswer << endl;


}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    long long S;
    scanf("%lld", &S);
    long long T;
    scanf("%lld", &T);
    std::vector<long long> U(M);
    std::vector<long long> V(M);
    std::vector<long long> D(M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &U[i]);
        scanf("%lld", &V[i]);
        scanf("%lld", &D[i]);
    }
    solve(N, M, S, T, std::move(U), std::move(V), std::move(D));
    return 0;
}
