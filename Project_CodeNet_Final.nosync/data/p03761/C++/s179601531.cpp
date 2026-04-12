#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  int n; scanf("%d", &n);
  vector<vector<int>> freqs(n, vector<int>(128, 0));
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    for (int j = 0; j < (int)s.size(); ++j) {
      ++freqs[i][s[j] - 'a'];
    }
  }
  string ans;
  for (int i = 0; i <= 26; ++i) {
    int cnt = 100;
    for (int j = 0; j < n; ++j) {
      cnt = min(cnt, freqs[j][i]);
    }
    ans += string(cnt, 'a' + i);
  }
  printf("%s\n", ans.c_str());
  return 0;
}
