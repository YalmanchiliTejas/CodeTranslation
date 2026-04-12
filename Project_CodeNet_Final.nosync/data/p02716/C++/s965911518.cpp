#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7, A = 2e5+5;
ll n, a[A], dp[A][3];
ll solve(int ind, int f)
{
	if (ind >= n)
		return (f == 2 ? -1e18 : 0);
	if (dp[ind][f] != -1e18)
		return dp[ind][f];
	ll val = -1e18;
	if (f) val = max(val, solve(ind + 1, f - 1));
	val = max(val, solve(ind + 2, f) + a[ind]);
	return dp[ind][f] = val;
}
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < A; i++)
		for (int j = 0; j < 3; j++)
				dp[i][j] = -1e18;
	cout << solve(0, 1 + (n % 2));
	return 0;
}
