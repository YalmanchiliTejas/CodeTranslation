#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  int n,m; cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i,m){
    int a,b;cin >> a >> b;
    --a;--b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int ans = 0;
  vector<int> perm;
  rep(i,n-1) perm.push_back(i+1);
  bool flag;
  do{
    // rep(i,n-1) cout << perm[i] << " ";
    // cout << endl;
    flag = true;
    int ind = 0;
    for(int i = 0;i < perm.size();i++){
      bool ok = false;
      for(auto nv:G[ind]) {
        //cout << nv <<" "<< perm[i] <<" " <<ind << endl;
        if(nv==perm[i]) ok = true;
      }
      if(!ok){
        flag = false;
        break;
      }
      ind = perm[i];
    }
    if(flag) {
      ans++;
      // rep(i,n-1) cout << perm[i] << " ";
      // cout << endl;
    }

  }while(next_permutation(perm.begin(),perm.end()));

  cout << ans << endl;
}