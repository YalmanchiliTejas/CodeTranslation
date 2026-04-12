#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;

int n,cnt,last[N],f[N],g[N];
struct edge{int to,next;}e[N*2];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void addedge(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dp(int x,int fa)
{
    int mx=-n;
    for (int i=last[x];i;i=e[i].next)
    {
        if (e[i].to==fa) continue;
        dp(e[i].to,x);
        g[x]+=max(g[e[i].to],f[e[i].to]);
        mx=max(mx,g[e[i].to]-f[e[i].to]);
    }
    if (mx>=0) f[x]=g[x]+1;
    else if (mx>-n) f[x]=g[x]+mx+1;
}

int main()
{
    n=read();
    for (int i=1;i<n;i++)
    {
        int x=read(),y=read();
        addedge(x,y);
    }
    dp(1,0);
    if (max(f[1],g[1])==n/2&&!(n&1)) puts("Second");
    else puts("First");
    return 0;
}