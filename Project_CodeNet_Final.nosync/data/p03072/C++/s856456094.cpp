#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void)
{
	int n, ans = 1;
	cin >> n;
	int h[21];
	int dp[21];

	for (int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}

	dp[0] = h[0];

	for (int i = 1; i < n; ++i)
	{
		if (dp[i - 1] <= h[i])
			++ans;
		dp[i] = max(dp[i - 1], h[i]);
	}

	cout << ans;

	return 0;
}