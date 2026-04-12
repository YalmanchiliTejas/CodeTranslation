#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll max_score(vector<ll>&score, ll i, ll j, vector<vector<ll>>&dp)
{
	if (i > j)
	{
		return 0;
	}

	//Lookup
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}

	ll op1 = score[i] + min(max_score(score, i + 2, j, dp), max_score(score, i + 1, j - 1, dp));
	ll op2 = score[j] + min(max_score(score, i + 1, j - 1, dp), max_score(score, i, j - 2, dp));
	ll ans = max(op1, op2);
	return dp[i][j] = ans;

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin >> n;
	vector<ll>score(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++)
	{
		ll d;
		cin >> d;
		score[i] = d;
		sum += d;
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, -1));
	//cout << sum;
	ll T_score = max_score(score, 0, n - 1, dp);
	ll J_score = sum - T_score;
	cout << T_score - J_score << endl;
	return 0;

}