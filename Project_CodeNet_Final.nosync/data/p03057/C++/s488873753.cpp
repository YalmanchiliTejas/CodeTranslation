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
const u32 P=1e9+7;
u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
u32 sum(u32 a, u32 b) {return inc(a, b);}
u32 dif(u32 a, u32 b) {return dec(a, b);}

const int N=2e5+5;
int n, m;
u32 f[N];
char s[N];
int main() {
	assert(scanf("%d%d%s", &n, &m, s)==3);
	if(s[0]=='B') for(int i=0; i<m; ++i) s[i]^='B'^'R';
	if(std::count(s, s+m, 'B')==0) {
		f[0]=f[1]=1;
		for(int i=2; i<=n; ++i) f[i]=sum(f[i-1], f[i-2]);
		printf("%u\n", sum(f[n], f[n-2]));
		return 0;
	}
	if(n%2==1) {
		puts("0");
		return 0;
	}
	int ml=n;
	for(int l=0, r; l<m; l=r+1) {
		for(r=l; r<m&&s[r]=='R'; ++r);
		if(r==m) break;
		if(l==0) cmin(ml, r+1); else if((r-l)%2==1) cmin(ml, r-l);
	}
	ml=(ml+1)/2;
	n/=2;
	u32 s=0;
	for(int i=1; i<=n; ++i) {
		f[i]=s;
		if(i<=ml) inc(f[i], 2*i);
		inc(s, f[i]);
		if(i>=ml) dec(s, f[i-ml]);
	}
	printf("%u\n", f[n]);
	return 0;
}
