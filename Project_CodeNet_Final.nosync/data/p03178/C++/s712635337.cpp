#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxK = 1e4 + 5, mxD = 110, mod = 1e9 + 7;
string K;
int n, D;
ll dp[mxK][mxD][2];
vector<int> digits;

ll rec(int idx, int sum, int flag)
{
	if (idx == n)
	{
		if (sum % D == 0)
			return 1;
		return 0;
	}
	if (dp[idx][sum][flag] != -1)
		return dp[idx][sum][flag];
	ll ans = 0;
	int lim = (flag == 1) ? digits[idx] : 9;
	for (int i = 0; i <= lim; i++)
	{
		if (i == digits[idx])
		{
			ans = (ans + rec(idx + 1, (sum + i) % D, flag)) % mod;
		}
		else
		{
			ans = (ans + rec(idx + 1, (sum + i) % D, 0)) % mod;
		}
	}
	return dp[idx][sum][flag] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> K >> D;
	for (auto it : K)
	{
		digits.push_back(it - '0');
	}
	n = digits.size();
	memset(dp, -1, sizeof(dp));
	ll answer = rec(0, 0, 1);
	answer -= 1;
	if (answer < 0)
		answer += mod;
	cout << answer;

	return 0;
}