#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <queue>
typedef long long ll;
#define rep(i,n) for(int i = 0;i<n;++i)
#define repnc(bit,k,n) for (int bit = (1<<k)-1;bit < (1<<n); bit = next_combination(bit))
#define repi(itr,vec) for(auto itr = vec.begin();itr!=vec.end();++itr)
using namespace std;
using Graph = vector<vector<int> >;

/* next combination */
int next_combination(int sub) {
  int x = sub & -sub, y = sub + x;
  return (((sub & ~y) / x) >> 1) | y;
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
  int n,m;cin>>n>>m;
  Graph G(n);
  rep(i,m){
    int a,b;cin>>a>>b;a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> v;
  rep(i,n-1){
    v.push_back(i+1);
  }
  int ans = 0;
  do{
    bool flag = true;
    if(find(G[0].begin(),G[0].end(),v[0])==G[0].end())continue;
    rep(i,n-2){
      vector<int>temp = G[v[i]];
      if(find(temp.begin(),temp.end(),v[i+1])==temp.end()){
        flag=false;
        break;
      }
    }
    if(flag) ans++;
  }while(next_permutation(v.begin(),v.end()));
  cout << ans << '\n';
        return 0;
}