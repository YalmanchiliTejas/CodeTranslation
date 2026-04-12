#include <iostream>
#include <vector>

using namespace std;

#define ALL(x) begin(x), end(x)

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> grid;
  vector<bool> cok(W,false);

  string rowstr;
  for(auto i = 0; i != H; ++i) {
    cin >> rowstr;
    if (rowstr == string(W,'.')) continue;
    grid.push_back(rowstr);
    for (auto j = 0; j != W; ++j) {
      cok[j] = cok[j] || (rowstr[j] == '#');
    }
  }

  for (auto &row: grid) {
    for (auto i = 0; i != W; ++i) {
      if (cok[i]) cout << row[i];
    }
    cout << endl;
  }
  
  return 0;
}
