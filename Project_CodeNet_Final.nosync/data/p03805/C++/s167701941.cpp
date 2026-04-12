#include<bits/stdc++.h>
using namespace std;
const int maxn=2002;
vector<int>m[maxn];
int n,p;
int sum;
int vis[maxn];
void dfs(int cot,int num)
{
    if(num==n)
    {
        sum++;
        return;
    }
    for(int i=0;i<m[cot].size();i++)
    {
        if(vis[m[cot][i]]==0)
        {
            vis[m[cot][i]]=1;
            dfs(m[cot][i],num+1);
            vis[m[cot][i]]=0;
        }
    }
}
int main()
{
    cin>>n>>p;
    for(int i=1;i<=p;i++)
    {
        int v,u;
        cin>>v>>u;
        m[v].push_back(u);
        m[u].push_back(v);
    }
    sum=0;
    vis[1]=1;
    dfs(1,1);
    cout<<sum<<endl;
    return 0;
}
