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
//!============================================================================!//
//!  8888ba.88ba                 dP     a88888b.                     dP        !//
//!  88  '8b  '8b                88    d8'   '88                     88        !//
//!  88   88   88 .d8888b. .d888b88    88        .d8888b. 88d8b.d8b. 88d888b.  !//
//!  88   88   88 88'  '88 88'  '88    88        88'  '88 88''88''88 88'  '88  !//
//!  88   88   88 88.  .88 88.  .88    Y8.   .88 88.  .88 88  88  88 88.  .88  !//
//!  dP   dP   dP '88888P' '88888P8     Y88888P' '88888P' dP  dP  dP 88Y8888'  !//
//!============================================================================!//
template <uint mod>
class ModComb
{
public:
    ModComb(const std::size_t N) : f(N + 1, ModInt<mod>(1)), in(N + 1, ModInt<mod>(1)), invf(N + 1, ModInt<mod>(1))
    {
        for (uint i = 2; i <= N; i++) { f[i] = f[i - 1] * i, in[i] = -in[mod % i] * (mod / i), invf[i] = invf[i - 1] * in[i]; }
    }
    ModInt<mod> fact(const std::size_t N) const { return f[N]; }
    ModInt<mod> inv(const std::size_t N) const { return in[N]; }
    ModInt<mod> invFact(const std::size_t N) const { return invf[N]; }
    ModInt<mod> perm(const std::size_t N, const std::size_t K) const { return N > f.size() or K > N ? ModInt<mod>(0) : f[N] * invf[N - K]; }
    ModInt<mod> comb(const std::size_t N, const std::size_t K) const { return N > f.size() or K > N ? ModInt<mod>(0) : f[N] * invf[K] * invf[N - K]; }

private:
    std::vector<ModInt<mod>> f, in, invf;
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
    const int N = read<int>(), M = read<int>(), K = read<int>();
    ModComb<MOD> mod(N * M);
    std::cout << mod.comb(K, 2) * mod.comb(N * M, K) * (N + M) / 3 << std::endl;
    return 0;
}
