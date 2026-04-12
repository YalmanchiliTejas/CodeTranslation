#include <bits/stdc++.h>

using namespace std;
int vis[9]={},x=0;
int n,m;
vector<vector<int> >v(9);
void dfs(int i)
{
    int q=0;
    for (int j=0;j<v[i].size();j++)
    {
        if(vis[v[i][j]]==0)
        {
            q=1;
            vis[v[i][j]]=1;
            dfs(v[i][j]);
            vis[v[i][j]]=0;
        }
    }
    if(q==0)
    {
        for (int j=1;j<=n;j++)
        {
            if(vis[j]==0)
                return;
        }
        x++;
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vis[1]=1;
    dfs(1);
    cout<<x<<endl;
    return 0;
}
