#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"

// Begin Header {{{
using namespace std;

#ifndef DEBUG
#define dump(...)
#endif

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rep(i, b, e) for (intmax_t i = (b), i##_limit = (e); i < i##_limit; ++i)
#define repc(i, b, e) for (intmax_t i = (b), i##_limit = (e); i <= i##_limit; ++i)
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

template <class Container, class Value = typename Container::value_type,
         enable_if_t<!is_same<Container, string>::value, nullptr_t> = nullptr>
         inline istream& operator>>(istream &is, Container &vs) {
             for (auto &v: vs) is >> v;
             return is;
         }

inline void output() { cout << "\n"; }
template <class Head, class... Tail>
inline void output(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail)) cout << " ";
    output(forward<Tail>(tail)...);
}

template <class Container, class Value = typename Container::value_type,
         enable_if_t<!is_same<Container, string>::value, nullptr_t> = nullptr>
         inline ostream& operator<<(ostream &os, const Container &vs) {
             static constexpr const char *delim[] = {" ", ""};
             for (auto it = begin(vs); it != end(vs); ++it) {
                 os << delim[it == begin(vs)] << *it;
             }
             return os;
         }

template <class Iterator>
inline void join(const Iterator &Begin, const Iterator &End, const string &delim = "\n", const string &last = "\n") {
    for (auto it = Begin; it != End; ++it) {
        cout << ((it == Begin) ? "" : delim) << *it;
    }
    cout << last;
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

void ioinit() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    clog << fixed << setprecision(10);
}
// }}} End Header

// detectCycle {{{
template <class T, class Fn>
pair<intmax_t, intmax_t> detectCycle(const T& s, const Fn& fn) {
    T tortoise = s;
    T hare = s;
    do {
        tortoise = fn(tortoise);
        hare = fn(fn(hare));
    } while (tortoise != hare);

    tortoise = s;
    intmax_t mu = 0;
    while (tortoise != hare) {
        ++mu;
        tortoise = fn(tortoise);
        hare = fn(hare);
    }

    intmax_t lamda = 0;
    do {
        ++lamda;
        hare = fn(hare);
    } while (hare != tortoise);

    return {mu, lamda};
}
// }}}

signed main() {
    ioinit();

    var(intmax_t, N, X, M);

    const auto f = [&](intmax_t i) -> intmax_t {
        return (i * i) % M;
    };

    const auto [mu, lamda] = detectCycle(X, f);
    dump(mu, lamda);

    intmax_t res = 0;
    if (N <= mu) {
        rep(i, 0, N) {
            res += X;
            X = f(X);
            dump(X);
        }
        output(res);
    } else {
        rep(i, 0, mu) {
            res += X;
            X = f(X);
            dump(X);
        }
        N -= mu;
        intmax_t sum = 0;
        rep(i, 0, lamda) {
            sum += X;
            X = f(X);
        }
        res += (N / lamda) * sum;
        N %= lamda;
        rep(i, 0, N) {
            res += X;
            X = f(X);
        }
        output(res);
    }

    return 0;
}
