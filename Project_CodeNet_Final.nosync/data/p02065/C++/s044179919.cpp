#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#define NDEBUG
#define SHOW(...) static_cast<void>(0)
//!===========================================================!//
//!  dP     dP                          dP                    !//
//!  88     88                          88                    !//
//!  88aaaaa88a .d8888b. .d8888b. .d888b88 .d8888b. 88d888b.  !//
//!  88     88  88ooood8 88'  '88 88'  '88 88ooood8 88'  '88  !//
//!  88     88  88.  ... 88.  .88 88.  .88 88.  ... 88        !//
//!  dP     dP  '88888P' '88888P8 '88888P8 '88888P' dP        !//
//!===========================================================!//
template <typename T>
T read()
{
    T v;
    return std::cin >> v, v;
}
template <typename T>
std::vector<T> readVec(const std::size_t l)
{
    std::vector<T> v(l);
    for (auto& e : v) { std::cin >> e; }
    return v;
}
using ld = long double;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr unsigned int MOD = 1000000007;
template <typename T>
constexpr T INF = std::numeric_limits<T>::max() / 4;
template <typename F>
constexpr F PI = static_cast<F>(3.1415926535897932385);
std::mt19937 mt{std::random_device{}()};
template <typename T>
bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template <typename T>
bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }
template <typename T>
std::vector<T> Vec(const std::size_t n, T v) { return std::vector<T>(n, v); }
template <class... Args>
auto Vec(const std::size_t n, Args... args) { return std::vector<decltype(Vec(args...))>(n, Vec(args...)); }
template <typename T>
constexpr T popCount(const T u)
{
#ifdef __has_builtin
    return u == 0 ? T(0) : (T)__builtin_popcountll(u);
#else
    unsigned long long v = static_cast<unsigned long long>(u);
    return v = (v & 0x5555555555555555ULL) + (v >> 1 & 0x5555555555555555ULL), v = (v & 0x3333333333333333ULL) + (v >> 2 & 0x3333333333333333ULL), v = (v + (v >> 4)) & 0x0F0F0F0F0F0F0F0FULL, static_cast<T>(v * 0x0101010101010101ULL >> 56 & 0x7f);
#endif
}
template <typename T>
constexpr T log2p1(const T u)
{
#ifdef __has_builtin
    return u == 0 ? T(0) : T(64 - __builtin_clzll(u));
#else
    unsigned long long v = static_cast<unsigned long long>(u);
    return v = static_cast<unsigned long long>(v), v |= (v >> 1), v |= (v >> 2), v |= (v >> 4), v |= (v >> 8), v |= (v >> 16), v |= (v >> 32), popCount(v);
#endif
}
template <typename T>
constexpr T clog(const T v) { return v == 0 ? T(0) : log2p1(v - 1); }
template <typename T>
constexpr T msbp1(const T v) { return log2p1(v); }
template <typename T>
constexpr T lsbp1(const T v)
{
#ifdef __has_builtin
    return __builtin_ffsll(v);
#else
    return v == 0 ? T(0) : popCount((v & (-v)) - T(1)) + T(1);
#endif
}
template <typename T>
constexpr bool ispow2(const T v) { return popCount(v) == 1; }
template <typename T>
constexpr T ceil2(const T v) { return v == 0 ? T(1) : T(1) << log2p1(v - 1); }
template <typename T>
constexpr T floor2(const T v) { return v == 0 ? T(0) : T(1) << (log2p1(v) - 1); }
//!===============================================================!//
//!   88888888b            dP       .88888.   a88888b. 888888ba   !//
//!   88                   88      d8'   '88 d8'   '88 88    '8b  !//
//!  a88aaaa    dP.  .dP d8888P    88        88        88     88  !//
//!   88         '8bd8'    88      88   YP88 88        88     88  !//
//!   88         .d88b.    88      Y8.   .88 Y8.   .88 88    .8P  !//
//!   88888888P dP'  'dP   dP       '88888'   Y88888P' 8888888P   !//
//!===============================================================!//
template <typename T>
constexpr std::pair<T, T> extgcd(const T a, const T b)
{
    if (b == 0) { return std::pair<T, T>{1, 0}; }
    const auto p = extgcd(b, a % b);
    return {p.second, p.first - p.second * (a / b)};
}
template <typename T>
constexpr T inverse(const T a, const T mod) { return (mod + extgcd((mod + a % mod) % mod, mod).first % mod) % mod; }
//!===============================================================!//
//!  888888ba  8888ba.88ba                 dP dP            dP    !//
//!  88    '8b 88  '8b  '8b                88 88            88    !//
//!  88     88 88   88   88 .d8888b. .d888b88 88 88d888b. d8888P  !//
//!  88     88 88   88   88 88'  '88 88'  '88 88 88'  '88   88    !//
//!  88    .8P 88   88   88 88.  .88 88.  .88 88 88    88   88    !//
//!  8888888P  dP   dP   dP '88888P' '88888P8 dP dP    dP   dP    !//
//!===============================================================!//
class DModInt
{
private:
    uint v;
    static uint norm(const uint x, const uint mod) { return x < mod ? x : x - mod; }
    static DModInt make(const uint x, const uint mod)
    {
        DModInt m(mod);
        return m.v = x, m;
    }
    static DModInt power(DModInt x, ll n)
    {
        assert(n >= 0);
        DModInt ans{1, x.mod};
        for (; n; n >>= 1, x *= x) {
            if (n & 1) { ans *= x; }
        }
        return ans;
    }
    static DModInt inv(const DModInt& x) { return DModInt{inverse(static_cast<ll>(x.v), static_cast<ll>(x.mod)), x.mod}; }

public:
    DModInt(const uint mod) : v{0}, mod{mod} {}
    DModInt(const ll val, const uint mod) : v{norm(static_cast<uint>(val % static_cast<ll>(mod) + static_cast<ll>(mod)), mod)}, mod{mod} {}
    DModInt(const DModInt& n) : v{n()}, mod{n.mod} {}
    explicit operator bool() const { return v != 0; }
    DModInt& operator=(const DModInt& n) { return assert(mod == n.mod), v = n(), (*this); }
    DModInt& operator=(const ll val) { return v = norm(static_cast<uint>(val % static_cast<ll>(mod) + static_cast<ll>(mod)), mod), (*this); }
    friend DModInt operator+(const DModInt& m) { return m; }
    friend DModInt operator-(const DModInt& m) { return make(norm(m.mod - m.v, m.mod), m.mod); }
    friend DModInt operator+(const DModInt& m1, const DModInt& m2) { return assert(m1.mod == m2.mod), make(norm(m1.v + m2.v, m1.mod), m1.mod); }
    friend DModInt operator-(const DModInt& m1, const DModInt& m2) { return assert(m1.mod == m2.mod), make(norm(m1.mod + m1.v - m2.v, m1.mod), m1.mod); }
    friend DModInt operator*(const DModInt& m1, const DModInt& m2) { return assert(m1.mod == m2.mod), make(static_cast<uint>(static_cast<ll>(m1.v) * static_cast<ll>(m2.v) % static_cast<ll>(m1.mod)), m1.mod); }
    friend DModInt operator/(const DModInt& m1, const DModInt& m2) { return assert(m1.mod == m2.mod), m1* inv(m2); }
    friend DModInt operator+(const DModInt& m, const ll val) { return DModInt{m.v + val, m.mod}; }
    friend DModInt operator-(const DModInt& m, const ll val) { return DModInt{m.v - val, m.mod}; }
    friend DModInt operator*(const DModInt& m, const ll val) { return DModInt{static_cast<ll>(m.v) * (val % m.mod), m.mod}; }
    friend DModInt operator/(const DModInt& m, const ll val) { return m * inv(DModInt{val, m.mod}); }
    friend DModInt operator+(const ll val, const DModInt& m) { return m + val; }
    friend DModInt operator-(const ll val, const DModInt& m) { return DModInt{val - static_cast<ll>(m.v), m.mod}; }
    friend DModInt operator*(const ll val, const DModInt& m) { return m * val; }
    friend DModInt operator/(const ll val, const DModInt& m) { return DModInt(val, m.mod) / m; }
    friend DModInt& operator+=(DModInt& m1, const DModInt& m2) { return assert(m1.mod == m2.mod), m1 = m1 + m2; }
    friend DModInt& operator-=(DModInt& m1, const DModInt& m2) { return assert(m1.mod == m2.mod), m1 = m1 - m2; }
    friend DModInt& operator*=(DModInt& m1, const DModInt& m2) { return assert(m1.mod == m2.mod), m1 = m1* m2; }
    friend DModInt& operator/=(DModInt& m1, const DModInt& m2) { return assert(m1.mod == m2.mod), m1 = m1 / m2; }
    friend DModInt& operator+=(DModInt& m, const ll val) { return m = m + val; }
    friend DModInt& operator-=(DModInt& m, const ll val) { return m = m - val; }
    friend DModInt& operator*=(DModInt& m, const ll val) { return m = m * val; }
    friend DModInt& operator/=(DModInt& m, const ll val) { return m = m / val; }
    friend DModInt operator^(const DModInt& m, const ll n) { return power(m, n); }
    friend DModInt& operator^=(DModInt& m, const ll n) { return m = m ^ n; }
    friend bool operator==(const DModInt& m1, const DModInt& m2) { return assert(m1.mod == m2.mod), m1.v == m2.v; }
    friend bool operator!=(const DModInt& m1, const DModInt& m2) { return assert(m1.mod == m2.mod), not(m1 == m2); }
    friend bool operator==(const ll val, const DModInt& m) { return m == val; }
    friend bool operator!=(const ll val, const DModInt& m) { return not(val == m); }
    friend bool operator==(const DModInt& m, const ll val) { return m.v == norm(static_cast<uint>(static_cast<ll>(m.mod) + val % static_cast<ll>(m.mod)), m.mod); }
    friend bool operator!=(const DModInt& m, const ll val) { return not(m == val); }
    friend std::istream& operator>>(std::istream& is, DModInt& m)
    {
        uint v;
        return is >> v, m = v, is;
    }
    friend std::ostream& operator<<(std::ostream& os, const DModInt& m) { return os << m.v; }
    static std::vector<DModInt> invVec(const uint mod, const std::size_t N)
    {
        std::vector<DModInt> ans(N + 1, 1);
        for (std::size_t i = 2; i <= N; i++) { ans[i] = -ans[mod % i] * (mod / i); }
        return ans;
    }
    uint operator()() const { return v; }
    const uint mod;
};
//!========================================================!//
//!  8888ba.88ba                 dP    dP            dP    !//
//!  88  '8b  '8b                88    88            88    !//
//!  88   88   88 .d8888b. .d888b88    88 88d888b. d8888P  !//
//!  88   88   88 88'  '88 88'  '88    88 88'  '88   88    !//
//!  88   88   88 88.  .88 88.  .88    88 88    88   88    !//
//!  dP   dP   dP '88888P' '88888P8    dP dP    dP   dP    !//
//!========================================================!//
template <uint mod>
class ModInt
{
private:
    uint v;
    static uint norm(const uint& x) { return x < mod ? x : x - mod; }
    static ModInt make(const uint& x)
    {
        ModInt m;
        return m.v = x, m;
    }
    static ModInt power(ModInt x, ll n)
    {
        ModInt ans = 1;
        for (; n; n >>= 1, x *= x) {
            if (n & 1) { ans *= x; }
        }
        return ans;
    }
    static ModInt inv(const ModInt& x) { return ModInt{inverse(static_cast<ll>(x.v), static_cast<ll>(mod))}; }

public:
    ModInt() : v{0} {}
    ModInt(const ll val) : v{norm(uint(val % static_cast<ll>(mod) + static_cast<ll>(mod)))} {}
    ModInt(const ModInt& n) : v{n()} {}
    explicit operator bool() const { return v != 0; }
    bool operator!() const { return not static_cast<bool>(*this); }
    ModInt& operator=(const ModInt& m) { return v = m(), (*this); }
    ModInt& operator=(const ll val) { return v = norm(uint(val % static_cast<ll>(mod) + static_cast<ll>(mod))), (*this); }
    friend ModInt operator+(const ModInt& m) { return m; }
    friend ModInt operator-(const ModInt& m) { return make(norm(mod - m.v)); }
    friend ModInt operator+(const ModInt& m1, const ModInt& m2) { return make(norm(m1.v + m2.v)); }
    friend ModInt operator-(const ModInt& m1, const ModInt& m2) { return make(norm(m1.v + mod - m2.v)); }
    friend ModInt operator*(const ModInt& m1, const ModInt& m2) { return make(static_cast<uint>(static_cast<ll>(m1.v) * static_cast<ll>(m2.v) % static_cast<ll>(mod))); }
    friend ModInt operator/(const ModInt& m1, const ModInt& m2) { return m1 * inv(m2.v); }
    friend ModInt operator+(const ModInt& m, const ll val) { return ModInt{static_cast<ll>(m.v) + val}; }
    friend ModInt operator-(const ModInt& m, const ll val) { return ModInt{static_cast<ll>(m.v) - val}; }
    friend ModInt operator*(const ModInt& m, const ll val) { return ModInt{static_cast<ll>(m.v) * (val % static_cast<ll>(mod))}; }
    friend ModInt operator/(const ModInt& m, const ll val) { return ModInt{static_cast<ll>(m.v) * inv(val)}; }
    friend ModInt operator+(const ll val, const ModInt& m) { return ModInt{static_cast<ll>(m.v) + val}; }
    friend ModInt operator-(const ll val, const ModInt& m) { return ModInt{-static_cast<ll>(m.v) + val}; }
    friend ModInt operator*(const ll val, const ModInt& m) { return ModInt{static_cast<ll>(m.v) * (val % static_cast<ll>(mod))}; }
    friend ModInt operator/(const ll val, const ModInt& m) { return ModInt{val * inv(static_cast<ll>(m.v))}; }
    friend ModInt& operator+=(ModInt& m1, const ModInt& m2) { return m1 = m1 + m2; }
    friend ModInt& operator-=(ModInt& m1, const ModInt& m2) { return m1 = m1 - m2; }
    friend ModInt& operator*=(ModInt& m1, const ModInt& m2) { return m1 = m1 * m2; }
    friend ModInt& operator/=(ModInt& m1, const ModInt& m2) { return m1 = m1 / m2; }
    friend ModInt& operator+=(ModInt& m, const ll val) { return m = m + val; }
    friend ModInt& operator-=(ModInt& m, const ll val) { return m = m - val; }
    friend ModInt& operator*=(ModInt& m, const ll val) { return m = m * val; }
    friend ModInt& operator/=(ModInt& m, const ll val) { return m = m / val; }
    friend ModInt operator^(const ModInt& m, const ll n) { return power(m.v, n); }
    friend ModInt& operator^=(ModInt& m, const ll n) { return m = m ^ n; }
    friend bool operator==(const ModInt& m1, const ModInt& m2) { return m1.v == m2.v; }
    friend bool operator!=(const ModInt& m1, const ModInt& m2) { return not(m1 == m2); }
    friend bool operator==(const ModInt& m, const ll val) { return m.v == norm(static_cast<uint>(static_cast<ll>(mod) + val % static_cast<ll>(mod))); }
    friend bool operator!=(const ModInt& m, const ll val) { return not(m == val); }
    friend bool operator==(const ll val, const ModInt& m) { return m.v == norm(static_cast<uint>(static_cast<ll>(mod) + val % static_cast<ll>(mod))); }
    friend bool operator!=(const ll val, const ModInt& m) { return not(m == val); }
    friend std::istream& operator>>(std::istream& is, ModInt& m)
    {
        uint v;
        return is >> v, m = v, is;
    }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& m) { return os << m(); }
    static std::vector<ModInt> invVec(const std::size_t N)
    {
        std::vector<ModInt> ans(N + 1, 1);
        for (std::size_t i = 2; i <= N; i++) { ans[i] = -ans[mod % i] * (mod / i); }
        return ans;
    }
    uint operator()() const { return v; }
};
//!=====================================!//
//!  8888ba.88ba           oo           !//
//!  88  '8b  '8b                       !//
//!  88   88   88 .d8888b. dP 88d888b.  !//
//!  88   88   88 88'  '88 88 88'  '88  !//
//!  88   88   88 88.  .88 88 88    88  !//
//!  dP   dP   dP '88888P8 dP dP    dP  !//
//!=====================================!//
int main()
{
    using mint = DModInt;
    const int N = read<int>(), K = read<int>(), M = read<uint>();
    std::uniform_int_distribution<int> dist{2, MOD - 2};
    std::vector<ModInt<MOD>> r1(2 * N + 3, 0), r2(2 * N + 3, 0);
    for (int i = 0; i <= 2 * N + 2; i++) { r1[i] = dist(mt), r2[i] = dist(mt); }
    using P = std::pair<int, int>;
    using T = std::pair<int, P>;
    std::map<T, int> memo;
    auto dp = [&, N, K, M](auto&& self, const int n, const int l, const int u, const std::deque<int>& us) -> mint {
        if (n == 2 * N + 2) { return u == N + 1 ? mint(1, M) : mint(0, M); }
        ModInt<MOD> hash1 = 1, hash2 = 1;
        for (const auto& d : us) { hash1 *= r1[d], hash2 *= r2[d]; }
        if (memo.find(T{l, {hash1(), hash2()}}) != memo.end()) { return mint(memo[T{l, {hash1(), hash2()}}], M); }
        mint ans(0, M);
        if (n % 2 == 0 and u == n / 2) {
            if (n > us.back() + K) {
                ans = mint(0, M);
            } else {
                auto v = us;
                v.pop_front(), v.push_back(n), ans = self(self, n + 1, l, u + 1, v);
            }
        } else {
            const int lm = std::min(us.front(), l) + K;
            if (n <= lm) {
                auto v = us;
                if (v.size() > 1) { v.pop_front(); }
                ans += self(self, n + 1, n, u, v);
            }
            if (u < N + 1 and n <= us.back() + K and n + 1 - l <= K) {
                auto v = us;
                v.push_back(n), ans += self(self, n + 1, l, u + 1, v);
            }
        }
        return memo[T{l, {hash1(), hash2()}}] = ans(), ans;
    };
    std::cout << dp(dp, 3, INF<int>, 2, {2}) << std::endl;
    return 0;
}

