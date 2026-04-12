#include <bits/stdc++.h>
using namespace std;
#define maxn 4000
#define int long long
#define N 3500
int n, P, f[maxn][maxn];
int fac[maxn], ans, inv[maxn];

int read()
{
	int x = 0, k = 1;
	char c; c = getchar();
	while(c < '0' || c > '9') { if(c == '-') k = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * k;
}

void init()
{
	inv[1] = inv[0] = 1;
	for(int i = 2; i <= N; i ++)
		inv[i] = (P - P / i) * inv[P % i] % P;
	fac[0] = 1;
	for(int i = 1; i <= N; i ++)
		fac[i] = fac[i - 1] * i % P,
		inv[i] = inv[i - 1] * inv[i] % P;
}

void update(int &x, int y) { x = (x + y) % P; }

int C(int n, int m)
{
	if(m > n) return 0;
	return fac[n] * inv[m] % P * inv[n - m] % P;
}

int Qpow(int x, int times, int P)
{
	int base = 1;
	for(int i = times; i; x = x * x % P, i >>= 1)
		if(i & 1) base = base * x % P;
	return base;
}

void Get_DP()
{
	f[0][0] = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= i; j ++)
		{
			if(j) f[i][j] = f[i][j] + f[i - 1][j - 1] % P;
			f[i][j] = (f[i][j] + (j + 1) * f[i - 1][j] % P) % P;
		}
}

int DP(int i)
{
	int ret = 0;
	for(int j = 0; j <= i; j ++)
		update(ret, f[i][j] * Qpow(2, (n - i) * j % P, P));
	return ret;
}

signed main()
{
	n = read(), P = read();
	init(); Get_DP();
	for(int i = 0; i <= n; i ++)
	{
		int Mul = Qpow(2, Qpow(2, n - i, P - 1), P);
		if(i & 1) update(ans, (P - (Mul * C(n, i) % P * DP(i) % P)) % P);
		else update(ans, (Mul * C(n, i) % P * DP(i) % P) % P);
	}
	printf("%lld\n", ans);
	return 0;
}