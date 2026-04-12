#include <bits/stdc++.h>

using ll                            = long long;
using uint                          = unsigned int;
using ull                           = unsigned long long;
using ld                            = long double;
template<typename T> using max_heap = std::priority_queue<T>;
template<typename T> using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
constexpr int popcount(const ull v) { return v ? __builtin_popcountll(v) : 0; }
constexpr int log2p1(const ull v) { return v ? 64 - __builtin_clzll(v) : 0; }
constexpr int lsbp1(const ull v) { return __builtin_ffsll(v); }
constexpr int clog(const ull v) { return v ? log2p1(v - 1) : 0; }
constexpr ull ceil2(const ull v) { return 1ULL << clog(v); }
constexpr ull floor2(const ull v) { return v ? (1ULL << (log2p1(v) - 1)) : 0ULL; }
constexpr bool btest(const ull mask, const int ind) { return (mask >> ind) & 1ULL; }
template<typename T> void bset(T& mask, const int ind) { mask |= ((T)1 << ind); }
template<typename T> void breset(T& mask, const int ind) { mask &= ~((T)1 << ind); }
template<typename T> void bflip(T& mask, const int ind) { mask ^= ((T)1 << ind); }
template<typename T> void bset(T& mask, const int ind, const bool b) { (b ? bset(mask, ind) : breset(mask, ind)); }
template<typename T> bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template<typename T> bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }
template<typename T> constexpr T inf_v      = std::numeric_limits<T>::max() / 4;
template<typename Real> constexpr Real pi_v = Real{3.141592653589793238462643383279502884};
template<typename T> constexpr T TEN(const int n) { return n == 0 ? T{1} : TEN<T>(n - 1) * T{10}; }
template<typename F> struct fix : F
{
    fix(F&& f) : F{std::forward<F>(f)} {}
    template<typename... Args> auto operator()(Args&&... args) const { return F::operator()(*this, std::forward<Args>(args)...); }
};
template<typename T, int n, int i = 0>
auto nd_array(int const (&szs)[n], const T x = T{})
{
    if constexpr (i == n) {
        return x;
    } else {
        return std::vector(szs[i], nd_array<T, n, i + 1>(szs, x));
    }
}
class printer
{
public:
    printer(std::ostream& os_ = std::cout) : os{os_} { os << std::fixed << std::setprecision(15); }
    template<typename T> int operator()(const T& v) { return os << v, 0; }
    template<typename T> int operator()(const std::vector<T>& vs)
    {
        for (int i = 0; i < (int)vs.size(); i++) { os << (i ? " " : ""), this->operator()(vs[i]); }
        return 0;
    }
    template<typename T> int operator()(const std::vector<std::vector<T>>& vss)
    {
        for (int i = 0; i < (int)vss.size(); i++) { os << (0 <= i or i + 1 < (int)vss.size() ? "\n" : ""), this->operator()(vss[i]); }
        return 0;
    }
    template<typename T, typename... Args> int operator()(const T& v, const Args&... args) { return this->operator()(v), os << ' ', this->operator()(args...), 0; }
    template<typename... Args> int ln(const Args&... args) { return this->operator()(args...), os << '\n', 0; }
    template<typename... Args> int el(const Args&... args) { return this->operator()(args...), os << std::endl, 0; }
    template<typename... Args> int fmt(const std::string& s, const Args&... args) { return rec(s, 0, args...); }

private:
    int rec(const std::string& s, int index) { return os << s.substr(index, s.size()), 0; }
    template<typename T, typename... Args> int rec(const std::string& s, int index, const T& v, const Args&... args) { return index == s.size() ? 0 : s[index] == '%' ? (this->operator()(v), rec(s, index + 1, args...)) : (os << s[index], rec(s, index + 1, v, args...)); }
    std::ostream& os;
};
printer out;
class scanner
{
public:
    scanner(std::istream& is_ = std::cin) : is{is_} { is.tie(nullptr), std::ios::sync_with_stdio(false); }
    template<typename T> T val()
    {
        T v;
        return is >> v, v;
    }
    template<typename T> T val(const T offset) { return val<T>() - offset; }
    template<typename T> std::vector<T> vec(const int n)
    {
        std::vector<T> vs(n);
        for (auto& v : vs) { v = val<T>(); }
        return vs;
    }
    template<typename T> std::vector<T> vec(const int n, const T offset)
    {
        std::vector<T> vs(n);
        for (auto& v : vs) { v = val<T>(offset); }
        return vs;
    }
    template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1)
    {
        std::vector<std::vector<T>> vss(n0);
        for (auto& vs : vss) { vs = vec<T>(n1); }
        return vss;
    }
    template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1, const T offset)
    {
        std::vector<std::vector<T>> vss(n0);
        for (auto& vs : vss) { vs = vec<T>(n1, offset); }
        return vss;
    }
    template<typename... Args> auto tup() { return std::tuple<std::decay_t<Args>...>{val<Args>()...}; }
    template<typename... Args> auto tup(const Args&... offsets) { return std::tuple<std::decay_t<Args>...>{val<Args>(offsets)...}; }

private:
    std::istream& is;
};
scanner in;
#    define SHOW(...) static_cast<void>(0)
int main()
{
    const auto N = in.val<int>();
    auto as      = in.vec<int>(3 * N, 1);
    as.push_back(N), as.push_back(N);
    auto dp  = nd_array({N + 1, N + 1}, -inf_v<int>);
    auto mdp = nd_array({N + 1}, -inf_v<int>);
    int max  = 0;

    dp[as[0]][as[1]] = dp[as[1]][as[0]] = 0;
    mdp[as[0]] = mdp[as[1]] = 0;
    SHOW(dp);
    SHOW(mdp);
    int offset = 0;
    for (int i = 0; i < 3 * N; i += 3) {
        int pqr[] = {as[i + 2], as[i + 3], as[i + 4]};
        std::sort(pqr, pqr + 3);
        const auto [p, q, r] = pqr;
        SHOW(p, q, r);

        if (p == r) {
            offset++;
            continue;
        }

        using pii = std::pair<int, int>;
        std::map<pii, int> changes;
        auto change = [&](const int a, const int b, const int v) {
            if (changes.count(std::minmax(a, b))) {
                chmax(changes[std::minmax(a, b)], v);
            } else {
                changes[std::minmax(a, b)] = v;
            }
        };
        if (p == q) {
            for (int a = 0; a <= N; a++) { change(a, r, dp[a][p] + 1); }
        }
        if (q == r) {
            for (int a = 0; a <= N; a++) { change(a, p, dp[a][q] + 1); }
        }

        change(q, r, dp[p][p] + 1);
        change(r, p, dp[q][q] + 1);
        change(p, q, dp[r][r] + 1);

        change(p, q, max);
        change(r, p, max);
        change(q, r, max);

        for (int a = 0; a <= N; a++) {
            change(a, p, mdp[a]);
            change(a, q, mdp[a]);
            change(a, r, mdp[a]);
        }

        for (const auto& [pos, v] : changes) {
            const auto [a, b] = pos;
            chmax(dp[a][b], v), chmax(dp[b][a], v);
            chmax(mdp[a], dp[a][b]), chmax(mdp[b], dp[b][a]);
            chmax(max, dp[a][b]);
        }
    }
    int ans = 0;
    for (int a = 0; a <= N; a++) {
        for (int b = 0; b <= N; b++) { chmax(ans, dp[a][b]); }
    }
    ans += offset;
    out.ln(ans);
    return 0;
}
