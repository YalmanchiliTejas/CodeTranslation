#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

const int INF = 100;
const int alpha_size = 26;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> v(n, vector<int>(alpha_size));
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, s.size()) v[i][s[j] - 'a']++;
  }

  vector<int> a(alpha_size, INF);
  rep(j, alpha_size) rep(i, n) a[j] = min(a[j], v[i][j]);

  rep(i, alpha_size) {
    cout << string(a[i], i + 'a');
  }
  cout << endl;
}