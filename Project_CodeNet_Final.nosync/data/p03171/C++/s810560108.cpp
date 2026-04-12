#pragma region
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n; cin >> n;
	vector<ll> a(n); rep(i, n)cin >> a[i];
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
	rep(i, n + 1)dp[i][i] = 0;
	for (int l = 1; l <= n; ++l)
	{
		for (int i = 0; i + l <= n; ++i)
		{
			int j = i + l;
			if ((n - l) % 2 == 0)
			{
				dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
			}
			else
			{
				dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
			}
		}
	}
	cout << dp[0][n] << endl;
}