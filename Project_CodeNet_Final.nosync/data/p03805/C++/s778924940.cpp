#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

vector<vector<bool>>x(8,vector<bool>(8));
int dfs(int v,int N,bool visited[8]){
  bool all_visited=true;
  rep(i,N){
    if(visited[i]==false){
      all_visited=false;
    }
  }
  if(all_visited){
    return 1;
  }
  int ans=0;
  rep(i,N){
    if(x[v][i]==false){
      continue;
    }
    if(visited[i]){
      continue;
    }
    
    visited[i]=true;
    ans+=dfs(i,N,visited);
    visited[i]=false;
  }
  return ans;
}

int main() {
  int n,m;
  cin >> n>>m;
  
  vector<int>a(m),b(m);
  rep(i,m){
    cin>>a.at(i)>>b.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  
  rep(i,m){
    x.at(a.at(i)).at(b.at(i))=true;
    x.at(b.at(i)).at(a.at(i))=true;    
  }
  bool visited[8];
  rep(i,8){
    visited[i]=false;
  }
  visited[0]=true;
  
  cout<<dfs(0,n,visited)<<endl;
 
}