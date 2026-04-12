#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=210;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,m,book[N],res;
int head[N],maxE; struct Edge{ int nxt,to; }e[N];
inline void Add(int u,int v) { e[++maxE].nxt=head[u]; head[u]=maxE; e[maxE].to=v; }
void DFS(int x,int st)
{
    if(st==n) { res++; return; }
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(book[e[i].to]) continue;
        book[e[i].to]=1;
        DFS(e[i].to,st+1);
        book[e[i].to]=0;
    }
}
signed main()
{
    n=read(), m=read();
    for(ri int i=1;i<=m;i++)
    {
        int u,v;
        u=read(), v=read();
        Add(u,v), Add(v,u);
    }
    book[1]=1, DFS(1,1);
    printf("%lld\n",res);
    return 0;
}