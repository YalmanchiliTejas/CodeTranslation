#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
const int MOD=1e9+7;
LL dist[N];
bool vis[N];
int head[N],tot=0,fa[N];

struct node
{
    int from,to;
    LL w;
    int next;
} edge[N*4];
bool operator<(node a,node b)
{
    return a.w<b.w;
}
void add(int u,int v,LL w)
{
    edge[tot].from=u;
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int n;

int get(int x)
{
    if(x==fa[x])
        return x;
    else
        return fa[x]=get(fa[x]);
}
struct Point
{
	int x,y; 
	int id;
}p[N];
bool cmp1(Point a,Point b)
{
	return a.x<b.x;
}
bool cmp2(Point a,Point b)
{
	return a.y<b.y;
}
int main()
{
    memset(head,-1,sizeof(head));
    tot=0;


    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        fa[i]=i;


    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].id=i;
    }
    sort(p+1,p+n+1,cmp1);
    for(int i=2;i<=n;i++)
	{
		add(p[i-1].id,p[i].id,p[i].x-p[i-1].x);
	}
    sort(p+1,p+n+1,cmp2);
	for(int i=2;i<=n;i++)
	{
		add(p[i-1].id,p[i].id,p[i].y-p[i-1].y);
	}
  
    
    sort(edge,edge+tot);
    int cnt=0;
    LL ans=0;
    for(int i=0; i<tot; i++)
    {

        int fu=get(edge[i].from);
        int fv=get(edge[i].to);
        if(fu!=fv)
        {


            fa[fu]=fv;
            cnt++;
            ans+=edge[i].w;
            if(cnt==n-1)
                break;

        }
    }
    cout<<ans<<endl;

    return 0;

}
