#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define fout(x) cout << fixed << setprecision(20) << x << endl
const int MOD = 1e9 + 7;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 1e-8;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

auto print = [](auto &v) {
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
};

int cti(const char c) {
  return c - '0';
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string n;
  cin >> n;
  int k;
  cin >> k;
  VVL dp1(101, VL(k + 2, 0)), dp2(101, VL(k + 2, 0));

  int digit = n.size();
  dp1[0][0] = 1;
  dp1[0][1] = cti(n[0]) - 1;
  dp2[0][1] = 1;
  rep(i, digit - 1) {
    rep(j, k + 1) {
      ll num = cti(n[i + 1]);
      if (num == 0) {
        dp1[i + 1][j] += dp1[i][j];
        dp1[i + 1][j + 1] += dp1[i][j] * 9;
        dp2[i + 1][j] += dp2[i][j];
        dp2[i + 1][j + 1] += 0;
      }
      else {
        dp1[i + 1][j] += dp1[i][j] + dp2[i][j];
        dp1[i + 1][j + 1] = dp1[i][j] * 9 + dp2[i][j] * (num - 1);
        dp2[i + 1][j] += 0;
        dp2[i + 1][j + 1] += dp2[i][j];
      }
    }
  }

  out(dp1[digit - 1][k] + dp2[digit - 1][k]);

  return 0;
}
