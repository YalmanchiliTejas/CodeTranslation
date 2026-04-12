#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
const u32 P=998244353;
u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
u32 sum(u32 a, u32 b) {return inc(a, b);}
u32 dif(u32 a, u32 b) {return dec(a, b);}
u64 power(u64 a, u32 b) {
	u64 ans=1;
	for(; b; a=a*a%P, b>>=1) if(b&1) ans=ans*a%P;
	return ans;
}

const int N=1<<14;
int n, m, len;
u32 f[N], g[N], h[N], w[N];
u64 fac[N], ifac[N];
void dft(u32 *x) {
	int bits=__builtin_ctz(len);
	for(int i=1, j=0; i<len; ++i) {
		int k=bits;
		while(j>>--k&1) j^=1<<k;
		j^=1<<k;
		if(i<j) std::swap(x[i], x[j]);
	}
	for(int i=1; i<len; i*=2)
		for(int j=0; j<len; j+=i+i)
			for(int k=0; k<i; ++k) {
				u32 z=1llu*w[i+k]*x[i+j+k]%P;
				x[i+j+k]=dif(x[j+k], z);
				inc(x[j+k], z);
			}
}
void idft(u32 *x) {
	u64 inv=power(len, P-2);
	std::reverse(x+1, x+len);
	dft(x);
	for(int i=0; i<len; ++i) x[i]=x[i]*inv%P;
}
int main() {
	n=rd(), m=rd();
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=fac[i-1]*i%P;
	ifac[n]=power(fac[n], P-2);
	for(int i=n; i>=1; --i) ifac[i-1]=ifac[i]*i%P;
	for(len=1; len<=2*n; len*=2);
	u64 omega=power(3, P/len);
	w[len/2]=1;
	for(int i=len/2+1; i<len; ++i) w[i]=omega*w[i-1]%P;
	for(int i=len/2; --i; ) w[i]=w[i*2];
	for(int i=0; i<=n; ++i) g[i]=ifac[i];
	dft(g);
	f[0]=1;
	while(m--) {
		for(int i=0; i<=n; ++i) h[i]=(f[i]+2*f[i+1]+f[i+2])*ifac[i]%P;
		for(int i=n+1; i<len; ++i) h[i]=0;
		dft(h);
		for(int i=0; i<len; ++i) h[i]=1llu*g[i]*h[i]%P;
		idft(h);
		for(int i=1; i<=n; ++i) f[i]=dif(h[i]*fac[i]%P, (1llu*i*f[i]+(i+2llu)*f[i+1]+f[i+2])%P);
	}
	u32 ans=0;
	for(int i=0; i<=n; ++i) ans=(ans+ifac[i]*ifac[n-i]%P*f[i])%P;
	ans=ans*fac[n]%P;
	printf("%u\n", ans);
	return 0;
}
