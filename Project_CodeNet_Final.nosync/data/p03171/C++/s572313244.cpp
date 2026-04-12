#include<bits/stdc++.h>
using namespace std;
long long dp[3001][3001] = {0};
int main()
{
	long long n, i, j, a[3001] = {0};
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> a[i];
		if(n % 2)
			dp[i][i] = a[i];
		else
			dp[i][i] = -a[i];
	}
	for(i = 2; i <= n; i++)
	{
		for(j = 0; j + i - 1 < n; j++)
		{
			if(i % 2 && n % 2 || (!(i % 2)) && (!(n % 2)))
			{
				dp[j][i + j - 1] = max(dp[j][i + j - 2] + a[j + i - 1], dp[j + 1][i + j - 1] + a[j]);
			}
			else
			{
				dp[j][i + j - 1] = min(dp[j][i + j - 2] - a[j + i - 1], dp[j + 1][i + j - 1] - a[j]);
			}
		}
	}
	cout << dp[0][n - 1];
	return 0;
}