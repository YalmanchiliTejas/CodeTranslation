#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>
#include <chrono>
#include <ctime>
#include <bitset>
#include <iterator>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<long long, long long>
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }

  if (n==1) {
    cout << a[0] << endl;
    return 0;
  }

  ll dp[n+1][n+1];
  for(int i=1; i<n; i++) {
    dp[i][i+1] = abs(a[i] - a[i-1]);
    //cerr << i << ' ' << i+1 << ' ' << dp[i][i+1] << endl;
  }

  for(int i=2; i<n; i++) {
    for(int j=1; j+i<=n; j++) {
      if (i%2 == 0) {
        dp[j][j+i] = min(-a[j-1] + dp[j+1][j+i], dp[j][j+i-1] - a[j+i-1]);
      } else {
        dp[j][j+i] = max(a[j-1] + dp[j+1][j+i], dp[j][j+i-1] + a[j+i-1]);
      }
      //cerr << j << ' ' << j+i << ' ' << dp[j][j+i] << endl;
    }
  }

  ll ans;
  if (n%2 == 0) {
    ans = dp[1][n];
  } else {
    ans = -dp[1][n];
  }

  cout << ans << endl;
}