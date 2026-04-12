#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;


#define INF (1ll<<60)

long long gcd(long long a, long long b){
  if(b==0)return a;
  return gcd(b, a%b);
}

vector<vector<int>> G;

vector<int> match;
vector<bool> seen0;

bool dfs(int u){
  // cout<<Gl.size()<<endl;
  for(int v:G[u]){
    // cout<<"!"<<endl;
    if(!seen0[v]){
      seen0[v]=true;
      if(match[v]==-1||dfs(match[v])){
        match[v]=u;
        return true;
      }
    }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int n;cin>>n;
  G=vector<vector<int>>(n);
  for(int i=0;i<n-1;++i){
    int u,v;cin>>u>>v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  queue<int> que;
  vector<int> seen(n);
  que.push(0);
  int res=0;
  seen[0]=1;
  res+=seen[0];
  while(!que.empty()){
    int u=que.front();
    que.pop();
    for(int v:G[u]){
      if(seen[v]==0){
        seen[v]=-seen[u];
        res+=seen[v];
        que.push(v);
      }
    }
  }
  if(res!=0){
    cout<<"First"<<endl;
    return 0;
  }
  match=vector<int>(n,-1);
  int numm=0;
  for(int i=0;i<n;++i){
    seen0=vector<bool>(n,false);
    if(seen[i]==1)numm+=dfs(i);
  }
  if(numm*2==n)cout<<"Second"<<endl;
  else cout<<"First"<<endl;
  return 0;
}
