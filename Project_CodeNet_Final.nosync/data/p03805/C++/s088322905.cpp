#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

void dfs(vector<vector<bool>> &graph,vector<bool> &visited,int v,int N,int &ans){
  bool check=true;
  for(int i=0;i<N;i++)  if(!visited.at(i)) check=false;
  if(check){
    ans++;
    return;
  }

  for(int i=0;i<N;i++){
    if(graph.at(v).at(i)==true && visited.at(i)==false){
      visited.at(i)=true;
      dfs(graph,visited,i,N,ans);
      visited.at(i)=false;
    }
  }

  return;
}

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> a(M);
  vector<int> b(M);
  for(int i=0;i<M;i++){
    cin >> a.at(i) >> b.at(i);
    a.at(i)--;
    b.at(i)--;
  }

  vector<vector<bool>>  graph(N,vector<bool>(N,false));
  for(int i=0;i<M;i++){
    graph.at(a.at(i)).at(b.at(i))=true;
    graph.at(b.at(i)).at(a.at(i))=true;
  }

  vector<bool> visited(N,false);
  visited.at(0)=true;
  int ans=0;
  dfs(graph,visited,0,N,ans);

  cout << ans << endl;

  return 0;
}
