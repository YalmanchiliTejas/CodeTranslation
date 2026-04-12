#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
struct edge{
	int from,to;ll val;
	friend bool operator <(edge x,edge y) {return x.val>y.val;}
}e;
priority_queue<edge> q;
struct po{
	int num,x,y;
}a[100005];
int fa[100005];
int cmp1(const po &u,const po &v) {return u.x<v.x;}
int cmp2(const po &u,const po &v) {return u.y<v.y;}
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].num=fa[i]=i;
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=2;i<=n;i++)
	{
		e.from=a[i-1].num;
		e.to=a[i].num;
		e.val=a[i].x-a[i-1].x;
		q.push(e);
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=2;i<=n;i++)
	{
		e.from=a[i-1].num;
		e.to=a[i].num;
		e.val=a[i].y-a[i-1].y;
		q.push(e);
	}
	int cnt=0;ll ans=0;
	for(;cnt<n-1;)
	{
		e=q.top();q.pop();
		int x=find(e.from),y=find(e.to);
		if(x==y) continue;
		ans+=e.val;
		fa[x]=y;
		cnt++;
	}
	printf("%lld\n",ans);
    return 0;
}