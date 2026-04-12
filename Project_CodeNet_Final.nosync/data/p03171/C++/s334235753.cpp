#include <bits/stdc++.h>

#define N 3001

using namespace std;

int n;
bool p;
long long a[N];
long long dp[N][N];
long long vis[N][N] = {0};

long long solve(int i, int j)
{
	if (j < i)
		return 0;
	if (vis[i][j])
		return dp[i][j];
	vis[i][j] = 1;
	//cout << ((j - i + 1) & 1);
	if (((j - i + 1) & 1) == p)
		return dp[i][j] = max(a[i] + solve(i + 1, j), a[j] + solve(i, j - 1));
	return dp[i][j] = min(solve(i + 1, j) - a[i], solve(i, j - 1) - a[j]);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	p = n & 1;
	cout << solve(0, n - 1) << endl;
	return 0;
}
