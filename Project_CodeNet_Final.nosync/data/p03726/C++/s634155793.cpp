#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

vector<int> G[100005];
int d[500005],us[500005],n,f=0,du[500005],p;
void dfs(int u)
{
    us[u]=1;
    int i,ff=0;
    for(i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(us[v]==0)
        {
            dfs(v);
            if(d[v]>=3)
            {
                f=1;
            }
            if(d[v]==2)
            {
                ff=1;
            }
            d[u]+=d[v]%2;
        }
    }
    if(ff==1&&d[u]==0&&u==p)
    {
        f=1;
    }
    d[u]++;
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        int v,u;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
        du[u]++;
        du[v]++;
    }
    for(i=1;i<=n;i++)
    {
        if(du[i]>=2)
        {
            p=i;
            break;
        }
    }
    G[0].push_back(p);
    G[p].push_back(0);
    dfs(0);
    /*for(i=0;i<=n;i++)
    {
        printf("%d ",d[i]);
    }
    printf("\n");*/
    if(f==1)
    {
        printf("First\n");
    }
    else
    {
        printf("Second\n");
    }
    return 0;
}
