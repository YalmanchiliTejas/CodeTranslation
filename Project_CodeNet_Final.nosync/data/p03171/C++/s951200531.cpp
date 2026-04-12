#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 998244353;
ll n, a[3010], dp[3010][3010];
const ll INF = 1000000000000000;

ll pow(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2)
	{
		return pow(x, y - 1) * x % mod;
	}
	else
	{
		ll yyy = pow(x, y / 2);
		return yyy * yyy % mod;
	}
}

ll div(ll x)
{
	return pow(x, mod - 2);
}

ll res(ll x, ll y)
{
	if (dp[x][y] != INF)
	{
		return dp[x][y];
	}
	else if (x == y)
	{
		return dp[x][y] = a[x] * (n % 2 == 1 ? 1 : -1);
	}
	else if ((n - (y - x)) % 2 == 1)
	{
		return dp[x][y] = max(res(x + 1, y) + a[x], res(x, y - 1) + a[y]);
	}
	else
	{
		return dp[x][y] = min(res(x + 1, y) - a[x], res(x, y - 1) - a[y]);
	}
}

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			dp[i][j] = INF;
		}
	}
	cout << res(1, n) << endl;
	cin >> n;
}
