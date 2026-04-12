#include "bits/stdc++.h"

using namespace std;

#define FI              freopen("in.txt", "r", stdin)
#define FO              freopen("out.txt", "w", stdout)
#define FAST            ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define FOR(i, n)       for (int i = 1; i <= n; i++)
#define For(i, n)       for (int i = 0; i < n; i++)
#define ROF(i, n)       for (int i = n; i >= 1; i--)
#define Rof(i, n)       for (int i = n-1; i >= 0; i--)
#define FORI(i, n)      for (auto i : n)

#define ll              long long
#define ull             unsigned long long
#define vi              vector <int>
#define vl              vector <ll>
#define pii             pair <int, int>
#define pll             pair <ll, ll>
#define mk              make_pair
#define ff              first
#define ss              second
#define eb              emplace_back
#define em              emplace
#define pb              push_back
#define ppb             pop_back
#define All(a)          a.begin(), a.end()
#define memo(a, b)      memset(a, b, sizeof a)
#define Sort(a)         sort(All(a))
#define ED(a)           Sort(a), a.erase(unique(All(a)), a.end())
#define rev(a)          reverse(All(a))
#define sz(a)           (int)a.size()
#define max3(a, b, c)   max(a, max(b, c))
#define min3(a, b, c)   min(a, min(b, c))
#define maxAll(a)       *max_element(All(a))
#define minAll(a)       *min_element(All(a))
#define allUpper(a)     transform(All(a), a.begin(), :: toupper)
#define allLower(a)     transform(All(a), a.begin(), :: tolower)
#define endl            '\n'
#define nl              puts("")
#define ub              upper_bound
#define lb              lower_bound
#define Exp             exp(1.0)
#define PIE             2*acos(0.0)
#define Sin(a)          sin(((a)*PIE)/180.0)
#define EPS             1e-9

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;

template <typename T> using orderset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

#include "ext/rope"
using namespace __gnu_cxx;

// rope <int> Rope;

// int dr[] = {1, -1, 0, 0}; // 4 Direction
// int dc[] = {0, 0, 1, -1};
// int dr[] = {0, 0, 1, -1, 1, 1, -1, -1}; // 8 Direction
// int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};
// int dr[] = {-1, 1, -2, -2, -1, 1, 2, 2}; // knight Moves
// int dc[] = {-2, -2, -1, 1, 2, 2, 1, -1};

#define trace1(x)                           cerr << #x << ": " << x << endl;
#define trace2(x, y)                        cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)                     cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)                  cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)               cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)            cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

inline int setbit(int mask, int pos)        { return mask |= (1 << pos); }
inline int resetbit(int mask, int pos)      { return mask &= ~(1 << pos); }
inline int togglebit(int mask, int pos)     { return mask ^= (1 << pos); }
inline bool checkbit(int mask, int pos)     { return (bool)(mask & (1 << pos)); }

#define popcount(mask)                       __builtin_popcount(mask) // count set bit
#define popcountLL(mask)                     __builtin_popcountll(mask) // for long long

inline int read()                           { int a; scanf("%d", &a); return a; }
inline ll readLL()                          { ll a; scanf("%lld", &a); return a; }
inline double readDD()                      { double a; scanf("%lf", &a); return a; }

template <typename T> string toString(T num) { stringstream ss; ss << num; return ss.str(); }
int toInt(string s)                          { int num; istringstream iss(s); iss >> num; return num;  }
ll toLLong(string s)                         { ll num; istringstream iss(s); iss >> num; return num; }

#define inf             1e17
#define mod             1000000007

static const int maxn = 1e4 + 5;
static const int logn = 18;

ll dp[10000+5][100+5];
bool memoize[10000+5][100+5];
int a[10000+5];
int D;

inline ll solve(int pos, int rem = 0, bool flag = 1, bool take = 0)
{
      if (pos < 0) return rem == 0;
      ll &ret = dp[pos][rem];
      bool &mem = memoize[pos][rem];
      if (!flag and take and mem) return ret;
      int loop = 9;
      if (flag) loop = a[pos];
      ll sum = 0;
      For(i, loop+1)
      {
            if (!take && i == 0) sum = (sum + solve(pos-1, 0, 0, 0)) % mod;
            else sum = (sum + solve(pos-1, (rem + i) % D, flag & i == a[pos], 1)) % mod;
      }
      if (!flag and take) mem = 1, ret = sum;
      return sum;
}

inline ll digitDP(string &s)
{
      int len = 0;
      Rof(i, sz(s)) a[len++] = s[i] - '0';
      return solve(len-1);
}

int main()
{
      string K;
      cin >> K >> D;
      cout << (digitDP(K) - 1 + mod) % mod;
}
