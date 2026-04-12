#pragma GCC optimize ("Ofast")

#include <cstdio>
#include <cstring>

const int MAX_N = 3e3 + 5;
const int MOD = 998244353;
const int INV = 499122177;

int n, s, a[MAX_N], t[MAX_N], f[MAX_N][MAX_N], g[MAX_N][MAX_N], ans;

void add(int *a, int *b)
{
	for (int i = 0; i < MAX_N; ++i)
		(a[i] += b[i]) %= MOD;
}

int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		memcpy(f[i], f[i - 1], MAX_N * sizeof(int));
		memset(t, 0x00, a[i] * sizeof(int));
		memcpy(t + a[i], f[i], (MAX_N - a[i]) * sizeof(int));
		(t[a[i]] *= i) %= MOD;
		add(f[i], t);
		//printf("f[%d] = %d\n", i, f[i][s]);
		(ans += f[i][s]) %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}