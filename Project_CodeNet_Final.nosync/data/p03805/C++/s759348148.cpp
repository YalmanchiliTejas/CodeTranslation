#include <bits/stdc++.h>
using namespace std;
const int nmax=8;
bool graph[nmax][nmax];
int dfs(int v,bool visited[nmax],int n)
{
   bool allvisited=true;
   for(int i=0;i<n;i++)
   {
       if(!visited[i])
        allvisited=false;
   }
   if(allvisited)return 1;
   int ret=0;
   for(int i=0;i<n;i++)
   {
       if(graph[v][i]==false)continue;
       if(visited[i])continue;
       visited[i]=true;
       ret+=dfs(i,visited,n);
       visited[i]=false;
   }
   return ret;
}
int main()
{
    int i,j,n,m,ans,a,b;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a-1][b-1]=graph[b-1][a-1]=true;
        
    }
    bool visited[nmax];
    for(int i=0;i<n;++i){
    visited[i]=false;
    }
    visited[0]=true;
    ans=dfs(0,visited,n);
    cout<<ans;
}
