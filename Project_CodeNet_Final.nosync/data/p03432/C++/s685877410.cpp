#include <bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> void read(T &x){
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}
inline void write(int x){if (x > 9) write(x/10); putchar(x%10+'0'); }

const int P = 998244353,L = 16384,N = 8050,M = 205;
inline int power(int x,LL y){
	static int r; r = 1; while (y){ if (y&1) r = (LL)r * x % P; x = (LL)x * x % P; y >>= 1; } return r;
}
int fac[N<<1],nfac[N<<1],inv[N<<1];
inline int C(int n,int m){
	return (n<0||m<0||n<m) ? 0 : (LL)fac[n] * nfac[m] % P * nfac[n-m] % P; 
} 
int R[L],rt[30],irt[30];
inline void NTT(int *A,int n){
	register int i,j,k,l,w,w0,x,y;
	for (i = 0; i < n; ++i) if (i < R[i]) swap(A[i],A[R[i]]);
	for (i = l = 1; i < n; i <<= 1,++l)
	for (j = 0,w0 = rt[l]; j < n; j += i << 1)
	for (k = j,w = 1; k < i+j; ++k,w = (LL)w * w0 % P)
		x = A[k],y = (LL)w * A[k+i] % P,A[k] = (x+y>=P)?(x+y-P):(x+y),
		A[k+i] = (x<y)?(x+P-y):(x-y); 
}
inline void iNTT(int *A,int n){
	register int i,j,k,l,w,w0,x,y;
	for (i = 0; i < n; ++i) if (i < R[i]) swap(A[i],A[R[i]]);
	for (i = l = 1; i < n; i <<= 1,++l)
	for (j = 0,w0 = irt[l]; j < n; j += i << 1)
	for (k = j,w = 1; k < i+j; ++k,w = (LL)w * w0 % P)
		x = A[k],y = (LL)w * A[k+i] % P,A[k] = (x+y>=P)?(x+y-P):(x+y),
		A[k+i] = (x<y)?(x+P-y):(x-y);
	for (i = 0,w = power(n,P-2); i < n; ++i) A[i] = (LL)A[i] * w % P;
}
int Lim;
int A[L],B[L];
int Ans;
int f[N],g[N],n;
inline void solve(int m){
	int i;
	for (i = 0; i <= n; ++i) g[i] = 0;
	for (i = 0; i < Lim; ++i) A[i] = B[i] = 0;
	for (i = 0; i <= n; ++i) A[i] = (LL)nfac[i] * f[i] % P,B[i] = nfac[i+2]; B[0] = 0;
	NTT(A,Lim),NTT(B,Lim);
	for (i = 0; i < Lim; ++i) A[i] = (LL)A[i] * B[i] % P;
	iNTT(A,Lim);
	for (i = 0; i <= n; ++i) g[i] = (LL)A[i] * fac[i+2] % P,g[i] = (g[i] + (LL)(1+i+C(i,2)) * f[i]) % P,f[i] = g[i];
}

int main(){
	int i,j;
	for (i = 1,j = 2; i <= 25; ++i,j <<= 1) rt[i] = power(3,(P-1)/j),irt[i] = power(rt[i],P-2);
	inv[0] = fac[0] = nfac[0] = inv[1] = nfac[1] = fac[1] = 1;
	for (i = 2; i <= 16000; ++i){
		fac[i] = (LL)fac[i-1] * i % P;
		inv[i] = (LL)(P-P/i) * inv[P%i] % P;
		nfac[i] = (LL)nfac[i-1] * inv[i] % P; 
	}
	int m; cin >> n >> m; 
	int l = 0; Lim = 1;
	while (Lim <= n*2) Lim<<=1,++l;
	for (i = 0; i < Lim; ++i) R[i] = (R[i>>1]>>1) | ((i&1)<<l-1); 
	f[0] = 1;
	for (i = 1; i <= m; ++i) solve(i);
	for (i = 0; i <= n; ++i) Ans = (Ans + (LL)C(n,i) * f[i]) % P;
	cout << Ans << '\n';
	return 0;
}