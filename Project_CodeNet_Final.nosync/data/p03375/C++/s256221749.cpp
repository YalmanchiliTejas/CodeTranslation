#include<bits/stdc++.h>
#define Rint register int
using namespace std;
typedef long long LL;
const int N = 3005;
int n, mod, fac[N], inv[N], S[N][N], pw[4100], pw2[2200], ans;
inline void qmo(int &x){x += (x >> 31) & mod;}
inline int calc(int x){return (LL) pw[x & 4095] * pw2[x >> 12] % mod;}
inline int ksm(int a, int b, int p = mod){
	int res = 1;
	for(;b;b >>= 1, a = (LL) a * a % p) if(b & 1) res = (LL) res * a % p;
	return res;
}
inline int C(int n, int m){
	if(n < 0 || m < 0 || n < m) return 0;
	return (LL) fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main(){
	scanf("%d%d", &n, &mod);
	S[0][0] = fac[0] = 1;
	for(Rint i = 1;i <= n;++ i) fac[i] = (LL) fac[i - 1] * i % mod;
	inv[n] = ksm(fac[n], mod - 2);
	for(Rint i = n;i;-- i) inv[i - 1] = (LL) inv[i] * i % mod;
	for(Rint i = 1;i <= n + 1;++ i)
		for(Rint j = 1;j <= i;++ j)
			qmo(S[i][j] = (LL) j * S[i - 1][j] % mod + S[i - 1][j - 1] - mod);
	pw[0] = pw2[0] = 1;
	for(Rint i = 1;i <= 4096;++ i) qmo(pw[i] = pw[i - 1] * 2 - mod);
	pw2[1] = pw[4096];
	for(Rint i = 2;i <= 2197;++ i) pw2[i] = (LL) pw2[i - 1] * pw2[1] % mod;
	for(Rint i = 0;i <= n;++ i){
		int tmp = 0;
		for(Rint j = 0;j <= i;++ j) qmo(tmp += (LL) S[i + 1][j + 1] * calc((n - i) * j) % mod - mod);
		tmp = (LL) tmp * C(n, i) % mod * ksm(2, ksm(2, n - i, mod - 1)) % mod;
		if(i & 1) qmo(ans -= tmp); else qmo(ans += tmp - mod);
	}
	printf("%d", ans); 
}