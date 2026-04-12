/*
Author: QAQAutomaton
Lang: C++
Code: F.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		memset(&inf,0x3f,sizeof(inf));
	}
}__INIT___;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	template<typename A>
	inline bool read (A &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		x=gc();
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	template<typename A>
	inline bool write (A x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) {
		putc(x);
		return 0;
	}
	inline bool write(const char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y){
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
const int p=998244353,G=3,iG=332748118;
int s[8005];
int inv[8005],fac[8005],invf[8005];
int f[16389],g[16389],h[16389];
int rev[16389];
int N,iN;
int fpm(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
void NTT(int *f,int flg){
	for(int i=0;i<N;++i)if(i<rev[i])swap(f[i],f[rev[i]]);
	for(int i=1;i<N;i<<=1){
		int ww=fpm(flg==1?G:iG,(p-1)/(i*2)),w;
		for(int j=0;j<N;j+=i+i){
			w=1;
			for(int k=0;k<i;++k){
				int u=f[j+k],v=f[j+k+i]*w%p;
				f[j+k]=(u+v)%p;
				f[j+k+i]=(u+p-v)%p;
				w=w*ww%p;
			}
		}
	}
	if(flg==-1)
		for(int i=0;i<N;++i)f[i]=f[i]*iN%p;
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,m;
	read(n,m);
	inv[1]=fac[0]=fac[1]=invf[0]=invf[1]=1;
	for(int i=2;i<=n+2;++i){
		inv[i]=(p-p/i)*inv[p%i]%p;
		fac[i]=fac[i-1]*i%p;
		invf[i]=invf[i-1]*inv[i]%p;
	}
	g[0]=s[0]=1;
	for(int i=1;i<=n;++i)h[i]=invf[i+2];
	N=1;
	while(N<=n+n)N<<=1;
	iN=fpm(N,p-2);
	for(int i=1;i<N;++i)rev[i]=(rev[i>>1]>>1)|((i&1)*(N>>1));
	NTT(h,1);
	int ans=0;
	for(int i=0;i<m;++i){
		NTT(g,1);	
		for(int j=0;j<N;++j)f[j]=g[j]*h[j]%p;
		NTT(f,-1);
/*		for(int j=0;j<=n;++j){
			f[j]=0;
			for(int k=0;k<=j;++k)f[j]=(f[j]+g[k]*h[j-k])%p;
		}*/
		for(int j=0;j<N;++j){
			if(j>n)f[j]=g[j]=0;
			else{
				f[j]=f[j]*fac[j+2]%p;
				f[j]=(f[j]+((j+1)*j/2+1)*s[j])%p;
				s[j]=f[j];
				g[j]=f[j]*invf[j]%p;
			}
		}
	}
	for(int i=0;i<=n;++i)ans=(ans+fac[n]*invf[i]%p*invf[n-i]%p*f[i])%p;
	write(ans,'\n');
	return 0;
}

