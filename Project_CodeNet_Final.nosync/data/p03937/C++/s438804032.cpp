#include <iostream>
#include <vector>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  string ans = "Possible";
  for (int i = 0; i < h - 1; i++) {
    for (int j = 0; j < w - 1; j++) {
      if (a[i][j + 1] == '#' && a[i + 1][j + 1] == '#' && a[i + 1][j] == '#') {
        ans = "Impossible";
      }
      if (a[i][j + 1] == '#' && a[i][j] == '#' && a[i + 1][j] == '#') {
        ans = "Impossible";
      }
    }
  }
  cout << ans << endl;
  return 0;
}
