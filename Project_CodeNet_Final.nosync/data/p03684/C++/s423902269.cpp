#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<cmath>
#include<set>
#include<stack>
#define ll long long
#define pb push_back
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))
#define cls(name,x) memset(name,x,sizeof(name))
using namespace std;
const int inf=1e9+10;
const int maxn=1e5+10;
const int maxm=20;
const int mod=1e9+7;
const double pi=acos(-1.0);
int n;
struct node
{
    int x,y;
    int id;
}town[maxn];
struct edge
{
    int st,ed;
    int cost;
}e[maxn*4];
int fa[maxn];
bool cmp1(const node &a,const node &b)
{
    return a.x<b.x;
}
bool cmp2(const node &a,const node &b)
{
    return a.y<b.y;
}
bool cmp3(const edge &a,const edge &b)
{
    return a.cost<b.cost;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&town[i].x,&town[i].y);
            town[i].id=i;
        }
        int k=0;
        sort(town+1,town+1+n,cmp1);
        for(int i=1;i<=n-1;i++)
        {
            e[k].st=town[i].id;
            e[k].ed=town[i+1].id;
            e[k++].cost=abs(town[i].x-town[i+1].x);
        }
        sort(town+1,town+1+n,cmp2);
        for(int i=1;i<=n-1;i++)
        {
            e[k].st=town[i].id;
            e[k].ed=town[i+1].id;
            e[k++].cost=abs(town[i].y-town[i+1].y);
        }
        sort(e,e+k,cmp3);
        for(int i=1;i<=n;i++)
            fa[i]=i;
        int ans=0;
        for(int i=0;i<k;i++)
        {
            int a=Find(e[i].st),b=Find(e[i].ed);
            if(a!=b)
            {
                ans+=e[i].cost;
                fa[b]=a;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
