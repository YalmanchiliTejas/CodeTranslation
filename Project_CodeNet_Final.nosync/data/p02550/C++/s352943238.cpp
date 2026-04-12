#include <bits/stdc++.h>
// header {{{
#define all(x) std::begin(x), std::end(x)
#define rall(x) std::rbegin(x), std::rend(x)
#define rep(i, begin, end) for (std::make_signed_t<std::remove_cv_t<decltype(end)>> i = (begin), i##_end = (end); i < i##_end; ++i)
#define repc(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(end)>> i = (begin), i##_last = (last); i <= i##_last; ++i)
#define repr(i, begin, last) for (std::make_signed_t<std::remove_cv_t<decltype(end)>> i = (begin), i##_last = (last); i >= i##_last; --i)
#define let const auto
using i64 = std::int64_t;
using u64 = std::uint64_t;
constexpr std::int32_t INF = 0x3f3f3f3f;
constexpr std::int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;

template <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container, std::string>, std::nullptr_t> = nullptr>
std::istream& operator>>(std::istream& is, Container& v) {
    for (auto& e : v) is >> e;
    return is;
}

template <class Container, class = typename Container::value_type, std::enable_if_t<!std::is_same_v<Container, std::string>, std::nullptr_t> = nullptr>
std::ostream& operator<<(std::ostream& os, const Container& v) {
    for (auto it = std::begin(v); it != std::end(v); ++it) os << &" "[it == std::begin(v)] << *it;
    return os;
}

template <class T>
std::istream& operator,(std::istream& is, T& rhs) {
    return is >> rhs;
}

#define var(type, ...) \
    type __VA_ARGS__;  \
    std::cin >> __VA_ARGS__

inline void println() {
    std::cout << '\n';
}
template <class Head, class... Tail>
inline void println(Head&& head, Tail&&... tail) {
    std::cout << head << &" "[!sizeof...(tail)];
    println(std::forward<Tail>(tail)...);
}

template <class T, class U>
inline bool chmin(T& a, const U& b) {
    return b < a && (a = b, true);
}

template <class T, class U>
inline bool chmax(T& a, const U& b) {
    return b > a && (a = b, true);
}
// }}}

using namespace std;

// mod-int {{{
namespace impl {

template <class ModHolder>
class ModInt {
private:
    int64_t value;

public:
    constexpr ModInt()
        : value(0) {}
    constexpr ModInt(int64_t v)
        : value(ModInt::normalized(v)) {}

    static constexpr ModInt raw(int64_t v) {
        ModInt ret;
        ret.value = v;
        return ret;
    }

    static constexpr ModInt nullopt() { return ModInt::raw(std::numeric_limits<int64_t>::min()); }

    constexpr bool isNull() const { return *this == ModInt::nullopt(); }

    static constexpr int64_t mod() { return ModHolder::mod; }

    static int64_t setMod(int64_t m) {
        assert(m >= 1);
        return ModHolder::mod = m;
    }

    template <class T>
    constexpr explicit operator T() const {
        return static_cast<T>(value);
    }
    constexpr ModInt& operator+=(const ModInt& rhs) {
        if ((value += rhs.value) >= mod()) value -= mod();
        return *this;
    }
    constexpr ModInt& operator-=(const ModInt& rhs) {
        if ((value -= rhs.value) < 0) value += mod();
        return *this;
    }
    constexpr ModInt& operator*=(const ModInt& rhs) {
        (value *= rhs.value) %= mod();
        return *this;
    }
    constexpr ModInt& operator/=(const ModInt& rhs) { return *this *= rhs.inv(); }
    constexpr const ModInt inv() const { return ModInt(ModInt::inverse(value, mod())); }
    constexpr const ModInt operator+() const { return *this; }
    constexpr const ModInt operator-() const { return ModInt(-value); }

    constexpr const ModInt pow(int64_t expv) const {
        int64_t ret = 1, square = value;
        for (uint64_t p = std::abs(expv); p; p >>= 1) {
            if (p & 1) (ret *= square) %= mod();
            (square *= square) %= mod();
        }
        return (expv < 0) ? (ModInt::raw(1) / ModInt::raw(ret)) : ModInt::raw(ret);
    }

    friend constexpr bool operator==(const ModInt& lhs, const ModInt& rhs) { return lhs.value == rhs.value; }
    friend constexpr bool operator!=(const ModInt& lhs, const ModInt& rhs) { return lhs.value != rhs.value; }
    friend constexpr const ModInt operator+(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) += rhs; }
    friend constexpr const ModInt operator-(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }
    friend constexpr const ModInt operator*(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) *= rhs; }
    friend constexpr const ModInt operator/(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) /= rhs; }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) {
#ifdef LOCAL_DEBUG
        if (x.isNull()) return os << "{nullopt}";
#endif
        return os << x.value;
    }

    friend std::istream& operator>>(std::istream& is, ModInt& x) {
        is >> x.value;
        x.value = ModInt::normalized(x.value);
        return is;
    }

private:
    static constexpr int64_t normalized(int64_t n) {
        n = (-mod() <= n && n < mod() ? n : n % mod());
        if (n < 0) n += mod();
        return n;
    }

    static constexpr int64_t inverse(int64_t a, int64_t m) {
        int64_t u = 0, v = 1;
        while (a != 0) {
            const auto t = m / a;
            static_cast<void>(m -= t * a), std::swap(m, a);
            static_cast<void>(u -= t * v), std::swap(u, v);
        }
        assert(m == 1);
        return u;
    }
};

template <int64_t Mod>
struct StaticModHolder {
    static constexpr int64_t mod = Mod;
};

template <auto ID>
struct DynamicModHolder {
    static int64_t mod;
};
template <auto ID>
int64_t DynamicModHolder<ID>::mod;

}  // namespace impl

template <int64_t Mod>
using StaticModInt = impl::ModInt<impl::StaticModHolder<Mod>>;

using ModInt1000000007 = StaticModInt<int(1e9) + 7>;
using ModInt998244353 = StaticModInt<998244353>;

template <auto ID>
using DynamicModInt = impl::ModInt<impl::DynamicModHolder<ID>>;
// }}}

// debug {{{
template <class A, class B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& t) {
    return os << '{' << std::get<0>(t) << ", " << std::get<1>(t) << '}';
}
template <class A, class B, class C>
std::ostream& operator<<(std::ostream& os, const std::tuple<A, B, C>& t) {
    return os << '{' << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << '}';
}

template <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 4, std::nullptr_t> = nullptr>
constexpr T infinity() {
    return INF;
}

template <class T, std::enable_if_t<std::is_integral_v<T> && sizeof(T) == 8, std::nullptr_t> = nullptr>
constexpr T infinity() {
    return LINF;
}

#ifdef LOCAL_DEBUG

class Debug {
private:
    int w_ = 4;
    int valueOffset_ = 0;
    int indexOffset_ = 0;
    bool negativeValAsNull_ = true;
    static constexpr int32_t inf32_ = INF;
    static constexpr int64_t inf64_ = LINF;

public:
    std::ostream& os = std::cerr;

    Debug() = default;

    void line() const { os << "---------------------------------------------------\n"; }
    void flush() const { os << std::flush; }
    void w(int w) { w_ = w; }
    void valueOffset(int v) { valueOffset_ = v; }
    void indexOffset(int v) { indexOffset_ = v; }
    void negativeValAsNull(bool f) { negativeValAsNull_ = f; }

    template <class T>
    void show(const T& x) const {
        put(x), os << '\n';
    }

    template <class T, class U, class... Tail>
    void show(const T& x, const U& y, const Tail&... tail) const {
        put(x);
        os << ",  ";
        show(y, tail...);
    }

    template <class Arr>
    void showArray(const Arr& a) const {
        showArray(a, 0, a.size());
    }

    template <class Arr>
    void showArray(const Arr& a, size_t begin, size_t end) const {
        os << '\n';
        for (size_t i = begin; i < end; ++i) os << '[' << std::setw(w_) << (i + indexOffset_) << "] ";
        os << '\n';
        for (size_t i = begin; i < end; ++i) os << ' ' << std::setw(w_), put(a[i]), os << "  ";
        os << '\n';
    }

    template <class Table>
    void showTable(const Table& t) const {
        showTable(t, 0, t.size(), 0, t[0].size());
    }

    template <class Table>
    void showTable(const Table& t, size_t yBegin, size_t yEnd, size_t xBegin, size_t xEnd) const {
        os << '\n';
        os << std::string(1 + 2 + 1, ' ');
        for (size_t j = xBegin; j < xEnd; ++j) os << '[' << std::setw(w_) << (j + indexOffset_) << "] ";
        os << '\n';

        for (size_t i = yBegin; i < yEnd; ++i) {
            os << '[' << std::setw(2) << (i + indexOffset_) << "]";
            for (size_t j = xBegin; j < xEnd; ++j) os << ' ' << std::setw(w_), put(t[i][j]), os << "  ";
            os << '\n';
        }
    }

private:
    template <class T>
    void put(const T& x) const {
        if constexpr (std::is_same_v<T, char>) {
            os << '\'' << x << '\'';
        } else if constexpr (std::is_same_v<T, bool>) {
            os << std::setw(w_) << (x ? "1" : "0");
        } else if constexpr (std::is_integral_v<T>) {
            os << std::setw(w_) << convert(x);
        } else if constexpr (std::is_convertible_v<T, std::string_view>) {
            os << std::setw(w_) << std::quoted(x);
        } else {
            os << std::setw(w_) << x;
        }
    }

    template <class T>
    std::string convert(const T& x) const {
        if constexpr (std::is_signed_v<T>) {
            if (x <= -infinity<T>()) return "-INF";
            if (negativeValAsNull_ && x < 0) return "-";
        }
        if (x >= infinity<T>()) return "INF";
        return std::to_string(x + valueOffset_);
    }
};

#define dump(...)                                                                                    \
    debug.os << "line" << std::setw(3) << std::setfill('0') << __LINE__ << std::setfill(' ') << ": " \
             << "[" << #__VA_ARGS__ << "]: ",                                                        \
        debug.show(__VA_ARGS__)

#else

#define DEF_FUNC(funcName) \
    template <class... T>  \
    void funcName(T&&...) {}

struct Debug {
    DEF_FUNC(line)
    DEF_FUNC(flush)
    DEF_FUNC(w)
    DEF_FUNC(valueOffset)
    DEF_FUNC(indexOffset)
    DEF_FUNC(negativeValAsNull)
    DEF_FUNC(inf32)
    DEF_FUNC(inf64)
    DEF_FUNC(show)
    DEF_FUNC(showArray)
    DEF_FUNC(showTable)
};

#undef DEF_FUNC
#define dump(...) ((void)0)

#endif

Debug debug;
// }}}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(12);
    using Mint = DynamicModInt<'M'>;

    var(i64, N, X, M);
    Mint::setMod(M);
    dump(Mint::mod());

    vector<Mint> a(min<i64>(N + 5, 2 * M));
    a[1] = X;

    for (int i = 1; i + 1 < a.size(); ++i) {
        a[i + 1] = a[i] * a[i];
    }

    unordered_map<int, int> S;
    int loopBegin = -1;
    int loopEnd = -1;
    i64 sum = 0;
    for (int i = 1; i < a.size(); ++i) {
        if (i > N) {
            println(sum);
            return 0;
        }

        const int value = int(a[i]);

        if (value == 0) {
            println(sum);
            return 0;
        }

        if (S.count(value)) {
            loopBegin = S[value];
            loopEnd = i;
            break;
        }

        sum += value;
        S[value] = i;
    }

    i64 headSum = 0;
    i64 unitSum = 0;
    for (int i = 1; i < loopBegin; ++i) {
        headSum += int(a[i]);
    }
    for (int i = loopBegin; i < loopEnd; ++i) {
        unitSum += int(a[i]);
    }

    const i64 unitLen = loopEnd - loopBegin;
    const i64 remLen = N - (loopBegin - 1);

    dump(headSum, unitLen, remLen);

    i64 ans = 0;
    ans += headSum;
    ans += (remLen / unitLen) * unitSum;

    const auto xxx = remLen % unitLen;
    for (int i = 0; i < xxx; ++i) {
        ans += int(a[loopBegin + i]);
    }

    println(ans);

    return 0;
}
