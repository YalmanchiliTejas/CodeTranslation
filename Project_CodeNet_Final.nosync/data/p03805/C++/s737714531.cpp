#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
vector<int> a,b;
vector<bool> visit;
vector<vector<bool>> ab;
void dfs(int t){
  visit[t]=true;
  for(int i=0;i<n;i++){
    if(ab[t][i]&&visit[i]!=true){
      dfs(i);
    }
  }
  int f=0;
  for(int i=0;i<n;i++){
    if(visit[i]){
      f++;
    }
  }
  if(f==n){
    cnt++;
  }
  visit[t]=false;
}
int main(){
  cin>>n>>m;
  a.resize(m);
  b.resize(m);
  visit.resize(n);
  ab.resize(n);
  for(int i=0;i<n;i++){
    ab[i].resize(n);
    for(int j=0;j<n;j++){
      ab[i][j]=false;
    }
  }
  for(int i=0;i<m;i++){
    int aa,bb;
    cin>>aa>>bb;
    a.at(i)=--aa;
    b.at(i)=--bb;
    ab[a[i]][b[i]]=true;
    ab[b[i]][a[i]]=true;
  }
  dfs(0);
  cout<<cnt;
}