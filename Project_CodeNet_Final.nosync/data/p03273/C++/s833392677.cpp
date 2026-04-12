#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int h, w;
  cin >> h >> w;
  char a[h][w];
  vector<int> col, row;
  vector<vector<char>> ans;
  for (size_t i = 0; i < h; i++) {
    for (size_t j = 0; j < w; j++) cin >> a[i][j];
  }
  for (int i = 0; i < h; i++) {
    bool tf = true;
    for (int j = 0; j < w; j++) {
      if (a[i][j]!='.') tf = false;
    }
    if (tf) row.push_back(i);
  }
  for (int i = 0; i < w; i++) {
    bool tf = true;
    for (int j = 0; j < h; j++) {
      if (a[j][i]!='.') tf = false;
    }
    if (tf) col.push_back(i);
  }
  for (int i = 0; i < h; i++) {
    if (distance(row.begin(),find(row.begin(),row.end(), i))!=row.size()) continue;
    else{
      vector<char> temp;
      for (int j = 0; j < w; j++) {
        if (distance(col.begin(),find(col.begin(),col.end(), j))!=col.size()) continue;
        else {
          temp.push_back(a[i][j]);
        }
      }
      ans.push_back(temp);
    }
  }

  for (size_t i = 0; i < ans.size(); i++) {
    for (size_t j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
