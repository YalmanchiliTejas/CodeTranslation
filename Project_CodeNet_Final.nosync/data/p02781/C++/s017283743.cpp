#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

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

template <class T>
using MaxHeap = priority_queue<T, vector<T>, less<T>>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

inline void input() {}
template <class Head, class... Tail>
inline void input(Head&& head, Tail&&... tail) {
    cin >> head;
    input(forward<Tail>(tail)...);
}

template <class T>
inline void input(vector<T> &vec) {
    for (auto &e: vec) {
        cin >> e;
    }
}

template <class T>
inline void input(vector<vector<T>> &mat) {
    for (auto &vec: mat) {
        input(vec);
    }
}

inline void print() { cout << "\n"; }
template <class Head, class... Tail>
inline void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail)) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
inline ostream& operator<<(ostream &strm, const vector<T> &vec) {
    static constexpr const char *delim[] = {" ", ""};
    for (const auto &e: vec) {
        strm << e << delim[&e == &vec.back()];
    }
    return strm;
}

template <class T>
inline vector<T> make_v(const T &initValue, size_t sz) {
    return vector<T>(sz, initValue);
}

template <class T, class... Args>
inline auto make_v(const T &initValue, size_t sz, Args... args) {
    return vector<decltype(make_v<T>(initValue, args...))>(sz, make_v<T>(initValue, args...));
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    var(string, N);
    var(size_t, K);

    auto dp = make_v<intmax_t>(-1, N.length() + 1, K + 1, 2);
    const auto res = makeFixPoint([&](auto rec, size_t i, size_t cnt, bool tight) -> intmax_t {
        if (i == N.length()) {
            return (cnt == K);
        }

        auto &ret = dp[i][cnt][tight];
        if (~ret) {
            return ret;
        }

        ret = 0;
        size_t lim = (tight ? N[i] - '0' : 9_zu);

        if (cnt >= K) {
            ret += rec(i + 1, cnt, tight && (0 == lim));
        }

        else {
            for (size_t d = 0; d <= lim; ++d) {
                ret += rec(i + 1, cnt + (d != 0), tight && (d == lim));
            }
        }

        return ret;
    })(0, 0, true);

    print(res);

    return 0;
}
