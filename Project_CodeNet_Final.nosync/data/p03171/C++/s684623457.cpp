#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e3 + 5, mod = 1e9 + 7;

int a[N];
int dp[N][N];

int solve(int s, int e) {
	if (s > e)
		return 0;
	if (s == e)
		return a[s];

	if (dp[s][e] != -1)
		return dp[s][e];

	int op1 = a[s] + min(solve(s + 2, e), solve(s + 1, e - 1));
	int op2 = a[e] + min(solve(s, e - 2), solve(s + 1, e - 1));
	return dp[s][e] = max(op1, op2);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	//lets find max val of x hence y becomes sum - x;
	memset(dp, -1, sizeof dp);
	int X = solve(0, n - 1);
	int Y = sum - X;

	cout << X - Y << endl;

	return 0;
}