#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string ans = "";
  int n;
  cin >> n;
  vector<string> vec(n);
  vector<vector<int> > a(n, vector<int> (26, 0));
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    for (int j = 0; j < vec[i].size(); j++) {
      ++(a[i][ vec[i][j] - 'a']);
    }
  }

  for (int i = 0; i < 26; i++) {
    int m = INT_MAX;
    for (int j = 0; j < n; j++) {
      m = min(m, a[j][i]);
    }
    
    for (int r = 0; r < m; r++) {
      ans += (char)('a' + i);
    }
  }

  cout << ans << '\n';
}
