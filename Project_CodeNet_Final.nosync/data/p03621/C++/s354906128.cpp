#if 0
2019.08.07

#endif
#include <cstdio>
#include <cstring>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;
inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 10001, mod = 998244353;
int f[maxn];
char s[maxn], t[maxn];
int jie[maxn];

inline lolong power(lolong x, int k) {
	if(k < 0) k += mod - 1;
	lolong res = 1;
	while(k) {
		if(k & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return res;
}

inline lolong C(int n, int m) {
	return jie[n] * power(jie[n - m], -1) % mod * power(jie[m], -1) % mod;
}

int main() {
	scanf("%s", s);
	scanf("%s", t);
	int n = strlen(s), a = 0, b = 0;
	for(int i = 0; i < n; i ++)
		if(s[i] == '1' and t[i] == '1')
			a ++;
		else if(s[i] == '1')
			b ++;
	jie[0] = 1;
	for(int j = 1; j <= n; j ++)
		jie[j] = 1ll * jie[j - 1] * j % mod;
	for(int j = 0; j <= b; j ++)
		f[j] = 1ll * jie[j] * jie[j] % mod;
	int ans = 1ll * f[b] * jie[a] % mod * jie[a] % mod *
			C(a, a) % mod * C(a + b, a) % mod;
	for(int i = 1; i <= a; i ++) {
		// f[0] = (1ll * f[0] * i * i) % mod;
		f[0] = 0;
		for(int j = 1; j <= b; j ++)
			f[j] = (1ll * f[j - 1] * j * j + 1ll * f[j] * i * j) % mod;
		ans = (1ll * f[b] * jie[a - i] % mod * jie[a - i] % mod *
				C(a, a - i) % mod * C(a + b, a - i) + ans) % mod;
	}
	printf("%d\n", ans);
}
