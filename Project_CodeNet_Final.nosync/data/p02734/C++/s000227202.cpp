#include <bits/stdc++.h>
using namespace std;
inline void read (int &x) {
	char ch = getchar(); x = 0;
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
} const int N = 3010, mod = 998244353;
int n, s, res, a[N], f[N];
#define Mod(a, b) ((a += b) >= mod && (a -= mod))
signed main() {
	read (n), read (s);
	for (int i = 1; i <= n; ++i) read (a[i]);
	for (int i = 1; i <= n; ++i) {
		if (a[i] < s) res = (res + 1ll * f[s - a[i]] * (n - i + 1)) % mod;
		if (a[i] == s) res = (res + 1ll * i * (n - i + 1)) % mod;
		for (int j = s; j >= a[i]; --j) Mod (f[j], f[j - a[i]]); Mod (f[a[i]], i);
	} return printf ("%d\n", res), 0;
}