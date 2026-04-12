#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("Ofast")

using namespace std;
using ll = long long;

// MACRO
// for loop
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= ll(b); i--)

// for vector
#define ALL(x) x.begin(), x.end()
#define SIZE(x) ll(x.size())
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(ALL(x), greater<int>())
#define RSORTS(x) sort(ALL(x), greater<string>())
#define FIND(x, n) find(ALL(x), n)
#define VFOR(e, x) for (auto &e : x)

// Constant
const ll INF = 1000000000000; // 10^12:  ∞
const int MOD = 1000000007;   // 10^9+7: Congruence ceremony MOD
const int MAXR = 100000;      // 10^5:   Array Max Range
const char EL = '\n';         // newline

// alias
#define EB emplace_back // push as last element
#define PP pop_back     // pop last element
#define MP make_pair    // pair constractor
#define F first         // first element of pair
#define S second        // second element of pair

// change max/min
template <class T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
  if (b < a)
  {
    a = b;
    return 1;
  }
  return 0;
}

// optimize in/out
#define OPTIMIZE_CIN_COUT() \
  cin.tie(0);               \
  ios::sync_with_stdio(false);

template <typename... Args>
void input(Args... args)
{
  for (int &e : {args...})
  {
    cin >> e;
  }
}
#define INPUT1(a) \
  int a = 0;      \
  cin >> a;
#define INPUT2(a, b) \
  int a = 0;         \
  int b = 0;         \
  cin >> a >> b;
#define INPUT3(a, b, c) \
  int a = 0;            \
  int b = 0;            \
  int c = 0;            \
  cin >> a >> b >> c;
#define INPUTS(s) \
  string s = "";  \
  cin >> s;

#define INPUTA(n, a) \
  int n = 0;         \
  cin >> n;          \
  vector<int> a(n);  \
  REP(i, n)          \
  {                  \
    cin >> a[i];     \
  }
#define INPUTB(x, y, b)                     \
  int x = 0, y = 0;                         \
  cin >> x >> y;                            \
  vector<vector<int>> b(y, vector<int>(x)); \
  REP(i, y)                                 \
  {                                         \
    REP(j, x)                               \
    {                                       \
      cin >> b[i][j];                       \
    }                                       \
  }

int main()
{
  OPTIMIZE_CIN_COUT();

  INPUT1(X);
  if (X >= 30)
  {
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }

  // INPUT2(A, B);
  // INPUT3(A, B, C);
  // INPUTS(S);
  // INPUTA(N, A);
  // INPUTB(X, Y, B);
}
