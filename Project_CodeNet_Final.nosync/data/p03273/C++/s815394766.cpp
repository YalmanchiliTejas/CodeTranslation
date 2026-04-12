#include <iostream>
#include <vector>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<int> a(w);
  vector<int> b(h);
  vector<vector<char>> grid(h, vector<char>(w));

  for (int i=0; i<h; i++) {
    int bcnt=0;
    for (int j=0; j<w; j++) {
      cin >> grid[i][j];
      
      if (grid[i][j]=='.') {
        a[j]++;
        bcnt++;
      }
    }
    if (bcnt==w) b[i]++;
  }

  for (int i=0; i<h; i++) {
    if (b[i]) continue;
    for (int j=0; j<w; j++) {
      if (a[j]==h) continue;
      cout << grid[i][j];
    }
    cout << endl;
  }
}