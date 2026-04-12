#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
string s;
int d, n;
vector<int> v;
vector<vector<vector<ll>>> dp;

ll rec(int pos, int sum, int ok)
{
	if (pos == n)
	{
		if (sum % d == 0)
			return 1;
		return 0;
	}
	if (dp[pos][sum][ok] != -1)
		return dp[pos][sum][ok];
	int ans = 0, lim = 9;
	if (ok)
		lim = v[pos];
	for (int i = 0; i <= lim; i++)
	{
		if (i == v[pos])
			ans = (ans + rec(pos + 1, (sum + i) % d, ok)) % mod;
		else
			ans = (ans + rec(pos + 1, (sum + i) % d, 0)) % mod;
	}
	return dp[pos][sum][ok] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> s >> d;
	n = s.length();
	for (int i = 0; i < n; i++)
	{
		v.push_back(s[i] - '0');
	}
	dp.resize(n);
	for (int i = 0; i < n; i++)
	{
		dp[i].resize(d, vector<ll> (2, -1));
	}
	ll answer = rec(0, 0, 1);
	answer += (mod - 1);
	answer %= mod;
	cout << answer;

	return 0;
}