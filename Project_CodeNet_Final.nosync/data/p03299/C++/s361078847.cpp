#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<lint,lint> pll;
typedef long double louble;

#define lf ('\n')

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
}
using ae86::ty;

const int _ = 103 , mo = 1000000007;

inline lint powa(lint a,lint t)
{
	lint b=1;
	while(t){if(t&1)b=b*a%mo;a=a*a%mo,t>>=1;}
	return b;
}

int n,hig[_];

// pll = (not have adjacent same color, have adjacent same color)

pll dfs(int l,int r,int h)
{
	int mih=2e9;
	for(int i=l;i<=r;i++)mih=min(mih,hig[i]);

	pll ans=pll(2,1);
	for(int i=l;i<=r;i++)
	{
		if(hig[i]==mih)ans.second=ans.second*2%mo;
		else
		{
			int j=i;
			while(j<r && hig[j+1]>mih)j++;
			pll ret=dfs(i,j,mih);
			ans.first=ans.first*ret.first%mo;
			ans.second=(ret.first+ret.first+ret.second)%mo*ans.second%mo;
			i=j;
		}
	}

	ans.second=(ans.second-ans.first+mo)%mo;
	ans.first=ans.first*powa(2,mih-h-1)%mo;

	return ans;
}

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)hig[i]=ty();
	pll ret=dfs(1,n,0);
	printf("%lld\n",(ret.first+ret.second)%mo);

	return 0;
}
