#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_temp>
using smaller_queue = priority_queue<Q_temp, vector<Q_temp>, greater<Q_temp>>;

const ll MOD = (ll)(1e9 + 7);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const double PI = acos(-1.0);

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

string s;
ll memo[110][4][2];

ll f(int index, int k, bool any)
{
  if (memo[index][k][any] != -LINF)
  {
    return memo[index][k][any];
  }

  if (index == s.length())
  {
    memo[index][k][any] = (k == 0 ? 1 : 0);
    return memo[index][k][any];
  }

  if (any)
  {
    if (k == 0)
    {
      memo[index][k][any] = f(index + 1, 0, true);
      return memo[index][k][any];
    }
    else
    {
      memo[index][k][any] = 9 * f(index + 1, k - 1, true) + f(index + 1, k, true);
      return memo[index][k][any];
    }
  }
  else
  {
    ll top = s[index] - '0';
    if (k == 0)
    {
      memo[index][k][any] = 1;
      return memo[index][k][any];
    }
    else
    {
      if (top == 0)
      {
        memo[index][k][any] = f(index + 1, k, false);
        return memo[index][k][any];
      }
      else
      {
        memo[index][k][any] = f(index + 1, k, true) + max((top - 1), 0LL) * f(index + 1, k - 1, true) + f(index + 1, k - 1, false);
        return memo[index][k][any];
      }
    }
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(50) << setiosflags(ios::fixed);
  cin >> s;
  int k;
  cin >> k;
  rep(i, 110) rep(j, 4) memo[i][j][0] = memo[i][j][1] = -LINF;
  cout << f(0, k, false) << endl;
  return 0;
}
