#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  int a[27] = {};
  for (char c : s[0]) a[c-'a']++;
  for (int i = 1; i < n; i++) {
    int b[27] = {};
    for (char c : s[i]) b[c-'a']++;
    for (int j = 0; j < 27; j++) a[j] = min(a[j], b[j]);
  }
  for (int i = 0; i < 27; i++) {
    for (int j = 0; j < a[i]; j++) cout << char('a'+i);
  }
  cout << endl;
}