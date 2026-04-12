#include <bits/stdc++.h>
using namespace std;
vector<int> a[1000];
int ans;
int bj[1005];
void dfs(int k,int n,int c)
{
    if(c==n)
    {
        ans++;
        return;
    }
    for(int i=0; i<a[k].size(); i++)
    {
        if(!bj[a[k][i]])
        {
            bj[a[k][i]]=1;
            dfs(a[k][i],n,c+1);
            bj[a[k][i]]=0;
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(bj,0,sizeof(bj));
    ans=0;
    bj[1]=1;
    dfs(1,n,1);
    printf("%d\n",ans);
    return 0;
}
