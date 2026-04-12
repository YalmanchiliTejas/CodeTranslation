#include <iostream>
#include <vector>
using namespace std;
#define WHITE 0
#define GRAY  1
#define BLACK 2

int am[8][8];
int color[8];
int n, m;

int dfs(int u) {
  color[u] = GRAY;
  bool allVisited = true;
  for (int i=0; i<n; i++) {
    if (color[i] == WHITE) {
      allVisited = false;
    }
  }
  if (allVisited) {
    return 1;
  }


  int ans = 0;
  for (int i=0; i<n; i++) {
    if (am[u][i] != 0 && color[i] == WHITE) {
      ans += dfs(i);
      color[i] = WHITE;
    }
  }
  color[u] = BLACK;
  return ans;
}
  
  
  
int main() {
  cin >> n >> m;

  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
      am[i][j] = 0;
    }
    color[i] = WHITE;
  }
  int a, b;
  for (int i=0; i<m; i++) {
    cin >> a >> b;
    am[a-1][b-1] = 1;
    am[b-1][a-1] = 1;    
  }
  int ans = dfs(0);
  cout << ans << endl;
}
    
