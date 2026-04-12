#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

int getint()
{
    char ch=getchar();
    int f=1,x=0;
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
    return f*x;
}

const int N=100100;

int n;
struct edge
{
    int v;
    edge *next;
}pool[N*2],*head[N],*tp=pool;
int dep[N],fa[N];
bool vis[N];
int ord[N];

void addedge(int u,int v)
{
    *tp=(edge){v,head[u]},head[u]=tp++;
    *tp=(edge){u,head[v]},head[v]=tp++;
}

void init()
{
    n=getint();
    for(int i=1; i<n; i++){
        int u=getint(),v=getint();
        addedge(u,v);
    }
}

bool cmp(int a,int b)
{
    return dep[a]>dep[b];
}

void dfs(int x)
{
    for(edge *i=head[x]; i; i=i->next){
        if(dep[i->v]) continue;
        dep[i->v]=dep[x]+1;
        fa[i->v]=x;
        dfs(i->v);
    }
}

int main()
{
    init();
    dfs(1);
    for(int i=1; i<=n; i++){
        ord[i]=i;
    }
    sort(ord+1,ord+1+n,cmp);
    bool flag=true;
    vis[0]=1;
    for(int i=1; i<=n; i++){
        if(vis[ord[i]]) continue;
        vis[ord[i]]=1;
        if(vis[fa[ord[i]]]){
            flag=false;
            break;
        }
        vis[fa[ord[i]]]=1;
    }
    puts(flag?"Second":"First");
    return 0;
}
