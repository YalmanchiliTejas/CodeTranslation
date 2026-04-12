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

void dfs(const vector<vector<int>> &gr, vector<bool> &chk, int now, int c, int &ans){
  if(c == chk.size()){
    ans++;
    return ;
  }
  for(auto nx : gr.at(now)){
    if(chk.at(nx) == true) continue;
    chk.at(nx) = true;
    dfs(gr, chk, nx, c+1, ans);
    chk.at(nx) = false;
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
  chk.at(0) = true;
  int ans = 0;
  dfs(gr, chk, 0, 1, ans);
  cout << ans << endl;

  return 0;
}