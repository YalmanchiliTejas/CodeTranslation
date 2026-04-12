#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

void dfs(vector<vector<int>> &gr, int now, vector<bool> chk, int ct, int &ans){
  chk.at(now) = true;
  ct++;
  bool f = false;
  for(auto i : gr.at(now)){
    if(chk.at(i) == true) continue;
    f = true;
    dfs(gr, i, chk, ct, ans);
  }
  if(f == false){
    if(ct == gr.size()) ans++;
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
  vector<bool> chk(n, false);
  int ans = 0;
  dfs(gr, 0, chk, 0, ans);
  cout << ans << endl;
  return 0;
}