#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;
const int mod = 998244353;

LL f[3030][3030][3];
int a[3030];

int main()
{
	int n, s;
	scanf("%d%d", &n, &s);

	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

	f[0][0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= s; ++j)
		{
			(f[i][j][0] += (f[i - 1][j][0])) %= mod;
			(f[i][j][1] += (f[i - 1][j][0] + f[i - 1][j][1])) %= mod;
			(f[i][j][2] += (f[i - 1][j][0] + f[i - 1][j][1] + f[i - 1][j][2])) %= mod;
			if (j - a[i] >= 0)
			{
				(f[i][j][1] += (f[i - 1][j - a[i]][0] + f[i - 1][j - a[i]][1])) %= mod;
				(f[i][j][2] += (f[i - 1][j - a[i]][0] + f[i - 1][j - a[i]][1])) %= mod;
			}
		}
	}

	printf("%lld\n", f[n][s][2]);

	return 0;
}