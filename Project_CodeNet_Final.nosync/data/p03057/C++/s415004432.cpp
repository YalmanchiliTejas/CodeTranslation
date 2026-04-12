#include <bits/stdc++.h>

typedef long long ll;
const int N = 100054, mod = 1000000007;

int n, m, L;
int f[N];
char s[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void sub(int &x, const int y) {x -= y, x += x >> 31 & mod;}

int main() {
	int i, j, u, v, ans = 0;
	scanf("%d%d%s", &L, &n, s);
	for (i = 0; i < n; ++i) s[i] = s[i] >> 4 & 1;
	if (*s) for (i = 0; i < n; ++i) s[i] ^= 1;
	for (j = 0; j < n && !s[j]; ++j);
	if (j == n) {
		for (u = 2, v = i = 1; i < L; ++i) j = u, u = v, add(v, j);
		return printf("%d\n", v), 0;
	}
	if (L & 1) return putchar(48), putchar(10), 0;
	m = j | 1, L /= 2;
	for (i = j + 1; i < n; ++i) if (s[i]) (i ^ j) & 1 || (down(m, i - j - 1), 0), j = i;
	assert(m & 1), m = (m + 1) / 2;
	for (f[1] = *f = i = 1; i < L; ++i)
		if (add(f[i + 1] = f[i], f[i]), i >= m) sub(f[i + 1], f[i - m]);
	for (i = std::max(L - m, 0); i < L; ++i) ans = (ans + ll(L - i) * f[i]) % mod;
	printf("%d\n", ans * 2 % mod);
	return 0;
}