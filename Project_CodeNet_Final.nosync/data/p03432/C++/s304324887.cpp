#include<bits/stdc++.h>
#define Rint register int
using namespace std;
typedef long long LL;
const int N = 1 << 14, mod = 998244353, G = 3, Gi = 332748118;
inline void qmo(int &x){x += (x >> 31) & mod;}
template<typename T>
inline void read(T &x){
	int ch = getchar(); x = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
}
inline int ksm(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = (LL) res * a % mod;
		a = (LL) a * a % mod; b >>= 1;
	}
	return res;
}
int n, m, ans, rev[N], lim, fac[N], inv[N], f[N], g[N], tmp[N];
inline void calrev(int len){
	int L = -1; lim = 1;
	while(lim <= len){lim <<= 1; ++ L;}
	for(Rint i = 0;i < lim;++ i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << L);
}
inline void NTT(int *a, int type){
	for(Rint i = 0;i < lim;++ i)
		if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(Rint mid = 1;mid < lim;mid <<= 1){
		int Wn = ksm(type == 1 ? G : Gi, (mod - 1) / (mid << 1));
		for(Rint j = 0;j < lim;j += mid << 1){
			int w = 1;
			for(Rint k = 0;k < mid;++ k, w = (LL) w * Wn % mod){
				int x = a[j + k], y = (LL) w * a[j + k + mid] % mod;
				qmo(a[j + k] = x + y - mod); qmo(a[j + k + mid] = x - y); 
			}
		}
	}
	if(type == -1){
		int inv = ksm(lim, mod - 2);
		for(Rint i = 0;i < lim;++ i) a[i] = (LL) a[i] * inv % mod;
	}
}
inline void init(int n){
	fac[0] = 1;
	for(Rint i = 1;i <= n;++ i) fac[i] = (LL) fac[i - 1] * i % mod;
	inv[n] = ksm(fac[n], mod - 2);
	for(Rint i = n;i;-- i) inv[i - 1] = (LL) inv[i] * i % mod; 
}
int main(){
	read(n); read(m); init(n + 2);
	for(Rint i = 1;i <= n;++ i) g[i] = inv[i + 2]; calrev(n << 1); NTT(g, 1);
	f[0] = tmp[0] = 1;
	for(Rint i = 1;i <= m;++ i){
		NTT(tmp, 1);
		for(Rint j = 0;j < lim;++ j) tmp[j] = (LL) tmp[j] * g[j] % mod;
		NTT(tmp, -1);
		for(Rint j = 0;j <= n;++ j){
			f[j] = ((LL) tmp[j] * fac[j + 2] + (LL) f[j] * (1 + (j * (j + 1ll) >> 1))) % mod;
			tmp[j] = (LL) f[j] * inv[j] % mod;
		}
		memset(tmp + n + 1, 0, lim - n - 1 << 2);
	}
	for(Rint i = 0;i <= n;++ i) ans = (ans + (LL) inv[i] * inv[n - i] % mod * f[i]) % mod;
	printf("%d\n", (LL) fac[n] * ans % mod);
}