#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for (int i=0,_n=(int)(n); i < _n; i++)
template<class T> bool chmax(T &a, T b) { return a < b ? (a = b, true) : false; }
template<class T> bool chmin(T &a, T b) { return a > b ? (a = b, true) : false; }
 
typedef long long ll;

int main2() {
  int H, W;
  cin >> H >> W;
  vector<string> vs;
  REP(i, H) {
    string s; cin >> s;
    vs.push_back(s);
  }
  bool possible = true;

  int s = 0;
  REP(i, H) REP(j, W) if (vs[i][j] == '#') s++;
  int step = 0;
  int h = 0, w = 0;
  for (;;) {
    step++;
    if (h == H - 1 && w == W - 1) break;
    bool right = w+1 < W && (vs[h][w+1] == '#');
    bool down = h+1 < H && (vs[h+1][w] == '#');
    if (right && down) {
      possible = false; break;
    }
    if (!right && !down) {
      possible = false; break;
    }
    if (right) w++;
    else if (down) h++;
  }
  if (step != s) possible = false;
  
  cout << (possible ? "Possible" : "Impossible") << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws) main2();
  return 0;
}