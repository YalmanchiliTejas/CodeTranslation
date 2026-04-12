#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct Point
{
    ll x,y;
    int id;
};
struct edge
{
    int a,b,w;
};
bool cmp1(Point a,Point b)
{
    return a.x<b.x;
}
bool cmp2(Point a,Point b)
{
    return a.y<b.y;
}
bool cmp3(edge a,edge b)
{
    return a.w<b.w;
}
int f[100005];
int bcj(int p)
{
    if(f[p]==p)
        return p;
    f[p]=bcj(f[p]);
    return f[p];
}
void join(int p,int q)
{
    int fp=bcj(p);
    int fq=bcj(q);
    if(fp!=fq)
        f[fp]=fq;
}

Point village[100005];
edge e[200005];
int main()
{
    int N;

    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        f[i]=i;
    }
    for(int i=0;i<N;i++)
    {
        scanf("%lld%lld",&village[i].x,&village[i].y);
        village[i].id=i;
    }

    int cnt=0;
    sort(village,village+N,cmp1);
    for(int i=0;i<N-1;i++)
    {
        e[cnt].a=village[i].id;
        e[cnt].b=village[i+1].id;
        e[cnt].w=village[i].x-village[i+1].x;
        if(e[cnt].w<0)
            e[cnt].w*=-1;
        cnt++;
    }
    sort(village,village+N,cmp2);
    for(int i=0;i<N-1;i++)
    {
        e[cnt].a=village[i].id;
        e[cnt].b=village[i+1].id;
        e[cnt].w=village[i].y-village[i+1].y;
        if(e[cnt].w<0)
            e[cnt].w*=-1;
        cnt++;
    }

    sort(e,e+cnt,cmp3);
    ll ans=0;
    int p=0;
    while(N-->1)
    {
        while(1)
        {

            if(bcj(e[p].a)!=bcj(e[p].b))
            {
                join(e[p].a,e[p].b);
                ans+=(ll)e[p].w;

                p++;
                break;
            }
            p++;
        }
    }
    printf("%lld",ans);



}
