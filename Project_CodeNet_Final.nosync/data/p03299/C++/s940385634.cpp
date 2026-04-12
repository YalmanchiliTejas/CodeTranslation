#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
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
const u32 P=1e9+7;
inline u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
inline u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
inline u32 sum(u32 a, u32 b) {return (a+=b)<P?a:a-P;}
inline u32 dif(u32 a, u32 b) {return (a-=b)&0x80000000?a+P:a;}
u64 power(u64 a, int b) {
	u64 ans=1;
	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
	return ans;
}

const int N=101;
int n, m, h[N], real[N];
u32 f[N];
int main() {
	n=rd();
	for(int i=0; i<n; ++i) h[i]=real[i]=rd();
	std::sort(real, real+n);
	m=std::unique(real, real+n)-real;
	for(int i=0; i<n; ++i) h[i]=std::lower_bound(real, real+m, h[i])-real;
	f[0]=power(2, real[h[0]]);
	for(int i=0; i<=h[0]; ++i) f[i+1]=power(2, real[h[0]]-real[i]+1);
	for(int i=0; i<=h[0]; ++i) dec(f[i], f[i+1]);
	for(int i=1; i<n; ++i) {
		if(h[i]<=h[i-1]) {
			u32 s=0;
			for(int j=h[i]; j<=h[i-1]; ++j) inc(s, f[j+1]), f[j+1]=0;
			f[h[i]+1]=2*s%P;
		} else {
			u32 g=f[h[i-1]+1];
			for(int j=h[i-1]; j<=h[i]; ++j) f[j+1]=g*power(2, real[h[i]]-real[j]+1)%P;
			for(int j=h[i-1]; ++j<=h[i]; ) dec(f[j], f[j+1]);
			u64 p=power(2, real[h[i]]-real[h[i-1]]);
			for(int j=0; j<=h[i-1]; ++j) f[j]=f[j]*p%P;
		}
	}
	u32 ans=0;
	for(int i=0; i<=h[n-1]+1; ++i) inc(ans, f[i]);
	printf("%u\n", ans);
	return 0;
}
