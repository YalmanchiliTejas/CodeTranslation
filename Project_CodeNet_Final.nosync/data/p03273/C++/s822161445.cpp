#include <iostream>
#include <vector>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  char a[100][100] = {{'#'}};
  vector<int> rows(h, 1);
  vector<int> cols(w, 1);

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#') {
        rows[i] = 0;
        cols[j] = 0;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    if (rows[i]) continue;
    for (int j = 0; j < w; j++) {
      if (cols[j]) continue;

      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
