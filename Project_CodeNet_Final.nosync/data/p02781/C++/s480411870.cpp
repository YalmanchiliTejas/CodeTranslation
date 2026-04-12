/* #region Head */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vc<vc<T>>;
using vll = vc<ll>;
using vvll = vvc<ll>;
using vld = vc<ld>;
using vvld = vvc<ld>;
using vs = vc<string>;
using vvs = vvc<string>;

#define REP(i, m, n) for (ll i = (m), i##_len = (ll)(n); i < i##_len; ++(i))
#define REPM(i, m, n) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; ++(i))
#define REPR(i, m, n) for (ll i = (m), i##_min = (ll)(n); i >= i##_min; --(i))
#define REPD(i, m, n, d) for (ll i = (m), i##_len = (ll)(n); i < i##_len; i += (d))
#define REPMD(i, m, n, d) for (ll i = (m), i##_max = (ll)(n); i <= i##_max; i += (d))
#define REPI(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define ALL(x) begin(x), end(x)
#define SIZE(x) ((ll)(x).size())
#define PREM(c)   \
    sort(all(c)); \
    for (bool c##p = 1; c##p; c##p = next_permutation(all(c)))
#define UNIQ(v) v.erase(unique(ALL(v)), v.end());

constexpr ll INF = 1'010'000'000'000'000'017LL;
constexpr ll MOD = 1'000'000'007LL; // 1e9 + 7
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.14159265358979323846;

// vector入力
template <typename T>
istream &operator>>(istream &is, vc<T> &vec)
{
    for (T &x : vec)
        is >> x;
    return is;
}

// vector出力 (for dump)
template <typename T>
ostream &operator<<(ostream &os, vc<T> &vec)
{
    ll len = SIZE(vec);
    os << "{";
    for (int i = 0; i < len; i++)
        os << vec[i] << (i == len - 1 ? "" : ", ");
    os << "}";
    return os;
}

// vector出力 (inline)
template <typename T>
ostream &operator>>(ostream &os, vc<T> &vec)
{
    ll len = SIZE(vec);
    for (int i = 0; i < len; i++)
        os << vec[i] << (i == len - 1 ? "\n" : " ");
    return os;
}

// pair入力
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &pair_var)
{
    is >> pair_var.first >> pair_var.second;
    return is;
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
Problem
 */
void solve()
{
    string s;
    cin >> s;
    ll k;
    cin >> k;

    ll len = SIZE(s);
    vll nl(len);
    REP(i, 0, len)
    {
        nl[i] = s[i] - '0';
    }
    // dump(nl);

    vc<vvll> dp(2, vvll(4, vll(2, 0)));
    dp[0][0][0] = 1;
    dp[0][1][0] = nl[0] - 1;
    dp[0][1][1] = 1;

    // dump(dp[0]);
    REP(i, 1, len)
    {
        // dump(i);
        dp[i % 2][0][0] = dp[(i - 1) % 2][0][0];
        REPM(j, 1, 3)
        {
            // dump(i, j);

            if (nl[i] == 0) // 今の桁が 0
            {
                dp[i % 2][j][0] =
                    dp[(i - 1) % 2][j][0]                // この桁は 0 を使う
                    + (dp[(i - 1) % 2][j - 1][0] * 9);   // この桁は 1-9 を使う
                dp[i % 2][j][1] = dp[(i - 1) % 2][j][1]; // 上を這うなら 0 を使うしかない (0でない数字の個数は増えない)
            }
            else
            {
                dp[i % 2][j][0] =
                    dp[(i - 1) % 2][j][0]                       // この桁は 0 を使う
                    + (dp[(i - 1) % 2][j - 1][0] * 9)           // この桁は 1-9 を使う
                    + (dp[(i - 1) % 2][j - 1][1] * (nl[i] - 1)) // 前の桁までは上を這ってたが，この桁で解放 (1 〜 nl[i]-1 まで)
                    + (dp[(i - 1) % 2][j][1]);                  // 前の桁までは上を這ってたが，この桁で解放 (0)
                dp[i % 2][j][1] = dp[(i - 1) % 2][j - 1][1];    // 上を這うなら nl[i] (>0) を使うしかない (0でない数字の個数 += 1)
            }
            // dump(i, j);
        }
        // dump(i, dp[i % 2]);
    }
    cout << (dp[(len - 1) % 2][k][0] + dp[(len - 1) % 2][k][1]) << endl;
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
