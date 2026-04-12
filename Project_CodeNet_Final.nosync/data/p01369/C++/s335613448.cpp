#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  string a = "qwertasdfgzxcvb";
  string b = "yuiophjklnm";
  string s;
  while (getline(cin, s)) {
    if (s == "#") {
      break;
    }
    if (s.size() == 1) {
      cout << 0 << endl;
      continue;
    }
    vector<int> c;
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < a.size(); j++) {
        if (s[i] == a[j]) {
          c.push_back(0);
        }
      }
      for (int j = 0; j < b.size(); j++) {
        if (s[i] == b[j]) {
          c.push_back(1);
        }
      }
    }
    int ans = 0, x = c[0];
    for (int i = 1; i < c.size(); i++) {
      if (x != c[i]) {
        ans++;
        x = c[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
