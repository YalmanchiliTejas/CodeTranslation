#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, a, n) for (int i = a; i < (n); i++)
#define all(in) in.begin(), in.end()

typedef long double LD;
typedef long long LL;
typedef pair<LL, LL> pll;
typedef pair<int32_t, int32_t> pii;
typedef vector<int32_t> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout << fixed;

  int32_t n;
  cin >> n;
  int32_t a[n];
  int64_t dp[n][n][2];
  rep(i, n) { cin >> a[i]; }

  loop(w, 1, n + 1) {
    rep(si, n - w + 1) {
      if (w == 1) {
        dp[si][si][0] = a[si];
        dp[si][si][1] = -1 * a[si];
      } else {
				dp[si][si + w - 1][0] = max(a[si] + dp[si + 1][si + w - 1][1], a[si + w - 1] + dp[si][si + w - 2][1]);
				dp[si][si + w - 1][1] = min(dp[si + 1][si + w - 1][0] - a[si], dp[si][si + w - 2][0] - a[si + w - 1]);
      }
			//cerr << dp[si][si][0] << ':' << dp[si][si][1] << ' ';
    }
		//cerr << endl;
  }
	cout << dp[0][n-1][0];
}