#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define in read()
#define re register
#define fur(i,a,b) for(re int i=a;i<=b;++i)
#define fdr(i,a,b) for(re int i=a;i>=b;--i)
#define cl(a,b) memset(a,b,sizeof(a))
#define jinitaimei signed
#define int long long
inline int read()
{
	int x=0;
	char ch=getchar();
	for(;!isalnum(ch);ch=getchar());
	for(;isalnum(ch);ch=getchar()) x=x*10+ch-'0';
	return x;
}
const int xx=2e5+101;
struct person
{
	int x,y;
}m[xx];
inline bool cmp(person a,person b)
{
	return a.x<b.x;
}
jinitaimei main()
{
	int n=in,xmax=0,xmin=2e18,ymax=0,ymin=2e18;
	fur(i,1,n)
	{
		m[i].x=in,m[i].y=in;
		if(m[i].x>m[i].y) swap(m[i].x,m[i].y);
		xmax=max(xmax,m[i].x);
		xmin=min(xmin,m[i].x);
		ymax=max(ymax,m[i].y);
		ymin=min(ymin,m[i].y);
	}
	int ans=(xmax-xmin)*(ymax-ymin);
	sort(m+1,m+n+1,cmp);
	ymin=xmin;
	int maxl=m[1].y,minl=m[1].y,ans2=2e18;
	fur(i,2,n-1)
	{
		maxl=max(maxl,m[i].y);
		minl=min(minl,m[i].y);
		ans2=min(ans2,max(maxl,m[n].x)-min(minl,m[i+1].x));
	}
	if(n>2) ans2*=(ymax-ymin);
	ans=min(ans,ans2);
	cout<<ans<<endl;
	return 0;
}