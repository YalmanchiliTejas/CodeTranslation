// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int poly_bits=15;
const int poly_max=1<<poly_bits;
const int mod=998244353;
const int root=3;

#define COMB
int qpow(LL x,int y,const int&mod=::mod)
{
	LL ret=1;
	while(y)
	{
		if(y&1)ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}
int up_pw2(const int&x){int ret=1;while(ret<x)ret<<=1;return ret;}
inline void copy(int*a,int n,int*b,int m)
{
	if(n>=m)memcpy(b,a,sizeof(int)*m);
	else
	{
		if(a!=b)memcpy(b,a,sizeof(int)*n);
		memset(b+n,0,sizeof(int)*(m-n));
	}
}
#ifdef COMB
int fac[poly_max+1],inv[poly_max+1],invf[poly_max+1];
int comb(int x,int y){if(y<0||x<y)return 0;return (LL)fac[x]*invf[y]%mod*invf[x-y]%mod;}
#endif

void poly_dotmul(int*a,int*b,int*c,int n){for(int i=0;i<n;i++)c[i]=(LL)a[i]*b[i]%mod;}
void poly_add(int*a,int*b,int*c,int n){for(int i=0;i<n;i++)if((c[i]=a[i]+b[i])>=mod)c[i]-=mod;}
void poly_sub(int*a,int*b,int*c,int n){for(int i=0;i<n;i++)if((c[i]=a[i]-b[i])<0)c[i]+=mod;}

int w[poly_max+1];
inline void dft(int*a,int n,bool rev=0)
{
	for(int i=0,j=0;i<n;i++)
	{
		if(i<j)swap(a[i],a[j]);
		for(int t=n>>1;(j^=t)<t;t>>=1);
	}
	static int cw[poly_max];static uLL ca[poly_max];uLL md2=(LL)mod*mod;
	for(int i=0;i<n;i++)ca[i]=a[i];
	for(int l=1,d=poly_bits-1;l<n;l<<=1,d--)
	{
		int l2=l<<1;
		for(int j=0;j<l;j++)cw[j]=w[rev?poly_max-(j<<d):(j<<d)];
		for(int i=0;i<n;i+=l2)for(int j=0;j<l;j++)
		{
			uLL tmp=LL(ca[i|l|j]%mod)*cw[j];
			ca[i|l|j]=ca[i|j]-tmp+md2;
			ca[i|j]+=tmp;
		}
		if(l==(1<<16))for(int i=0;i<n;i++)ca[i]%=mod;
	}
	for(int i=0;i<n;i++)a[i]=ca[i]%mod;
	if(rev)
	{
		LL inv=qpow(n,mod-2);
		for(int i=0;i<n;i++)a[i]=a[i]*inv%mod;
	}
}

void poly_mult(int*a,int n,int*b,int m,int*c,int k=-1)
{
	static int tA[poly_max],tB[poly_max];
	if(k==-1)k=n+m-1;if(n>k)n=k;if(m>k)m=k;
	if(n<=50&&m<=50)
	{
		copy(tA,0,tA,k);
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)tA[i+j]=(tA[i+j]+(LL)a[i]*b[j])%mod;
		copy(tA,k,c,k);
		return;
	}
	int len=up_pw2(n+m-1);
	copy(a,n,tA,len);copy(b,m,tB,len);
	dft(tA,len);dft(tB,len);
	poly_dotmul(tA,tB,tA,len);
	dft(tA,len,1);
	copy(tA,k,c,k);
}

struct init_t
{
	init_t()
	{
		w[0]=1;w[1]=qpow(root,mod-1>>poly_bits);
		for(int i=2;i<=poly_max;i++)w[i]=(LL)w[i-1]*w[1]%mod;
#ifdef COMB
		fac[0]=invf[0]=fac[1]=invf[1]=1;inv[1]=1;
		for(int i=2;i<=poly_max;i++)
		{
			fac[i]=(LL)i*fac[i-1]%mod;
			inv[i]=(LL)(mod-(mod/i))*inv[mod%i]%mod;
			invf[i]=(LL)inv[i]*invf[i-1]%mod;
		}
#endif
	}
} initializer;

int n,m,dp[8111],t1[8111],t2[8111];
void do_dp()
{
	for(int i=0;i<=n;i++)
	{
		t1[i]=(LL)dp[i]*invf[i]%mod;
		if(i)t2[i]=invf[i+2];
	}
	poly_mult(t1,n+1,t2,n+1,t1,n+1);
	for(int i=0;i<=n;i++)
	{
		int coef=((LL)i*(i+1)/2+1)%mod;
		dp[i]=((LL)dp[i]*coef+(LL)t1[i]*fac[i+2])%mod;
	}
}

int main()
{
	get2(n,m);
	
	dp[0]=1;
	for(int i=1;i<=m;i++)do_dp();
	
	int ans=0;
	for(int i=0;i<=n;i++)ans=(ans+(LL)dp[i]*comb(n,i))%mod;
	printendl(ans);
	return 0;
}