#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int BIT = 16, MAXN = 1 << BIT;
namespace NTT {
    const int MOD = 998244353, G = 3;
    int w[2][MAXN], inv[MAXN], hasinit;//power table
    int modpow(int a, int b) {
        int res = 1;
        for (; b; b >>= 1) {
            if (b & 1) res = (LL)res * a % MOD;
            a = (LL)a * a % MOD;
        }
        return res;
    }
    void init() {
        hasinit = 1;
        int mul = modpow(G, (MOD - 1) >> BIT);
        for (int i = w[0][0] = 1; i < MAXN; i++) w[0][i] = (LL)w[0][i - 1] * mul % MOD;
        mul = modpow(G, MOD - 1 - ((MOD - 1) >> BIT));
        for (int i = w[1][0] = 1; i < MAXN; i++) w[1][i] = (LL)w[1][i - 1] * mul % MOD;
        inv[1] = 1;
        for (int i = 2; i < MAXN; i++) inv[i] = MOD - (LL)MOD / i * inv[MOD % i] % MOD;
    }
    int get_tpow(int n) {//return min{2^k|2^k>=n}
        int k = 1;
        while (k < n) k <<= 1;
        return k;
    }
    void ntt(int *b, int n, int rev) {
        if (!hasinit) init();
        typedef unsigned long long ull;
        static ull a[MAXN]; static int ww[MAXN];
        const ull mmod = (ull)MOD * MOD; const int *W = w[rev];
        for (int i = 0, j = 0; i < n; i++) {
            a[j] = b[i];
            for (int k = n >> 1; (j ^= k) < k; k >>= 1);
        }
        int n0 = __builtin_ctz(n);
        if (n0 & 1) {
            for (int i = 0; i < n; i += 2) {
                const ull x = a[i], y = a[i + 1];
                a[i] = x + y, a[i + 1] = x + MOD - y;
            }
        }
        for (int h = n0 & 1 ? 4 : 2; h <= n; h <<= 2) {
            int hh = h >> 1, t = (1 << BIT) / h >> 1;
            for (int i = 0; i < h; i++) ww[i] = W[i * t];
            for (int i = 0; i < n; i += h << 1) {
                ull *ax = a + i, *ay = a + i + hh, *au = a + i + h, *av = a + i + h + hh;
                register int *aw = ww, *bw = ww, *cw = ww + hh;
                for (register int j = i; j < i + hh; ++j, ++ax, ++ay, ++au, ++av, aw += 2, ++bw, ++cw) {
                    const ull x = *ax, y = *ay % MOD * *aw, u = *au, v = *av % MOD * *aw;
                    const ull p = x + y, q = x + mmod - y, o = (u + v) % MOD * *bw, r = (u + mmod - v) % MOD * *cw;
                    *ax = p + o, *ay = q + r, *au = p + mmod - o, *av = q + mmod - r;
                }
            }
            if (h == 65536 || h == 32768) for (int j = 0; j < n; j++) a[j] %= MOD;
        }
        for (int i = 0; i < n; i++) b[i] = a[i] % MOD;
        if (rev) {
            int inv = modpow(n, MOD - 2);
            for (int i = 0; i < n; i++) b[i] = (LL)b[i] * inv % MOD;
        }
    }
    //reset a polynomial to zero
    void reset(int *a, int n) { memset(a, 0, sizeof(int) * n); }
    //copy polynomial a to b
    void copy(int *a, int *b, int n) { memcpy(b, a, sizeof(int) * n); }
    //get multiplication of two polynomial in O(nlogn)
    void get_mul(int *a, int *b, int *c, int n, int m, int p) {
        if ((LL)n * m <= 4096) {
            typedef unsigned long long ull;
            static ull res[MAXN];
            for (int i = 0; i < p; i++) res[i] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m && i + j < p; j++) res[i + j] += (ull)a[i] * b[j];
                if (!(i & 15)) for (int j = 0; j < p; j++) res[j] %= MOD;
            }
            for (int i = 0; i < p; i++) c[i] = res[i] % MOD;
        } else {
            static int A[MAXN], B[MAXN];
            int len = get_tpow(n + m - 1);
            reset(A, len), reset(B, len);
            copy(a, A, n), copy(b, B, m);
            ntt(A, len, 0), ntt(B, len, 0);
            for (int i = 0; i < len; i++) A[i] = (LL)A[i] * B[i] % MOD;
            ntt(A, len, 1);
            copy(A, c, p);
        }
    }
    //get inverse in O(nlogn)
    void get_inv(int *a, int *b, int n) {
        static int ta[MAXN];
        b[0] = modpow(a[0], MOD - 2), b[1] = 0;
        for (int ii = 1; ii < n; ii <<= 1) {
            int i = ii << 1, m = i << 1;
            reset(ta + i, i), reset(b + i, i);
            copy(a, ta, i);
            ntt(ta, m, 0), ntt(b, m, 0);
            for (int j = 0; j < m; j++) b[j] = (2LL - (LL)b[j] * ta[j] % MOD + MOD) * b[j] % MOD;
            ntt(b, m, 1);
            reset(b + i, i);
        }
    }
    //get derivitive function in O(n)
    void get_der(int *a, int *b, int n) {//b can equal with a
        for (int i = 0; i < n - 1; i++) b[i] = (LL)a[i + 1] * (i + 1) % MOD;
        b[n - 1] = 0;
    }
    //get primitive function in O(nlogn)
    void get_pri(int *a, int *b, int n) {//b can equal with a
        for (int i = n - 1; i > 0; i--) b[i] = (LL)a[i - 1] * inv[i] % MOD;
        b[0] = 0;
    }
    //get ln in O(nlogn)
    void get_ln(int *a, int *b, int n) {
        static int tb[MAXN];
        get_der(a, b, n);
        get_inv(a, tb, n);
        get_mul(b, tb, b, n, n, n);
        get_pri(b, b, n);
    }
    //get exp in O(nlogn)
    void get_exp(int *a, int *b, int n) {
        static int ta[MAXN], tb[MAXN], tc[MAXN];
        b[0] = tb[0] = 1, b[1] = tb[1] = 0;
        for (int ii = 1; ii < n; ii <<= 1) {
            int i = ii << 1, m = i << 1;
            //get inverse b to tc
            reset(ta + i, i), reset(tb + i, i), reset(tc + i, i);
            copy(b, ta, i), copy(tb, tc, i);
            ntt(ta, m, 0), ntt(tc, m, 0);
            for (int j = 0; j < m; j++) tc[j] = (2LL - (LL)ta[j] * tc[j] % MOD + MOD) * tc[j] % MOD;
            ntt(tc, m, 1), reset(tc + i, i);
            //get ln b
            get_der(b, ta, i), reset(ta + i, i);
            get_mul(ta, tc, ta, i, i, i);
            get_pri(ta, ta, i);
            //get exp to b
            for (int j = 0; j < i; j++) ta[j] = (!j - ta[j] + a[j] + MOD) % MOD;
            get_mul(b, ta, b, i, i, i), reset(b + i, i);
            if (i < n) { //get inverse b to tb
                reset(ta + i, i), copy(b, ta, i);
                ntt(ta, m, 0), ntt(tb, m, 0);
                for (int j = 0; j < m; j++) tb[j] = (2LL - (LL)ta[j] * tb[j] % MOD + MOD) * tb[j] % MOD;
                ntt(tb, m, 1), reset(tb + i, i);
            }
        }
    }
    //get divisor in O(nlogn)
    void get_div(int *a, int *b, int *p, int n, int m) {//a=bp+r
        if (n < m) return;
        reverse(a, a + n), reverse(b, b + m);
        int lp = n - m + 1, len = get_tpow(lp);
        get_inv(b, p, len);
        get_mul(p, a, p, lp, n, lp);
        reverse(p, p + lp), reverse(a, a + n), reverse(b, b + m);
    }
    //get modular in O(nlogn)
    void get_mod(int *a, int *b, int *r, int n, int m) {//a=bp+r
        if (n < m) { copy(a, r, n); return; }
        static int d[MAXN];
        int lp = n - m + 1;
        get_div(a, b, d, n, m);
        get_mul(b, d, r, m, lp, m - 1);
        for (int i = 0; i < m - 1; i++) r[i] = (a[i] - r[i] + MOD) % MOD;
    }
    //get divisor and modular in O(nlogn)
    void get_div(int *a, int *b, int *p, int *r, int n, int m) {//a=bp+r
        if (n < m) { copy(a, r, n); return; }
        get_div(a, b, p, n, m);
        int lp = n - m + 1;
        get_mul(p, b, r, lp, m, m - 1);
        for (int i = 0; i < m - 1; i++) r[i] = (a[i] - r[i] + MOD) % MOD;
    }
    //get power in O(nlogn)
    void get_pow(int *a, int *b, int n, int m, int p) {//b=a^m MOD x^p
        static int tc[MAXN], td[MAXN];
        int t = 0;
        reset(b, p);
        while (t < n && !a[t]) ++t;
        if ((LL)t * m >= n) return;
        int inv = modpow(a[t], MOD - 2);
        for (int i = t; i < n; i++) tc[i - t] = (LL)a[i] * inv % MOD;
        int len = get_tpow(p - t * m);
        get_ln(tc, td, len);
        for (int i = 0; i < len; i++) td[i] = (LL)td[i] * m % MOD;
        get_exp(td, b, len);
        inv = modpow(a[t], m);
        for (int i = p - 1; i >= t * m; i--) b[i] = (LL)b[i - t * m] * inv % MOD;
        reset(b, t * m);
    }
    //get square root in O(nlogn) and make sure a[0]=1
    void get_sqrt(int *a, int *b, int n) {
        static int ta[MAXN];
        if (n == 1) { b[0] = 1; b[1] = 0; return; }
        get_sqrt(a, b, n >> 1);
        get_inv(b, ta, n);
        get_mul(a, ta, ta, n, n, n);
        const int inv2 = (MOD + 1) / 2;
        for (int i = 0; i < n; i++) b[i] = (LL)(b[i] + ta[i]) * inv2 % MOD;
    }
    //get evaluation of polynomial in O(nlog^2n)
    void pre_eval(int *a, int store[][MAXN], int l, int r, int dep) {
        if (l == r) { store[dep][l << 1] = MOD - a[l], store[dep][l << 1 | 1] = 1; return; }
        int mid = (l + r) >> 1;
        pre_eval(a, store, l, mid, dep + 1);
        pre_eval(a, store, mid + 1, r, dep + 1);
        get_mul(store[dep + 1] + (l << 1), store[dep + 1] + ((mid + 1) << 1), store[dep] + (l << 1), mid - l + 2, r - mid + 1, r - l + 2);
    }
    void cal_eval(int *a, int *ans, int store[][MAXN], int temp[][MAXN], int n, int l, int r, int dep) {
        get_mod(a, store[dep] + (l << 1), temp[dep] + l, n, r - l + 2);
        if (l == r) { ans[l] = temp[dep][l]; return; }
        int mid = (l + r) >> 1;
        cal_eval(temp[dep] + l, ans, store, temp, r - l + 1, l, mid, dep + 1);
        cal_eval(temp[dep] + l, ans, store, temp, r - l + 1, mid + 1, r, dep + 1);
    }
    void get_eval(int *a, int *x, int *y, int n, int m) {//a(x[i])=y[i]
        static int store[BIT][MAXN], temp[BIT][MAXN];
        pre_eval(x, store, 0, m - 1, 0);
        cal_eval(a, y, store, temp, n, 0, m - 1, 0);
    }
    //get interpolation in O(nlog^2n)
    void cal_inter(int *val, int store[][MAXN], int temp[][MAXN], int n, int l, int r, int dep) {//a(x[i])=y[i]
        if (l == r) { temp[dep][l] = val[l]; return; }
        int mid = (l + r) >> 1;
        cal_inter(val, store, temp, n, l, mid, dep + 1);
        cal_inter(val, store, temp, n, mid + 1, r, dep + 1);
        get_mul(store[dep + 1] + ((mid + 1) << 1), temp[dep + 1] + l, temp[dep] + l, r - mid + 1, mid - l + 1, r - l + 1);
        get_mul(store[dep + 1] + (l << 1), temp[dep + 1] + mid + 1, temp[dep + 1] + l, mid - l + 2, r - mid, r - l + 1);
        for (int i = l; i <= r; i++) temp[dep][i] = (temp[dep][i] + temp[dep + 1][i]) % MOD;
    }
    void get_inter(int *x, int *y, int *a, int n) {
        static int store[BIT][MAXN], temp[BIT][MAXN], der[MAXN], val[MAXN];
        pre_eval(x, store, 0, n - 1, 0);
        get_der(store[0], der, n + 1);
        cal_eval(der, val, store, temp, n, 0, n - 1, 0);
        for (int i = 0; i < n; i++) val[i] = (LL)y[i] * modpow(val[i], MOD - 2) % MOD;
        cal_inter(val, store, temp, n, 0, n - 1, 0);
        for (int i = 0; i < n; i++) a[i] = temp[0][i];
    }
}
using NTT::MOD;
using NTT::modpow;

char A[MAXN], B[MAXN];
int C[MAXN], D[MAXN], cnt[2][2], n;
LL fac[MAXN], inv[MAXN];

void init() {
	int n = 2e4;
	for (int i = fac[0] = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
	inv[n] = modpow(fac[n], MOD - 2);
	for (int i = n; i > 0; i--) inv[i - 1] = inv[i] * i % MOD;
}

int main() {
	init();
	scanf("%s%s", A, B);
	n = strlen(A);
	for (int i = 0; i < n; i++) ++cnt[A[i] - '0'][B[i] - '0'];
	assert(cnt[1][0] == cnt[0][1]);
	int m = cnt[1][1];
	for (int i = 0; i <= m; i++) C[i] = inv[i + 1];
	NTT::get_pow(C, D, m + 1, cnt[0][1], m + 1);
	LL ans = 0;
	for (int i = 0; i <= m; i++) ans += D[i];
	printf("%lld\n", ans % MOD * fac[m + cnt[0][1]] % MOD * fac[m] % MOD * fac[cnt[0][1]] % MOD);
	return 0;
}