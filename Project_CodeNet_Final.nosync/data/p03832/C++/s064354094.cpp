#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>

#define lowbit(x) (x&(-x))
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e7;
const int maxn = 3e5 + 5;
ll mod = 1e9 + 7;

ll f[1005][1005];
ll g[1005], inv[1005], inv2[1005][1005];

ll ss(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1) (ans *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ans;
}

int n, A, B, C, D;

ll per(ll n, ll m)
{
	return g[n] * inv[n - m] % mod;
}

int main()
{
	g[0] = inv[0] = 1;
	for (int i = 1; i <= 1000; i++)
	{
		g[i] = g[i - 1] * i%mod;
		inv[i] = ss(g[i], mod - 2);
	}

	scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
	for (int i = A; i <= B; i++)
	{
		for (int j = C; j <= D; j++)
		{
			inv2[i][j] = ss(ss(g[i], j), mod - 2);
		}
	}
	f[A - 1][0] = 1;
	for (int i = A; i <= B; i++)
	{
		f[i][0] = 1;
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = f[i - 1][j];
			for (int k = C; k <= D && i*k<=j; k++)
			{
				f[i][j] += f[i - 1][j - i * k] * per(j, i*k) % mod * inv2[i][k] % mod *inv[k] % mod;
				if (f[i][j] >= mod) f[i][j] -= mod;
			}
		}
	}

	cout << f[B][n];
}