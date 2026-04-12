#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> ans(26, 51);
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    vector<int> cnt(26, 0);
    for (int j = 0; j < s.size(); j++) cnt.at(s.at(j) - 'a')++;
    for (int j = 0; j < 26; j++) ans.at(j) = min(ans.at(j), cnt.at(j));
  }
  string alp = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++) {
    if (ans.at(i) == 0) continue;
    for (int j = 0; j < ans.at(i); j++) cout << alp.at(i);
  }
  cout << endl;
}