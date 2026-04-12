#include<bits/stdc++.h>

#define pb push_back
#define fr first
#define sc second
#define ll long long

using namespace std;

const int N = 1e4 + 7;
const int mod = 1e9 + 7;

int dp[N][107][2];

int ad(int x)
{
	return ((x + mod) % mod);
}

main()
{
	string s;
	int m, n;
	
	cin >> s >> m;
	
	n = s.size();
	
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < int(s[0] - '0'); j++)
			{
				dp[i][j % m][1] += 1;
			}
			dp[0][int(s[0] - '0') % m][0] = 1;
			continue;
		}
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				dp[i][(j + k) % m][1] += dp[i - 1][j][1];
				dp[i][(j + k) % m][1] %= mod;
			}
			for (int k = 0; k < int(s[i] - '0'); k++)
			{
				dp[i][(j + k) % m][1] += dp[i - 1][j][0];
				dp[i][(j + k) % m][1] %= mod;
			}
			dp[i][((j + int(s[i] - '0')) % m)][0] += dp[i - 1][j][0];
			dp[i][((j + int(s[i] - '0')) % m)][0] %= mod;
		}
	}
	cout << ad((dp[n - 1][0][0] + dp[n - 1][0][1]) - 1) << endl;
}
/*
 * I will solve it in two way
	/					\
   /					 \
 Memory optimization    Time optimization
*/
