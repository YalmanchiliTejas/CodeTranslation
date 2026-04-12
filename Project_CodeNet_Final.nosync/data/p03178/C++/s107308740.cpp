#include<bits/stdc++.h>

#define pb push_back
#define fr first
#define sc second
#define ll long long

using namespace std;

const int N = 1e4 + 7;
const int mod = 1e9 + 7;

int dp[107][2], dp2[107][2];

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
	dp2[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		memset(dp, 0, sizeof(dp));
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				dp[(j + k) % m][1] += dp2[j][1];
				dp[(j + k) % m][1] %= mod;
			}
			for (int k = 0; k < int(s[i] - '0'); k++)
			{
				dp[(j + k) % m][1] += dp2[j][0];
				dp[(j + k) % m][1] %= mod;
			}
			dp[((j + int(s[i] - '0')) % m)][0] += dp2[j][0];
			dp[((j + int(s[i] - '0')) % m)][0] %= mod;
		}
		for (int j = 0; j < m; j++)
			dp2[j][0] = dp[j][0], dp2[j][1] = dp[j][1];
	}
	cout << ad((dp[0][0] + dp[0][1]) - 1) << endl;
}
/*
 * I will solve it in two way
	/					\
   /					 \
 Memory optimization    Time optimization
*/
