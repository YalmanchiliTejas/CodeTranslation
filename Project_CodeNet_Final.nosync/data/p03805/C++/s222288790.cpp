#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

bool used[10];

vector<int>node[10];

int N,M;

int ans(int i,int cnt){

  if(cnt==N-1){
    return 1;
  }

  int ret=0;

  used[i]=1;
  
  for(int j=0;j<node[i].size();j++){
    if(used[node[i][j]]!=1){
      ret+=ans(node[i][j],cnt+1);
    }
  }

  used[i]=0;

  return ret;

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

  cout<<ans(1,0)<<endl;
  
  return 0;

}
