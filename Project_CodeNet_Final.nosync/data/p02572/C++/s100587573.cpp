#pragma once
#undef _GLIBCXX_DEBUG

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

void trace(int x)                         { cerr << x; }
void trace(long x)                        { cerr << x; }
void trace(long long x)                   { cerr << x; }
void trace(unsigned x)                    { cerr << x; }
void trace(unsigned long x)               { cerr << x; }
void trace(unsigned long long x)          { cerr << x; }
void trace(float x)                       { cerr << x; }
void trace(double x)                      { cerr << x; }
void trace(long double x)                 { cerr << x; }
void trace(char x)                        { cerr << '\'' << x << '\''; }
void trace(const char *x)                 { cerr << '\"' << x << '\"'; }
void trace(const string &x)               { cerr << '\"' << x << '\"'; }
void trace(bool x)                        { cerr << (x ? "true" : "false"); }

template <typename A, typename B>                         void trace(const pair <A, B> &x)         { cerr << '{'; trace(x.first); cerr << ','; trace(x.second); cerr << '}'; }
template <typename A, typename B, typename C>             void trace(const tuple <A, B, C> &x)     { cerr << '{'; trace(get <0> (x)); cerr << ','; trace(get <1> (x)); cerr << ','; trace(get <2> (x)); cerr << '}'; }
template <typename A, typename B, typename C, typename D> void trace(const tuple <A, B, C, D> &x)  { cerr << '{'; trace(get <0> (x)); cerr << ','; trace(get <1> (x)); cerr << ','; trace(get <2> (x)); cerr << ','; trace(get <3> (x)); cerr << '}'; }
template <typename T>                                     void trace(const T &x)                   { int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), trace(i); cerr << "}"; }
template <size_t N>                                       void trace(bitset <N> v)                 { cerr << '{'; for (size_t i = 0; i < N; i++) cerr << static_cast <char> ('0' + v[i]); cerr << '}'; }
void _print()                                                                                      { cerr << "]\n"; }
template <typename T, typename... V>                      void _print(T t, V... v)                 { trace(t); if (sizeof...(v)) cerr << ", "; _print(v...); }

#ifndef ONLINE_JUDGE
      #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
      #define debug(x...)
#endif // ONLINE_JUDGE

template <typename T> using ordered_set                = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T1, typename T2> using ordered_map  = tree <T1, T2, less <T1>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> T binaryExpo(T a, T p)              { if (p == 0) { return 1LL; } if (p == 1) { return a; } if (p & 1) { return a * binaryExpo(a, p - 1); } T ret = binaryExpo(a, p / 2); return ret * ret; }
template <typename T> T bigMod(T a, T p, T m)             { if (p == 0) { return 1LL % m; } if (p == 1) { return a % m; } if (p & 1) { return (a % m * bigMod(a, p - 1, m)) % m; } T ret = bigMod(a, p / 2, m) % m; return (ret * ret) % m; }
template <typename T> T modInv(T a, T m)                  { return bigMod(a, m - 2, m); }

template <class T> bool MIN(T &a, T b)                    { return a > b ? (a = b, true) : false; }
template <class T> bool MAX(T &a, T b)                    { return a < b ? (a = b, true) : false; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define ll              long long int
#define ull             unsigned long long int
#define ld              long double
#define endl            '\n'
#define pii             pair <int, int>
#define pll             pair <ll, ll>
#define mk              make_pair
#define ff              first
#define ss              second
#define all(a)          (a).begin(), (a).end()
#define rall(a)         (a).rbegin(), (a).rend()
#define eb              emplace_back
#define pb              push_back
#define pf              push_front
#define allUpper(a)     transform(all(a), a.begin(), :: toupper)
#define allLower(a)     transform(all(a), a.begin(), :: tolower)
#define memo(a, b)      memset(a, b, sizeof a)
#define sz(a)           (int)(a.size())
#define ook             order_of_key             // The number of items in a set that are strictly smaller than k
#define fbo             find_by_order            // It returns an iterator to the i'th largest element

#define int             long long int

const int maxn = 3e5 + 5;
const int logn = 19;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

struct mi {
      long long v;
      explicit operator long long() const { return v; }
      mi() { v = 0; }
      mi(long long _v) { v = (-MOD < _v && _v < MOD) ? _v : _v % MOD; if (v < 0) { v += MOD; } }

      friend bool operator == (const mi& a, const mi& b) { return a.v == b.v; }
      friend bool operator != (const mi& a, const mi& b) { return !(a == b); }
      friend bool operator < (const mi& a, const mi& b) { return a.v < b.v; }

      mi& operator += (const mi& m) { if ((v += m.v) >= MOD) { v -= MOD; } return *this; }
      mi& operator -= (const mi& m) { if ((v -= m.v) < 0) { v += MOD; } return *this; }
      mi& operator *= (const mi& m) { v = v * m.v % MOD; return *this; }
      mi& operator /= (const mi& m) { return (*this) *= inv(m); }

      friend mi pow(mi a, long long p) { mi ans = 1; assert(p >= 0); for (; p; p /= 2, a *= a) { if (p & 1) { ans *= a; } } return ans; }
      friend mi inv(const mi& a)       { assert(a.v != 0); return pow(a, MOD - 2); }

      mi operator - () const { return mi(-v); }
      mi& operator ++ () { return *this += 1; }
      mi& operator -- () { return *this -= 1; }
      #undef int
      mi operator ++ (int) { mi temp; temp.v = v++; return temp; }
      mi operator -- (int) { mi temp; temp.v = v--; return temp; }
      #define int         long long int
      friend mi operator + (mi a, const mi& b) { return a += b; }
      friend mi operator - (mi a, const mi& b) { return a -= b; }
      friend mi operator * (mi a, const mi& b) { return a *= b; }
      friend mi operator / (mi a, const mi& b) { return a /= b; }

      friend ostream& operator << (ostream& os, const mi& m) { os << m.v; return os; }
      friend istream& operator >> (istream& is, mi& m) { long long x; is >> x; m.v = x; return is; }
};

signed main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr); cout.tie(nullptr);
      cout.precision(12);

      bool FILEIO = 0;
      if (FILEIO and fopen("in.txt", "r")) {
            freopen("in.txt", "r", stdin);
      }

      int n;
      cin >> n;
      mi ans = 0;
      mi sum = 0;
      for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ans += sum * x;
            sum += x;
      }
      cout << ans << endl;
}
