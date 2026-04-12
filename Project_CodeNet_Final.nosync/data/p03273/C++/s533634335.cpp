#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;

  vector<bool> row(h, false), col(w, false);
  string s[h];

  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        row[i] = col[j] = true;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    if (!row[i]) continue;
    for (int j = 0; j < w; j++) {
      if (!col[j]) continue;
      cout << s[i][j];
    }
    cout << endl;
  }
}
