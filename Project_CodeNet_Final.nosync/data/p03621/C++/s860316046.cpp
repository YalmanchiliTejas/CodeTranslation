#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N = 1e5 + 5, mo = 998244353 ;
using namespace std ;

char A[N], B[N] ;
int fac[N], inv[N], G[N], W[N], n, rev[N], a[2][N] ;
inline void upd(int &x, int y) {
	x = (x + y) % mo ; 
}
inline int mul(int a, int b) {
	int ans = 1, w = a % mo ;
	for ( ; b; b /= 2) {
		if (b & 1) ans = (ll) ans * w % mo ;
		w = (ll) w * w % mo ;
	}
	return ans ;
}

void dft(int x, int fl) {
	int u, v, w, wn, inv3 = mul(3, mo - 2) ;
	rep(i, 0, n - 1) if (i < rev[i]) swap(a[x][i], a[x][rev[i]]) ;
	for (int i = 2 ; i <= n ; i <<= 1) {
		if (fl) wn = mul(inv3, (mo - 1) / i) ; else wn = mul(3, (mo - 1) / i) ;
		for (int j = 0 ; j < n ; j += i)
		  for (int w = 1, q = j ; q < j + i / 2 ; q ++ , w = (ll) w * wn % mo) {
			  u = a[x][q], v = (ll) a[x][q + i / 2] * w % mo ;
			  a[x][q] = (u + v) % mo, a[x][q + i / 2] = (u - v) % mo ;
		  }
	}
}

void ntt(const int A[N], const int B[N], int (&ret)[N], int na) {
	++ na ;
	for (n = 1 ; n <= na + na ; n <<= 1) ;
	rep(i, 0, n - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0) ;
	rep(i, 0, n - 1) a[0][i] = a[1][i] = 0 ;
	rep(i, 0, na - 1) a[0][i] = A[i], a[1][i] = B[i] ;
	dft(0, 0), dft(1, 0) ;
	rep(i, 0, n - 1) a[0][i] = (ll) a[0][i] * a[1][i] % mo ;
	dft(0, 1) ; int inv = mul(n, mo - 2) ;
	rep(i, 0, n - 1) ret[i] = 0 ;
	rep(i, 0, na - 1) ret[i] = (ll) a[0][i] * inv % mo ;
}

void solve(int m, int e) {
	fac[0] = 1 ;
	int mx = max(m + 1, m + e) ;
	rep(i, 1, mx) fac[i] = (ll) fac[i - 1] * i % mo ;
	inv[mx] = mul(fac[mx], mo - 2) ;
	for (int i = mx - 1; i >= 0; -- i) inv[i] = (ll) inv[i + 1] * (i + 1) % mo ;
	G[0] = 1 ;
	rep(i, 0, m) W[i] = inv[i + 1] ;
	int ans = 0 ;
	mx = m + e ;
	for ( ; e; e /= 2) {
		if (e & 1) ntt(G, W, G, m) ;
		ntt(W, W, W, m) ;
	}
	rep(i, 0, m) upd(ans, G[i]) ;
	ans = (ll) ans * fac[mx - m] % mo * fac[m] % mo * fac[mx] % mo ;
	printf("%d\n", (ans + mo) % mo) ;
}

int main() {
	scanf("%s%s", A + 1, B + 1) ;
	int n = strlen(A + 1), m = 0, e = 0 ;
	rep(i, 1, n) m += (A[i] == '1' && B[i] == '1'), e += (A[i] == '1' && B[i] == '0') ;
	solve(m, e) ;
	return 0 ;
}