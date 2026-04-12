#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N,M;
  cin >> N >> M;
  vector<vector<bool>> graph(N,vector<bool>(N,false));
  for(ll i=0;i<M;i++){
    for(ll j=0;j<M;j++){
      ll a,b;
      cin >> a >> b;
      graph[a-1][b-1]=true;
      graph[b-1][a-1]=true;
    }
  }
  vector<ll> Root(N,0);
  iota(Root.begin(),Root.end(),1);
  ll ans=0;
  do{
    bool flag=true;
    for(ll i=0;i<N-1;i++){
      if(graph[Root[i]-1][Root[i+1]-1]){
        continue;
      }
      else{
        flag=false;
        break;
      }
    }
    if(flag){
      ans++;
    }
  }while(next_permutation(Root.begin()+1,Root.end()));
  cout << ans << endl;
}

