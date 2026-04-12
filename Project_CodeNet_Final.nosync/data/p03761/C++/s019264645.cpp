#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int n;
  cin >> n;

  vector<string> S(n);
  vector<vector<int>> c(n);
  rep(i, n) {
    cin >> S[i];
    std::sort(S[i].begin(), S[i].end());

    c[i].resize(26, 0);
    rep(j, S[i].size()) {
      int pos = S[i][j] - 'a';
      c[i][pos]++;
    }
  }

  rep(i, 26) {
    int mn = c[0][i];

    rep(j, n) {
      if (mn > c[j][i]) mn = c[j][i];
    }

    if (mn > 0) {
      char al = 'a' + i;
      rep(k, mn) cout << al;
    }
  }

  cout << endl;

  return 0;
}
