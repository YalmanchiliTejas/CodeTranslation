#include<bits/stdc++.h>
using namespace std;
int n,m,c;
vector<bool> edge(8);
vector<int> to[8];
void dfs(int now,int cnt){
  if(cnt==n){
    c++;
    return;
  }
  for(auto au:to[now]){
    if(!edge[au]){
      edge[au]=true;
      dfs(au,cnt+1);
      edge[au]=false;
    }
  }
}
int main(){
  cin>>n>>m;
  int a,b;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    a--,b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  edge[0]=true;
  dfs(0,1);
  cout<<c<<endl;
}