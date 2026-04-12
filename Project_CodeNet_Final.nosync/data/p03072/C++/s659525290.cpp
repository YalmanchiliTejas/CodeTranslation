/* #region Head */

//============================================================================
// Name        : filename.cpp
// Author      : abb
// Version     :
// Copyright   : [My copyright notice]
// Description : test program
//============================================================================

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;
using vvs = vector<vs>;

#define REP(i, m, n) for (ll i = (m), i##_len = (ll)(n); i < i##_len; ++(i))
#define REPM(i, m, n) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; ++(i))
#define REPR(i, m, n) for (ll i = (m), i##_min = (ll)(n); i >= i##_min; --(i))
#define REPD(i, m, n, d) for (ll i = (m), i##_len = (ll)(n); i < i##_len; i += (d))
#define REPMD(i, m, n, d) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; i += (d))
#define REPI(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define ALL(x) begin(x), end(x)
#define SIZE(x) ((ll)(x).size())

constexpr ll INF = 1'010'000'000'000'000'017LL;
constexpr ll MOD = 1'000'000'007LL; // 1e9 + 7
constexpr double EPS = 1e-12;
constexpr double PI = 3.14159265358979323846;

// vector入力
template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x;
    return is;
}

// vector出力
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec)
{
    ll len = SIZE(vec);
    os << "{";
    for (int i = 0; i < len; i++)
        os << vec[i] << (i == len - 1 ? "" : ", ");
    os << "}";
    return os;
}

// pair出力
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var)
{
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}

// map出力
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var)
{
    os << "{";
    REPI(itr, map_var)
    {
        os << *itr;
        itr++;
        if (itr != map_var.end())
            os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

// set 出力
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var)
{
    os << "{";
    REPI(itr, set_var)
    {
        os << *itr;
        itr++;
        if (itr != set_var.end())
            os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

// dump
#define DUMPOUT cerr
void dump_func()
{
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail)
{
    DUMPOUT << head;
    if (sizeof...(Tail) > 0)
    {
        DUMPOUT << ", ";
    }
    dump_func(move(tail)...);
}

// chmax (更新「される」かもしれない値が前)
template <typename T, typename U, typename Comp = less<>>
bool chmax(T &xmax, const U &x, Comp comp = {})
{
    if (comp(xmax, x))
    {
        xmax = x;
        return true;
    }
    return false;
}

// chmin (更新「される」かもしれない値が前)
template <typename T, typename U, typename Comp = less<>>
bool chmin(T &xmin, const U &x, Comp comp = {})
{
    if (comp(x, xmin))
    {
        xmin = x;
        return true;
    }
    return false;
}

// container 内の最初の element のインデックスを探す
template <class Container>
ll indexof(const Container &container, const typename Container::value_type &element)
{
    auto iter = find(container.begin(), container.end(), element);
    size_t index = distance(container.begin(), iter);
    if (index == container.size())
    {
        index = -1;
    }
    return index;
}

// ローカル用
#define DEBUG_

#ifdef DEBUG_
#define DEB
#define dump(...)                                                       \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                     \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" \
            << endl                                                     \
            << "    ",                                                  \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif

struct AtCoderInitialize
{
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    AtCoderInitialize()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cout << fixed << setprecision(IOS_PREC);
        if (AUTOFLUSH)
            cout << unitbuf;
    }
} ATCODER_INITIALIZE;

/* #endregion */

/**
B - Great Ocean View

実行時間制限: 2 sec / メモリ制限: 1024 MB

配点 : 200 点

問題文
東西に N 個の山が連なっており、西の果てには広大な海が広がっています。
各山頂には旅館があり、あなたは海を眺められる旅館を選ぶことにしました。
西から i 番目の山の高さは H_i です。
西から 1 番目の山頂にある旅館からは必ず海を眺めることができます。
西から i (i = 2, 3, ..., N) 番目の山頂にある旅館については、H_1 <= H_i, H_2 <= H_i, ..., かつ H_{i-1} <= H_i のとき、その旅館から海を眺めることができます。
これら N 個の旅館のうち、海を眺められる旅館はいくつあるでしょうか。

制約

・入力は全て整数である。
・1 <= N <= 20
・1 <= H_i <= 100
 */
void solve()
{
    ll n;
    cin >> n;
    vll h(n);
    cin >> h;

    ll hm = 0, cnt = 0;
    REP(i, 0, n)
    {
        if (hm <= h[i])
            ++cnt;
        chmax(hm, h[i]);
    }
    cout << cnt << endl;
}

/**
 * エントリポイント．
 * @return 0.
 */
int main()
{
    solve();
    return 0;
}
