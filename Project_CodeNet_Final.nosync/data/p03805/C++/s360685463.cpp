#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;
const int MAXN = 15;
const int MAXCASE = 25;
vector<int> m[MAXN];
int n, p;
int sum;
int vis[MAXN];
int judge[MAXN][MAXN];
void dfs(int cot,int num)
{
    if(num == n)
    {
        sum++;
        return;
    }
    for(int i = 0;i < m[cot].size();i++)
    {
        if(vis[m[cot][i]] == 0)
        {
            vis[m[cot][i]] = 1;
            dfs(m[cot][i],num + 1);
            vis[m[cot][i]] = 0;
        }
    }
}
int main()
{
    int Test, numCase = 0;
    //cin >> Test;
    while(cin >> n >> p)
    {

        assert(2 <= n && n <= 8);
        assert(1 <= p && p <= n * (n - 1) / 2);

        memset(judge, 0, sizeof(judge));
        numCase++;
        for(int i=1;i<=p;i++)
        {
            int v,u;
            cin >> v >> u;
            m[v].push_back(u);
            m[u].push_back(v);

            assert(1 <= v && v <= n);
            assert(1 <= u && u <= n);
            assert(u != v && judge[u][v] == judge[v][u] && judge[u][v] == 0);
            judge[u][v] = judge[v][u] = 1;
        }

        sum = 0;
        vis[1] = 1;
        dfs(1, 1);
        cout << sum << endl;
    }
    //assert(numCase == MAXCASE);
    return 0;
}
