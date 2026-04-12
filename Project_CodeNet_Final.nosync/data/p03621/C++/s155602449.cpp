#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include <set>
#include <map>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
#define ev g[i].y
#define eps 1e-10
using namespace std;
typedef long long ll;
typedef double db;
const int N = 20005, mod = 998244353;
char A[N], B[N];
int n, m, len;
ll fac[N], inv[N], f[2][N], ans;
ll mypow(ll x, int y) {
	ll z = 1;
	while (y) {
		if (y & 1) (z *= x) %= mod;
		y >>= 1; (x *= x) %= mod;
	}
	return z;
}
ll sqr(ll x) { return x * x % mod; }
ll C(int x, int y) { return fac[x] * inv[y] % mod * inv[x - y] % mod; }
int main()
{
	scanf ("%s%s", A + 1, B + 1);
	len = strlen(A + 1);
	fac[0] = 1;
	Rep(i, 1, len) fac[i] = fac[i - 1] * i % mod;
	inv[len] = mypow(fac[len], mod - 2);
	Dwn(i, len, 1) inv[i - 1] = inv[i] * i % mod;
	Rep(i, 1, len) if (A[i] == '1') {
		if (B[i] == '1') n ++;
		else m ++;
	}
	// f[0][0] = 1;
	Rep(i, 0, n) {
		bool u = i & 1;
		if (i) {
			Rep(j, 0, m) f[u][j] = f[u ^ 1][j] * i * j % mod;
		} else f[u][0] = 1;
		Rep(j, 1, m) (f[u][j] += f[u][j - 1] * j * j) %= mod;
		// cout << i<<" "<<f[u][m]<<endl;
		(ans += f[u][m] * C(n, i) % mod * C(n + m, i + m) % mod * sqr(fac[n - i])) %= mod;
	}
	printf("%lld\n", ans);

	return 0;
}