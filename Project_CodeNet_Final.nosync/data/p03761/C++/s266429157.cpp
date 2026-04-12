#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s[n];
  int m[n][26] = {};
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; s[i][j] != '\0'; j++) {
      m[i][s[i][j] - 'a']++;
    }
  }
  for (int i = 0; i < 26; i++) {
    int cn = 50;
    for (int j = 0; j < n; j++) {
      cn = min(cn, m[j][i]);
    }
    cout << string(cn, i + 'a');
  }
  cout << endl;
  return 0;
}
