#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cassert>
#include <memory>
#include <stack>
#include <set>

#define MAX_SIZE 100000000
typedef unsigned long long ull;
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  vector<string> lines(H);
  for(auto& line : lines) {
    cin >> line;
  }

  vector<bool> row(H, false);
  vector<bool> col(W, false);
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(lines[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }

  for(int i = 0; i < H; i++) {
    if(!row[i]) {
      continue;
    }
    for(int j = 0; j < W; j++) {
      if(row[i] && col[j]) {
        cout << lines[i][j];
      }
    }

    cout << endl;
  }
}
