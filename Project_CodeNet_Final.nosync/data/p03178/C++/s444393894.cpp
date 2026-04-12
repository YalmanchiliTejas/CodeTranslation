#include <bits/stdc++.h>
using namespace std;
const int N = 10004, MOD = 1E9 + 7;
int dp[N][100][2], d;
vector<int> k;
string s;
int cal(int idx, int sum, int f)
{
	if (idx == k.size())
		return sum == 0;
	if (dp[idx][sum][f] != -1)
		return dp[idx][sum][f];
	int ans = 0, lim;
	if (f)
		lim = k[idx];
	else
		lim = 9;
	for (int i = 0; i <= lim ; ++i)
	{
		if (f)
		{
			if (i < lim)
				ans = (1LL * ans + cal(idx + 1, (sum + i) % d, 0)) % MOD;
			else
				ans = (1LL * ans + cal(idx + 1, (sum + i) % d, 1)) % MOD;
		}
		else
			ans = (1LL * ans + cal(idx + 1, (sum + i) % d, 0)) % MOD;
	}
	return dp[idx][sum][f] = ans;
}
int main(int argc, char const *argv[])
{
	memset(dp, -1, sizeof(dp));
	cin >> s;
	cin >> d;
	for (char c: s)
		k.push_back(c - '0');
	cout << (1LL * cal(0, 0, 1) - 1 + MOD) % MOD;
	return 0;
}
