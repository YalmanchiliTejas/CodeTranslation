#include "bits/stdc++.h"
// Begin Header {{{
#define all(x) (x).begin(), (x).end()
#define rep(i, s, n) for (i64 i = (s), i##_limit = (n); i < i##_limit; ++i)
#define repr(i, s, t) for (i64 i = (s), i##_limit = (t); i >= i##_limit; --i)
#define var(type, ...) \
    type __VA_ARGS__;  \
    read(__VA_ARGS__);
#ifndef DBG
#define dump(...)
#endif
using namespace std;
using i64 = int_fast64_t;
using pii = pair<i64, i64>;
template <class T, class U>
inline bool chmax(T &a, const U &b) {
    return b > a && (a = b, true);
}
template <class T, class U>
inline bool chmin(T &a, const U &b) {
    return b < a && (a = b, true);
}
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;

template <class T>
inline vector<T> makeV(const T &initValue, size_t sz) {
    return vector<T>(sz, initValue);
}

template <class T, class... Args>
inline auto makeV(const T &initValue, size_t sz, Args... args) {
    return vector<decltype(makeV<T>(initValue, args...))>(
        sz, makeV<T>(initValue, args...));
}

template <class T>
inline istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &e : vec) is >> e;
    return is;
}

inline void read() {}

template <class Head, class... Tail>
inline void read(Head &head, Tail &... tail) {
    cin >> head;
    read(tail...);
}

inline void print() { cout << "\n"; }

template <class Head, class... Tail>
inline void print(Head &&head, Tail &&... tail) {
    cout << head;
    if (sizeof...(tail)) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
inline ostream &operator<<(ostream &os, const vector<T> &vec) {
    static constexpr const char *delim[] = {" ", ""};
    for (const auto &e : vec) os << e << delim[&e == &vec.back()];
    return os;
}

template <class Container>
struct Rev {
    Container &x_;
    inline Rev(Container &x) : x_(x) {}
    inline auto begin() { return rbegin(x_); }
    inline auto end() { return rend(x_); }
};
// }}} End Header

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    var(int, N);
    vector<i64> a(N);
    read(a);

    sort(all(a), greater<>());

    dump(a);

    i64 ans = 0;
    {
        const i64 L = N / 2;
        const i64 H = N - L;

        auto itr = a.cbegin();
        i64 highSum = accumulate(itr, itr + H, 0LL) * 2;
        i64 lowSum = accumulate(itr + H, itr + N, 0LL) * 2;

        if (H == L) {
            highSum -= a[H - 1];
            lowSum -= a[H];
        } else {
            highSum -= a[H - 1];
            highSum -= a[H - 2];
        }

        dump(H, L, highSum, lowSum);
        chmax(ans, highSum - lowSum);
    }

    {
        const i64 H = N / 2;
        const i64 L = N - H;

        auto itr = a.cbegin();
        i64 highSum = accumulate(itr, itr + H, 0LL) * 2;
        i64 lowSum = accumulate(itr + H, itr + N, 0LL) * 2;

        if (H == L) {
            highSum -= a[H - 1];
            lowSum -= a[H];
        } else {
            lowSum -= a[H];
            lowSum -= a[H + 1];
        }

        dump(H, L, highSum, lowSum);
        chmax(ans, highSum - lowSum);
    }

    print(ans);
    return 0;
}
