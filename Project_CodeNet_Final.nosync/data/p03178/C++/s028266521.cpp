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

//only for variables and vi;
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
string s;
ll d, n, dp[10010][2][100];  

ll fn(ll i, ll f, ll sum) { 
  if(i == n) {
    return !sum;
  }
  ll &res = dp[i][f][sum];
  if(res != -1) return res;
  res = 0;
  ll curdig = s[i] - 48;
  for(ll dig = 0; dig <= 9; dig++) {
    if(!f && dig > curdig) 
      break;
    res += fn(i + 1, f | (dig < curdig), (sum + dig) % d);
    if(res >= mod) 
      res -= mod;
  }
  return res;
}

main()
{
  memset(dp, -1, sizeof(dp));
  cin >> s >> d;
  n = s.length();
  ll ans = fn(0, 0, 0);
  ans--;
  if(ans < 0) {
    ans += mod;
  }
  cout << ans;
}
