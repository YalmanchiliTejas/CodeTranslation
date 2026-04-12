#include "bits/stdc++.h"

// Begin Header {{{
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
// End Header }}}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios_base::fixed);
    cout.precision(10);
    var(intmax_t, N, K);
    if (N <= K) return output(0), 0;
    if (K == 0) return output(N * N), 0;
    intmax_t res = 0;
    reps(b, K + 1, N) {
        const intmax_t val = (N / b) * (b - K) + max(0_jd, (N % b) - K + 1);
        res += val;
    }
    output(res);
    return 0;
}
