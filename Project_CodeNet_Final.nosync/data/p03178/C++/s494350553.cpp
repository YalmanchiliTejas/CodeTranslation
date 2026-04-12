#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	string K;
	int d;
	cin >> K >> d;

	int n = K.size();
	int dp[n][d][10];
	int sum[n][d];
	int mod = 1e9 + 7;

	for(int j = 0; j < d; j++)
	{
		sum[0][j] = 0;

		for(int k = 0; k < 10; k++)
		{
			dp[0][j][k] = (j == k % d);
			sum[0][j] += dp[0][j][k];
		}
	}

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < d; j++)
		{
			sum[i][j] = 0;
			for(int k = 0; k < 10; k++)
			{
				int prev_rest = (j - k + d * 10) % d;
				dp[i][j][k] = sum[i - 1][prev_rest];      

				sum[i][j] += dp[i][j][k];
				if(sum[i][j] > mod) sum[i][j] -= mod;
			}
		}
	}

	int ans = 0;
	int rest = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		int curr = K[n - 1 - i] - '0';
		if(i == 0) curr++;

		for(int k = 0; k < curr; k++)
		{
			ans += dp[i][rest][k];
			if(ans > mod) ans -= mod;
		}

		rest = (rest - curr + d) % d;
	}

	// 0 jest wliczone do wyniku
	cout << ans - 1 << "\n";
}
