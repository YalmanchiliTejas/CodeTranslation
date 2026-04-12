#include <bits/stdc++.h>
//!===========================================================!//
//!  dP     dP                          dP                    !//
//!  88     88                          88                    !//
//!  88aaaaa88a .d8888b. .d8888b. .d888b88 .d8888b. 88d888b.  !//
//!  88     88  88ooood8 88'  '88 88'  '88 88ooood8 88'  '88  !//
//!  88     88  88.  ... 88.  .88 88.  .88 88.  ... 88        !//
//!  dP     dP  '88888P' '88888P8 '88888P8 '88888P' dP        !//
//!===========================================================!//
using ld = long double;
using ll = long long;
std::mt19937 mt{std::random_device{}()};
template <typename F>
constexpr F PI() { return 3.1415926535897932385; }
template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename T, typename A>
std::ostream& operator<<(std::ostream& os, const std::deque<T, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename K, typename T, typename C, typename A>
std::ostream& operator<<(std::ostream& os, const std::multimap<K, T, C, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << "<" << e.first << ": " << e.second << ">,"; }
    return (os << "]" << std::endl);
}
template <typename T, typename C, typename A>
std::ostream& operator<<(std::ostream& os, const std::multiset<T, C, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename K, typename T, typename C, typename A>
std::ostream& operator<<(std::ostream& os, const std::map<K, T, C, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << "<" << e.first << ": " << e.second << ">,"; }
    return (os << "]" << std::endl);
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& v) { return (os << "<" << v.first << "," << v.second << ">"); }
template <typename T1, typename T2, typename T3>
std::ostream& operator<<(std::ostream& os, const std::priority_queue<T1, T2, T3>& v)
{
    auto q = v;
    os << "[";
    while (not q.empty()) { os << q.top() << ",", q.pop(); }
    return os << "]\n";
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::queue<T1>& v)
{
    auto q = v;
    os << "[";
    while (not q.empty()) { os << q.front() << ",", q.pop(); }
    return os << "]\n";
}
template <typename T, typename C, typename A>
std::ostream& operator<<(std::ostream& os, const std::set<T, C, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::stack<T1>& v)
{
    auto q = v;
    os << "[";
    while (not q.empty()) { os << q.top() << ",", q.pop(); }
    return os << "]\n";
}
template <typename K, typename T, typename H, typename P, typename A>
std::ostream& operator<<(std::ostream& os, const std::unordered_multimap<K, T, H, P, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << "<" << e.first << ": " << e.second << ">,"; }
    return (os << "]" << std::endl);
}
template <typename T, typename H, typename P, typename A>
std::ostream& operator<<(std::ostream& os, const std::unordered_multiset<T, H, P, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename K, typename T, typename H, typename P, typename A>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, T, H, P, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << "<" << e.first << ": " << e.second << ">,"; }
    return (os << "]" << std::endl);
}
template <typename T, typename H, typename P, typename A>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T, H, P, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
template <typename T, typename A>
std::ostream& operator<<(std::ostream& os, const std::vector<T, A>& v)
{
    os << "[";
    for (const auto& e : v) { os << e << ","; }
    return (os << "]" << std::endl);
}
#define SHOW(...) (std::cerr << "(" << #__VA_ARGS__ << ") = ("), HogeHogeSansuu(__VA_ARGS__), std::cerr << ")" << std::endl;
void HogeHogeSansuu() { ; }
template <typename T>
void HogeHogeSansuu(const T x) { std::cerr << x; }
template <typename T, typename... Args>
void HogeHogeSansuu(const T x, Args... args) { (std::cerr << x << ", "), HogeHogeSansuu(args...); }
template <typename T>
std::vector<T> Vec(const std::size_t n, T v) { return std::vector<T>(n, v); }
template <class... Args>
auto Vec(const std::size_t n, Args... args) { return std::vector<decltype(Vec(args...))>(n, Vec(args...)); }
template <typename T>
constexpr T PopCount(T v) { return v = (v & 0x5555555555555555ULL) + (v >> 1 & 0x5555555555555555ULL), v = (v & 0x3333333333333333ULL) + (v >> 2 & 0x3333333333333333ULL), v = (v + (v >> 4)) & 0x0F0F0F0F0F0F0F0FULL, static_cast<T>(v * 0x0101010101010101ULL >> 56 & 0x7f); }
template <typename T>
constexpr T log2p1(T v) { return v |= (v >> 1), v |= (v >> 2), v |= (v >> 4), v |= (v >> 8), v |= (v >> 16), v |= (v >> 32), PopCount(v); }
template <typename T>
constexpr bool ispow2(const T v) { return (v << 1) == (T(1) << (log2p1(v))); }
template <typename T>
constexpr T ceil2(const T v) { return ispow2(v) ? v : T(1) << log2p1(v); }
template <typename T>
constexpr T floor2(const T v) { return v == 0 ? T(0) : ispow2(v) ? v : T(1) << (log2p1(v) - 1); }
//!========================================================!//
//!  8888ba.88ba                 dP    dP            dP    !//
//!  88  '8b  '8b                88    88            88    !//
//!  88   88   88 .d8888b. .d888b88    88 88d888b. d8888P  !//
//!  88   88   88 88'  '88 88'  '88    88 88'  '88   88    !//
//!  88   88   88 88.  .88 88.  .88    88 88    88   88    !//
//!  dP   dP   dP '88888P' '88888P8    dP dP    dP   dP    !//
//!========================================================!//
template <typename T, T mod>
class ModInt
{
private:
    T value;
    static T pow(const T p, const T n) { return p < 0 ? pow(mod + p, n) : n == 0 ? 1 : n % 2 == 1 ? pow(p, n - 1) * p % mod : pow(p * p % mod, n / 2); }
    static T inv(const T p) { return pow(p, mod - 2); }

public:
    ModInt() : value{0} {}
    ModInt(const T val) : value{((val % mod) + mod) % mod} {}
    ModInt(const ModInt<T, mod>& n) : value{n()} {}
    ModInt<T, mod>& operator=(const ModInt<T, mod>& n) { return value = n(), (*this); }
    ModInt<T, mod>& operator=(const T v) { return value = (mod + v % mod) % mod, (*this); }
    ModInt<T, mod> operator+() const { return *this; }
    ModInt<T, mod> operator-() const { return ModInt{mod - value}; }
    ModInt<T, mod> operator+(const ModInt<T, mod>& val) const { return ModInt{value + val()}; }
    ModInt<T, mod> operator-(const ModInt<T, mod>& val) const { return ModInt{value - val() + mod}; }
    ModInt<T, mod> operator*(const ModInt<T, mod>& val) const { return ModInt{value * val()}; }
    ModInt<T, mod> operator/(const ModInt<T, mod>& val) const { return ModInt{value * inv(val())}; }
    ModInt<T, mod>& operator+=(const ModInt<T, mod>& val) { return (((value += val()) %= mod) += mod) %= mod, (*this); }
    ModInt<T, mod>& operator-=(const ModInt<T, mod>& val) { return (((value -= val()) %= mod) += mod) %= mod, (*this); }
    ModInt<T, mod>& operator*=(const ModInt<T, mod>& val) { return (((value *= val()) %= mod) += mod) %= mod, (*this); }
    ModInt<T, mod>& operator/=(const ModInt<T, mod>& val) { return (((value *= inv(val())) %= mod) += mod) %= mod, (*this); }
    ModInt<T, mod> operator+(const T val) const { return ModInt{value + val}; }
    ModInt<T, mod> operator-(const T val) const { return ModInt{value - val}; }
    ModInt<T, mod> operator*(const T val) const { return ModInt{value * val}; }
    ModInt<T, mod> operator/(const T val) const { return ModInt{value * inv(val)}; }
    ModInt<T, mod>& operator+=(const T val) { return (((value += val) %= mod) += mod) %= mod, (*this); }
    ModInt<T, mod>& operator-=(const T val) { return (((value -= val) %= mod) += mod) %= mod, (*this); }
    ModInt<T, mod>& operator*=(const T val) { return (((value *= val) %= mod) += mod) %= mod, (*this); }
    ModInt<T, mod>& operator/=(const T val) { return (((value *= inv(val)) %= mod) += mod) %= mod, (*this); }
    bool operator==(const ModInt<T, mod>& val) const { return value == val.value; }
    bool operator!=(const ModInt<T, mod>& val) const { return not(*this == val); }
    bool operator==(const T val) const { return value == (mod + val % mod) % mod; }
    bool operator!=(const T val) const { return not(*this == val); }
    T operator()() const { return value; }
};
template <typename T, T mod>
inline ModInt<T, mod> operator+(const T val, const ModInt<T, mod>& n) { return ModInt<T, mod>{n() + val}; }
template <typename T, T mod>
inline ModInt<T, mod> operator-(const T val, const ModInt<T, mod>& n) { return ModInt<T, mod>{-n() + val}; }
template <typename T, T mod>
inline ModInt<T, mod> operator*(const T val, const ModInt<T, mod>& n) { return ModInt<T, mod>{n() * val}; }
template <typename T, T mod>
inline ModInt<T, mod> operator/(const T val, const ModInt<T, mod>& n) { return ModInt<T, mod>(val) / n; }
template <typename T, T mod>
inline bool operator==(const T val, const ModInt<T, mod>& n) { return n == val; }
template <typename T, T mod>
inline bool operator!=(const T val, const ModInt<T, mod>& n) { return not(val == n); }
template <typename T, T mod>
inline std::istream& operator>>(std::istream& is, ModInt<T, mod>& n)
{
    T v;
    return is >> v, n = v, is;
}
template <typename T, T mod>
std::ostream& operator<<(std::ostream& os, const ModInt<T, mod>& n) { return (os << n()); }
template <int mod>
using mint = ModInt<int, mod>;
template <ll mod>
using mll = ModInt<ll, mod>;
template <typename T>
constexpr T INF() { return std::numeric_limits<T>::max() / 4; }
//!============================================!//
//!    8888ba.88ba             oo              !//
//!    88  '8b  '8b                            !//
//!    88   88   88  .d8888b.  dP  88d888b.    !//
//!    88   88   88  88'  '88  88  88'  '88    !//
//!    88   88   88  88.  .88  88  88    88    !//
//!    dP   dP   dP  '88888P8  dP  dP    dP    !//
//!============================================!//
constexpr ll MOD = 1000000007;
int main()
{
    ll A, B, X;
    std::cin >> A >> B >> X;
    if (X < A) { return std::cout << X % MOD << std::endl, 0; }
    ll N = std::max(0LL, (X - B) / (A - B));
    const ll res = X - (A - B) * N;
    assert(res >= 0 and res < A);
    N %= MOD, B %= MOD, X %= MOD;
    const ll ans = (X + (N * B % MOD)) % MOD;
    std::cout << ans << std::endl;
    return 0;
}

