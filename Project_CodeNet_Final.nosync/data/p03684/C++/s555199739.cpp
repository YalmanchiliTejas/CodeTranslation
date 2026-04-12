#include<bits/stdc++.h>
using namespace std;
#define maxn 100100
#define ll long long
struct DSU
{
    int fa[maxn],m;
    void init(int x)
    {
        m=x;
        for(int i=0;i<=m;++i)
            fa[i]=i;
    }
    int find(int x)
    {
        if(fa[x]==x) return x;
        else return fa[x]=find(fa[x]);
    }
    void unite(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y) return;
        fa[x]=y;
    }
}dsu;
struct edge
{
    int from,to;
    int w;
    bool operator <(const edge& ee) const
    {
        return w<ee.w;
    }
}g[maxn<<2];
int cnt;
struct poi
{
    int x,y;
    int id;
    bool operator <(const poi& pp) const
    {
        return x<pp.x;
    }
}p[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        p[i].id=i;
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    dsu.init(n);
    sort(p+1,p+1+n);
    for(int i=1;i<n;++i)
    {
        g[cnt].from=p[i].id;
        g[cnt].to=p[i+1].id;
        g[cnt].w=p[i+1].x-p[i].x;
        cnt++;
    }
    for(int i=1;i<=n;++i) swap(p[i].x,p[i].y);
    sort(p+1,p+1+n);
    for(int i=1;i<n;++i)
    {
        g[cnt].from=p[i].id;
        g[cnt].to=p[i+1].id;
        g[cnt].w=p[i+1].x-p[i].x;
        cnt++;
    }
    sort(g,g+cnt);
    ll ans=0;
    for(int i=0;i<cnt;++i)
    {
        int u=g[i].from,v=g[i].to;
        int fu=dsu.find(u);
        int fv=dsu.find(v);
        if(fu==fv) continue;
        dsu.unite(fu,fv);
        ans+=g[i].w;
    }
    cout<<ans<<"\n";
    return 0;
}
