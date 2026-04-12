#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
int a[3001];
int dp[3001][3001][2];
int n, s;
int main(void)
{
	cin >> n >> s;
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int x=1;x<=s;x++)
		{
			dp[i][x][1] = dp[i-1][x][1];
			if(x == a[i]) dp[i][x][1] += i;
			else if(x > a[i]) dp[i][x][1] += dp[i-1][x-a[i]][1];
			dp[i][x][1] %= MOD;
			dp[i][x][0] = dp[i-1][x][0] + dp[i][x][1];
			dp[i][x][0] %= MOD;
		}
	}
	cout << dp[n][s][0] << endl;
	return 0;
}
