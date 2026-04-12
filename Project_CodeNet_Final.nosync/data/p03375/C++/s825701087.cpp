#include <bits/stdc++.h>
#define MAX_N 3000
using namespace std;
typedef long long lnt;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-48);
}
int n; lnt P, C[MAX_N+5][MAX_N+5];
lnt f[MAX_N+5], g[MAX_N+5][MAX_N+5];
lnt Pow(lnt x, lnt k, lnt P) {
	lnt ret = 1;
	for (; k; k >>= 1, x = x*x%P)
		if (k&1) ret = ret*x%P;
	return ret;
}
int main() {
	read(n), read(P);
	for (int i = 0; i <= n; i++) C[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i-1][j-1]+C[i-1][j])%P;
	for (int i = 0; i <= n; i++) g[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			g[i][j] = (g[i-1][j-1]+g[i-1][j]*(j+1)%P)%P;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++)
			(f[i] += g[i][j]*Pow(2, (n-i)*j, P)%P) %= P;
	for (int i = 0; i <= n; i++)
		(f[i] *= Pow(2, Pow(2, n-i, P-1), P)) %= P;
	lnt tot = 0;
	for (int i = 0; i <= n; i++)
		(tot += Pow(-1, i, P)*C[n][i]*f[i]%P) %= P;
	return printf("%lld\n", (tot+P)%P), 0;
}
