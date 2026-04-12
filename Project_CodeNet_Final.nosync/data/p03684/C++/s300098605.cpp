#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxN=1e5+5;

int fa[maxN];

struct node
{
    int x,y,id;
}a[maxN],b[maxN];

struct edge
{
    int f,t,w;
}e[maxN*2];

bool cmp1(node x1,node x2)
{
    return x1.x<x2.x;
}

bool cmp2(node x1,node x2)
{
    return x1.y<x2.y;
}

bool cmp3(edge x1,edge x2)
{
    return x1.w<x2.w;
}

int find(int x)
{
    if(fa[x]==-1)return x;
    return fa[x]=find(fa[x]);
}

int uni(int f,int t)
{
    f=find(f);t=find(t);
    if(f==t)return 0;
    fa[f]=t;return 1;
}

int main()
{
    int k,n,cnt=0,now=0;
    long long ans=0;
    memset(fa,-1,sizeof(fa));
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        scanf("%d%d",&a[k].x,&a[k].y);
        a[k].id=k;b[k].id=k;
        b[k].x=a[k].x;
        b[k].y=a[k].y;
    }
    sort(a,a+n,cmp1);
    sort(b,b+n,cmp2);
    for(k=1;k<n;k++)
    {
        e[cnt].f=a[k-1].id;
        e[cnt].t=a[k].id;
        e[cnt].w=a[k].x-a[k-1].x;
        cnt++;
    }
    for(k=1;k<n;k++)
    {
        e[cnt].f=b[k-1].id;
        e[cnt].t=b[k].id;
        e[cnt].w=b[k].y-b[k-1].y;
        cnt++;
    }
    sort(e,e+cnt,cmp3);
    for(k=0;k<cnt;k++)
    {
        if(uni(e[k].f,e[k].t))
        {
            ans+=e[k].w;
            now++;
        }
        if(now==n-1)break;
    }
    cout<<ans;
    return 0;
}
