#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ss[50][26];
int main(void) {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < s[i].size(); j++) {
      ss[i][s[i][j] - 'a']++;
    }
  }
  vector<int> cnt(26, 51);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      if (cnt[j] > ss[i][j]) {
        cnt[j] = ss[i][j];
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      cout << (char)('a' + i);
    }
  }
  cout << endl;
  return 0;
}