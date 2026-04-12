#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll MAX = 3001;
ll dp[2][MAX][MAX];

int main(void)
{
	ll n;
	cin >> n;
	ll a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++)
	{
		dp[0][i][i] = a[i];
		dp[1][i][i] = 0;
	}

	for(int l = 2; l <= n; l++)
	{
		for(int i = 0; l + i <= n; i++)
		{
			int j = l + i - 1;
			dp[0][i][j] = max(a[i] + dp[1][i + 1][j], a[j] + dp[1][i][j - 1]);
			
			if(dp[0][i][j] == a[i] + dp[1][i + 1][j])
				dp[1][i][j] = dp[0][i + 1][j];
			else
				dp[1][i][j] = dp[0][i][j - 1];
		}
	}
	
	cout << dp[0][0][n - 1] - dp[1][0][n - 1] << endl;





	return 0;
}