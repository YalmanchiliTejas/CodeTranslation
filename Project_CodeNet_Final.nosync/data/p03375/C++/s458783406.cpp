#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 3005
#define ll long long
void Read(int &p)
{
	p = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
}
int n, mod, fac[N], inv[N], S[N][N];
int Pow(int a, int k, int m)
{
	if (!k)
		return 1;
	int p = Pow(a, k / 2, m);
	if (k & 1)
		return (ll)p * p % m * a % m;
	return (ll)p * p % m;
}
int C(int n, int m)
{
	if (n < m)return 0;
	if (m < 0)return 0;
	return (ll)fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
	Read(n), Read(mod);
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (ll)fac[i - 1] * i % mod;
	inv[n] = Pow(fac[n], mod - 2, mod);
	for (int i = n; i >= 1; i--)
		inv[i - 1] = (ll)inv[i] * i % mod;
	S[0][0] = 1;
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= i; j++)
			S[i][j] = (S[i - 1][j - 1] + (ll)j * S[i - 1][j]) % mod;
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		int sum = 0;
		for (int x = 0; x <= i; x++)
			sum = (sum + (ll)Pow(Pow(2, n - i, mod), x, mod) * S[i + 1][x + 1] % mod) % mod;
		sum = (ll)sum * Pow(2, Pow(2, n - i, mod - 1), mod) % mod * C(n, i) % mod;
		if (i & 1)
			ans = (ans + mod - sum) % mod;
		else
			ans = (ans + sum) % mod;
	}
	printf("%d\n", ans);
}
