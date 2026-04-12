#include <iostream>
#include <vector>
using namespace std;

char grid[110][110];

int main() {
  int H, W;
  cin >> H >> W;
  vector<int> hs(H + 1);
  vector<int> ws(W + 1);
  for(int h = 1; h <= H; ++h) {
    string s;
    cin >> s;
    for(int w = 1; w <= W; ++w) {
      auto c = s[w - 1];
      auto n = c == '.' ? 0 : 1;
      grid[h][w] = c;
      hs[h] += n;
      ws[w] += n;
    }
  }
  for(int h = 1; h <= H; ++h) {
    if(hs[h] == 0) {
      continue;
    }
    for(int w = 1; w <= W; ++w) {
      if(ws[w] == 0) {
        continue;
      }
      cout << grid[h][w];
    }
    cout << endl;
  }
  return 0;
}
