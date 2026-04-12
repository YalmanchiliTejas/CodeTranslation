#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i, s, t) for(i = s; i <= t; ++i)
#define dep(i, s, t) for(i = s; i >= t; --i)

using namespace std;

typedef long long LL;
const int N = 16010, M = 210, G = 131072;
const int P = 998244353;
int n, m; LL ans;
LL fac[G], inv[G];
LL w[G], iw[G], a[G], b[G]; int r[G], L, tot;
LL f[N];

LL lp(LL a, LL b) {
	LL c = 1;
	for(; b; b >>= 1, a = a * a % P)
		if(b & 1) c = c * a % P;
	return c;
}

void excel() {
	int i; LL base, inv_base;
	base = lp(3, (P-1) / tot);
	inv_base = lp(base, P-2);
	w[0] = iw[0] = 1;
	rep(i, 1, tot-1) {
		w[i] = w[i-1] * base % P;
		iw[i] = iw[i-1] * inv_base % P;
	}
}

LL C(int a, int b) {return fac[a] * inv[b] % P * inv[a-b] % P;}

LL inc(LL a, LL b) {
	a += b; return a >= P? a-P: a;
}

LL dec(LL a, LL b) {
	a -= b; return a < 0? a+P: a;
}

void ntt(LL *a, LL *b){
	int i, j, k;
	LL x, y;
	for(i = 0; i < L; ++i)
		if(i < r[i]) swap(a[i], a[r[i]]);
	for(i = 1; i < L; i <<= 1){
		for(j = 0; j < L; j += i<<1){
			for(k = 0; k < i; ++k){
				x = a[j+k]; y = b[tot/i/2*k] * a[j+k+i] % P;
				a[j+k] = inc(x, y); a[j+k+i] = dec(x, y);
			}
		}
	}
}

int main() {
	int i, t = 0, k, p, q; LL fei;
	scanf("%d%d", &n, &m);
	for(L = 1; L <= (n<<1); L <<= 1) ++t;
	fei = lp(L, P-2);
	rep(i, 0, L-1) r[i] = (r[i>>1]>>1) | ((i&1)<<t-1);
	
	fac[0] = 1;
	rep(i, 1, n+2) fac[i] = fac[i-1] * i % P;
	inv[n+2] = lp(fac[n+2], P-2);
	dep(i, n+2, 1) inv[i-1] = inv[i] * i % P;
	tot = 65536; excel();	
	rep(p, 0, n) f[p] = 1;
	rep(k, 2, m) {
		rep(q, 0, n) a[q] = f[q] * inv[q] % P; fill(a+n+1, a+L, 0);
		rep(q, 1, n) b[q] = inv[q+2]; b[0] = 0; fill(b+n+1, b+L, 0); 
		//rep(q, n+1, L-1) a[q] = b[q] = 0;
		ntt(a, w); ntt(b, w);
		rep(q, 0, L-1) a[q] = a[q] * b[q] % P;
		ntt(a, iw);
		rep(q, 0, L-1) a[q] = a[q] * fei % P;
		rep(q, 0, n) f[q] = (f[q]*(q*(q+1)/2+1)%P + a[q]*fac[q+2]%P) % P;
		//printf("%d\n", k);
	}
	rep(p, 0, n) ans = (ans + C(n, p) * f[p] % P) % P;
	printf("%lld\n", ans);
	return 0;
}