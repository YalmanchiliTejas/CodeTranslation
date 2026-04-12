#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string S;
  vector<int> c(26, 0);
  for (int i = 0; i < n; i++) {
    cin >> S;
    vector<int> tmp(26, 0);
    for (char s : S) {
      tmp[s - 'a']++;
    }
    for (int j = 0; j < 26; j++) {
      if (i == 0) {
        c[j] = tmp[j];
      } else {
        c[j] = min(c[j], tmp[j]);
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < c[i]; j++) {
      cout << (char)('a' + i);
    }
  }
  cout << endl;
}