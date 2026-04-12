#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph = vector<vector<int> >;
Graph G;

void dfs(int v,vector<bool> &seen,int &res){
  bool end=true;
  for(int i=0;i<seen.size();++i){
    if(seen[i]==false && i!=v){
      end=false;
    }
  }
  if(end==true){
    res++;
    return;
  }
  seen[v]=true;
  for(auto nv : G[v]){
    if(seen[nv]) continue;
    dfs(nv,seen,res);
  }
  seen[v] = false;
}

int main(){
  int n,m;
  cin >> n >> m;
  G.assign(n,vector<int>());
  for(int i=0;i<m;++i){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<bool> seen(n,false);
  int res=0;
  dfs(0,seen,res);
  cout << res << endl;
  return 0;
}
