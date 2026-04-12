#include<bits/stdc++.h>
using namespace std;
#define ll long long

//
ll n;
vector<ll>ar;
vector<vector<ll>>dp;
//

ll F(ll a, ll b)
{
	if (a == b + 1)
		return 0;
	if (a == b)
		return ar[a];
	if (dp[a][b] != -1)
		return dp[a][b];
	ll a1 = ar[a] - F(a + 1, b);
	ll a2 = ar[b] - F(a, b - 1);
	return (dp[a][b] = max(a1, a2));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; ar = vector<ll>(n);
	dp = vector<vector<ll>>(n, vector<ll>(n, -1));
	for (auto &it : ar)
		cin >> it;
	cout << F(0, n - 1);

	return 0;
}