#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

string k;
int n, d;
ll dp[10010][110][2];

ll F(int idx, int cursum, bool eq)
{
	if (idx == n)
		return (cursum == 0);
	if (dp[idx][cursum][eq] != -1)
		return dp[idx][cursum][eq];
	ll ans = 0;
	if (eq)
	{
		int dig = k[idx] - '0';
		for (int i = 0; i < dig; i++)
			ans = (ans + F(idx + 1, (cursum + i) % d, 0)) % MOD;
		ans = (ans + F(idx + 1, (cursum + dig) % d, 1)) % MOD;
	}
	else
	{
		for (int i = 0; i <= 9; ++i)
			ans = (ans + F(idx + 1, (cursum + i) % d, 0)) % MOD;
	}
	return (dp[idx][cursum][eq] = ans);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> k; cin >> d;
	n = k.length();
	memset(dp, -1, sizeof(dp));
	cout << ((F(0, 0, 1) - 1) % MOD + MOD) % MOD;

	return 0;
}