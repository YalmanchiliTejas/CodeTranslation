/*  
   |\_/|
   |* *|
   \_+_/
          */
#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int used[10];
int cnt=0;

vector<int>node[10];
  
int N,M;

int ans=0;

int dfs(int i){

  if(cnt==N-1){
    ans++;
  }
  
  used[i]=1;
  
  for(int j=0;j<node[i].size();j++){

    if(used[node[i][j]]==0){
      cnt++;
      dfs(node[i][j]);
      used[node[i][j]]=0;
      cnt--;
    }

  }

  return 0;
}

int main(){

  cin.tie(0);     // cout と cin の同期を切る
  ios::sync_with_stdio(false);  /* cの stdioストリーム (printfとか)と*/

  cin>>N>>M;

  int a,b;  
  
  for(int i=0;i<M;i++){
    cin>>a>>b;

    node[a].push_back(b);
    node[b].push_back(a);

  }

  dfs(1);

  cout<<ans<<endl;
  
  return 0;

}
