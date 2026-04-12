#include <cstdio>
#include <cctype>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
#define repe(i,x) for (edge *i=fst[x]; i; i=i->nxt)
using namespace std;

int n,cnt[100100],stk[100100],top;
struct edge
{
    int v;
    edge *nxt;
} pool[200100],*tp=pool,*fst[100100];
bool flag[100100];

int getint()
{
    char ch;
    while (!isdigit(ch=getchar()));
    int x=ch-'0';
    for (; isdigit(ch=getchar()); x=x*10+ch-'0');
    return x;
}

int main()
{
    n=getint();
    repu(i,1,n-1)
    {
        int u=getint(),v=getint();
        *tp=(edge){v,fst[u]},fst[u]=tp++;
        *tp=(edge){u,fst[v]},fst[v]=tp++;
        ++cnt[u],++cnt[v];
    }
    repu(i,1,n)
        if (cnt[i]==1)
            stk[++top]=i;
    while (top)
    {
        int u=stk[top--],v=0;
        if (flag[u])
            continue;
        if (!cnt[u])
        {
            puts("First");
            return 0;
        }
        repe(i,u)
            if (cnt[i->v]>0)
                v=i->v;
        repe(i,v)
        {
            if (i->v!=u && cnt[i->v]==1)
            {
                puts("First");
                return 0;
            }
            if ((--cnt[i->v])==1)
                stk[++top]=i->v;
        }
        cnt[u]=cnt[v]=0,flag[u]=flag[v]=1;
    }
    puts("Second");
    return 0;
}