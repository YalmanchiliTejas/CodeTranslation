#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef unsigned long long u64;
u32 P;
u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
u32 sum(u32 a, u32 b) {return inc(a, b);}
u32 dif(u32 a, u32 b) {return dec(a, b);}
u64 power(u64 a, int b) {
	u64 ans=1;
	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
	return ans;
}

const int N=3005;
u32 ifac[N], s[N][N];
int main() {
	int n;
	u32 ans=0, x=1;
	u64 fac=1, tot=2;
	assert(scanf("%d%u", &n, &P)==2);
	for(int i=1; i<=n; ++i) fac=fac*i%P;
	ifac[n]=power(fac, P-2);
	for(int i=n; i--; ) ifac[i]=(i+1llu)*ifac[i+1]%P;
	s[0][0]=1;
	for(int i=1; i<=n; ++i) {
		s[i][0]=1;
		for(int j=1; j<=i; ++j) s[i][j]=(s[i-1][j-1]+(j+1llu)*s[i-1][j])%P;
	}
	for(int i=0; i<=n; ++i) {
		u64 y=tot*ifac[i]%P*ifac[n-i]%P;
		if((n-i)&1) y=dif(0, y);
		for(int j=0; j<=n-i; ++j) {
			ans=(ans+y*s[n-i][j])%P;
			y=y*x%P;
		}
		inc(x, x);
		tot=(u64)tot*tot%P;
	}
	ans=ans*fac%P;
	printf("%u\n", ans);
	return 0;
}
