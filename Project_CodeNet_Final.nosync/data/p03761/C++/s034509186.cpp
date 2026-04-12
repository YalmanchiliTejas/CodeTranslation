#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];

  map<char, int> m;
  for (int i = 0; i < n; i++) {
    map<char, int> t;
    for (int j = 0; j < s[i].size(); j++) {
      if (i == 0 || m[s[i][j]] > 0) t[s[i][j]]++;
    }

    if (i == 0) {
      m = t;
      continue;
    }
    for (auto v : m) {
      if (t[v.first] == 0) {
        m.erase(v.first);
        continue;
      }
      if (v.second > t[v.first]) { m[v.first] = t[v.first]; }
    }
  }
  string ans = "";
  for (auto v : m) {
    for (int i = 0; i < v.second; i++)
      ans += v.first;
  }
  cout << ans << endl;
}