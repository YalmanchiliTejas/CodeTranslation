#include <bits/stdc++.h>
using namespace std;

const int maxN = 4e4 + 10, mod = 998244353, g = 3, gi = 332748118;

int n, m;
int lim, cnt, r[maxN + 1];
int f[205][8005];
int A[maxN + 1], B[maxN + 1];
int fac[maxN + 1], inv[maxN + 1];

inline int ADD(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }

inline int SUB(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }

inline int mpow(int a, int x)
{
	int ans = 1;
	while(x)
	{
		if(x & 1) ans = 1ll * ans * a % mod;
		a = 1ll * a * a % mod;
		x >>= 1;
	}
	return ans;
}

inline void NTT(int *a, int type)
{
	for(int i = 0; i < lim; i++)
		if(i < r[i]) swap(a[i], a[ r[i] ]);
	for(int mid = 1; mid < lim; mid <<= 1)
	{
		int wn = mpow(type == 1 ? g : gi, (mod - 1) / (mid << 1));
		for(int i = 0; i < lim; i += (mid << 1))
		{
			int w = 1;
			for(int j = 0; j < mid; j++, w = 1ll * w * wn % mod)
			{
				int x = a[i + j], y = 1ll * a[i + mid + j] * w % mod;
				a[i + j] = ADD(x, y); a[i + mid + j] = SUB(x, y);
			}
		}
	}
	if(type == -1)
	{
		int inv = mpow(lim, mod - 2);
		for(int i = 0; i < lim; i++) a[i] = 1ll * a[i] * inv % mod;
	}
}

inline int C(int n, int m)
{
	if(n < m) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main()
{
	scanf("%d %d", &n, &m);

	fac[0] = 1;
	for(int i = 1; i <= n + 5; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n + 5] = mpow(fac[n + 5], mod - 2);
	for(int i = n + 4; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;

	lim = 1, cnt = 0;
	while(lim <= n * 2) lim <<= 1, cnt ++;
	for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << cnt - 1);

	for(int i = 0; i <= n; i++) B[i] = inv[i + 3];
	NTT(B, 1);

	f[0][0] = 1;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j <= n; j++) A[j] = 1ll * f[i - 1][j] * inv[j] % mod;
		
		NTT(A, 1);
		for(int j = 0; j < lim; j++) A[j] = 1ll * A[j] * B[j] % mod;
		NTT(A, -1);

		f[i][0] = f[i - 1][0];
		for(int j = 1; j <= n; j++) 
			f[i][j] = ADD(1ll * fac[j + 2] * A[j - 1] % mod, 1ll * ADD(C(j + 1, 2), 1) * f[i - 1][j] % mod);

		for(int j = 0; j < lim; j++) A[j] = 0;
	}

	int ans = 0;
	for(int i = 0; i <= n; i++) ans = ADD(ans, 1ll * f[m][i] * C(n, i) % mod);

	printf("%d", ans);
	return 0;
}
