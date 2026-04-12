#include <bits/stdc++.h> 
#define ll long long
using namespace std; 

int main()
{
	ll int n;
	cin >> n;
	ll int a[n];
	ll int sum = 0;
	for (ll int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum = sum + a[i];
	}

	ll int dp[n][n];
	memset(dp, 0, sizeof(dp));


	for(ll int k = 0; k < n; k++)
	{
		for(ll int i=0, j = i+k; i<n and j<n; i++, j++)
		{
			if( i == j)
				dp[i][j] = a[i];
			else if (k == 1)
				dp[i][j] = max(a[i], a[j]);
			else
				dp[i][j] = max( a[i] + min( dp[i+1][j-1], dp[i+2][j] ) , a[j] + min( dp[i+1][j-1], dp[i][j-2] ) );
		}
	}

	cout << dp[0][n-1] - ( sum - dp[0][n-1] );
	
	return 0;
}