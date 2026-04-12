#include "bits/stdc++.h"
using namespace std;
#define fst first
#define scd second
long long dp[101][5][2];
int main()
{
	string n;
	int k;
	cin >> n >> k;
	dp[0][0][1] = 1;
	for(int i = 0; i < n.size(); ++i)
	{
		for(int j = 0; j <= k; ++j)
		{
			for(int l = 0; l < 2; ++l)
			{
				for(int m = (l ? n[i] - '0' : 9); m > 0; --m)
				{
					dp[i + 1][j + 1][l & (m == n[i] - '0')] += dp[i][j][l];
				}
				dp[i + 1][j][l & (0 == n[i] - '0')] += dp[i][j][l];
			}
		}
	}
	cout << dp[n.size()][k][0] + dp[n.size()][k][1] << "\n";
}
