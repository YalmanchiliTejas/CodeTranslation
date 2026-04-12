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

int main()
{
    int N;
    std::cin >> N;
    std::vector<bool> v(N);
    for (int i = 0; i < N; i++) {
        char c;
        std::cin >> c, v[i] = c == 'T';
    }
    const bool ans = std::accumulate(v.begin() + 1, v.end(), v[0], [](const bool i, const bool j) { return (not i) or j; });
    std::cout << (ans ? 'T' : 'F') << std::endl;
    return 0;
}

