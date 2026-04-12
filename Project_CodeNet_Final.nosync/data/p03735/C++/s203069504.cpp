#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
#define fint register int
#define flint register lint

inline int ty()
{
	fint a=0,b=1,c=getchar();
	while(!isdigit(c))b^=c=='-',c=getchar();
	while(isdigit(c))a=a*10+c-48,c=getchar();
	return b?a:-a;
}

const int _ = 200007 , inf = 0x3f3f3f3f;
const lint linf = 0x3f3f3f3f3f3f3f3f;

struct node
{
	lint a,b;
	node(lint _a=0,lint _b=0){a=min(_a,_b),b=max(_a,_b);}
	inline friend int operator < (node a,node b)
	{
		return a.a<b.a;
	}
};

node p[_];
int n;
lint ans;

int main()
{
	n=ty();
	flint mia=linf,mxa=-linf,mib=linf,mxb=-linf;
	for(fint i=1;i<=n;i++)
	{
		flint a=ty(),b=ty();
		if(a>b)swap(a,b);
		p[i]=node(a,b);
		mia=min(mia,a),mxa=max(mxa,a);
		mib=min(mib,b),mxb=max(mxb,b);
	}
	
	flint distan=mxb-mia;
	ans=(mxa-mia)*(mxb-mib);
	sort(p+1,p+n+1),mib=mxb=p[1].b;
	
	for(fint i=2;i<n;i++)
	{
		mib=min(mib,p[i].b),mxb=max(mxb,p[i].b);
		ans=min(ans,((max(mxb,p[n].a)-min(mib,p[i+1].a))*distan));
	}
	printf("%lld\n",ans);
	return 0;
}
