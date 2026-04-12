#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

void dfs(vector<vector<int>> &gr, int now, int chk, int &ans){
  chk += 1 << now;
  bool f = true;
  for(int nx : gr.at(now)){
    if((chk & (1 << nx)) == 0){
      dfs(gr, nx, chk, ans);
      f = false;
    }
  }
  if(f == true){
    int a = __builtin_popcount(chk);
    if(a == gr.size()){
      ans++;
    }
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  int ans = 0;
  dfs(gr, 0, 0, ans);
  cout << ans << endl;
  return 0;
}