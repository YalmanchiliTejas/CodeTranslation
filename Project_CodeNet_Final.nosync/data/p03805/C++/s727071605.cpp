
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
#define FF(i,a,b) for (int i=a;i<=b;i++)
#define F(i,b,a)  for (int i=b;i>=a;i--)
#define mes(a,b)  memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
typedef long long ll;
const int N = 10;

int G[N][N], vis[N], cnt, ans, n, m;
void dfs(int u)
{
    cnt++, vis[u]=1;
    if(cnt==n)  ans++;
    FF(i,1,n) {
        if(vis[i]==0 && G[u][i]==1) dfs(i);
    }
    vis[u]=0, cnt--;
}
int main()
{
    cin>>n>>m;
    int u, v;
    FF(i,1,m) cin>>u>>v, G[u][v]=G[v][u]=1;
    dfs(1);
    cout<<ans<<endl;

    return 0;
}
