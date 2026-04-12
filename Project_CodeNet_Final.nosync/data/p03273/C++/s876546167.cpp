#include <bits/stdc++.h>
// created [2020/02/02] 22:07:29
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsign-conversion"

using i32   = int32_t;
using i64   = int64_t;
using u32   = uint32_t;
using u64   = uint64_t;
using uint  = unsigned int;
using usize = std::size_t;
using ll    = long long;
using ull   = unsigned long long;
using ld    = long double;
template<typename T, usize n>
using arr = T (&)[n];
template<typename T, usize n>
using c_arr = const T (&)[n];
template<typename T>
using max_heap = std::priority_queue<T>;
template<typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T> constexpr T popcount(const T u) { return u ? static_cast<T>(__builtin_popcountll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T log2p1(const T u) { return u ? static_cast<T>(64 - __builtin_clzll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T msbp1(const T u) { return log2p1(u); }
template<typename T> constexpr T lsbp1(const T u) { return __builtin_ffsll(u); }
template<typename T> constexpr T clog(const T u) { return u ? log2p1(u - 1) : static_cast<T>(u); }
template<typename T> constexpr bool ispow2(const T u) { return u and (static_cast<u64>(u) & static_cast<u64>(u - 1)) == 0; }
template<typename T> constexpr T ceil2(const T u) { return static_cast<T>(1) << clog(u); }
template<typename T> constexpr T floor2(const T u) { return u == 0 ? static_cast<T>(0) : static_cast<T>(1) << (log2p1(u) - 1); }
template<typename T> constexpr bool btest(const T mask, const usize ind) { return static_cast<bool>((static_cast<u64>(mask) >> ind) & static_cast<u64>(1)); }
template<typename T> void bset(T& mask, const usize ind) { mask |= (static_cast<T>(1) << ind); }
template<typename T> void breset(T& mask, const usize ind) { mask &= ~(static_cast<T>(1) << ind); }
template<typename T> void bflip(T& mask, const usize ind) { mask ^= (static_cast<T>(1) << ind); }
template<typename T> void bset(T& mask, const usize ind, const bool b) { (b ? bset(mask, ind) : breset(mask, ind)); }
template<typename T> constexpr T bcut(const T mask, const usize ind) { return ind == 0 ? static_cast<T>(0) : static_cast<T>((static_cast<u64>(mask) << (64 - ind)) >> (64 - ind)); }
template<typename T> bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template<typename T> bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }
constexpr unsigned int mod                  = 1000000007;
template<typename T> constexpr T inf_v      = std::numeric_limits<T>::max() / 4;
template<typename Real> constexpr Real pi_v = Real{3.141592653589793238462643383279502884};
auto mfp = [](auto&& f) { return [=](auto&&... args) { return f(f, std::forward<decltype(args)>(args)...); }; };

template<typename T>
T in()
{
    T v;
    return std::cin >> v, v;
}
template<typename T, typename Uint, usize n, usize i>
T in_v(typename std::enable_if<(i == n), c_arr<Uint, n>>::type) { return in<T>(); }
template<typename T, typename Uint, usize n, usize i>
auto in_v(typename std::enable_if<(i < n), c_arr<Uint, n>>::type& szs)
{
    const usize s = (usize)szs[i];
    std::vector<decltype(in_v<T, Uint, n, i + 1>(szs))> ans(s);
    for (usize j = 0; j < s; j++) { ans[j] = in_v<T, Uint, n, i + 1>(szs); }
    return ans;
}
template<typename T, typename Uint, usize n>
auto in_v(c_arr<Uint, n> szs) { return in_v<T, Uint, n, 0>(szs); }
template<typename... Types>
auto in_t() { return std::tuple<std::decay_t<Types>...>{in<Types>()...}; }
struct io_init
{
    io_init()
    {
        std::cin.tie(nullptr), std::ios::sync_with_stdio(false);
        std::cout << std::fixed << std::setprecision(20);
    }
    void clear()
    {
        std::cin.tie(), std::ios::sync_with_stdio(true);
    }
} io_setting;

int out() { return 0; }
template<typename T>
int out(const T& v) { return std::cout << v, 0; }
template<typename T>
int out(const std::vector<T>& v)
{
    for (usize i = 0; i < v.size(); i++) {
        if (i > 0) { std::cout << ' '; }
        out(v[i]);
    }
    return 0;
}
template<typename T1, typename T2>
int out(const std::pair<T1, T2>& v) { return out(v.first), std::cout << ' ', out(v.second), 0; }
template<typename T, typename... Args>
int out(const T& v, const Args... args) { return out(v), std::cout << ' ', out(args...), 0; }
template<typename... Args>
int outln(const Args... args) { return out(args...), std::cout << '\n', 0; }
template<typename... Args>
int outel(const Args... args) { return out(args...), std::cout << std::endl, 0; }
#    define SHOW(...) static_cast<void>(0)
constexpr ull TEN(const usize n) { return n == 0 ? 1ULL : TEN(n - 1) * 10ULL; }

template<typename T, typename Uint, usize n, usize i>
auto make_v(typename std::enable_if<(i == n), c_arr<Uint, n>>::type, const T& v = T{}) { return v; }
template<typename T, typename Uint, usize n, usize i>
auto make_v(typename std::enable_if<(i < n), c_arr<Uint, n>>::type szs, const T& v = T{})
{
    const usize s = (usize)szs[i];
    return std::vector<decltype(make_v<T, Uint, n, i + 1>(szs, v))>(s, make_v<T, Uint, n, i + 1>(szs, v));
}
template<typename T, typename Uint, usize n>
auto make_v(c_arr<Uint, n> szs, const T& t = T{}) { return make_v<T, Uint, n, 0>(szs, t); }
int main()
{
    const auto H = in<int>(), W = in<int>();
    const auto ass = in_v<std::string>({H});
    std::vector<bool> rok(H, true), cok(W, true);
    for (int i = 0; i < H; i++) {
        bool all = true;
        for (int j = 0; j < W; j++) {
            if (ass[i][j] == '#') { all = false; }
        }
        rok[i] = not all;
    }
    for (int j = 0; j < W; j++) {
        bool all = true;
        for (int i = 0; i < H; i++) {
            if (ass[i][j] == '#') { all = false; }
        }
        cok[j] = not all;
    }
    for (int i = 0; i < H; i++) {
        if (not rok[i]) { continue; }
        std::string ans;
        for (int j = 0; j < W; j++) {
            if (cok[j]) { ans.push_back(ass[i][j]); }
        }
        outln(ans);
    }
    return 0;
}
