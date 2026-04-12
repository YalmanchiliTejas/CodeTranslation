#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[n];
  int ct[n][26]={0};
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int len = s[i].size();
    for (int j = 0; j < len; j++)
      ct[i][s[i][j] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    int tmp = 100;
    for (int j = 0; j < n; j++)
      if (ct[j][i] < tmp)
        tmp = ct[j][i];
    for (int k = 0; k < tmp; k++)
      cout << char('a' + i);
  }
  return 0;
}
