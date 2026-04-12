#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF -1
using namespace std;

typedef vector< vector<int> > table;

bool bfs(table& M,int n,int m,int s,vector<int>& r)
{
    vector<int> dist(n+1,0);
    queue<int> q;
    for (int i = 1; i <= n; i++) dist[i]=INF;
    dist[s]=0;
    q.push(s);
    vector<int> h;
    
    int now=0;
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        h.push_back(u);
        for (int v = 1; v <= n; v++)
        {
            if(M[u][v]==0)continue;
            if(dist[v]!=INF)continue;
            if(v!=r[now])continue;
            dist[v]=dist[u]+1;
            q.push(v);
            now++;
            break;
        }
    }
    if(now==r.size()) return true;
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> r; 
    for (int i = 2; i <= n; i++) r.push_back(i);
    table M(n+1,vector<int>(n+1,0));
    
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        M[a][b]=M[b][a]=1;
    }

    int count=0;
    do
    {
        if(bfs(M,n,m,1,r))count++;
    } while (next_permutation(r.begin(),r.end()));
    cout<<count<<endl;

    return 0;
}