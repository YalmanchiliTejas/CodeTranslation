#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  string t = "abcdefghijklmnopqrstuvwxyz";
  int cnt[26] = {0};
  for (int i = 0; i < 26; i++) {
    int c = 999;
    for (int j = 0; j < n; j++) {
      int tmp = 0;
      for (int k = 0; k < s[j].size(); k++) {
        if (t[i] == s[j][k]) {
          tmp++;
        }
      }
      if (tmp < c) {
        c = tmp;
      }
    }
    cnt[i] = c;
  }
  string ans = "";
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      ans += t[i];
    }
  }
  cout << ans << endl;
  return 0;
}