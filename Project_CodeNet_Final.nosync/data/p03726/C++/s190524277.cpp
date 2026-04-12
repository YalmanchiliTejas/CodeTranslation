#include <cstdio>
#include <queue>

int n;
std::vector<int> edges[100010];
int degree[100010];
std::queue<int> queue;
bool removed[100010];

int main(void)
{
    int u,v;
    int i;
    int e;

    //freopen("x.in","r",stdin);

    scanf("%d",&n);
    for(i = 1;i < n;++i)
        scanf("%d %d",&u,&v),edges[u].push_back(v),edges[v].push_back(u),++degree[v],++degree[u];

    for(i = 1;i <= n;++i)
        if(degree[i] == 1)
            queue.push(i);

    while(!queue.empty())
    {
        u = queue.front();
        queue.pop();
        if(removed[u])
            continue;
        if(!degree[u])
            return puts("First"),0;
        for(e = 0;e < edges[u].size();++e)
            if(!removed[edges[u][e]])
                v = edges[u][e];
        removed[v] = removed[u] = true;
        for(e = 0;e < edges[v].size();++e)
            if(!removed[edges[v][e]] && --degree[edges[v][e]] == 1)
                queue.push(edges[v][e]);
            else if(!removed[edges[v][e]] && degree[edges[v][e]] == 0)
                return puts("First"),0;
    }
    puts("Second");

    return 0;
}