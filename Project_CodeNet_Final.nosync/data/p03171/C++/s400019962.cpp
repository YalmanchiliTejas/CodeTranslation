#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<ll, ll> mpii;
typedef unordered_map<ll, ll> umpii;

#define pb(v) push_back(v)
#define all(v) v.begin(), v.end()
#define upb(v, key) (upper_bound(all(v), key) - v.begin())
#define lob(v, key) (lower_bound(all(v), key) - v.begin())

ll inf = 1e9;
ll INF = inf * 1ll * inf;
ll mod = 1e9 + 7;
double eps = 1e-9;
const ld pi = ld(3.1415926535897932384626433832795);
ll dr[] = {-1, 0, 0, 1};
ll dc[] = {0, 1, -1, 0};

template <class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a)
{
  while (*sdbg != ',')
    cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
  os << "[";
  for (auto vv : V)
    os << vv << ",";
  return os << "]";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
  return os << "(" << P.st << "," << P.nd << ")";
}
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

/*...................................................*/
ll dp[3010][3010][2];
ll a[3010];

main()
{
  int n, i, j;
  cin >> n;
  for(i = 0; i < n; i++)
  cin >> a[i];
  for(i = 0; i < n; i++)
  dp[i][i][0] = a[i], dp[i][i][1] = -a[i];

  for(i = n - 1; i >= 0; i--)
  for(j = i + 1; j < n; j++)
  {
    dp[i][j][0] = max((i + 1 == n? -INF: dp[i + 1][j][1] + a[i]), dp[i][j - 1][1] + a[j]);
    dp[i][j][1] = min((i + 1 == n? INF: dp[i + 1][j][0] - a[i]), dp[i][j - 1][0] - a[j]);
  }
  cout << dp[0][n - 1][0];
}