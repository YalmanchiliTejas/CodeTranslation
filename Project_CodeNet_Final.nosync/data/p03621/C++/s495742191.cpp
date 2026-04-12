#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = (1 << 15) + 5;
const int mod = 998244353;

inline int power(int x, int p) {
	int res = 1;
	while (p) {
		if (p & 1) 
			res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		p >>= 1;
	}
	return res;
}

namespace NTT {
	const int G = 3;
	int g[maxn], R[maxn], a[maxn], b[maxn];
	int n, L, tmp;
	
	void ntt(int a[], int n, int flag) {
		rep (i, 0, n - 1)
			if (i < R[i]) swap(a[i], a[R[i]]);
				
		for (int d = 1, t = n >> 1; d < n; d <<= 1, t >>= 1)
			for (int i = 0; i < n; i += (d << 1))
				for (int j = 0; j < d; j++) {
					tmp = 1ll * g[!flag ? t*j : n - t*j] 
							  * a[i+j+d] % mod;
					a[i+j+d] = a[i+j] - tmp;
					if (a[i+j+d] < 0) a[i+j+d] += mod;
					a[i+j] = a[i+j] + tmp;
					if (a[i+j] >= mod) a[i+j] -= mod;
				}
		
		if (!flag) return;
		
		int rev = power(n, mod - 2);
		rep (i, 0, n - 1)
			a[i] = 1ll * a[i] * rev % mod;
	}
	
	void mul(int n, int N, int A[], int B[], int C[]) {
		rep (i, 0, N - 1) a[i] = A[i];
		rep (i, N, n - 1) a[i] = 0;
		rep (i, 0, N - 1) b[i] = B[i];
		rep (i, N, n - 1) b[i] = 0;
			
		ntt(a, n, 0);
		ntt(b, n, 0);
		
		rep (i, 0, n - 1)
			a[i] = 1ll * a[i] * b[i] % mod;
			
		ntt(a, n, 1);
		
		rep (i, 0, N - 1) C[i] = a[i];
		rep (i, N, n - 1) C[i] = 0;
	}
	
	void solve(int N, int x[], int p, int res[]) {
		for (n = 1; n <= 2 * N + 1; n <<= 1, L++);
		rep (i, 0, n - 1)
			R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
		g[0] = g[n] = 1;
		g[1] = power(G, (mod - 1) / n);
		rep (i, 2, n - 1)
			g[i] = 1ll * g[i-1] * g[1] % mod;
		
		res[0] = 1;
		while (p) {
			if (p & 1) mul(n, N, res, x, res);
			mul(n, N, x, x, x);	p >>= 1;
		}
	}
}

char s[maxn], t[maxn];
int A[maxn], B[maxn], fac[maxn], rev[maxn];
int n, x, y, ans;

int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	
	fac[0] = 1;
	rep (i, 1, n + 1) 
		fac[i] = 1ll * fac[i-1] * i % mod;
	rev[n+1] = power(fac[n+1], mod - 2);
	per (i, n, 0)
		rev[i] = 1ll * rev[i+1] * (i + 1) % mod;
	
	rep (i, 1, n)
		if (s[i] == '1' && t[i] == '1') x++;
		else if (s[i] == '1' && t[i] == '0') y++;
			
	rep (i, 0, x) A[i] = rev[i+1];
	NTT::solve(x + 1, A, y, B);
	
	rep (i, 0, x) {
		ans = ans + B[i];
		if (ans >= mod) ans -= mod;
	}
	
	ans = 1ll * ans * fac[x] % mod;
	ans = 1ll * ans * fac[y] % mod;
	ans = 1ll * ans * fac[x+y] % mod;
	
	cout << ans << endl;
	
	return 0;
}
