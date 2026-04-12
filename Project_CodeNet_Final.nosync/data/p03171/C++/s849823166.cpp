#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[3001][3001][2];

ll solve(vector<int>& v, int i, int j, bool turn)
{
	if (i > j)//invalid subarray
		return 0;

	if (dp[i][j][turn] != -1)
		return dp[i][j][turn];

	if (turn == 1)
	{

		return dp[i][j][turn] = max(v[i] + solve(v, i + 1, j, 0), v[j] + solve(v, i, j - 1, 0));
	}
	else
		return dp[i][j][turn] = min(solve(v, i + 1, j, 1), solve(v, i, j - 1, 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	std::vector<int> v(n + 1);
	memset(dp, -1, sizeof dp);
	ll sum = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	ll scoreX = solve(v, 1, n, 1);
	ll scoreY = (sum - (scoreX));//X+Y=sum
	cout << scoreX - scoreY;
}