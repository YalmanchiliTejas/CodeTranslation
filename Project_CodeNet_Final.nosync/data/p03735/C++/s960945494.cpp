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
using ld = long double;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <typename T>
constexpr T INF = std::numeric_limits<T>::max() / 4;
constexpr unsigned int MOD = 1000000007;
template <typename F>
constexpr F PI = static_cast<F>(3.1415926535897932385);
std::mt19937 mt{std::random_device{}()};
template <typename T>
bool chmin(T& a, const T& b) { return a = std::min(a, b), a == b; }
template <typename T>
bool chmax(T& a, const T& b) { return a = std::max(a, b), a == b; }
template <typename T, typename F>
void For(const T s, const T t, const F f)
{
    for (T i = s; i != t; i += T(s < t ? 1 : -1)) { f(i); }
}
template <typename T, typename F>
void Rep(const T N, const F f) { For<T, F>(0, N, f); }
template <typename T, typename F>
void RRep(const T N, const F f) { For<T, F>(N - 1, -1, f); }
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
//!============================================!//
//!    8888ba.88ba             oo              !//
//!    88  '8b  '8b                            !//
//!    88   88   88  .d8888b.  dP  88d888b.    !//
//!    88   88   88  88'  '88  88  88'  '88    !//
//!    88   88   88  88.  .88  88  88    88    !//
//!    dP   dP   dP  '88888P8  dP  dP    dP    !//
//!============================================!//
int main()
{
    int N;
    std::cin >> N;
    std::vector<ll> x(N), y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> x[i] >> y[i];
        if (x[i] < y[i]) { std::swap(x[i], y[i]); }
    }
    const int Mind = std::max_element(x.begin(), x.end()) - x.begin();
    const int mind = std::min_element(y.begin(), y.end()) - y.begin();
    ll ans = INF<ll>;
    const ll R = x[Mind], b = y[mind];
    ll r = R, B = b;
    for (int i = 0; i < N; i++) {
        if (i != Mind) { chmin(r, x[i]); }
        if (i != mind) { chmax(B, y[i]); }
    }
    chmin(ans, (R - r) * (B - b));
    if (Mind != mind) {
        const ll R_r = x[Mind] - y[mind];
        std::vector<int> ind;
        std::multiset<ll> B;
        B.insert(x[mind]), B.insert(y[Mind]);
        for (int i = 0; i < N; i++) {
            if (i == mind or i == Mind) { continue; }
            ind.push_back(i), B.insert(y[i]);
        }
        chmin(ans, R_r * (*B.rbegin() - *B.begin()));
        std::sort(ind.begin(), ind.end(), [&](const int i, const int j) { return y[i] < y[j]; });
        for (int i = 0; i < ind.size(); i++) { B.erase(B.find(y[ind[i]])), B.insert(x[ind[i]]), chmin(ans, R_r * (*B.rbegin() - *B.begin())); }
    }
    std::cout << ans << std::endl;
    return 0;
}
