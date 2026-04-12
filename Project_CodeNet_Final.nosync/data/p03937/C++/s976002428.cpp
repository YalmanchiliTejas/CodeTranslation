#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) REP(i, 0, n)
#define REP(i,s, e) for(int i = (int)(s); i < (int)(e); ++i)

struct UF {
  vector<int> d;
  UF(int n) : d(n, -1){};
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool same(int x, int y) {
    return root(x) == root(y); 
  }
  int size(int x) {
    return -d[root(x)];
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(size(x) > size(y)) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  UF uf(h * w);
  rep(y, h) {
    rep(x, w) {
      if(s[y][x] == '.') continue;
      rep(i, 4) {
	int nx = x + dx[i], ny = y + dy[i];
	if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
	if(s[ny][nx] == '.') continue;
	uf.unite(y*w+x, ny*w+nx);
      }
    }
  }
  if(uf.size(0) == h + w -1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}
