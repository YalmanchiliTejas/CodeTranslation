#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

const int MOD_TYPE = 1;
const ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-11;

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define possible(n) cout << ((n) ? "possible" : "impossible") << endl
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << endl
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << endl;

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

int n;
int a[3010];
ll dp[3010][3010][2];

ll f(int l, int r, bool First)
{
  if (r - l == 1)
    return (First ? a[l] : -a[l]);

  if (dp[l][r][First] != -1)
    return dp[l][r][First];

  if (First)
  {
    ll res = max(a[l] + f(l + 1, r, !First), a[r - 1] + f(l, r - 1, !First));
    return dp[l][r][First] = res;
  }
  else
  {
    ll res = min(-a[l] + f(l + 1, r, !First), -a[r - 1] + f(l, r - 1, !First));
    return dp[l][r][First] = res;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);

  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, 3010) rep(j, 3010) rep(k, 2) dp[i][j][k] = -1;
  cout << f(0, n, true) << endl;
  return 0;
}
