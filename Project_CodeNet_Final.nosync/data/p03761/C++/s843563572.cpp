#include <bits/stdc++.h>
using namespace std;
#define REP(i, FN) for (int i = 0; i < FN; i++)
const int INF = 0x3f3f3f3f;

int a[55][26];

int main() {
  int n;
  cin >> n;

  REP(i, n) {
    string s;
    cin >> s;
    REP(j, s.size()) a[i][s[j] - 'a']++;
  }

  REP(j, 26) {
    int mn = INF;
    REP(i, n) mn = min(mn, a[i][j]);
    REP(i, mn) cout << (char)('a' + j);
  }
  cout << endl;
}
