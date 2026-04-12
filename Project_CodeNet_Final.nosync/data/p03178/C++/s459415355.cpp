#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4+10;
const int maxd = 110;
const long long mod = 1e9+7;

typedef long long ll;

int n, d;

ll dp[maxn][maxd][3];

string num;

ll solve(int i, int m, int maior)
{
	if (i == n) return 0LL;
	if (dp[i][m][maior] != -1) return dp[i][m][maior];

	ll ans = 0LL;
	for (int j = 0; j <= 9; j++)
	{
		if (!i && !j) continue;

		int m1 = 2;
		if (maior == 1) m1 = 1;
		else if (!maior) m1 = 0;
		else if (j > ((int)num[i]-(int)'0')) m1 = 1;
		else if (j < ((int)num[i]-(int)'0')) m1 = 0;

		ll add = 0LL;

		if (i == n-1 && m1 != 1 && (m+j)%d == 0) add = 1LL;
		else if (i < n-1 && (m+j)%d == 0) add = 1LL;

		ans = (ans + add + solve(i+1, (m+j)%d, m1))%mod;
	}

	return dp[i][m][maior] = ans;
}

int main(void)
{
	cin >> num >> d;
	n = num.size();

	memset(dp, -1, sizeof dp);

	cout << solve(0, 0, 2) << "\n";
}