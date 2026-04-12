#include <bits/stdc++.h>
using namespace std;

int n;

int f(int pos, int cnt, vector<vector<int>> &v){
  cnt += (1 << pos);
  if(cnt == (1<<n) -1) return 1;
  int ans = 0;
  for(int a:v[pos]){
    if(cnt >> a &1) continue;
    ans += f(a,cnt,v);
  }
  return ans;
}

int main(){
  int m, a, b;
  cin >> n >> m;
  vector<vector<int>> vn(n);
  for(int i=0; i<m; ++i){
    cin >> a >> b;
    --a; --b;
    vn[a].push_back(b);
    vn[b].push_back(a);
  }
  int ans = 0;
  ans += f(0,0,vn);
  cout << ans << endl;
}