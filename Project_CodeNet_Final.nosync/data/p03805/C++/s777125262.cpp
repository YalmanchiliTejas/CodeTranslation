#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<ll> v[10];
bool tf[10];
ll ans=0;
void DFS(ll x,ll k){
  if(k==n){
      ans++;
      return;
  }
  tf[x]=true;
  for(auto z:v[x]){
      if(!tf[z]){
          DFS(z,k+1);
      }
  }
  tf[x]=false;
}
int main(void) {
  cin>>n>>m;
  for(int i=0;i<m;i++){
      ll a,b;
      cin>>a>>b;
      v[a].push_back(b);
      v[b].push_back(a);
  }
  DFS(1,1);
  cout<<ans<<endl;
  return 0;
}