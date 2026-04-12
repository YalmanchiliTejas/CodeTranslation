/*input
10
1000000000 1 1000000000 1 1000000000 1 1000000000 1 1000000000 1
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 3003;
vector < ll > v;
ll dp[N][N];

int main()
{
  int n;
  cin >> n;
  v.resize(n);
  ll sum = 0;
  for(auto &x: v) {
  	cin >> x;
  	sum += x;
  }

  for(int i = n; i >= 1; i --) {
  	for(int j = i; j <= n; j ++) {
  		ll a = v[i - 1] + min(dp[i + 2][j], dp[i + 1][j - 1]);
  		ll b = v[j - 1] + min(dp[i + 1][j - 1], dp[i][j - 2]);
  		dp[i][j] = max(a, b);
  	}
  }

  ll d = dp[1][n];
  sum -= d;
  cout << d - sum;
  return 0;
}