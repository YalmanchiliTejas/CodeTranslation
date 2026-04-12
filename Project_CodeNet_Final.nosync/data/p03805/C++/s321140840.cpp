#include<bits/stdc++.h>
using namespace std;

int n,m,ans=0;
vector<vector<int>> g(8);
vector<int> c(8),d;
void dfs(int k,int cnt){
  c.at(k)=1;
  d.push_back(k);
  if(cnt==n){
    ans++;
//    for(auto y:d) cout<<y+1<<' ';
//    cout<<endl;
  }
  else{
    for(auto z:g.at(k)) if(c.at(z)==0) dfs(z,cnt+1);
  }
  c.at(k)=0;
  d.erase(prev(d.end(),1));
}
int main(){
  int x,y,i;
  cin>>n>>m;
  for(i=0;i<m;i++){
    cin>>x>>y;
    x--;y--;
    g.at(x).push_back(y);
    g.at(y).push_back(x);
  }
  dfs(0,1);
  cout<<ans<<endl;
}