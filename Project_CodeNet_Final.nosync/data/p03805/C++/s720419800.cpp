#include <iostream>
using namespace std;

bool used[8];
int k[8][8];
int n,m,ans=0;
bool check(){ //すべて訪問済みか
  for(int i=0;i<n;i++){
    if(!used[i]) return false;
  }
  return true;
}
void dfs(int a){
  used[a]=true;
  for(int i=0;i<n;i++){
    if(!used[i]&&k[a][i]){
      dfs(i);
    }
  }
  if(check()) ans++;
  used[a]=false;
  return;
}
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b; a--,b--;
    k[a][b]=k[b][a]=1;
  }
  dfs(0);
  cout<<ans<<"\n";

}
