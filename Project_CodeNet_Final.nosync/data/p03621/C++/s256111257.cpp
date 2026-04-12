#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod=998244353,maxn=32768;
int n,m,e,i,j,fac[maxn+5],inv[maxn+5],fi[maxn+5],w[maxn+5],rev[maxn+5];
int a[maxn+5],b[maxn+5];
string s,t;
int qp(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1){
			z=1ll*z*x%mod;
		}
		y/=2;
		x=1ll*x*x%mod;
	}
	return z;
}
void init()
{
	int i;
	w[0]=inv[1]=fac[0]=fac[1]=fi[0]=fi[1]=1;w[1]=qp(3,(mod-1)/maxn);
	fz(i,2,maxn){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fi[i]=1ll*fi[i-1]*inv[i]%mod;
		w[i]=1ll*w[i-1]*w[1]%mod;
	}
}
int getrev(int x)
{
	int len=1,i;
	while(len<=x){
		len*=2;
	}
	fz0k(i,len){
		rev[i]=rev[i/2]/2+((i&1)*(len/2));
	}
	return len;
}
void ntt(int *a,int len,int op)
{
	int i,j,k;
	fz0k(i,len) if(i<rev[i])swap(a[i],a[rev[i]]);
	for(i=1;i<len;i<<=1){
		int ys=maxn/i/2;
		for(j=0;j<len;j+=i+i){
			int t=(op==1?0:maxn);
			fz0k(k,i){
				int x=a[j+k],y=1ll*a[j+k+i]*w[t]%mod;
				a[j+k]=(x+y)%mod;
				a[j+k+i]=(x-y+mod)%mod; 
				t+=op*ys;
			}
		}
	}
	if(op==-1) fz0k(i,len) a[i]=1ll*a[i]*inv[len]%mod;
}
int main()
{
	init();
	cin>>s>>t;
	n=s.length();
	s=" "+s;t=" "+t;
	fz1(i,n){
		if((s[i]&15)&&(t[i]&15)){
			m++;
		}
		else if((s[i]&15)){
			e++;
		}
	}
	int len=getrev(m*2+1); 
	fz0g(i,m){
		a[i]=fi[i+1];
	}
	b[0]=1;
	int y=e;
	while(y)
	{
		ntt(a,len,1);
//		ntt(a,len,-1);
		if(y&1){
			ntt(b,len,1);
			fz0k(i,len) b[i]=1ll*a[i]*b[i]%mod;
			ntt(b,len,-1);
			fz(i,m+1,len) b[i]=0;
		}
		fz0k(i,len) a[i]=1ll*a[i]*a[i]%mod;
		ntt(a,len,-1);
		fz(i,m+1,len) a[i]=0;
		y/=2;
	}
	int ans=0;
	fz0g(i,m){
		inc(ans,b[i])
	}
	printf("%d\n",1ll*ans*fac[e]%mod*fac[m]%mod*fac[e+m]%mod);
	return 0;
}