#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int H,W;
char field[9][9];
int dx[2] = {0,1};
int dy[2] = {1,0};

bool DFS(int x,int y) {
  if (x == H - 1 && y == W - 1) {
    return true;
  } else {
    bool res = false;
    for (int i = 0; i < 2; i++) {
      int fx = x + dx[i];
      int fy = y + dy[i];
      if (field[fx][fy] == '#' && fx <= H - 1 && fy <= W - 1) {
        if (DFS(fx,fy)) {
          res = true;
        }
      } 
    }
    return res;
  }
}

int main() {
  cin >> H >> W;
  int cnt = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> field[i][j];
      if (field[i][j] == '#') {
        cnt++;
      }
    }
  }
  bool ans = true;
  if (!DFS(0,0)) {
    ans = false;
  }
  if (H + W - 1 != cnt) {
    ans = false;
  }
  if (ans) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}