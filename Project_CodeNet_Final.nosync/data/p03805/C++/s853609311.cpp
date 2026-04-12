#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

vector<vector<int>> a;

ll dfs(vector<bool> used, ll from){
  used[from] = true;
  bool ok = true;
  rep(i, used.size()){
    if(!used[i]) ok = false;
  }
  if(ok)  return 1;

  ok = false;
  ll count = 0;
  rep(i, a[from].size()){
    if(!used[a[from][i]]){
      count += dfs(used, a[from][i]);
      ok = true;
    }
  }
  if(ok)  return count;
  else return 0;
}

int main(){
  int n, m;
  cin >> n >> m;
  a.resize(n);
  rep(i, m){
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    a[s].push_back(t);
    a[t].push_back(s);
  }
  vector<bool> used(n, false);
  ll ans = dfs(used, 0);
  cout << ans << endl;
}