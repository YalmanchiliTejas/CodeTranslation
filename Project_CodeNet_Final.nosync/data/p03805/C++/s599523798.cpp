#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 8

bool graph[MAXN][MAXN];
int dfs(int v,int N,bool visited[MAXN])
{
  int i;
  bool all_visited=true;
  for(i=0;i<N;i++)
    {
      if(visited[i]==false)
	{
	  all_visited=false;
	}
    }
  if(all_visited == true)
    {
      return 1;
    }
  int ret=0;
  for(i=0;i<N;i++)
    {
      if(graph[v][i] == false) continue;
      if(visited[i] == true) continue;
      visited[i]=true;
      ret+=dfs(i,N,visited);
      visited[i]=false;
    }
  return ret;
}

int main(int argc,char const* argv[])
{
  int n,m,i,ans,a,b;
  cin >> n >> m;
  for(i=0;i<m;i++)
    {
      cin >> a >> b;
      graph[a-1][b-1]=graph[b-1][a-1]=true;
    }

  bool visited[MAXN];
  for(i=0;i<n;i++)
    {
      visited[i]=false;
    }
  visited[0]=true;
  ans=dfs(0,n,visited);
  cout << ans << endl;
  return 0;
}
