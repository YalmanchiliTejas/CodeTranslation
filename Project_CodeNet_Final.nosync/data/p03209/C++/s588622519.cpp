#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

// Begin Headelr {{{
using namespace std;

#ifndef DEBUG
#define dump(...)
#endif

#define all(x) x.begin(), x.end()
#define rep(i, b, e) for (intmax_t i = (b), i##_limit = (e); i < i##_limit; ++i)
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

using imax = intmax_t;
using usize = size_t;

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

template <class Container>
struct reverse_t {
    Container &c;
    reverse_t(Container &c) : c(c) {}
    auto begin() { return c.rbegin(); }
    auto end() { return c.rend(); }
};

template <class Container>
auto reversed(Container &c) {
    return reverse_t<Container>(c);
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
// }}} End Header

constexpr int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

const auto inside = [](int y, int x, int H, int W) -> bool {
    return (y >= 0 && x >= 0 && y < H && x < W);
};

// SegmentTree {{{
template <class Monoid>
struct SegmentTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    const size_t sz;
    const Func fn;
    const Monoid unity;
    vector<Monoid> seg;

    SegmentTree(const size_t n, const Monoid &u, Func f)
        : sz(1 << (__lg(n + 5) + 1)), fn(f), unity(u), seg(sz * 2, unity) {}

    void set(size_t k, const Monoid &v) {
        seg[k + sz] = v;
    }

    Monoid& operator[](size_t k) {
        return seg[k + sz];
    }
    const Monoid& operator[](size_t k) const {
        return seg[k + sz];
    }

    void build() {
        for (size_t k = sz - 1; k > 0; --k) {
            seg[k] = fn(seg[2 * k], seg[2 * k + 1]);
        }
    }

    void update(size_t k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = fn(seg[2 * k], seg[2 * k + 1]);
        }
    }

    Monoid query(size_t a, size_t b) const {
        Monoid L = unity, R = unity;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = fn(L, seg[a++]);
            if (b & 1) R = fn(seg[--b], R);
        }
        return fn(L, R);
    }
};
// }}}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios_base::fixed);
    cout.precision(10);
    var(imax, N, X);
    vector<imax> a(N + 1), p(N + 1);
    // a[N] := N 枚バーガーの層の総数
    // p[N] := N 枚バーガーのパティの総数
    a[0] = p[0] = 1;
    reps(i, 1, N) {
        a[i] = 3 + 2 * a[i - 1];
        p[i] = 1 + 2 * p[i - 1];
    }
    // f(N, X) := レベル N バーガーの下から X 層に含まれるパティの枚数。
    const auto res = makeFixPoint([&](auto f, imax N, imax X) -> imax {
        imax ret = 0;
        if (X == a[N]) {
            return p[N];
        } else if (X == 1) {
            return 0;
        } else if (X <= 1 + a[N - 1]) {
            ret += f(N - 1, X - 1);
        } else if (X == 2 + a[N - 1]) {
            return 1 + p[N - 1];
        } else {
            ret += p[N - 1] + 1 + f(N - 1, X - (2 + a[N - 1]));
        }
        return ret;
    })(N, X);
    output(res);
    return 0;
}