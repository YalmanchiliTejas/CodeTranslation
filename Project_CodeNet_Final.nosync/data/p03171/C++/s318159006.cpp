#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 3e3 + 5;
int n, a[M], dp[M][M][2];

int solve(int i, int j, int turn)
{
	if(i == j)	return (!turn ? a[i] : -a[i]);

	if(dp[i][j][turn] != -1)	return dp[i][j][turn];

	int c1 = (turn ? -a[i] : a[i]) + solve(i + 1, j, turn ^ 1);
	int c2 = (turn ? -a[j] : a[j]) + solve(i, j - 1, turn ^ 1);
	int ans = max(c1, c2);
	if(turn)
		ans = min(c1, c2);

	return dp[i][j][turn] = ans;	
}

int32_t main() 
{
	ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)	cin >> a[i];
	memset(dp, -1, sizeof dp);
	cout << solve(0, n - 1, 0) << "\n";
    return 0;
}
