#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <algorithm>
#define N 201000
typedef long long ll;
template <typename T> inline void read(T &x) {
	x = 0; char c = getchar(); bool flag = false;
	while (!isdigit(c)) { if (c == '-')	flag = true; c = getchar(); }
	while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	if (flag)	x = -x;
}
using namespace std;
const int P = 1e9 + 7;
const int inf = 987654321;
inline void MIN(int &a, int b) {
	if (b < a)	a = b;
}
int n, m;
char s[N];
namespace jzp1 {
	ll jie[N], jieni[N];
	inline ll get_c(int n, int m) {
//		printf("get_c(%d, %d)\n", n, m);
		if (n < 0 || m < 0 || n - m < 0)	return 0;
//		printf("get_c(%d, %d)\n", n, m);
		return jie[n] * jieni[m] % P * jieni[n - m] % P;
	}
	inline ll quickpow(ll x, int k) {
		ll res = 1;
		while (k) {
			if (k & 1)	res = res * x % P;
			x = x * x % P;
			k >>= 1;
		}
		return res;
	}
	inline void sol() {
//		while(1);
		if (n == 1) { puts("1"); return ; }
		jie[0] = jieni[0] = 1;
		int up = n + 1;
		for (int i = 1; i <= up; ++i)	jie[i] = jie[i - 1] * i % P;
		jieni[up] = quickpow(jie[up], P - 2);
		for (int i = up - 1; i; --i)	jieni[i] = jieni[i + 1] * (i + 1) % P;
		ll res = 0;
		for (int i = 0; i <= n; ++i) {
			res = (res + get_c(n - i + 1, i) - get_c(n - i - 1, i - 2)) % P;
//			printf("res = %lld\n", res);
		}
		printf("%lld\n", (res % P + P) % P);
	}
}
ll f[N];
ll sum[N];
int main() {
	read(n), read(m);
	scanf("%s", s + 1);
	bool flag = false;
	int tmp = 0;
	for (int i = 1; i <= m; ++i)	if (s[i] != s[1]) { flag = true; tmp = i - 1; break; }
	if (!flag) { jzp1::sol(); return 0; }
	if (n & 1) { puts("0"); return 0; }
	int lst = 1, mn = tmp | 1;
	for (int i = 2; i <= m; ++i) {
//		printf("i = %d, mn = %d\n", i, mn);
		if (s[i] != s[1]) {
			if (lst & 1)	MIN(mn, lst);
			lst = 0;
			continue;
		}
		if (s[i] == s[i - 1])	++lst;
		else {
			if (lst & 1) MIN(mn, lst);
			lst = 1;
		}
	}
	if (mn == inf) {
//		while (1);
		int memo = 1;
		for (int i = 1; s[i] == s[1]; ++i) memo = i;
		mn = memo + 1;
		printf("memo = %d\n", memo);
	}
	n >>= 1;
	int k = (mn + 1) >> 1;
	MIN(k, n);
	f[0] = 1; sum[0] = 1;
//	printf("n = %d, k = %d\n", n, k);
	for (int i = 1; i <= n; ++i) {
		if (i <= k)	f[i] = sum[i - 1];
		else f[i] = (sum[i - 1] - sum[i - k - 1]) % P;
		sum[i] = (sum[i - 1] + f[i]) % P;
	}
	ll ans = 0, mx = k;
	const int mod = 1e9 + 7;
		for(int i = 0 ; i <= n ; ++i)
		if(n - i <= mx) (ans += (ll)f[i] * (n - i) % mod * 2 % mod) %= mod;
//	ll ans = 0;
//	for (int i = 1; i <= k; ++i) {
//		ans = (ans + f[n - i] * i) % P;
//	}
//	ans = (ans << 1) % P;
	printf("%lld\n", (ans % P + P) % P);
	return 0;
}

/*
3 3
BBB
//4

1 1
B
//1

12 10
RRRRBRRRRB
//78

6 5
RRBBR
//8
*/