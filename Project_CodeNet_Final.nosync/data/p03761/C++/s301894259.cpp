#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 55

int main() {
  int n;
  cin >> n;
  string str[n];
  for (int i = 0; i < n; i++) {
    cin >> str[i];
    sort(str[i].begin(), str[i].end());
  }

  int alpha[MAX][26] = {};
  int len[26] = {};

  for (int i = 0; i < 26; i++) len[i] = 100;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      alpha[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < str[i].length(); j++) {
      for (int k = 0; k < 26; k++) {
        if (str[i][j] - 'a' == k) alpha[i][k]++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 26; k++) {
      len[k] = min(len[k], alpha[i][k]);
    }
  }

  string ans = "";
  for (int i = 0; i < 26; i++) {
    if (len[i] == 100) continue;
    for (int j = 0; j < len[i]; j++) {
      ans += char('a' + i);
    }
  }

  cout << ans << endl;
}