#include <cstdio>
#define LL long long
#define F(i, a, b) for (int i = a; i <= b; ++i)

const int MS = 2e5 + 5, mod = 1e9 + 7;
int n, a[MS];

int main()
{
	scanf("%d", &n);
	LL sum = 0, sq = 0;
	F(i, 1, n)
	{
		scanf("%d", &a[i]);
		sum = (sum + a[i]) % mod;
		sq = (sq + (LL)a[i] * a[i]) % mod;
	}
	printf("%lld", (sum * sum % mod - sq + mod) % mod * (mod + 1) / 2 % mod);
	return 0;
}
