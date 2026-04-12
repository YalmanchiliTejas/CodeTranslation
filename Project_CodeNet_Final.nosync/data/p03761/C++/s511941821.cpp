#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  string s;
  map<char, int> ans, tmp;
  char a = 'a';
  for (int i = 0; i < 26; ++i) {
    ans[a] = INF;
    tmp[a] = 0;
    a++;
  }

  rep(i, n) {
    cin >> s;
    for (int i = 0; i < s.length(); ++i) tmp[s[i]]++;

    a = 'a';
    for (int i = 0; i < 26; ++i) {
      ans[a] = min(ans[a], tmp[a]);
      tmp[a] = 0;
      a++;
    }
  }

  for (auto x : ans)
    for (int i = 0; i < x.second; ++i) cout << x.first;
  cout << "\n";
  return 0;
}