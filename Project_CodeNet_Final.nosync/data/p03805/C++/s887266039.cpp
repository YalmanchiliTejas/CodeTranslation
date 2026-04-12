#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
vector<vector<bool>> ab;
vector<bool> br;
void dfs(int i){
  br[i]=true;
  bool f=true;
  for(int j=0;j<n;j++){
    if(!br[j]){
      f=false;
      break;
    }
  }
  if(f){
    cnt++;
  }
  for(int j=0;j<n;j++){
    if(!br[j]&&ab[i][j]){
      dfs(j);
    }
  }
  br[i]=false;
}
int main(){
  cin>>n>>m;
  ab.resize(n);
  br.resize(n);
  for(int i=0;i<n;i++){
    ab[i].resize(n);
    br[i]=false;
    for(int j=0;j<n;j++){
      ab[i][j]=false;
    }
  }
  int a,b;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    ab[a-1][b-1]=true;
    ab[b-1][a-1]=true;
  }
  cnt=0;
  dfs(0);
  cout<<cnt;
}