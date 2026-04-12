#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long int ll;
typedef vector<pair<ll,ll> > Q;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v,int n,bool visited[nmax])
{
  bool all=true;

  rep(i,n)
  {
    if(!visited[i]) all=false;
  }

  if(all) return 1;

  int ret=0;
  rep(i,n)
  {
      if(!graph[v][i]) continue;
      if(visited[i]) continue;

      visited[i]=true;
      ret+=dfs(i,n,visited);
      visited[i]=false;
  }
  return ret;
}

int main()
{
  int n,m;
  cin>>n>>m;

  rep(i,m)
  {
    int a,b;
    cin>>a>>b;
    graph[a-1][b-1]=graph[b-1][a-1]=true;
  }

  bool visited[nmax];
  rep(i,n) visited[i]=false;

  visited[0]=true;
  cout<<dfs(0,n,visited)<<endl;

}