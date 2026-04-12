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

inline void outs() { cout << "\n"; }
template <class Head, class... Tail> inline void outs(Head&& head, Tail&&... tail) {
    cout << head << (sizeof...(tail) ? " " : "");
    outs(forward<Tail>(tail)...);
}

template <class T> inline void outs(vector<T> &vec) {
    for (auto &e : vec) cout << e << " \n"[&e == &vec.back()];
}

template <class T> inline void outs(vector<vector<T>> &df) {
    for (auto &vec : df) outs(vec);
}

inline void outl() { cout << "\n"; }
template <class Head, class... Tail> inline void outl(Head&& head, Tail&&... tail) {
    cout << head << (sizeof...(tail) ? "\n" : "");
    outl(forward<Tail>(tail)...);
}

template <class T> inline void outl(vector<T> &vec) {
    for (auto &e : vec) cout << e << "\n";
}

inline void outn() {}
template <class Head, class... Tail> inline void outn(Head&& head, Tail&&... tail) {
    cout << head;
    outn(forward<Tail>(tail)...);
}

template <class T> inline void outn(vector<T> &vec) {
    for (auto &e : vec) cout << e;
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

    var(size_t, N);

    vector<intmax_t> a(N);
    for (auto &ai: a) input(ai);

    sort(all(a));

    deque<intmax_t> deq1;
    deq1.emplace_back(a[0]);

    bool opt = true;
    int left = 1, right = N - 1;

    while (left <= right) {
        if (diff(left, right) == 0) {
            intmax_t midValue = a[left];
            intmax_t leftValue = deq1.front();
            intmax_t rightValue = deq1.back();
            if (diff(midValue, leftValue) > diff(midValue, rightValue)) {
                deq1.emplace_front(midValue);
            } else {
                deq1.emplace_back(midValue);
            }
            break;
        }
        if (opt) {
            deq1.emplace_front(a[right]);
            right--;
            deq1.emplace_back(a[right]);
            right--;
        } else {
            deq1.emplace_front(a[left]);
            left++;
            deq1.emplace_back(a[left]);
            left++;
        }
        opt ^= 1;
    }

    deque<intmax_t> deq2;
    deq2.emplace_back(a[N - 1]);

    opt = true;
    left = 0, right = N - 2;

    while (left <= right) {
        if (diff(left, right) == 0) {
            intmax_t midValue = a[left];
            intmax_t leftValue = deq2.front();
            intmax_t rightValue = deq2.back();
            if (diff(midValue, leftValue) > diff(midValue, rightValue)) {
                deq2.emplace_front(midValue);
            } else {
                deq2.emplace_back(midValue);
            }
            break;
        }
        if (opt) {
            deq2.emplace_front(a[left]);
            left++;
            deq2.emplace_back(a[left]);
            left++;
        } else {
            deq2.emplace_front(a[right]);
            right--;
            deq2.emplace_back(a[right]);
            right--;
        }
        opt ^= 1;
    }

    vector<intmax_t> buff1;
    while (!deq1.empty()) {
        buff1.emplace_back(deq1.front());
        deq1.pop_front();
    }

    vector<intmax_t> buff2;
    while (!deq2.empty()) {
        buff2.emplace_back(deq2.front());
        deq2.pop_front();
    }

    dump(buff1, buff2);

    intmax_t res1 = 0, res2 = 0;
    reps(i, 1, N - 1) {
        res1 += diff(buff1[i], buff1[i - 1]);
        res2 += diff(buff2[i], buff2[i - 1]);
    }

    dump(res1, res2);

    outl(max(res1, res2));

    return 0;
}

} // namespace moke

signed main() { // {{{

    moke::main_();

    return 0;
} // }}}
