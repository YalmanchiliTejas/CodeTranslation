#include<bits/stdc++.h>
#define rep(i,n) for(int (i) = 0;(i) < (n);(i)++)
using namespace std;
typedef long long ll;

int main(void) {
  int n;
  cin >> n;

  map<char, int> mp;
  rep (i, n) {
    string s;
    cin >> s;

    map<char, int> tmp;

    for (auto c: s) tmp[c]++;

    if (i == 0) {
      for (auto c: s) mp[c]++;
      continue;
    }

    for (char c = 'a'; c <= 'z'; c++) {
      if (tmp[c] < mp[c]) mp[c] = tmp[c];
    }
  }

  vector<char> ans;
  for (char c = 'a'; c <= 'z'; c++) {
    rep (i, mp[c]) ans.push_back(c);
  }
  sort(ans.begin(), ans.end());

  rep (i, ans.size()) cout << ans[i];
  cout << endl;
  return 0;
}
