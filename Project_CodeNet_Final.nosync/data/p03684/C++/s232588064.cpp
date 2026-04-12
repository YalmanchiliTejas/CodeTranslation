#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge
{
    int x,y,v;
}e[200005];
int n,f[100005],cnt=0;
inline void Addedge(int x,int y,int v)
{
    e[++cnt]=(Edge){x,y,v};return;
}
inline bool cmp(const Edge& a,const Edge& b){return a.v<b.v;}
struct Node
{
    int x,y;
}a[100005];
inline int dis(int x,int y)
{
    return min(abs(a[x].x-a[y].x),abs(a[x].y-a[y].y));
}
inline int GetFather(int x)
{
    if(f[x]==x)return x;
    else return f[x]=GetFather(f[x]);
}
inline int Kruskal(void)
{
    int i,x,y,ans=0;
    for(i=1;i<=n;++i)f[i]=i;
    for(i=1;i<=cnt;++i)
    {
        x=GetFather(e[i].x);
        y=GetFather(e[i].y);
        if(x==y)continue;
        f[x]=y;ans+=e[i].v;
    }
    return ans;
}
pair<int,int>sx[100005],sy[100005];
int main(void)
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        sx[i]=make_pair(a[i].x,i);
        sy[i]=make_pair(a[i].y,i);
    }
    sort(sx+1,sx+n+1);
    sort(sy+1,sy+n+1);
    for(i=2;i<=n;++i)
    {
        Addedge(sx[i-1].second,sx[i].second,dis(sx[i-1].second,sx[i].second));
        Addedge(sy[i-1].second,sy[i].second,dis(sy[i-1].second,sy[i].second));
    }
    sort(e+1,e+cnt+1,cmp);
    printf("%d\n",Kruskal());
    return 0;
}
