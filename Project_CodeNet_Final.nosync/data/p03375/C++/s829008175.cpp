#pragma GCC optimize(2,3,"Ofast","unroll-loops")
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
    in int gs(char *s) {char c,*t=s;while(c=gc(),c<=32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
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
#define pb push_back
const int N=3e3+5;
int n,p,c[N][N],s[N][N],ans;
in void M(int &x) {x-=p;x+=x>>31&p;}
in int qpow(int a,int b,int p=::p) {int c=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)c=1ll*a*c%p;return c;}
int main()
{
	n=read(),p=read();c[0][0]=s[0][0]=1;
	for(int i=1;i<=n+1;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++) M(s[i][j]=s[i-1][j-1]+1ll*j*s[i-1][j]%p),M(c[i][j]=c[i-1][j-1]+c[i-1][j]);
	}
	for(int i=0;i<=n;i++)
	{
		int _2=qpow(2,n-i),__2=qpow(2,n-i,p-1),t=(i&1)?p-1:1,res=0;
		t=1ll*t*c[n][i]%p*qpow(2,__2)%p;
		for(int j=0,j2=1;j<=i;j++) M(res+=1ll*s[i+1][j+1]*j2%p),j2=1ll*j2*_2%p;
		M(ans+=1ll*res*t%p);
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233
