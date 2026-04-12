#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

const char lf = '\n';

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

	inline int ts(char *s)
	{
		int a=0,c=fetch();
		while(c<=32 && c!=EOF)c=fetch();
		while(c>32 && c!=EOF)s[a++]=c,c=fetch();
		s[a]=0;
		return a;
	}
}
using ae86::ty;
using ae86::ts;

const int _ = 10007 , mo = 998244353;

template<typename T1,typename T2> inline T1 ad(T1 &a,T2 b){return a=a+b>=mo?a+b-mo:a+b;}
template<typename T1,typename T2> inline T1 dl(T1 &a,T2 b){return a=a>=b?a-b:a-b+mo;}

lint powa(lint a,lint t)
{
	lint b=1;a=(a+mo)%mo;
	while(t){if(t&1)b=b*a%mo;a=a*a%mo,t>>=1;}
	return b;
}

inline lint inva(lint a)
{
	return powa(a,mo-2);
}

lint jc[_],rjc[_];

void fuck(int n=_-1)
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

int n;char sa[_],sb[_];
int f[_][_]={0};

int main()
{
	ios::sync_with_stdio(0),cout.tie(nullptr);

	fuck();
	
	n=ts(sa+1),ts(sb+1);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		if(sa[i]=='1' && sb[i]=='1')cnt1++;
		if(sa[i]=='1' && sb[i]=='0')cnt2++;
	}

	for(int i=0;i<=cnt2;i++)f[0][i]=jc[i]*jc[i]%mo;
	for(int i=1;i<=cnt1;i++)
		for(int j=1;j<=cnt2;j++)
			f[i][j]=(1ll*f[i][j-1]*j%mo*j%mo+1ll*f[i-1][j]*i%mo*j%mo)%mo;
	lint ans=0;
	for(int i=0;i<=cnt1;i++)
		ad(ans,1ll*f[cnt1-i][cnt2]*jc[i]%mo*jc[i]%mo*C(cnt1,i)%mo*C(cnt1+cnt2,i)%mo);
	cout<<ans<<lf;

	return 0;
}
