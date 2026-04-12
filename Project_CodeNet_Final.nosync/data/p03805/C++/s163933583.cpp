#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> e[10];
int n,m,sum;
int b[10];

void dfs(int x)
{
    int i,f = 1;
    for(i=1;i<=n;i++)
    {
        if(b[i] == 0)
            f = 0;
    }
    if(f == 1)
    {
        sum++;
        return;
    }
    for(i=0;i<e[x].size();i++)
    {
        int xx = e[x][i];
        if(b[xx] || x == xx)
            continue;
        b[xx] = 1;
        dfs(xx);
        b[xx] = 0;
    }
}
int main(void)
{
    int i,j;
    while(scanf("%d%d",&n,&m)==2)
    {
        int x,y;
        for(i=0;i<=n;i++)
            e[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        sum = 0;
        memset(b,0,sizeof(b));
        b[1] = 1;
        dfs(1);
        printf("%d\n",sum);
    }


    return 0;
}
