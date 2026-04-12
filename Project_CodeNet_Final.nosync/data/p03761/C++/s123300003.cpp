#include <iostream>
#define REP(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n; cin >> n;
  string s[n];
  int m[n][26] = {};
  REP(i,n) {
    cin >> s[i];
    for (int j = 0; s[i][j] != '\0'; ++j) {
      ++m[i][s[i][j] - 'a'];
    }
  }
  REP(i,26) {
    int cnt = 50;
    REP(j,n) {
      cnt = min(cnt, m[j][i]);
    }
    cout << string(cnt, 'a' + i);
  }
  cout << endl;
  return 0;
}