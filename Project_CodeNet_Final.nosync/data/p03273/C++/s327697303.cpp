#include <iostream>
#include <vector>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  for(int i = 0; i < h; ++i)
    cin >> v[i];
  vector<bool> row(h, false);
  vector<bool> col(w, false);
  for(int i = 0; i < h; ++i) {
    for(int j = 0; j < w; ++j) {
      if(v[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }
  for(int i = 0; i < h; ++i) {
    if(row[i]) {
      for(int j = 0; j < w; ++j)
        if(col[j])
          cout << v[i][j];
      cout << endl;
    }
  }
  return 0;
}