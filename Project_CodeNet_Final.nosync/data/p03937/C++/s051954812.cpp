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
  vector<vector<char>> A(H, vector<char>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) cin >> A[i][j];
  }
  int num = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (A[i][j]=='#') num++;
    }
  }
  if (num==H+W-1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}