#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  int cnt[n][26];
  int ansCnt[26];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      cnt[i][j] = 0;
      ansCnt[j] = 2500;
    }
  }
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < s.length(); j++) {
      int index = s[j] - 'a';
      cnt[i][index]++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      if (ansCnt[j] > cnt[i][j]) {
        ansCnt[j] = cnt[i][j];
      }
    }
  }
  std::string ans = "";
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < ansCnt[i]; j++) {
      ans += ('a' + i);
    }
  }
  std::cout << ans << "\n";
  return 0;
}