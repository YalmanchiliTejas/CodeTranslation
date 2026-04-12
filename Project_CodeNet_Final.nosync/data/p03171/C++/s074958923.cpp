/*
    [Gnana Deepak]
    [August 03, 2020 5:14 PM]
    [L - Deque]
    [https://atcoder.jp/contests/dp/tasks/dp_l]
    [2000 ms]
    [1024 MB]
*/
#include <bits/stdc++.h>
using namespace std;

using ld = long double;
#define int long long

#define F first
#define S second
#define s(x) set<x>
#define um(x, y) unordered_map<x, y>
#define m(x, y) map<x, y>
#define p(x, y) pair<x, y>
#define v(x) vector<x>
#define min_heap(t) priority_queue<t, vector<t>, greater<t>>
#define max_heap(t) priority_queue<t>

#define eb emplace_back
#define mp make_pair
#define bs binary_search
#define lb lower_bound
#define ub upper_bound

#define all(v) v.begin(), v.end()
#define ss(v) stable_sort(all(v))
#define fori(i, a, b) for (int i = a; i <= b; i++)
#define rofi(i, a, b) for (int i = a; i >= b; --i)
#define scn(v1)        \
    for (auto &x : v1) \
        cin >> x;
#define deb(x) cout << #x << "=" << x << endl;
#define R(x) reverse(all(x));

#define FILE_READ_IN freopen("input.txt", "r", stdin);
#define FILE_READ_OUT freopen("output.txt", "w", stdout);

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define stprs(x) cout << fixed << setprecision(x);

const char nl = '\n';
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const ld PI = acos(-1);

// Everything till line 152 is taken from "https://codeforces.com/contest/997/submission/88692369 and made few changes"
typedef string str;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define sz(x) (int)(x).size()
#define ts to_string
str ts(char c)
{
    return str(1, c);
}
str ts(const char *s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b)
{
#ifdef LOCAL
    return b ? "true" : "false";
#else
    return ts((int)b);
#endif
}
template <class A>
str ts(complex<A> c)
{
    stringstream ss;
    ss << c;
    return ss.str();
}
str ts(vector<bool> v)
{
    str res = "{";
    F0R(i, sz(v))
    res += char('0' + v[i]);
    res += "}";
    return res;
}
template <size_t SZ>
str ts(bitset<SZ> b)
{
    str res = "";
    F0R(i, SZ)
    res += char('0' + b[i]);
    return res;
}
template <class A, class B>
str ts(pair<A, B> p);
template <class T>
str ts(T v)
{
#ifdef LOCAL
    bool fst = 1;
    str res = "{";
    for (const auto &x : v)
    {
        if (!fst)
            res += ", ";
        fst = 0;
        res += ts(x);
    }
    res += "}";
    return res;
#else
    bool fst = 1;
    str res = "";
    for (const auto &x : v)
    {
        if (!fst)
            res += " ";
        fst = 0;
        res += ts(x);
    }
    return res;

#endif
}
template <class A, class B>
str ts(pair<A, B> p)
{
#ifdef LOCAL
    return "(" + ts(p.F) + ", " + ts(p.S) + ")";
#else
    return ts(p.F) + " " + ts(p.S);
#endif
}
void debug()
{
    cout << "\ncompleted debug\n";
}
template <class H, class... T>
void debug(H h, T... t)
{
    string _h = ts(h);
    cout << _h;
    if (sizeof...(t))
        cout << "\n";
    debug(t...);
}

// variables and consts
const int N = 3000;
int DP[N + 1][N + 1];
int Arr[N + 1];
// -- variables and consts --

void accio_ac(void)
{
    int n;
    cin >> n;
    fori(i, 1, n)
    {
        cin >> Arr[i];
    }
    rofi(i, n, 1) fori(j, i, n)
    {
        if (i == j)
        {
            DP[i][j] = Arr[i];
        }
        else
        {
            DP[i][j] = max(Arr[i] - DP[i + 1][j], Arr[j] - DP[i][j - 1]);
        }
    }
    cout << DP[1][n] << nl;
}

int32_t main(void)
{
    fastio;
    int __ = 1;
    // cin >> __;
    while (__--)
    {
        accio_ac();
    }
    return 0;
}
