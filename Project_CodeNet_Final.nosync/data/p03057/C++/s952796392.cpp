#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

namespace ae86
{
	const int bufl = 1<<15;
	
	char buf[bufl],*s=buf,*t=buf;
	
	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}
	
	inline int ty()
	{
		int a=0,b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}

	template<typename T> inline int ts(T *s)
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

const int _ = 200007 , mo = 1000000007;

int n,m,s[_];
lint f[_]={0};

int main()
{
	n=ty(),m=ty(),ts(s+1);
	for(int i=m;i>=1;i--)s[i]=s[i]==s[1];

	lint ans=0;
	while(m && s[m])m--;
	if(m<=0)ans=1;
	
	int lim=n;
	for(int l=1,r=1;l<=m;l=r+1)
	{
		while(l<=m && !s[l])l++;
		if(l>m)break;
		r=l;
		while(r<m && s[r+1])r++;
		int len=r-l+1;
		if(l==1)lim=min(lim,len+(1-len%2));
		if(len&1)lim=min(lim,len);
	}

	if(lim>=n)
	{
		f[0]=1;
		for(int i=1,x=0;i<=n;i++)f[i]=x,x=(x+f[i-1])%mo;
		for(int i=2;i<=n;i++)ans=(ans+f[n-i]*i%mo)%mo;
	}
	else
	{
		f[0]=1;
		for(int i=2,x=f[0];i<=n;i+=2)
		{
			f[i]=x,x=(x+f[i])%mo;
			if(i>lim)x=(x-f[i-lim-1]+mo)%mo;	
		}
		for(int i=2;i<=lim+1;i+=2)ans=(ans+f[n-i]*i%mo)%mo;
	}
	printf("%lld\n",ans);

	return 0;
}
