#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
int read() {
	int x = 0, f = 1; char ch;
	while(! isdigit(ch = getchar())) (ch == '-') && (f = -f);
	for(x = ch ^ 48; isdigit(ch = getchar()); x = (x << 3) + (x << 1) + (ch ^ 48));
	return x * f;
}
template <class T> T Max(T a, T b) { return a > b ? a : b; }
template <class T> T Min(T a, T b) { return a < b ? a : b; }
char s[N];
int n, m, k = 2e9, ans, a[N], b[N], f[N];
signed main() {
	n = read(); m = read(); scanf("%s", s + 1);
	int tag = 1;
	for(int i = 1, len = 0; i <= m; ++ i) {
		if(s[i] != s[1]) {
			if(tag || len & 1) k = min(k, len / 2 + 1);
			tag = len = 0;
		}
		else ++ len;
	}
	if(tag) {
		f[0] = 0; f[1] = 1;
		for(int i = 2; i <= n; ++ i) f[i] = (f[i - 1] + f[i - 2]) % mod;
		printf("%lld\n", (2 * f[n - 1] + f[n]) % mod);
		return 0;
	}
	if(n & 1) return puts("0"), 0;
	n /= 2;// k = min(k, n);
	a[0] = b[0] = 1;
	for(int i = 1; i <= n; ++ i) {
		a[i] = b[i - 1];
		if(i > k) a[i] = ((a[i] - b[i - k - 1]) % mod + mod) % mod;
		b[i] = (b[i - 1] + a[i]) % mod; 
	}
	for(int i = 1; i <= k; ++ i) ans = (ans + 2 * i * a[n - i]) % mod;
	printf("%lld\n", ans);
	return 0;
}