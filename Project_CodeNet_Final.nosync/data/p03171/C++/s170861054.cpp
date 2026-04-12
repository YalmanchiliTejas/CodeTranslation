#include <bits/stdc++.h>
using namespace std;
typedef long long lnt;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, a[3005];
lnt f[3005][3005];
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), f[i][i] = a[i];
	for (int d = 2; d <= n; d++)
		for (int l = 1, r = d; r <= n; l++, r++)
			f[l][r] = max(a[l]-f[l+1][r], a[r]-f[l][r-1]);
	return printf("%lld\n", f[1][n]), 0;
}
