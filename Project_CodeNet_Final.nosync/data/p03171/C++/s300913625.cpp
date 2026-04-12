#include <bits/stdc++.h>
#define int long long
using namespace std;
struct cell
{
	int first, second;
};
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	cell dp[n][n];

	for (int i = 0; i < n; i++)
	{
		dp[i][i].first = arr[i];
		dp[i][i].second = 0;
	}
	for (int len = 2; len <= n; len++)
	{
		for (int i = 0; i < n - len + 1; i++)
		{
			int j = i + len - 1;
			if (arr[i] + dp[i + 1][j].second > arr[j] + dp[i][j - 1].second)
			{
				dp[i][j].first = arr[i] + dp[i + 1][j].second;
				dp[i][j].second = dp[i + 1][j].first;
			}
			else
			{
				dp[i][j].first = arr[j] + dp[i][j - 1].second;
				dp[i][j].second = dp[i][j - 1].first;
			}
		}
	}
	cout << dp[0][n-1].first - dp[0][n-1].second;

	return 0;
}