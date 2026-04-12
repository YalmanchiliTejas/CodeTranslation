#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for(int i = 0; i < h; i++) cin >> a.at(i);
  
  bool ok = true;
  vector<int> dx = {0, 1, 0, -1};
  vector<int> dy = {1, 0, -1, 0};
  vector<vector<int>> check(h, vector<int>(w));
  queue<pair<int, int>> dfs;
  dfs.push({0,0});
  while(dfs.size() > 0){
    queue<pair<int, int>> now;
    while(dfs.size() > 0){
      now.push(dfs.front());
      dfs.pop();
    }
    
    while(now.size() > 0){
      auto nw = now.front();
      now.pop();
      check.at(nw.second).at(nw.first) = 1;
      int cnt = 0;
      for(int i = 0; i < 4; i++){
        int nx = nw.first + dx.at(i), ny = nw.second + dy.at(i);
        if(nx >= w || nx < 0 || ny >= h || ny < 0) continue;
        if(a.at(ny).at(nx) == '.') continue;
        if(check.at(ny).at(nx) == 1) continue;
        if(i >= 2) ok = false;
        cnt++;
        dfs.push({nx, ny});
      }
      if(cnt > 1){
        ok = false;
        break;
      }
    }
  }
  if(check.at(h-1).at(w-1) != 1) ok = false;
  
  if(ok) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}