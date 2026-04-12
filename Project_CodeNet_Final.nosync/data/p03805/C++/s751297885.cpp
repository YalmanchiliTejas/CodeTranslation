#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define local
//if you find any bug in my code, please tell me.
int graph[10][10],a[10],visit[10];
int n,m;
int dfs(int now, int cnt)
{
    if(cnt==n) return 1;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(graph[now][i]&&!visit[i])
        {
            visit[i]=1;
            ans+=dfs(i,cnt+1);
            visit[i]=0;
        }
    }
    return ans;
}
int main()
{
#ifdef local
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a][b]=graph[b][a]=1;
    }
    visit[1]=1;
    cout<<dfs(1,1)<<endl;
    return 0;
}
