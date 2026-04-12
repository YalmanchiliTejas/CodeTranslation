#include <bits/stdc++.h>
using namespace std;

const int N=1e6+50, mod=998244353;
inline int add(int x,int y) {return (x+y>=mod) ? (x+y-mod) : (x+y);}
inline int dec(int x,int y) {return (x-y<0) ? (x-y+mod) : (x-y);}
inline int mul(int x,int y) {return (long long)x*y%mod;}
inline int power(int a,int b,int rs=1) {for(;b;b>>=1,a=mul(a,a)) if(b&1) rs=mul(rs,a); return rs;}
inline int sgn(int x) {return (x&1) ? (mod-1) : 1;}

namespace FFT {
	const int G=3;
	int A[N],B[N],w[N],pos[N],k;
	inline void init(int n) {
		for(k=1;k<=n;k<<=1);
		memset(A,0,sizeof(int)*k);
		memset(B,0,sizeof(int)*k);
		for(int i=1;i<k;i++) pos[i]=(i&1) ? ((pos[i>>1]>>1)^(k>>1)) : (pos[i>>1]>>1);
	}
	inline void dft(int *a) {
		for(int i=1;i<k;i++)
			if(pos[i]>i) swap(a[pos[i]],a[i]);
		for(int bl=1;bl<k;bl<<=1) {
			int tl=bl<<1, wn=power(G,(mod-1)/tl);
			w[0]=1; for(int i=1;i<bl;i++) w[i]=mul(w[i-1],wn);
			for(int bg=0;bg<k;bg+=tl)
				for(int j=0;j<bl;j++) {
					int &t1=a[bg+j], &t2=a[bg+j+bl], t=mul(t2,w[j]);
					t2=dec(t1,t); t1=add(t1,t);
				}
		}
	}
	inline void func() {
		dft(A); dft(B);
		for(int i=0;i<k;i++) B[i]=mul(B[i],A[i]);
		dft(B); const int inv=power(k,mod-2);
		for(int i=0;i<k;i++) B[i]=mul(B[i],inv);
		reverse(B+1,B+k); 
	}
}
struct combin {
	int fac[N],ifac[N];
	combin() {
		fac[0]=1;
		for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
		ifac[0]=ifac[1]=1;
		for(int i=2;i<N;i++) ifac[i]=mul(mod-mod/i,ifac[mod%i]);
		for(int i=2;i<N;i++) ifac[i]=mul(ifac[i-1],ifac[i]); 
	}
	inline int C(int a,int b) {return mul(fac[a],mul(ifac[b],ifac[a-b]));}
} C;

struct poly {
	vector <int> a;
	poly(int d=0,int t=0) {a.resize(d+1); a[d]=t;}
	inline int& operator [](const int &i) {return a[i];}
	inline const int& operator [](const int &i) const {return a[i];}
	inline int deg() const {return a.size()-1;}
	inline poly extend(int k) {poly c=*this; c.a.resize(k); return c;}
	friend inline poly operator *(const poly &a,const poly &b) {
		poly c(a.deg()+b.deg()); FFT::init(c.deg());
		for(int i=0;i<=a.deg();i++) FFT::A[i]=a[i];
		for(int i=0;i<=b.deg();i++) FFT::B[i]=b[i];
		FFT::func();
		for(int i=0;i<=c.deg();i++) c[i]=FFT::B[i];
		return c;
	}
	inline void pt() {
		for(int i=0;i<=deg();i++) cerr<<a[i]<<' '; cerr<<'\n';
	}
};

int n,m,l;
char a[N],b[N];
int main() {
	scanf("%s%s",a,b);
	l=strlen(a);
	for(int i=0;i<l;i++)
		if(a[i]=='1' &&a[i]==b[i]) ++n;
		else if(a[i]=='1') ++m;
	poly g(n+1,0); 
	for(int i=1;i<=n+1;i++) g[i]=C.ifac[i];
	poly f(n+m,0); f[0]=1;
	for(int b=m;b;b>>=1,g=(g*g).extend(n+m+1))
		if(b&1) f=(f*g).extend(n+m+1);
	int ans=0;
	for(int i=m;i<=n+m;i++) {
		int res=mul(mul(f[i],C.fac[i]),C.C(n+m,i));
		res=mul(res,mul(C.fac[n+m-i],C.fac[n+m-i]));
		res=mul(res,C.C(n,i-m));
		res=mul(res,C.fac[i-m]);
		ans=add(ans,res);
	}
	cout<<mul(ans,C.fac[m]);
}