#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int dfs(vector<vector<bool>> &graph,vector<bool> &flag,int v,int N,int &ans){
  bool check=true;
  for(int i=0;i<N;i++)  if(!flag.at(i)) check=false;
  if(check){
    ans++;
    return 0;
  }

  for(int i=0;i<N;i++){
    if(graph.at(v).at(i)==true && flag.at(i)==false){
      flag.at(i)=true;
      dfs(graph,flag,i,N,ans);
      flag.at(i)=false;
    }
  }

  return ans;
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

  vector<bool> flag(N,false);
  flag.at(0)=true;
  int ans=0;

  cout << dfs(graph,flag,0,N,ans) << endl;

  return 0;
}
