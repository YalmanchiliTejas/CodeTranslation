#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in int read()
	{
		int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
};
using namespace fast_io;
#define init(x,n) static int x[N];memset(x,0,4*n);
const int N=1e5+5,K=8e3+5,B=2e2+5,p=998244353,G=3;
int n,m,ans,len,L,a[K<<2],b[K<<2],f[B][K<<2],fac[K<<2],inv[K<<2];
in void M(int&x) {x-=p,x+=x>>31&p;}
in int add(int x,int y) {return M(x+=y),x;}
in int sub(int x,int y) {return M(x+=p-y),x;}
in int c(int n,int m) {return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;}
in int qpow(int x,int y) {int z=1;for(;y;y>>=1,x=1ll*x*x%p) if(y&1) z=1ll*x*z%p;return z;}
in void read(int *a,int n) {for(int i=0;i<n;i++) a[i]=read();}
in void print(int *a,int n) {for(int i=0;i<n;i++) write(a[i]," \n"[i==n-1]);}
int r[N],ny[N],o[N],_o[N];
in void calrev(int len,int L)
{
	for(int i=1;i<=len;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(L-1));
	o[0]=1;o[1]=qpow(G,(p-1)/len);
	for(int i=2;i<=len;i++) o[i]=1ll*o[1]*o[i-1]%p;
	for(int i=0;i<len;i++) _o[i]=o[len-i];
}
in void ntt(int *a,int n,int op)
{
	for(int i=0;i<n;i++) if(i<r[i]) swap(a[i],a[r[i]]);int *w=(op==1)?o:_o;
	for(int i=1;i<n;i<<=1) for(int j=0,d=i<<1;j<n;j+=d) for(int k=j,x,y;k<j+i;k++)
	x=a[k],y=1ll*w[n/d*(k-j)]*a[i|k]%p,M(a[k]=x+y),M(a[i|k]=x+p-y);
	if(op==1) return; int inv=qpow(n,p-2);for(int i=0;i<n;i++) a[i]=1ll*a[i]*inv%p;
}
int main()
{
	n=read()+1,m=read();L=ceil(log2(2*n-1)),calrev(len=1<<L,L);
	fac[0]=fac[1]=inv[0]=inv[1]=1;for(int i=2;i<=n+1;i++) inv[i]=1ll*(p-p/i)*inv[p%i]%p;
	for(int i=2;i<=n+1;i++) inv[i]=1ll*inv[i]*inv[i-1]%p,fac[i]=1ll*fac[i-1]*i%p;
	for(int i=0;i<n;i++) f[m][i]=c(n-1,n-i-1);for(int i=1;i<n;i++) a[i]=inv[i+2];ntt(a,len,1);
	for(int i=m-1;~i;i--)
	{
		for(int j=0;j<n;j++) b[j]=1ll*f[i+1][j]*fac[n+1-j]%p;memset(b+n,0,4*(len-n));
		ntt(b,len,1);for(int j=0;j<len;j++) b[j]=1ll*a[j]*b[j]%p;ntt(b,len,-1);
		for(int j=0;j<n;j++) M(f[i][j]=1ll*b[j]*inv[n-j-1]%p+1ll*f[i+1][j]*(c(n-j,2)+1)%p);
	}
	write(f[0][n-1],'\n');return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.