#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  string s;
  map<char, int> ans, t;

  cin >> s;
  for (int j = 0; j < s.size(); ++j) ans[s[j]]++;

  for (int i = 0; i < n - 1; ++i) {
    cin >> s;
    t.clear();
    for (int j = 0; j < s.size(); ++j) t[s[j]]++;
    for (char j = 'a'; j <= 'z'; ++j) ans[j] = min(ans[j], t[j]);
  }

  for (auto a : ans)
    if (a.second > 0)
      for (int i = 0; i < a.second; ++i) cout << a.first;
  cout << endl;

  return 0;
}