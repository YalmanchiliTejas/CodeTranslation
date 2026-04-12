#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=100005;
const int maxm=200005;

struct Edge
{
    int u,v,dist;
    Edge(){}
    Edge(int u,int v,int d):u(u),v(v),dist(d){}
    bool operator<(const Edge &rhs)const
    {
        return dist < rhs.dist;
    }
};
 struct node
 {
     int x,y,id;
 }p[maxn];
 bool cmp(node a,node b)
 {
     return a.x<b.x;
 }
 bool cmp2(node a,node b)
 {
     return a.y<b.y;
 }
struct Kruskal
{
    int n,m;
    Edge edges[maxm];
    int fa[maxn];
    int findset(int x){ return fa[x]==-1? x:fa[x]=findset(fa[x]); }

    void init(int n)
    {
        this->n=n;
        m=0;
        memset(fa,-1,sizeof(fa));
    }

    void AddEdge(int u,int v,int dist)
    {
        edges[m++]=Edge(u,v,dist);
    }

    ll kruskal()
    {
        ll sum=0;
        int cnt=0;
        sort(edges,edges+m);

        for(int i=0;i<m;i++)
        {
            int u=edges[i].u, v=edges[i].v;
            if(findset(u) != findset(v))
            {

                sum +=edges[i].dist;
                fa[findset(u)] = findset(v);
                if(++cnt>=n-1) break;
            }
        }
        if(cnt<n-1) return -1;
        return sum;
    }
}KK;



int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        KK.init(n);
        for(int i=1;i<=n;i++)
            {scanf("%d%d",&p[i].x,&p[i].y);
        p[i].id=i;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<n;i++)
       KK.AddEdge(p[i].id,p[i+1].id,abs(p[i+1].x-p[i].x));
    sort(p+1,p+n+1,cmp2);
    for(int i=1;i<n;i++)
        KK.AddEdge(p[i].id,p[i+1].id,abs(p[i+1].y-p[i].y));
    printf("%lld\n",KK.kruskal());
    }
    return 0;
}
