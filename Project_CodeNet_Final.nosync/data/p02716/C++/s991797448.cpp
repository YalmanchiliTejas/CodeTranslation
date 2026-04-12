#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
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
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#pragma endregion

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val)
{
  fill((T *)array, (T *)(array + N), val);
}

bool chmax(ll &a, ll b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);

  int n;
  cin >> n;
  ll a[200010];
  rep(i, n) cin >> a[i];
  if (n == 2)
    a[2] = -LINF;
  ll dp[200010][3];
  Fill(dp, -LINF);
  dp[1][0] = a[0];
  dp[2][1] = a[1];
  dp[3][2] = a[2];
  rep(i, n + 1)
  {
    if (i >= 2)
    {
      chmax(dp[i][0], dp[i - 2][0] + a[i - 1]);
      chmax(dp[i][1], dp[i - 2][1] + a[i - 1]);
      chmax(dp[i][2], dp[i - 2][2] + a[i - 1]);
    }
    if (i >= 3)
    {
      chmax(dp[i][1], dp[i - 3][0] + a[i - 1]);
      chmax(dp[i][2], dp[i - 3][1] + a[i - 1]);
    }
  }
  ll Max = -LINF;
  if (n % 2 == 0)
  {
    chmax(Max, dp[n - 1][0]);
    chmax(Max, dp[n][1]);
  }
  else
  {
    chmax(Max, dp[n - 2][0]);
    chmax(Max, dp[n - 1][1]);
    chmax(Max, dp[n][2]);
  }
  cout << Max << endl;
  return 0;
}
