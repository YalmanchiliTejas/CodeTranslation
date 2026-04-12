#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template <class T1, class T2>
ostream& operator << (ostream& out, pair <T1, T2> p)
{
    out << '(' << p.first << ',' << p.second << ')';
    return out;
}

template <class T1, class T2>
istream& operator >> (istream& in, pair<T1, T2> &p)
{
    in >> p.first >> p.second;
    return in;
}

template <class T>
istream& operator >> (istream& in, vector<T> &v)
{
    for (T &x : v)
        in >> x;
    return in;
}

template <class T>
ostream& operator << (ostream& out, vector<vector<T>> &v)
{
    for (vector<T> &x : v)
        out << x << '\n';
    return out;
}

template <class T>
ostream& operator << (ostream& out, vector<T> &v)
{
    for (T &x : v)
        out << x << ' ';
    return out;
}

long long gcd (long long a, long long b)
{
    if (b > a)
        swap(a, b);
    return (b ? gcd(b, a % b) : a);
}

using ll   = long long;
using pii  = pair<int, int>;
using pll  = pair<long long, long long>;
using tiii = pair<pair<int, int>, int>;
using vi   = vector<int>;
using vl   = vector<long long>;
using vvi  = vector<vector<int>>;
using vvl  = vector<vector<long long>>;

#define F          first
#define S          second
#define First      first.first
#define Second     first.second
#define Third      second
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)
#define per(i,b,a) for (int i = b; i > a; i--)
#define all(x)     x.begin(), x.end()
#define ret(x)     return cout << x, 0;
#define throwex    throw runtime_error ("Found the error.");

const int h = 998244353;

signed main()
{
    ios::sync_with_stdio(false);
    #ifdef ONLINE_JUDGE
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.setstate(ios::failbit);
    #endif

    int n, s;
    cin >> n >> s;
    vi v(n);
    cin >> v;
    vvl dp(n+1, vl(s+1));
    ll ans = 0;
    rep(i,0,n)
    {
        dp[i+1] = dp[i];
        if(v[i] <= s)
            (dp[i+1][v[i]] += i + 1) %= h;
        rep(j,0,s+1)
            if(j + v[i] <= s)
                (dp[i+1][j + v[i]] += dp[i][j]) %= h;
        (ans += dp[i+1][s]) %= h;
    }
    cout << ans;
}
