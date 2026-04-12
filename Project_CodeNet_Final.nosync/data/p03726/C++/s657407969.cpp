#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
vector<ll> node[100005];
bool matched[100005],used[100005];
void dfs(ll pos){
  for(int i=0;i<node[pos].size();i++){
    ll son=node[pos][i];
    if(!used[son]){
      used[son]=true;
      dfs(son);
      if(!matched[pos]&&!matched[son]){
        matched[pos]=true;
        matched[son]=true;
      }
    }
  }
}
int main(){
  ll n;
  cin>>n;
  for(int i=1;i<n;i++){
    ll s,t;
    cin>>s>>t;
    node[s].push_back(t);
    node[t].push_back(s);
  }
  for(int i=1;i<=n;i++) {
    used[i]=false;
    matched[i]=false;
  }
  used[1]=true;
  dfs(1);
  for(int i=1;i<=n;i++){
    if(!matched[i]){
      cout<<"First"<<endl;
      return 0;
    }
  }
  cout<<"Second"<<endl;
  return 0;
}
