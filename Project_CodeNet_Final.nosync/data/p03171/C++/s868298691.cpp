#include <bits/stdc++.h>

#define N 3001

using namespace std;

int n;
bool p;
long long a[N];
long long dp[N][N];

long long solve2()
{
	for (int len = 1; len <= n; len++)
	{
		for (int i = 0; i <= n - len; i++)
		{
			int j = i + len - 1;
			int s = ((j - i + 1) & 1) == p;
			if (i == j)
				dp[i][j] = (s == 1 ? 1 : -1) * a[i];
			else if (s == 1)
				dp[i][j] = max(a[i] + dp[i + 1][j], a[j] + dp[i][j - 1]);
			else
				dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j]);
		}
	}
	return dp[0][n - 1];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	p = n & 1;
	cout << solve2() << endl;
	return 0;
}
