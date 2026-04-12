#include <cctype>
#include <cstdio>
#include <cstdlib>
#define rep(i,x,y) for (int i=x; i<=y; ++i)

int get()
{
    char c;
    while (!isdigit(c=getchar()));
    int k=c-'0';
    for (; isdigit(c=getchar()); k=k*10+c-'0');
    return k;
}

const int N=1e5+10;
struct edge
{
    int v;
    edge *nxt;
} pool[N*2],*tp=pool,*fst[N];
int n,ans;

bool dfs(int x,int fa)
{
    int t=1;
    for (edge *i=fst[x]; i; i=i->nxt)
        if (i->v!=fa)
            t-=dfs(i->v,x);
    if (t<0)
        puts("First"),exit(0);
    return t;
}

int main()
{
    n=get();
    if (n&1)
        puts("First"),exit(0);
    rep(i,2,n)
    {
        int u=get(),v=get();
        *tp=(edge){v,fst[u]},fst[u]=tp++;
        *tp=(edge){u,fst[v]},fst[v]=tp++;
    }
    dfs(1,0);
    puts("Second");
    return 0;
}