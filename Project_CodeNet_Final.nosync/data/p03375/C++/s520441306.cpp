#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 3005;

int n;

ll MOD,ans;
ll sum[MAXN];
ll pw2[MAXN * MAXN];
ll C[MAXN][MAXN];
ll S[MAXN][MAXN];

ll power(ll a,ll b,ll p)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= p;
		(a *= a) %= p;
		b >>= 1;
	}
	return res;
}

int main()
{
	scanf("%d%lld",&n,&MOD);
	for (int i = 0;i <= n;i++)
	{
		C[i][0] = S[i][0] = 1;
		for (int j = 1;j <= i;j++)
		{
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
			S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * (j + 1)) % MOD;
		}
	}
	pw2[0] = 1;
	for (int i = 1;i <= n * n;i++)
		pw2[i] = (pw2[i - 1] << 1) % MOD;
	for (int i = 0;i <= n;i++)
	{
		ll tot = 0;
		for (int j = 0;j <= i;j++)
			(tot += S[i][j] * pw2[(n - i) * j]) %= MOD;
		if (i & 1)
			(ans -= C[n][i] * power(2,power(2,n - i,MOD - 1),MOD) % MOD * tot) %= MOD;
		else
			(ans += C[n][i] * power(2,power(2,n - i,MOD - 1),MOD) % MOD * tot) %= MOD;
	}
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}