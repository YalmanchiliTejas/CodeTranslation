/**
 * ちゃんと左/上方向も確認すること。例えば:
 *
 *    ###
 *      #
 *     ####
 *
 * 右下隅からさらに動いた可能性があるので、右下隅で停止するところまで
 * 確認しなければならない
 */

// #include {{{
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#ifdef DEBUG
#include <fmt/format.h>
#endif

using namespace std;
// }}}

// type {{{
using  s8 =   int8_t;
using  u8 =  uint8_t;
using s16 =  int16_t;
using u16 = uint16_t;
using s32 =  int32_t;
using u32 = uint32_t;
using s64 =  int64_t;
using u64 = uint64_t;

template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;
template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
// }}}

// 適宜調整
//#define int s64
constexpr bool IOS_SYNCSTDIO = false;
constexpr int  IOS_PREC      = 10;

constexpr int    INF = numeric_limits<int>::max();
constexpr double EPS = 1e-9;

// util {{{
template<typename T>
constexpr bool is_odd(T x)
{
    return x % 2 == 1;
}

template<typename T>
constexpr bool is_even(T x)
{
    return x % 2 == 0;
}

template<typename T>
constexpr int sgn(T x)
{
    return (x > T(0)) - (x < T(0));
}

template<typename T>
constexpr typename enable_if<is_signed<T>::value,T>::type modulo(T a, T b)
{
    assert(b > 0);
    T r = a % b;
    return r >= 0 ? r : r+b;
}

template<typename T>
constexpr T clamp(T x, T lo, T hi)
{
    assert(lo <= hi);
    if(x < lo)
        return lo;
    else if(x > hi)
        return hi;
    else
        return x;
}

int sqrti(int x)
{
    assert(x >= 0);
    return static_cast<int>(sqrt(x));
}

s64 sqrtl(s64 x)
{
    assert(x >= 0);
    return static_cast<s64>(sqrtl(x));
}

template<typename T>
bool max_update(T& xmax, const T& x)
{
    if(x > xmax) {
        xmax = x;
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
bool min_update(T& xmin, const T& x)
{
    if(x < xmin) {
        xmin = x;
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
constexpr int SIZE(const T& c)
{
    return static_cast<int>(c.size());
}

template<typename T, size_t N>
constexpr int SIZE(const T (&)[N])
{
    return static_cast<int>(N);
}

ostream& FPRINT(ostream& out) { return out; }

template<typename T, typename... TS>
ostream& FPRINT(ostream& out, const T& x, const TS& ...args)
{
    out << x;
    if(sizeof...(args))
        out << ' ';
    return FPRINT(out, args...);
}

template<typename... TS>
ostream& FPRINTLN(ostream& out, const TS& ...args)
{
    FPRINT(out, args...);
    return out << '\n';
}

template<typename InputIt>
ostream& FPRINTSEQ(ostream& out, InputIt first, InputIt last)
{
    for(InputIt it = first; it != last; ++it) {
        if(it != first) out << ' ';
        out << *it;
    }
    return out;
}

template<typename T, size_t N>
ostream& FPRINTARRAY1(ostream& out, const T (&c)[N])
{
    return FPRINTSEQ(out, cbegin(c), cend(c));
}

template<typename T, size_t N1, size_t N2>
ostream& FPRINTARRAY2(ostream& out, const T (&c)[N1][N2])
{
    out << '\n';
    for(const auto& e : c) {
        FPRINTARRAY1(out, e) << '\n';
    }
    return out;
}

template<typename... TS>
ostream& PRINT(const TS& ...args)
{
    return FPRINT(cout, args...);
}

template<typename... TS>
ostream& PRINTLN(const TS& ...args)
{
    return FPRINTLN(cout, args...);
}

template<typename InputIt>
ostream& PRINTSEQ(InputIt first, InputIt last)
{
    return FPRINTSEQ(cout, first, last);
}

template<typename T, size_t N>
ostream& PRINTARRAY1(const T (&c)[N])
{
    return FPRINTARRAY1(cout, c);
}

template<typename T, size_t N1, size_t N2>
ostream& PRINTARRAY2(const T (&c)[N1][N2])
{
    return FPRINTARRAY2(cout, c);
}

template<typename... TS>
ostream& DPRINT(const TS& ...args)
{
    return FPRINT(cerr, args...);
}

template<typename... TS>
ostream& DPRINTLN(const TS& ...args)
{
    return FPRINTLN(cerr, args...);
}

template<typename InputIt>
ostream& DPRINTSEQ(InputIt first, InputIt last)
{
    return FPRINTSEQ(cerr, first, last);
}

template<typename T, size_t N>
ostream& DPRINTARRAY1(const T (&c)[N])
{
    return FPRINTARRAY1(cerr, c);
}

template<typename T, size_t N1, size_t N2>
ostream& DPRINTARRAY2(const T (&c)[N1][N2])
{
    return FPRINTARRAY2(cerr, c);
}

template<typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1,T2>& p)
{
    return out << '(' << p.first << ',' << p.second << ')';
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& c)
{
    return FPRINTSEQ(out, cbegin(c), cend(c));
}

template<typename T>
ostream& operator<<(ostream& out, const vector<vector<T>>& c)
{
    out << '\n';
    for(const auto& e : c) {
        out << e << '\n';
    }
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const deque<T>& c)
{
    return FPRINTSEQ(out, cbegin(c), cend(c));
}

template<typename T>
ostream& operator<<(ostream& out, const list<T>& c)
{
    return FPRINTSEQ(out, cbegin(c), cend(c));
}

template<typename T>
ostream& operator<<(ostream& out, const forward_list<T>& c)
{
    return FPRINTSEQ(out, cbegin(c), cend(c));
}

template<typename T>
ostream& operator<<(ostream& out, const set<T>& c)
{
    return FPRINTSEQ(out, cbegin(c), cend(c));
}

template<typename T>
ostream& operator<<(ostream& out, const unordered_set<T>& c)
{
    return out << set<T>(cbegin(c), cend(c));
}

template<typename T, size_t N>
ostream& operator<<(ostream& out, const array<T,N>& c)
{
    return FPRINTSEQ(out, cbegin(c), cend(c));
}

template<typename InputIt>
ostream& FPRINTMAP(ostream& out, InputIt first, InputIt last)
{
    out << "{\n";
    for(auto it = first; it != last; ++it) {
        out << "  " << it->first << " : " << it->second << '\n';
    }
    out << "}\n";
    return out;
}

template<typename InputIt>
ostream& PRINTMAP(InputIt first, InputIt last)
{
    return FPRINTMAP(cout, first, last);
}

template<typename InputIt>
ostream& DPRINTMAP(InputIt first, InputIt last)
{
    return FPRINTMAP(cerr, first, last);
}

template<typename K, typename V>
ostream& operator<<(ostream& out, const map<K,V>& c)
{
    return FPRINTMAP(out, cbegin(c), cend(c));
}

template<typename K, typename V>
ostream& operator<<(ostream& out, const unordered_map<K,V>& c)
{
    return out << map<K,V>(cbegin(c), cend(c));
}

template<typename T, typename C>
ostream& operator<<(ostream& out, stack<T,C> c)
{
    while(!c.empty()) {
        out << c.top();
        c.pop();
        if(!c.empty()) out << ' ';
    }
    return out;
}

template<typename T, typename C>
ostream& operator<<(ostream& out, queue<T,C> c)
{
    while(!c.empty()) {
        out << c.front();
        c.pop();
        if(!c.empty()) out << ' ';
    }
    return out;
}

template<typename T, typename Cont, typename Cmp>
ostream& operator<<(ostream& out, priority_queue<T,Cont,Cmp> c)
{
    while(!c.empty()) {
        out << c.top();
        c.pop();
        if(!c.empty()) out << ' ';
    }
    return out;
}

struct IosIni {
    IosIni()
    {
        cin.tie(nullptr);
        ios::sync_with_stdio(IOS_SYNCSTDIO);
        cout << fixed << setprecision(IOS_PREC);
    }
} IOSINI;

#define FOR(i, start, end) for(int i = (start); i < (end); ++i)
#define REP(i, n) FOR(i, 0, n)

#define ALL(f,cc,...) ([&](decltype((cc)) c) { return (f)(begin(c), end(c), ## __VA_ARGS__); })(cc)

#define DBG(x) DPRINTLN('L', __LINE__, ':', #x, ':', (x))
// }}}

int H, W;
vector<string> A;

bool dfs(int x, int y)
{
    int xl = x-1; int yl = y;
    int xr = x+1; int yr = y;
    int xu = x;   int yu = y-1;
    int xd = x;   int yd = y+1;

    if(x != 1 && y != 1 && A[yl][xl] == A[yu][xu]) return false;

    if(x == W && y == H && A[yr][xr] == '.' && A[yd][xd] == '.') return true;

    if(A[yr][xr] == A[yd][xd]) return false;

    if(A[yr][xr] == '#')
        return dfs(xr, yr);
    else if(A[yd][xd] == '#')
        return dfs(xd, yd);
    else
        assert(false);

    // NOTREACHED
    assert(false);
}

void solve()
{
#ifdef DEBUG
    DBG(A);
#endif

    PRINTLN(dfs(1,1) ? "Possible" : "Impossible");
}

signed main(signed /*argc*/, char** /*argv*/)
{
    cin >> H >> W;
    A.assign(H+2, string(W+2, '.')); // 1-based, 壁つき

    REP(i, H) {
        string s;
        cin >> s;
        A[i+1] = '.' + s + '.';
    }

    solve();

    return 0;
}
