#include<bits/stdc++.h>
using namespace std;
bool all(const vector<bool>&xs){
  for(const auto&x:xs)if(!x)return false;
  return true;
}
void Print(const vector<bool>&xs){
  for(const auto&x:xs)cout<<x<<",";
}
int N,M;
vector<vector<bool>>xss;
int f(int from,vector<bool>visited){
  visited[from]=true;
  // cout<<from<<"...";Print(visited);cout<<endl;
  if(all(visited))return 1;
  int n_paths=0;
  for(int i=0;i<N;++i){
    if(xss[from][i]&&!visited[i])
      n_paths+=f(i,visited);
  }
  return n_paths;
}
main(){
  cin>>N>>M;
  xss=vector<vector<bool>>(N,vector<bool>(N));
  for(int i=1;i<=M;++i){
    int a,b;
    cin>>a>>b;
    --a;
    --b;
    xss[a][b]=true;
    xss[b][a]=true;
  }
  int n_paths=f(0,vector<bool>(N));
  cout<<n_paths<<endl;
}
