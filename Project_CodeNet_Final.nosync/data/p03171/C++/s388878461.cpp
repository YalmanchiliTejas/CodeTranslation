/*input
6
4 2 9 7 1 5
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 3003;
vector < ll > v;
ll dp[N][N];

ll func(int l, int r)
{
	if(l > r) {
		return 0;
	}
	if(dp[l][r] > -1) {
		return dp[l][r];
	}

	ll a = v[l] + min(func(l + 2, r), func(l + 1, r - 1));
	ll b = v[r] + min(func(l + 1, r - 1), func(l, r - 2));
	return dp[l][r] = max(a, b);
}

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

  memset(dp, -1, sizeof(dp));
  ll d = func(0, n - 1);

  sum -= d;
  cout << d - sum;
  return 0;
}