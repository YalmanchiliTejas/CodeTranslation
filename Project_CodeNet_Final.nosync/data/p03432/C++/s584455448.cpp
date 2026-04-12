/************************************************
 * Au: Hany01
 * Date: Feb 13th, 2019
 * Prob: agc021f
 * Email: hany01dxx@gmail.com & hany01@foxmail.com
 * Inst: Yali High School
************************************************/

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
#define Rep(i, j) for (register int i = 0, i##_end_ = (j); i < i##_end_; ++ i)
#define For(i, j, k) for (register int i = (j), i##_end_ = (k); i <= i##_end_; ++ i)
#define Fordown(i, j, k) for (register int i = (j), i##_end_ = (k); i >= i##_end_; -- i)
#define Set(a, b) memset(a, b, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define X first
#define Y second
#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(), a.end()
#define INF (0x3f3f3f3f)
#define INF1 (2139062143)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define y1 WoXiHuanNiA

template <typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> inline T read() {
	register T _, __; register char c_;
    for (_ = 0, __ = 1, c_ = getchar(); c_ < '0' || c_ > '9'; c_ = getchar()) if (c_ == '-') __ = -1;
    for ( ; c_ >= '0' && c_ <= '9'; c_ = getchar()) _ = (_ << 1) + (_ << 3) + (c_ ^ 48);
    return _ * __;
}
//EOT


const int MAXN = 8005, MAXM = 205, MOD = 998244353, MAXN_ = (1 << 14) + 1, g0 = 3;
int ig0;

int fpm(int a, int b = MOD - 2) {
	int ans = 1;
	for ( ; b; b >>= 1, a = (LL)a * a % MOD)
		if (b & 1) ans = (LL)ans * a % MOD;
	return ans;
}
void inc(int &x, int y) {
	if ((x += y) >= MOD) x -= MOD;
}
int plu(int x, int y) {
	return (x += y) >= MOD ? x - MOD : x;
}

int fac[MAXN], ifac[MAXN];
void Init(int n) {
	fac[0] = 1;
	For(i, 1, n) fac[i] = (LL)fac[i - 1] * i % MOD;
	ifac[n] = fpm(fac[n]);
	Fordown(i, n, 1) ifac[i - 1] = (LL)ifac[i] * i % MOD;
}
int C(int n, int m) {
	if (n < m) return 0;
	return (LL)fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}


int pwg[MAXN_], ipwg[MAXN_], rev[MAXN_];
void NTT(int *a, int n, int ty) {
	Rep(i, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 2, p = 1; i <= n; p = i, i <<= 1) {
		int wn = ty == 1 ? pwg[i] : ipwg[i];
		for (int j = 0; j < n; j += i) {
			int w = 1;
			Rep(k, p) {
				int x = a[j + k], y = (LL)a[j + k + p] * w % MOD;
				a[j + k] = plu(x, y);
				a[j + k + p] = (LL)plu(x, MOD - y);
				w = (LL)w * wn % MOD;
			}
		}
	}
	if (ty == -1) {
		int inv = fpm(n);
		Rep(i, n) a[i] = (LL)a[i] * inv % MOD;
	}
}


int main() {
#ifdef hany01
	freopen("agc021f.in", "r", stdin);
	freopen("agc021f.out", "w", stdout);
#endif

	static int n, m, N, pt, f[2][MAXN_], g[MAXN_];

	n = read<int>(), m = read<int>();

	Init(n + 2);

	ig0 = fpm(g0);
	for (N = 1, pt = 0; N <= (n << 1); ) {
		N <<= 1, ++ pt;
		pwg[N] = fpm(g0, (MOD - 1) / N);
		ipwg[N] = fpm(ig0, (MOD - 1) / N);
	}
	Rep(i, N) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (pt - 1));

	int t = 0;
	f[0][0] = 1;
	For(i, 1, n) g[i] = ifac[i + 2];
	NTT(g, N, 1);

	For(j, 0, m - 1) {
		For(i, 0, n) f[t ^ 1][i] = (LL)f[t][i] * ifac[i] % MOD;
		For(i, n + 1, N - 1) f[t ^ 1][i] = 0;
		NTT(f[t ^ 1], N, 1);
		Rep(i, N) f[t ^ 1][i] = (LL)f[t ^ 1][i] * g[i] % MOD;
		NTT(f[t ^ 1], N, -1);
		For(i, 0, n) f[t ^ 1][i] = plu((LL)f[t ^ 1][i] * fac[i + 2] % MOD,
				(LL)f[t][i] * (1 + C(i + 1, 2)) % MOD);
		t ^= 1;
	}

	int ans = 0;
	For(i, 0, n)
		inc(ans, (LL)C(n, i) * f[t][i] % MOD);
	printf("%d\n", ans);

	return 0;
}