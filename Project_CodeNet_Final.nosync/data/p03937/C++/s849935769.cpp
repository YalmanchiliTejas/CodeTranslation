#include<iostream>
#include<vector>
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)

using namespace std;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int H, W;
vector<vector<char>> cc;
vector<vector<int>> check;

bool dfs (int x, int y) {
  check[y][x] = 1;
  if (x == W && y == H) {
    bool f = true;
    REP (i, 1, H + 1) {
      REP (j, 1, W + 1) {
	if (!((cc[i][j] == '#' && check[i][j] == 1) || (cc[i][j] == '.' && check[i][j] == 0))) f = false;
      }
    }
    if (f) return true;
    check[y][x] = 0;
    return false;
  }
  REP (i, 0, 2) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (cc[yy][xx] == '.') continue;
    bool f = dfs(xx, yy);
    if (f) return true;
  }
  check[y][x] = 0;
  return false;
}


int main () {
  cin >> H >> W;
  cc = vector<vector<char>>(10, vector<char>(10, '.'));
  check = vector<vector<int>>(10, vector<int>(10, 0));
  REP (i, 1, H + 1) {
    REP (j, 1, W + 1) {
      cin >> cc[i][j];
    }
  }
  cout << (dfs(1, 1) == 1 ? "Possible" : "Impossible") << endl;
  return 0;
}
