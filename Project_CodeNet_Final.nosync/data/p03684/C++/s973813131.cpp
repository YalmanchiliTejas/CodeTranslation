#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n,num;
unsigned long long ans=0;
int fa[100010];
struct zhk1{int f,t,val;}b[200010];
struct nancy{int id,x,y;}a[100010];

inline int get_num()
{
	int now=0;int fh=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')fh=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){now=(now<<3)+(now<<1)+ch-'0';ch=getchar();}
	return now*fh;
}

inline bool cmp(zhk1 a,zhk1 b){return a.val<b.val;}
inline bool cmp1(nancy a,nancy b){return a.x<b.x;}
inline bool cmp2(nancy a,nancy b){return a.y<b.y;}

inline int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

inline void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	fa[fy]=fx;
}

int main()
{
	n=get_num();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		a[i].x=get_num();
		a[i].y=get_num();
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=2;i<=n;i++)
	{
		b[++num].f=a[i-1].id;
		b[num].t=a[i].id;
		b[num].val=abs(a[i].x-a[i-1].x);
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=2;i<=n;i++)
	{
		b[++num].f=a[i-1].id;
		b[num].t=a[i].id;
		b[num].val=abs(a[i].y-a[i-1].y);
	}
	sort(b+1,b+num+1,cmp);
	for(int i=1;i<=num;i++)
	{
		if(find(b[i].f)!=find(b[i].t))
		{
			merge(b[i].f,b[i].t);
			ans+=b[i].val;
		}
	}
	printf("%lld\n",ans);
	return 0;
}