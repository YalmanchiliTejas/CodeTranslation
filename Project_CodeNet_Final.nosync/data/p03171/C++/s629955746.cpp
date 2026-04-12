// Grzegorz Suwaj
// TEMPLATE
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define FE(i, a, b) for (size_t i = a; i < b; i++)
#define FI(i, a, b) for (size_t i = a; i <= b; i++)
#define RFE(i, a, b) for (int i = a; i > b; i--)
#define RFI(i, a, b) for (int i = a; i >= b; i--)
#define FEA(i, c) for (auto&& i : c)
#define FEAC(i, c) for (typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define RANGE(c) (c).begin(), (c).end()
#define mp std::make_pair
#define fi first
#define se second
#define th third
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define bgn begin
#define ers erase
#define ins insert
#define putcxi putchar_unlocked
#define getcxi getchar_unlocked
#define y1 _y1
#define y0 _y0
#define esle else
#define szie size
#define isze size
#define boid void

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = std::pair<int, int>;
using pill = std::pair<int, ll>;
using plli = std::pair<ll, int>;
using pll = std::pair<ll, ll>;
using pld = std::pair<ld, ld>;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using vld = std::vector<ld>;
using vpi = std::vector<pi>;
using vpill = std::vector<pill>;
using vplii = std::vector<plli>;
using vpll = std::vector<pll>;
using vpld = std::vector<pld>;
using vvi = std::vector<vi>;
using vvll = std::vector<vll>;
using vvvi = std::vector<vvi>;
using vvpi = std::vector<vpi>;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using si = std::set<int>;
using sll = std::set<ll>;
using sull = std::set<ull>;
using spi = std::set<pi>;

const int MAX_INT = std::numeric_limits<int>::max();
const int MXI = 1e9;
const ll MAX_LL = std::numeric_limits<long long>::max();
const ull MAX_ULL = std::numeric_limits<unsigned long long>::max();
const ll MXLL = 1e18;

template <typename T1, typename T2, typename T3>
class triple {
public:
    T1 first;
    T2 second;
    T3 third;

    constexpr triple() {}
    constexpr triple(const T1& first, const T2& second, const T3& third)
        : first(first)
        , second(second)
        , third(third)
    {
    }
    triple(const triple& t) = default;
    triple(triple&& t) = default;

    triple& operator=(const triple& t)
    {
        first = t.first;
        second = t.second;
        third = t.third;
        return *this;
    }
    bool operator==(const triple& t) const
    {
        return first == t.first && second == t.second && third == t.third;
    }
    bool operator!=(const triple& t) const
    {
        return !(*this == t);
    }
    bool operator<(const triple& t) const
    {
        if (first == t.first) {
            if (second == t.second)
                return third < t.third;
            return second < t.second;
        }
        return first < t.first;
    }
    bool operator>(const triple& t) const
    {
        if (first == t.first) {
            if (second == t.second)
                return third > t.third;
            return second > t.second;
        }
        return first > t.first;
    }
    bool operator<=(const triple& t) const
    {
        return !(*this > t);
    }
    bool operator>=(const triple& t) const
    {
        return !(*this < t);
    }

    friend std::ostream& operator<<(std::ostream& os, const triple& t)
    {
        return os << t.fi << ' ' << t.se << ' ' << t.th;
    }
};

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p)
{
    return os << p.fi << ' ' << p.se;
}
template <typename... T, template <typename...> class Container, typename std::enable_if<!std::is_same<Container<T...>, std::string>::value>::type* = nullptr>
std::ostream& operator<<(std::ostream& os, const Container<T...>& c)
{
    for (auto&& x : c)
        os << x << ' ';
    // os << '\n';
    return os;
}
template <typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
inline void getcx(T& var)
{
    var = 0;
    register char c = getchar();
    register T sgn = 1;
    while (c < '0' || c > '9') {
        if (c == '-')
            sgn *= -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        var = (var << 3) + (var << 1) + c - '0';
        c = getchar();
    }
    var *= sgn;
}
template <typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
inline void putcx(T var)
{
    if (var == 0) {
        putchar('0');
        putchar(' ');
        return;
    }
    register T rev = 0;
    register int zeros = 0;
    while (var % 10 == 0) {
        zeros++;
        var /= 10;
    }
    while (var) {
        rev = (rev << 3) + (rev << 1) + (var % 10);
        var /= 10;
    }
    while (rev) {
        putchar(rev % 10 + '0');
        rev /= 10;
    }
    while (zeros--)
        putchar('0');
}
// KOD CODE PROGRAM SOURCE
int n;
vll arr;
vvll dp;

int main()
{
#ifndef DEBUG
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif

    std::cin >> n;
    arr = vll(n + 1);
    dp = vvll(n + 1, vll(n + 1));
    FI (i, 1, n)
        std::cin >> arr[i];
    FI (i, 1, n)
        dp[i][i] = arr[i];
    FI (i, 2, n)
        for (size_t j = 1; j + i - 1 <= n; j++)
            dp[j][j + i - 1] = (i & 1 ? std::max(dp[j][j + i - 2] + arr[j + i - 1], dp[j + 1][j + i - 1] + arr[j]) : std::min(dp[j][j + i - 2] - arr[j + i - 1], dp[j + 1][j + i - 1] - arr[j]));

    std::cout << (n & 1 ? dp[1][n] : -dp[1][n]);
    return 0;
}