#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int N = 3e3 + 5;

int S[N][N], fac[N], ifac[N], inv[N];

inline int ksm(int a, int b, const int& mod) {
	int ans = 1; 
	for (; b; b >>= 1, a = 1ll * a * a % mod) 
		if (b & 1) ans = 1ll * ans * a % mod;
	return ans;
}

inline int binom(int n, int m, const int& mod) {
	if (n < m || n < 0 || m < 0) return 0;
	if (n == 0 || m == 0) return 1; 
	return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

int add(int a, int b, const int& mod) {return a += b, a >= mod ? a - mod : a;}
int sub(int a, int b, const int& mod) {return a -= b, a < 0 ? a + mod : a;}

int main() {
	S[0][0] = 1; int n, mod; scanf("%d%d", &n, &mod);
	inv[0] = ifac[0] = fac[0] = inv[1] = fac[1] = ifac[1] = 1;
	for (int i = 2; i < N; ++i) {
		inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
		fac[i] = 1ll * fac[i - 1] * i % mod;
		ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
	}
	for (int i = 1; i < N; ++i) 
		for (int j = 1; j <= i; ++j) 
			S[i][j] = (1ll * S[i - 1][j] * j % mod + S[i - 1][j - 1]) % mod;
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		 int sum = 0;
		 for (int j = 0; j <= i; ++j) {
		 	int val = ksm(2, 1ll * j * (n - i) % (mod - 1), mod);
		 	val = 1ll * val * S[i + 1][j + 1] % mod;
			sum = (sum + val) % mod;
		}
		if (i & 1) ans = sub(ans, 1ll * sum * ksm(2, ksm(2, n - i, mod - 1), mod) % mod * binom(n, i, mod) % mod, mod); 
		else ans = add(ans, 1ll * sum * ksm(2, ksm(2, n - i, mod - 1), mod) % mod * binom(n, i, mod) % mod, mod);
	}
	printf("%d\n", ans);
	return 0;
}