#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

void ioinit() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios_base::fixed);
    cout.precision(10);
}
// End Header }}}

const intmax_t MOD = intmax_t(1e9) + 7;
// ModInt {{{
template <intmax_t MOD>
class ModInt {
    intmax_t value;

public:
    inline ModInt(const ModInt& other) :
        value(other.value)
    {}

    inline ModInt(const intmax_t& value = 0) {
        if (value >= MOD) {
            this->value = value % MOD;
        } else if (value < 0) {
            this->value = (value % MOD + MOD) % MOD;
        } else {
            this->value = value;
        }
    }

    template <class T>
        explicit inline operator T() const {
            return static_cast<T>(value);
        }

    inline ModInt inverse() const {
        return ModInt::pow(value, MOD - 2);
    }

    inline ModInt& operator+=(const ModInt& other) {
        if ((value += other.value) >= MOD) value -= MOD;
        return *this;
    }

    inline ModInt& operator-=(const ModInt& other) {
        if ((value -= other.value) < 0) value += MOD;
        return *this;
    }

    inline ModInt& operator*=(const ModInt& other) {
        value = (value * other.value) % MOD;
        return *this;
    }

    inline ModInt& operator/=(const ModInt& other) {
        value = (value * other.inverse().value) % MOD;
        return *this;
    }

    inline ModInt operator+(const ModInt& other) {
        return ModInt(*this) += other;
    }

    inline ModInt operator-(const ModInt& other) {
        return ModInt(*this) -= other;
    }

    inline ModInt operator*(const ModInt& other) {
        return ModInt(*this) *= other;
    }

    inline ModInt operator/(const ModInt& other) {
        return ModInt(*this) /= other;
    }

    inline ModInt& operator++() {
        value = (value + 1) % MOD;
        return *this;
    }

    inline ModInt& operator--() {
        value = (value - 1 + MOD) % MOD;
        return *this;
    }

    inline ModInt operator++(int) {
        ModInt tmp(*this);
        ++*this;
        return tmp;
    }

    inline ModInt operator--(int) {
        ModInt tmp(*this);
        --*this;
        return tmp;
    }

    inline bool operator==(const ModInt& other) {
        return value == other.value;
    }

    inline bool operator!=(const ModInt& other) {
        return value != other.value;
    }

    friend ostream& operator<<(ostream &os, const ModInt& other) {
        os << other.value;
        return os;
    }

    friend istream& operator>>(istream &is, ModInt& other) {
        is >> other.value;
        other.value = (other.value % MOD + MOD) % MOD;
        return is;
    }

    static constexpr inline ModInt pow(intmax_t n, intmax_t p) {
        intmax_t ret = 1;
        for (; p > 0; p >>= 1) {
            if (p & 1) ret = (ret * n) % MOD;
            n = (n * n) % MOD;
        }
        return ret;
    }
};

using Mint = ModInt<MOD>;
// }}}

// BinaryIndexedTree {{{
template <class T>
struct BinaryIndexedTree {
    vector<T> bit;
    const size_t SIZE;

    explicit BinaryIndexedTree(size_t n) : bit(n + 5, 0), SIZE(1 << (__lg(n + 5) + 1)) {}

    void add(int i, const T& v) {
        for (++i; i < bit.size(); i += i & -i) bit[i] += v;
    }

    // [0, i]
    T sum(int i) const {
        T ret = 0;
        for (++i; i > 0; i -= i & -i) ret += bit[i];
        return ret;
    }

    // [s, t]
    T sum(int s, int t) const {
        if (s > t) swap(s, t);
        return sum(t) - sum(s - 1);
    }

    size_t lower_bound(T v) const {
        if (v <= 0) return 0;
        T x = 0;
        for (size_t k = SIZE; k > 0; k >>= 1) {
            if (x + k < bit.size() && bit[x + k] < v) {
                v -= bit[x + k];
                x += k;
            }
        }
        return x;
    }
};
// }}}

signed main() {
    ioinit();

    var(size_t, N);

    vector<Mint> a(N);
    input(a);

    BinaryIndexedTree<Mint> bit(N);
    rep(i, 0, N) bit.add(i, a[i]);

    Mint res = 0;
    rep(i, 0, N - 1) {
        res += a[i] * bit.sum(i + 1, N - 1);
    }

    output(res);

    return 0;
}
