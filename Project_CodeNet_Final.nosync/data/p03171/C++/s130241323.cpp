#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[4000][4000];
int a[8000];
int solve(int l, int r)
{
	if(l > r || l <= 0 || r <= 0)
		return 0;
	if(l == r)
		return a[l];
	if(dp[l][r] != -1)
		return dp[l][r];
	if(r - l + 1 == 2)
		return max(a[l], a[r]);
	return dp[l][r] = max(a[l] + min(solve(l + 2, r), solve(l + 1, r - 1)), a[r] + min(solve(l + 1, r - 1), solve(l, r - 2)));
}
signed main()
{
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	for(int i = 0; i < n + 4; i++)
		for(int j = 0; j < n + 4; j++)
			dp[i][j] = -1;
	for(int i = 1; i <= n; i++)
		dp[i][i] = a[i];
	cout << 2*solve(1, n) - (sum)<< endl;
	
}
