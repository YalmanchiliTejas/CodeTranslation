#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) cin >> a[i][j];
  }
  vector<int> memo_line, memo_column;
  // 黒いマスが存在する行と列
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (a[i][j]=='#') {
        memo_line.push_back(i);
        memo_column.push_back(j);
      }
    }
  }
  sort(memo_line.begin(), memo_line.end());
  sort(memo_column.begin(), memo_column.end());
  memo_line.erase(unique(memo_line.begin(), memo_line.end()), memo_line.end());
  memo_column.erase(unique(memo_column.begin(), memo_column.end()), memo_column.end());
  for (int i=0; i<memo_line.size(); i++) {
    for (int j=0; j<memo_column.size(); j++) {
      if (j==memo_column.size()-1) cout << a[memo_line[i]][memo_column[j]] << endl;
      else cout << a[memo_line[i]][memo_column[j]];
    }
  }
}