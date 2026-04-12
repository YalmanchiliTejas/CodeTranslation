#include <bits/stdc++.h>
#define all(cont) cont.begin(), cont.end()
#define pb push_back
#define fi first
#define se second
#define DEBUG(x) cerr << (#x) << ": " << (x) << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

template<class T> bool uin(T &a, T b) {return (a < b ? false : (a = b, true));}
template<class T> bool uax(T &a, T b) {return (a > b ? false : (a = b, true));}

//ifstream f(".in");
//ofstream g(".out");

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL_DEFINE
  freopen(".in", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  const long long INF = 1e18L + 5;
  vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, -INF));
  // dp[l][r] = maximum diff to be made by the player moving next
  for (int i = 1; i <= n; ++i) {
    dp[i][i] = a[i];
    for (int j = 1; j <= i - 1; ++j) {
      dp[i][j] = -INF;
    }
  }
  for (int l = n; l >= 1; --l) {
    for (int r = l + 1; r <= n; ++r) {
      uax(dp[l][r], max(a[l] - dp[l + 1][r],
                        a[r] - dp[l][r - 1]));
    }
  }

  cout << dp[1][n] << ' ';

#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
