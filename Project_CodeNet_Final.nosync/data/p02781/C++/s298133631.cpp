#pragma region Macros
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

string s;
int k;

ll memo[110][5][2];
ll f(int i, int cnt, bool less)
{
  if (memo[i][cnt][less] != -1)
    return memo[i][cnt][less];
  if (cnt >= 4)
    return 0;
  if (i == s.length())
    return (cnt == k);

  ll res = 0;
  if (less)
  {
    res += f(i + 1, cnt, true);
    res += 9 * f(i + 1, cnt + 1, true);
  }
  else
  {
    if (s[i] == '0')
    {
      res += f(i + 1, cnt, false);
    }
    else
    {
      res += f(i + 1, cnt, true);
      for (int j = 1; j < s[i] - '0'; j++)
        res += f(i + 1, cnt + 1, true);
      res += f(i + 1, cnt + 1, false);
    }
  }
  return memo[i][cnt][less] = res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);

  cin >> s >> k;
  rep(i, 110) rep(ii, 5) rep(iii, 2) memo[i][ii][iii] = -1;
  cout << f(0, 0, false) << endl;
  return 0;
}
