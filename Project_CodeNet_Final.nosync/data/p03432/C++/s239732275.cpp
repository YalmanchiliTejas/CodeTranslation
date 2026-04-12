#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

#define so(a) ((int)((a).size()))

const char lf = '\n';

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

namespace ae86
{
	const int bufl = 1 << 15;
	
	char buf[bufl],*s=buf,*t=buf;
	
	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}
	
	inline int ty()
	{
		int a=0;int b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

const int _ = 8007 , __ = 66667 , mo = 998244353 , gmo = 3 , igmo = 332748118;

template<typename T1,typename T2> inline T1 ad(T1 &a,T2 b){return a=a+b>=mo?a+b-mo:a+b;}
template<typename T1,typename T2> inline T1 dl(T1 &a,T2 b){return a=a>=b?a-b:a-b+mo;}
template<typename T1,typename T2> inline T1 add(T1 a,T2 b){return a+b>=mo?a+b-mo:a+b;}
template<typename T1,typename T2> inline T1 del(T1 a,T2 b){return a>=b?a-b:a-b+mo;}

lint powa(lint a,lint t)
{
	lint b=1;
	while(t){if(t&1)b=b*a%mo;a=a*a%mo,t>>=1;}
	return b;
}

inline lint inva(lint a)
{
	return powa(a,mo-2);
}

lint jc[__],rjc[__];

void fuck(int n=__-1)
{
	jc[0]=jc[1]=rjc[0]=1;
	for(int i=2;i<=n;i++)jc[i]=jc[i-1]*i%mo;
	rjc[n]=inva(jc[n]);
	for(int i=n-1;i>=1;i--)rjc[i]=rjc[i+1]*(1ll+i)%mo;
}

lint C(int n,int m)
{
	if(n<m || n<0 || m<0)return 0;
	return jc[n]*rjc[m]%mo*rjc[n-m]%mo;
}

int rev[__];

int nttmake(int n)
{
	int nn=1,lg=0;
	while(nn<n)nn<<=1,lg++;
	rev[0]=0;
	for(int i=1;i<nn;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	return nn;
}

void ntt(lint a[],int nn,int dir)
{
	for(int i=0;i<nn;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<nn;i<<=1)
		for(int j=0,g=powa(dir>0?gmo:igmo,(mo-1)/(i+i));j<nn;j+=i+i)
			for(int k=0,ig=1,x,y;k<i;k++,ig=1ll*ig*g%mo)
				x=a[j+k],y=1ll*ig*a[j+k+i]%mo,a[j+k]=add(x,y),a[j+k+i]=del(x,y);
	if(dir<0)for(int i=0,x=inva(nn);i<nn;i++)a[i]=a[i]*x%mo;
}

int n,m,nn;
lint f[__]={0},pa[__]={0},pb[__]={0};

int main()
{
	ios::sync_with_stdio(0),cout.tie(nullptr);

	fuck();

	n=ty(),m=ty();

	nn=nttmake(n+n+2);
	f[0]=1;
	for(int i=1;i<=n;i++)pa[i]=rjc[i+2];
	ntt(pa,nn,1);

	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)pb[j]=f[j]*rjc[j]%mo;
		for(int j=n+1;j<nn;j++)pb[j]=0;
		ntt(pb,nn,1);
		for(int j=0;j<nn;j++)pb[j]=pb[j]*pa[j]%mo;
		ntt(pb,nn,-1);
		for(int j=0;j<=n;j++)f[j]=add(f[j]*add(1ll*j*(j+1)/2,1)%mo,pb[j]*jc[j+2]%mo);
	}

	lint ans=0;
	for(int i=0;i<=n;i++)ad(ans,f[i]*C(n,i)%mo);
	cout<<ans<<lf;
	
	return 0;
}
