#include <bits/stdc++.h>

#define SZ(x) (((int)x.size()))
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

using namespace std;

const int maxn = 200*1000+10;
const ll inf = 1000000000000000000;
ll dp[maxn][2];
int a[maxn], n;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		dp[i][0] = dp[i][1] = -inf;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dp[1][0] = 0;
	dp[1][1] = a[0];
	for (int i = 2; i <= n; i++)
	{
		if (i & 1)
		{
			dp[i][0] = max(dp[i - 1][0], a[i - 1] + dp[i - 2][0]);
			dp[i][1] = a[i - 1] + dp[i - 2][1];
		}
		else
			dp[i][0] = max(dp[i - 1][1], a[i - 1] + dp[i - 2][0]);
	}
	cout << dp[n][0];
	return 0;
}
