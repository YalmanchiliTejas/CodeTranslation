#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, m, k = 2e9, a[N], b[N], ans, f[N];
char s[N];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
signed main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read(); m = read(); scanf("%s", s + 1);
	int tag = 1;
	for(int i = 1, len = 0; i <= m; i ++)
	{
		if(s[i] != s[1])
		{
			if(tag || len & 1) k = min(k, len / 2 + 1);
			tag = len = 0;
		}
		else len ++;
	}
	if(tag)
	{
		f[0] = 0; f[1] = 1;
		for(int i = 2; i <= n; i ++) f[i] = (f[i - 1] + f[i - 2]) % mod;
		printf("%lld\n", (2 * f[n - 1] + f[n]) % mod);
		return 0;
	}
	if(n & 1) {puts("0"); return 0;}
	n /= 2; a[0] = b[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		a[i] = b[i - 1];
		if(i > k) a[i] = (b[i - 1] - b[i - k - 1] + mod) % mod;
		b[i] = (b[i - 1] + a[i]) % mod;
	}
	for(int i = 1; i <= k; i ++) ans = (ans + 2 * i * a[n - i]) % mod;
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
