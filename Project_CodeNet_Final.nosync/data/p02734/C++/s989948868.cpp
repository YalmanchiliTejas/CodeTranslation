#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;
const int N = 3005;
const int mod = 998244353;

int a[N], f[N];

int main()
{
	int n, s;
	scanf("%d%d", &n, &s);

	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

	LL res = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] > s)continue;
		else if (a[i] == s)
		{
			res = (res + 1LL * i * (n - i + 1)) % mod;
		}
		else
		{
			res = (res + 1LL * f[s - a[i]] * (n - i + 1)) % mod;
			for (int j = s; j > a[i]; --j)
				(f[j] += f[j - a[i]]) %= mod;
			f[a[i]] = (f[a[i]] + i) % mod;
		}
	}
	printf("%lld\n", res);
	

	return 0;
}