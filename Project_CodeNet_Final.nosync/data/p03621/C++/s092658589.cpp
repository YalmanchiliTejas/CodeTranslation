//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=998244353;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
//FFT & polynomial
const double pi=acos(-1);
struct point
{
	double x,y;
	point(double _x=0,double _y=0){x=_x;y=_y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	point conj()const{return point(x,-y);}
};
const int FFTmx=100111;
const int FFTpsz=65536;
int FFTsz,pbitrev[FFTmx],bitrev[FFTmx];
point _prew[FFTmx],_w[FFTmx];
void FFTprecalc()
{
	for(int i=0;i<=FFTpsz;i++)_prew[i]=point(cos(2.0/FFTpsz*i*pi),sin(2.0/FFTpsz*i*pi));
	for(int i=0,j=0;i<=FFTpsz;i++)
	{
		pbitrev[i]=j;
		for(int t=FFTpsz>>1;(j^=t)<t;t>>=1);
	}
}
void FFTinit(int n)
{
	FFTsz=1;
	while(FFTsz<n)FFTsz<<=1;
	int tmp=__builtin_ctz(FFTpsz/FFTsz);
	for(int i=0;i<FFTsz;i++)bitrev[i]=pbitrev[i]>>tmp;
}
void FFT(point a[],int coef)
{
	for(int i=0,j=0;i<FFTsz;i++)if(i<bitrev[i])swap(a[i],a[bitrev[i]]);
	for(int l=1,k=1;l<FFTsz;l<<=1,k++)
	{
		if(coef==1)for(int i=0;i<l;i++)_w[i]=_prew[(FFTpsz>>k)*i];
		else for(int i=0;i<l;i++)_w[i]=_prew[FFTpsz-(FFTpsz>>k)*i];
		for(int i=0;i<FFTsz;i+=l+l)
		{
			for(int j=0;j<l;j++)
			{
				point tmp=a[i+l+j]*_w[j];
				a[i+l+j]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
		}
	}
	if(coef==-1)
	{
		for(int i=0;i<FFTsz;i++)a[i]=a[i]*(1.0/FFTsz);
	}
}
point _tl[FFTmx],_tr[FFTmx],_ta[FFTmx],_tb[FFTmx];
void FFTfor2(point a[],point b[],int coef)
{
	for(int i=0;i<FFTsz;i++)a[i]=a[i]+b[i]*point(0,1);
	if(coef==1)
	{
		FFT(a,1);
		for(int i=0;i<FFTsz;i++)_ta[i]=a[i];
		_ta[FFTsz]=a[0];
		for(int i=0;i<FFTsz;i++)
		{
			a[i]=(_ta[i]+_ta[FFTsz-i].conj())*point(+0.5,0);
			b[i]=(_ta[i]-_ta[FFTsz-i].conj())*point(0,-0.5);
		}
	}
	else 
	{
		FFT(a,-1);
		for(int i=0;i<FFTsz;i++)b[i]=a[i].y,a[i]=a[i].x;
	}
}
int tc[FFTmx];
void polymulti(int a[],int b[],int c[],int n,int m)
{
	if(n<=1000&&m<=1000)
	{
		for(int i=0;i<FFTsz;i++)tc[i]=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)continue;
			for(int j=0;j<m;j++)
			{
				if(b[j]==0)continue;
				tc[i+j]=(tc[i+j]+1ll*a[i]*b[j])%mod;
			}
		}
		for(int i=0;i<FFTsz;i++)c[i]=tc[i];
		return;
	}
	for(int i=0;i<n;i++)a[i]=a[i]<0?a[i]+mod:a[i];
	for(int i=0;i<m;i++)b[i]=b[i]<0?b[i]+mod:b[i];
	FFTinit(n+m);
	for(int i=0;i<FFTsz;i++)
	{
		_ta[i]=i<n?point(a[i]&32767,a[i]>>15):0;
		_tb[i]=i<m?point(b[i]&32767,b[i]>>15):0;
	}
	FFT(_ta,1);_ta[FFTsz]=_ta[0];
	FFT(_tb,1);_tb[FFTsz]=_tb[0];
	for(int i=0;i<FFTsz;i++)
	{
		point a0=(_ta[i]+_ta[FFTsz-i].conj())*point(+0.5,0),a1=(_ta[i]-_ta[FFTsz-i].conj())*point(0,-0.5);
		point b0=(_tb[i]+_tb[FFTsz-i].conj())*point(+0.5,0),b1=(_tb[i]-_tb[FFTsz-i].conj())*point(0,-0.5);
		_tl[i]=a0*b0+a0*b1*point(0,1);
		_tr[i]=a1*b0+a1*b1*point(0,1);
	}
	FFT(_tl,-1);
	FFT(_tr,-1);
	for(int i=0;i<FFTsz;i++)
	{
		c[i]=(ll(_tl[i].x+0.5)+
		    ((ll(_tr[i].y+0.5)%mod)<<30)+
	       (((ll(_tl[i].y+0.5)+ll(_tr[i].x+0.5))%mod)<<15))%mod;
	}
}
ll kissme(ll x,ll k){return k==0?1:kissme(x*x%mod,k>>1)*(k&1?x:1)%mod;}
char s1[10011],s2[10011];
int n,a,b;
int A[FFTmx];
ll fac[10011],ifac[10011];
int B[FFTmx];
void fftpw()
{
	int t=b;
	B[0]=1;
	while(t>0)
	{
		if(t&1)
		{
			polymulti(B,A,B,n+1,n+1);
			for(int i=n+1;i<FFTsz;i++)B[i]=0;
		}
		polymulti(A,A,A,n+1,n+1);
		for(int i=n+1;i<FFTsz;i++)A[i]=0;
		t>>=1;
	}
}
int main()
{
	fac[0]=1;
	for(int i=1;i<=10005;i++)fac[i]=fac[i-1]*i%mod;
	ifac[10005]=kissme(fac[10005],mod-2);
	for(int i=10004;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	FFTprecalc();
	scanf("%s",s1);
	scanf("%s",s2);
	n=strlen(s1);
	for(int i=0;i<n;i++)
	{
		a+=s1[i]=='1'&&s2[i]=='1';
		b+=s1[i]=='1'&&s2[i]=='0';
	}
	n=a+b;
//	cerr<<a<<" "<<b<<endl;
	FFTinit(2*(n+1));
	for(int i=0;i<=a;i++)
	{
//		A[i+1]=fac[i]*ifac[i+1]%mod;
		A[i+1]=ifac[i+1];
	}
//	for(int i=0;i<=n;i++)cout<<A[i]<<" ";cout<<endl;
	fftpw();
//	for(int i=0;i<=n;i++)cout<<B[i]<<" ";cout<<endl;
	ll ans=0;
	for(int i=b;i<=a+b;i++)
	{
		int c=i-b;
		ll v=B[i]*fac[i]%mod*fac[c]%mod;
//		cout<<i<<":"<<v<<endl;
		ans+=v*fac[b]%mod*fac[a-c]%mod*fac[n]%mod*ifac[n-a+c]%mod*fac[a]%mod*ifac[c]%mod*ifac[a-c]%mod;//*fac[a]%mod;
//		cout<<v*fac[b]%mod*fac[a-c]%mod*fac[n]%mod*ifac[n-a+c]%mod*fac[a]%mod*ifac[c]%mod*ifac[a-c]%mod<<endl;
	}
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}