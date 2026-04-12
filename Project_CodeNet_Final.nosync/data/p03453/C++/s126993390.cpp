#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <bitset>
#include <queue>
#define N 110000
#define M 210000
#define inf 1000000007
using namespace std;
struct EDGE {int adj,w,next; }edge[M*2];
struct dat{int id; long long dist; dat(int id=0,long long dist=0):id(id),dist(dist){}};
struct cmp{ bool operator()(const dat &a,const dat &b){ return a.dist>b.dist; } };
priority_queue< dat, vector<dat>,cmp> q;
int n,m,st,ed,top,gh[N],v[N];
long long dist1[N],dist2[N],way1[N],way2[N];
struct node
{
    int x,y,w;
}save[2*M];
void addedge(int x,int y,int w)
{
    edge[++top].adj=y;
    edge[top].w=w;
    edge[top].next=gh[x];
    gh[x]=top;
}
void dijkstra(int s,long long dist[],long long way[])
{
    for(int i=1;i<=n;i++)dist[i]=2147483647ll*1000000ll;
    for(int i=1;i<=n;i++)way[i]=0;
    memset(v,0,sizeof(v));
    dist[s]=0;
    way[s]=1;
    q.push(dat(s,0));
    while (!q.empty())
    {
        dat x=q.top();
        q.pop();
        if (v[x.id])continue;
        v[x.id]=1;
        for(int p=gh[x.id];p;p=edge[p].next)
        {
            if (x.dist+edge[p].w<dist[edge[p].adj])
            {
                dist[edge[p].adj]=x.dist+edge[p].w;
                way[edge[p].adj]=way[x.id];
                q.push(dat(edge[p].adj,dist[edge[p].adj]));
            }
            else 
            if (x.dist+edge[p].w==dist[edge[p].adj])
                way[edge[p].adj]=(way[edge[p].adj]+way[x.id])%inf;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&st,&ed);
    top=0;
    for(int i=1;i<=n;i++)gh[i]=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        addedge(x,y,w);
        addedge(y,x,w);
        save[i].x=x; save[i].y=y; save[i].w=w;
        save[i+m].x=y; save[i+m].y=x; save[i+m].w=w;
    }
    dijkstra(st,dist1,way1);
    dijkstra(ed,dist2,way2);
    //for(int i=1;i<=n;i++)cout<<way1[i]<<" "; puts("");
    //for(int i=1;i<=n;i++)cout<<way2[i]<<" "; puts("");


    long long ans=way1[ed]*way2[st]%inf;
    for(int i=1;i<=n;i++)
        if (dist1[i]==dist2[i] && 2*dist1[i]==dist1[ed])
            {
                long long t=way1[i]*way2[i]%inf;
                t=t*t%inf;
                ans=((ans-t)%inf + inf )%inf;
            }
    for(int i=1;i<=2*m;i++)
    {
        int x=save[i].x;
        int y=save[i].y;
        int w=save[i].w;
        if (dist1[x]*2<dist1[ed] && dist1[y]*2>dist1[ed] 
            && dist1[x]+w+dist2[y]==dist1[ed])
            {
                long long t=way1[x]*way2[y]%inf;
                t=t*t%inf;
                ans=((ans-t)%inf + inf )%inf;
            }
    }
    cout<<ans<<endl;
}
