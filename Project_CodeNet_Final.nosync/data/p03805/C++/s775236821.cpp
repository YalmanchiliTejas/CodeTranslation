#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

vector<bool> seen;
int sum;
int N,M;

void dfs(const Graph &G, int v) {
  
  seen[v]=true;

  int cnt=0;
  for(int i=0;i<N;++i){
    if(seen[i]){
      ++cnt;
    }
  }
  if(cnt==N) ++sum;
  
  for(auto next_v:G[v]){
    if(seen[next_v]) continue;
    dfs(G,next_v);
    seen[next_v]=false;
  }
  
}

int main(){
    cin>>N>>M;
    Graph G(N);
  
    for(int i=0;i<M;++i) {
      int a,b;
      cin>>a>>b;
      --a,--b;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    sum=0;
    seen.assign(N, false);//falseで初期化する
    dfs(G,0);
    cout<<sum<<endl;
}
