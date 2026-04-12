#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iomanip>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define rep(i,k,n) for(int i=(k);i<=(n);i++)
#define red(i,k,n) for(int i=(k);i>=(n);i--)
#define sqr(x) ((x)*(x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define mod 1000000007
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
//const int maxn = ;

struct Edge
{
    int u,v,w,id;
}e[200010];

bool cmp(const Edge &a,const Edge &b){return a.w<b.w;}

struct tE
{
    int v,ord,next;
}te[200010];

int head[100010];
int tet;
LL mst;
LL ans[200010];
int f[100010];
int n,m,cnt;
bool me[200010];
int dep[100010];
int fa[100010];
bool vis[100010];
int fae[100010];

vector<int> ne;

void add(int u,int v,int ord)
{
    te[++tet].v=v;
    te[tet].ord=ord;
    te[tet].next=head[u];
    head[u]=tet;
}

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void dfs(int u)
{
    vis[u]=1;
    for(int i=head[u];~i;i=te[i].next)
    {
        int v=te[i].v;
        if(vis[v])continue;
        fa[v]=u;
        fae[v]=i;
        dep[v]=dep[u]+1;
        dfs(v);
    }
}

int main()
{
//#define LOCAL
#ifdef LOCAL
	freopen("e:\\read.txt","r",stdin);
	//freopen("e:\\write.txt","w",stdout);
#endif
    while(cin>>n>>m)
    {
        ne.clear();
        rep(i,1,m)
        {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
            e[i].id=i;
        }
        sort(e+1,e+1+m,cmp);
        rep(i,1,n)f[i]=i;
        mst=cnt=0;
        int a,b;
        clr(me,0);
        clr(head,-1);
        tet=0;
        rep(i,1,m)
        {
            a=e[i].u;
            b=e[i].v;
            if(getf(a)!=getf(b))
            {
                cnt++;
                mst+=e[i].w;
                me[e[i].id]=1;
                f[getf(a)]=getf(b);
                add(a,b,i);
                add(b,a,i);
            }
            else
            {
                ne.push_back(i);
            }
        }
        if(cnt<n-1){rep(i,1,m)puts("-1");continue;}
        rep(i,1,m)if(!me[i])ans[i]=mst;else ans[i]=-1;
        rep(i,1,n)f[i]=i;
        clr(dep,0);
        clr(fa,0);
        clr(vis,0);
        dfs(1);
        for(int i=0;i<ne.size();i++)
        {
            a=e[ne[i]].u;
            b=e[ne[i]].v;
            while(getf(a)!=getf(b))
            {
                if(dep[a]>dep[b])swap(a,b);
                int k=te[fae[b]].ord;
                if(ans[e[k].id]==-1)ans[e[k].id]=mst-e[k].w+e[ne[i]].w;
                else ans[e[k].id]=MIN(ans[e[k].id],mst-e[k].w+e[ne[i]].w);
                f[getf(b)]=getf(fa[b]);
                b=getf(fa[b]);
            }
        }
        rep(i,1,m)
        {
            printf("%lld\n",ans[i]);
        }
    }


	return 0;
}