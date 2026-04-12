#include<iostream>
#include<map>
#include<vector>
#include<set>
 
using namespace std;
 
struct Node {
  int x, y, d;
};
 
bool operator<(const Node &lhs, const Node &rhs) {
  return lhs.d < rhs.d;
}
 
int hx[2] = {1, 0};
int hy[2] = {0, 1};
 
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> mp(h);
  for(int i = 0; i < h; i++) cin >> mp[i];
  vector<vector<bool>> ch(h);
  for(int i = 0; i < h; i++) ch[i].resize(w);
  multiset<Node> q;
  Node start{0, 0, 0};
  q.insert(start);
  vector<bool> route(10000);
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(ch[now.y][now.x] || route[now.d]) {
      cout << "Impossible" << endl;
      return 0;
    }
    ch[now.y][now.x] = true;
    route[now.d] = true;
    mp[now.y][now.x] = '.';
    for(int i = 0; i < 2; i++) {
      int x = now.x + hx[i], y = now.y + hy[i];
      if(x < 0 || x >= w || y < 0 || y >= h) continue;
      if(mp[y][x] != '#') continue;
      Node next{x, y, now.d + 1};
      q.insert(next);
    }
  }
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(mp[i][j] == '#') {
    cout << "Impossible" << endl;
    return 0;
  }
  if(ch[h - 1][w - 1]) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}