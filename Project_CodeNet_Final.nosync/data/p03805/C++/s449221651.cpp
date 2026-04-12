#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g(0, vector<int>(0));
int solve(int x, int cnt, vector<int> c){
  c.at(x) = 1;
  bool ok = true;
  for(auto now : c) if(!now) ok = 0;
  if(ok) return ++cnt;
  
  for(auto now : g.at(x)){
    if(c.at(now)) continue;
    cnt = solve(now, cnt, c);
  }
  return cnt;
}

int main() {
  cin >> n >> m;
  g.resize(n);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;
    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }
  
  vector<int> check(n);
  int ans = solve(0, 0, check);
  
  cout << ans << endl;
}