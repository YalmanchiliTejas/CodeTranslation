#include "bits/stdc++.h"

// Begin Header {{{
using namespace std;

#ifndef DEBUG
#define dump(...)
#endif

#define all(x) x.begin(), x.end()
#define rep(i, n) for (intmax_t i = 0, i##_limit = (n); i < i##_limit; ++i)
#define reps(i, b, e) for (intmax_t i = (b), i##_limit = (e); i <= i##_limit; ++i)
#define repr(i, b, e) for (intmax_t i = (b), i##_limit = (e); i >= i##_limit; --i)
#define var(Type, ...) Type __VA_ARGS__; input(__VA_ARGS__)

constexpr size_t    operator""_zu(unsigned long long value) { return value; };
constexpr intmax_t  operator""_jd(unsigned long long value) { return value; };
constexpr uintmax_t operator""_ju(unsigned long long value) { return value; };

constexpr int INF = 0x3f3f3f3f;
constexpr intmax_t LINF = 0x3f3f3f3f3f3f3f3f_jd;

template <class T, class Compare = less<>>
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template <class T, class Compare = greater<>>
using MinHeap = priority_queue<T, vector<T>, Compare>;

inline void input() {}
template <class Head, class... Tail>
inline void input(Head&& head, Tail&&... tail) {
    cin >> head;
    input(forward<Tail>(tail)...);
}

template <class T>
inline istream& operator>>(istream &is, vector<T> &vec) {
    for (auto &e: vec) {
        is >> e;
    }
    return is;
}

inline void output() { cout << "\n"; }
template <class Head, class... Tail>
inline void output(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail)) {
        cout << " ";
    }
    output(forward<Tail>(tail)...);
}

template <class T>
inline ostream& operator<<(ostream &os, const vector<T> &vec) {
    static constexpr const char *delim[] = {" ", ""};
    for (const auto &e: vec) {
        os << e << delim[&e == &vec.back()];
    }
    return os;
}

template <class T>
inline vector<T> makeVector(const T &initValue, size_t sz) {
    return vector<T>(sz, initValue);
}

template <class T, class... Args>
inline auto makeVector(const T &initValue, size_t sz, Args... args) {
    return vector<decltype(makeVector<T>(initValue, args...))>(sz, makeVector<T>(initValue, args...));
}

template <class Func>
class FixPoint : Func {
public:
    explicit constexpr FixPoint(Func&& f) noexcept : Func(forward<Func>(f)) {}

    template <class... Args>
    constexpr decltype(auto) operator()(Args&&... args) const {
        return Func::operator()(*this, std::forward<Args>(args)...);
    }
};

template <class Func>
static inline constexpr decltype(auto) makeFixPoint(Func&& f) noexcept {
    return FixPoint<Func>{forward<Func>(f)};
}

template <class T>
inline bool chmax(T &a, const T &b) noexcept {
    return b > a && (a = b, true);
}

template <class T>
inline bool chmin(T &a, const T &b) noexcept {
    return b < a && (a = b, true);
}

template <class T>
inline T diff(const T &a, const T &b) noexcept {
    return a < b ? b - a : a - b;
}
// End Header }}}

// Edge {{{
template <class Weight>
struct Edge {
    size_t from, to;
    Weight weight;

    Edge() {}
    Edge(size_t from, size_t to, Weight weight = 1) :
        from(from), to(to), weight(weight)
    {}

    bool operator<(const Edge &rhs) const {
        return weight < rhs.weight;
    }

    bool operator>(const Edge &rhs) const {
        return weight > rhs.weight;
    }

    operator size_t() const {
        return to;
    }
};
// }}}

// Graph {{{
template <class Weight>
class Graph : public vector<vector<Edge<Weight>>> {
    using graph = vector<vector<Edge<Weight>>>;

public:
    Graph() {}
    Graph(const size_t V) : graph(V) {}

    void connect(size_t from, size_t to, Weight weight = 1) {
        (*this)[from].emplace_back(from, to, weight);
    }

    friend ostream& operator<<(ostream &strm, const Graph &G) {
        for (size_t v = 0; v < G.size(); ++v) {
            strm << '[' << setw(2) << v << ']';
            for (const auto &e: G[v]) {
                strm << ' ' << setw(2) << e.to;
            }
            strm << '\n';
        }
        return strm;
    }
};
// }}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    var(size_t, V, E);

    Graph<size_t> G(V);
    rep(i, E) {
        var(size_t, u, v);
        u--, v--;
        G.connect(u, v);
        G.connect(v, u);
    }

    auto dp = makeVector<intmax_t>(-1, V, (1 << V));
    const auto res = makeFixPoint([&](auto dfs, size_t cur, size_t mask) -> intmax_t {
        if (__builtin_popcount(mask) == V) {
            return 1;
        }

        auto &ret = dp[cur][mask];
        if (~ret) {
            return ret;
        }

        ret = 0;
        for (const auto e: G[cur]) {
            if (mask & (1 << e.to)) {
                continue;
            }
            ret += dfs(e.to, mask | (1 << e.to));
        }

        return ret;
    })(0, 1);

    output(res);

    return 0;
}
