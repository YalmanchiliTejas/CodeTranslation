#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> vec(h);
  for (auto &v : vec)
    cin >> v;

  vector<int> hidx, widx;
  for (int i = 0; i < h; ++i) {
    bool flag = false;
    for (int j = 0; j < w; ++j)
      if (vec[i][j] == '#')
        flag = true; 
    if (flag)
      hidx.push_back(i);
  }

  for (int i = 0; i < w; ++i) {
    bool flag = false;
    for (int j = 0; j < h; ++j)
      if (vec[j][i] == '#')
        flag = true;
    if (flag)
      widx.push_back(i);
  }

  for (auto &i : hidx) {
    for (auto &j : widx)
      cout << vec[i][j];
    cout << endl;
  }
}
