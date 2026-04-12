#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100010
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int head[maxn],nxt[maxn*2],to[maxn*2],tot;
void add(int u,int v)
{
    tot++;
    nxt[tot]=head[u];
    head[u]=tot;
    to[tot]=v;
}
int used[maxn];
void solve(int x,int las)
{
    for(int i=head[x];i;i=nxt[i])
    {
        if(to[i]==las)  continue;
        solve(to[i],x);
    }
    if(!used[x])
    {
        if(used[las])
        {
            puts("First");
            exit(0);
        }
        used[x]=used[las]=1;
    }
}
int main()
{
    n=read();
    for(int i=1;i<n;i++)
    {
        int q=read(),w=read();
        add(q,w);
        add(w,q);
    }
    used[0]=1;
    solve(1,0);
    puts("Second");
    return 0;
}