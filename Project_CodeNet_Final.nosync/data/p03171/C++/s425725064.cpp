#include <bits/stdc++.h>
using namespace std;
const int N = 3003;
int n;
long long a[N], ans[N][N][2], sum[N][N];
long long solve(int l, int r, int f)
{
	if (l > r)
		return 0;
	if (l == r)
		return ans[l][r][f] = a[l];
	if (ans[l][r][f] != -1)
		return ans[l][r][f];
	long long left = a[l] + sum[l + 1][r] - solve(l + 1, r, 1 - f);
	long long right = a[r] + sum[l][r - 1] - solve(l, r - 1, 1 - f);
	return ans[l][r][f] = max(left, right);
}
int main(int argc, char const *argv[])
{
	memset(ans, -1, sizeof(ans));
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		long long s = 0;
		for (int j = i; j < n; ++j)
		{
			s += a[j];
			sum[i][j] = s;
		}
	}
	solve(0, n - 1, 0);
	printf("%lld", 2 * ans[0][n - 1][0] - sum[0][n - 1]);

	return 0;
}