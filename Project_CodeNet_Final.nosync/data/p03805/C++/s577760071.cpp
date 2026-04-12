#include <bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int> >;

int sum=0;

void dfs(Graph &g,vector<bool> visit,int v){
  visit[v]=true;
  vector<bool> fin(visit.size(),true);
  if(visit==fin){
    sum++;
    return ;
  }
  for(auto nv:g.at(v)){
    if(visit[nv]){
      continue;
    }
    dfs(g,visit,nv);
  }
}

int main(){
  int N,M;
  cin>>N>>M;
  Graph G(N);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    G.at(a-1).push_back(b-1);
    G.at(b-1).push_back(a-1);
  }

  vector<bool> visit(N,false);
  dfs(G,visit,0);

  cout<<sum<<endl;
}
