#include<iostream>
#include<queue>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<vector>

using namespace std;
#define MAX_V 10
int N,M;
bool G[MAX_V][MAX_V];
bool used[MAX_V];

// 全頂点を訪問済みならtrue,そうでないならfalse
bool finish(void)
{
  int i;
  for(i=0;i<N;i++)
    if(!used[i])
      return false;
  return true;
}
int dfs(int v)
{
  if(finish()) return 1;
  int sum=0;
  int i;
  for(i=0;i<N;i++)
    {
      if(!G[v][i]) continue;
      if(used[i]) continue;
      used[i]=true;
      sum+=dfs(i);
      used[i]=false;
    }
  return sum;
}

int main(void)
{
  cin>>N>>M;
  int i;
  for(i=0;i<M;i++)
    {
      int a,b;
      cin>>a>>b;
      G[a-1][b-1]=true;
      G[b-1][a-1]=true;
    }
  used[0]=true;
  cout<<dfs(0)<<endl;
}
