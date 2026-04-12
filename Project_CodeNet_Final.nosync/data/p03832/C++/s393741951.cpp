#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
#define per(i, a, b) for (int i = a; i >= b; -- i)
const int mo = 1000000007, N = 1005;
using namespace std;
int n, A, B, C, D, fac[N], inv[N], g[N], f[N];
void upd(int &x, int y) { x = (x + y) % mo; }
int mul(int a, int b) {
	int ans = 1, w = a % mo;
	for ( ; b; b /= 2, w = (ll) w * w % mo) 
		if (b & 1) ans = (ll) ans * w % mo;
	return ans;
}
int main() {
	scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
	fac[0] = 1; rep(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mo;
	rep(i, 0, n) inv[i] = mul(fac[i], mo - 2);
	f[0] = 1;
	rep(i, A, B) {
		g[0] = 1;
		rep(j, 1, n / i) g[j] = (ll) g[j - 1] * inv[i] % mo; 
		per(j, n, 0) rep(k, max(1, C), min(n / i, D)) 
		if (j - k * i >= 0) 
			upd(f[j], (ll) f[j - k * i] * fac[n - (j - k * i)] % mo * g[k] % mo * inv[k] % mo * inv[n - j] % mo);
		else break;
	}
	printf("%d\n", f[n]);
	return 0;
}