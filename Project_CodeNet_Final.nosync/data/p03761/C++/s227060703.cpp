#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << endl
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> V;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<vector<int>> x(n, vector<int>(26, 0));
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < (int)s[i].size(); j++) {
      x[i][s[i][j]-'a']++;
    }
  }
  vector<int> ans(26, 100);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      ans[j] = min(ans[j], x[i][j]);
    }
  }
  for (int i = 0; i < 26; i++) {
    while (ans[i]--) {
      printf("%c", 'a'+i);
    }
  }
  dump("");
  return 0;
}
