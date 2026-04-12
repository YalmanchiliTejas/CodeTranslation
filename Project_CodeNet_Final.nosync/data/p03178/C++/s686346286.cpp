#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;
const int MAX_N = 10005;
const int MAX_D = 105;

string s;
int d;
ll dp[MAX_N][MAX_D][2];

int main()
{
	ios::sync_with_stdio(false);
	cin >> s >> d;
	int n = (int)s.length();

	dp[0][0][1] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < d; j++)
			for (int x = 0; x < 10; x++)
			{
				int nextJ = (j + x) % d;
				dp[i + 1][nextJ][0] = (dp[i + 1][nextJ][0] + dp[i][j][0]) % MOD;
				if (x == s[i] - '0')
					dp[i + 1][nextJ][1] = (dp[i + 1][nextJ][1] + dp[i][j][1]) % MOD;
				if (x < s[i] - '0')
					dp[i + 1][nextJ][0] = (dp[i + 1][nextJ][0] + dp[i][j][1]) % MOD;
			}

	cout << ((dp[n][0][0] + dp[n][0][1] - 1 + MOD) % MOD) << endl;
}