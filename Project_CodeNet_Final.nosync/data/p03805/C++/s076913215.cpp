#include <iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int head[10], vis[10], k;
int ans;
struct Edge
{
    int v, next;
}edge[200];
void add_edge(int x, int y)
{
    edge[++k].v = y;
    edge[k].next = head[x];
    head[x] = k;
}
void dfs(int u, int rest)
{
    if(rest == 0)
    {
        ans++;
        return ;
    }
    for(int kk = head[u]; kk; kk = edge[kk].next)
    {
        int v = edge[kk].v;
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v, rest - 1);
        vis[v] = 0;
    }
}
int main()
{
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
    k = 0;
    while(m--)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    ans = 0;
    vis[1] = 1;
    dfs(1, n - 1);
    printf("%d\n", ans);
    return 0;
}
