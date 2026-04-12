#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000000LL;
const int MAX_N = 3005;

int n;
ll a[MAX_N];
bool used[MAX_N][MAX_N][2];
ll dp[MAX_N][MAX_N][2];

ll calc(int i, int j, int p)
{
	if (i == j)
		return (p == 0 ? 1 : -1) * a[i];
	if (used[i][j][p])
		return dp[i][j][p];
	
	ll result = (p == 0 ? -1 : 1) * INF;
	if (p == 0)
	{
		if (i + 1 <= j)
			result = max(result, a[i] + calc(i + 1, j, 1 - p));
		if (i <= j - 1)
			result = max(result, a[j] + calc(i, j - 1, 1 - p));
	}
	else
	{
		if (i + 1 <= j)
			result = min(result, calc(i + 1, j, 1 - p) - a[i]);
		if (i <= j - 1)
			result = min(result, calc(i, j - 1, 1 - p) - a[j]);
	}

	used[i][j][p] = true;
	dp[i][j][p] = result;
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << calc(0, n - 1, 0) << endl;
}