#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 1e7 + 5;
const int P = 998244353;
int fac[N], ifac[N];

int Pow(int x, int t)
{
	int res = 1;
	for (; t; t >>= 1, x = 1LL * x * x % P)
		if (t & 1) res = 1LL * res * x % P;
	return res;
}

int C(int n, int m)
{
	if (n < m || m < 0) return 0;
	return 1LL * fac[n] * ifac[m] % P * ifac[n - m] % P;
}

int main()
{
	int n = read();
	
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = 1LL * i * fac[i - 1] % P;
	ifac[n] = Pow(fac[n], P - 2);
	for (int i = n; i >= 1; --i) ifac[i - 1] = 1LL * i * ifac[i] % P;
	
	int ans = Pow(3, n); 
	for (int i = n / 2 + 1; i <= n; ++i) 
		ans = (ans - 2LL * C(n, i) * Pow(2, n - i) % P + P) % P;
	printf("%d\n", ans);
	return 0;
}
