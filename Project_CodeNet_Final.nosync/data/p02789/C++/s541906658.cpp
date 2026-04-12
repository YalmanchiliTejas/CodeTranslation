#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

// Begin Header {{{
using namespace std;

#ifndef DEBUG
#define dump(...)
#endif

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, n) for (intmax_t i = 0, i##_limit = (n); i < i##_limit; ++i)
#define reps(i, b, e) for (intmax_t i = (b), i##_limit = (e); i <= i##_limit; ++i)
#define repr(i, b, e) for (intmax_t i = (b), i##_limit = (e); i >= i##_limit; --i)
#define var(Type, ...) Type __VA_ARGS__; input(__VA_ARGS__)

constexpr size_t    operator""_zu(unsigned long long value) { return value; };
constexpr intmax_t  operator""_jd(unsigned long long value) { return value; };
constexpr uintmax_t operator""_ju(unsigned long long value) { return value; };

constexpr int INF = 0x3f3f3f3f;
constexpr intmax_t LINF = 0x3f3f3f3f3f3f3f3f_jd;

namespace moke {

template <class T> using MaxHeap = priority_queue<T, vector<T>, less<T>>;
template <class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

inline void input() {}
template <class Head, class... Tail> inline void input(Head&& head, Tail&&... tail) {
    cin >> head;
    input(forward<Tail>(tail)...);
}

template <class T> inline void input(vector<T> &vec) {
    for (auto &e: vec) {
        cin >> e;
    }
}

template <class T> inline void input(vector<vector<T>> &mat) {
    for (auto &vec: mat) {
        input(vec);
    }
}

inline void print() { cout << "\n"; }
template <class Head, class... Tail> inline void print(Head&& head, Tail&&... tail) {
    static constexpr const char *delim[] = {"", " "};
    cout << head << delim[sizeof...(tail)];
    print(forward<Tail>(tail)...);
}

template <class T> inline ostream& operator<<(ostream &strm, const vector<T> &vec) {
    static constexpr const char *delim[] = {" ", ""};
    for (const auto &e: vec) {
        strm << e << delim[&e == &vec.back()];
    }
    return strm;
}

template <class T> inline vector<T> make_v(const T &initValue, size_t sz) {
    return vector<T>(sz, initValue);
}

template <class T, class... Args> inline auto make_v(const T &initValue, size_t sz, Args... args) {
    return vector<decltype(make_v<T>(initValue, args...))>(sz, make_v<T>(initValue, args...));
}

template <class A, class B> inline bool chmax(A &a, const B &b) noexcept {
    return b > a && (a = b, true);
}

template <class A, class B> inline bool chmin(A &a, const B &b) noexcept {
    return b < a && (a = b, true);
}

template <class A, class B> inline common_type_t<A, B> min(const A &a, const B &b) noexcept {
    return a < b ? a : b;
}

template <class A, class B, class... Args>
inline common_type_t<A, B, Args...> min(const A &a, const B &b, const Args&... args) noexcept {
    return moke::min(a < b ? a : b, args...);
}

template <class A, class B> inline common_type_t<A, B> max(const A &a, const B &b) noexcept {
    return a > b ? a : b;
}

template <class A, class B, class... Args>
inline common_type_t<A, B, Args...> max(const A &a, const B &b, const Args&... args) noexcept {
    return moke::max(a > b ? a : b, args...);
}

template <class A, class B> inline common_type_t<A, B> diff(const A &a, const B &b) noexcept {
    return a < b ? b - a : a - b;
}

} // namespace moke

// }}} End Header

namespace moke {

int main_() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    var(int, N, M);

    cout << ((N == M) ? "Yes" : "No") << "\n";

    return 0;
}

} // namespace moke

signed main() { // {{{
    moke::main_();
    return 0;
} // }}}
