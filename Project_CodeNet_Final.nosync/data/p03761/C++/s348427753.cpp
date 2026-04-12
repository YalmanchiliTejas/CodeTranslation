#include <bits/stdc++.h>
using namespace std;

int countStr(string objStr, string str) {
  int cnt = 0;
  int index = 0;
  while (1) {
    int pos = objStr.find(str, index);
    if (pos == string::npos) return cnt;
    cnt++;
    index = pos + str.size();
  }
}

int main() {
  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; i++) cin >> S.at(i);
  vector<int> cnt(26, 0);
  vector<string> alp = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
  "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
  for (int i = 0; i < 26; i++) {
    int tmp = 50;
    for (int j = 0; j < n; j++) {
      tmp = min(tmp, countStr(S.at(j), alp.at(i)));
    }
    cnt.at(i) = tmp;
  }
  string ans = "";
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < cnt.at(i); j++) {
      ans = ans + alp.at(i);
    }
  }
  cout << ans << endl;
}