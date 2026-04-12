#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int n;
  string s;
  int k;
  cin >> n;
  cin >> s;
  cin >> k;
  char x = s[k - 1];
  string ans = "";
  for (int i = 0; i < n; i++) {
    if (s[i] == x) {
      ans += s[i];
    }
    else {
      ans += '*';
    }
  }
  cout << ans << endl;
  return 0;
}