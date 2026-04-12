#include <bits/stdc++.h>
using namespace std;
vector<int> e[10];
bool check[10];
int ans,n,m;
void dfs(int p,int tot)
{
    check[p] = 1;
    if (tot == n)
    {
        ans++;
    } else {
        for (int i = 0;i < e[p].size();i++)
        {
            if (check[e[p][i]]) continue;
            dfs(e[p][i],tot+1);
        }
    }
    check[p] = 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 0;i < m;i++)
    {
        int x,y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,1);
    printf("%d\n",ans);
}
