#include <iostream>
#include <vector>

using namespace std;

int main() {
  char a[100][101];
  int h, w;
  cin >> h >> w;
  vector<bool> col(w, false);
  vector<bool> row(h, false);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char c;
      cin >> c;
      row[i] = row[i] || c == '#';
      col[j] = col[j] || c == '#';
      a[i][j] = c;
    }
  }
  for (int i = 0; i < h; ++i) {
    if (!row[i]) continue;
    for (int j = 0; j < w; ++j) {
      if (!col[j]) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
}
