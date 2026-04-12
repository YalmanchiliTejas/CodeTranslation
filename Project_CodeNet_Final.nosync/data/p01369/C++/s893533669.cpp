#include <bits/stdc++.h>
using namespace std;
int main() {
  string left = {"qwertasdfgzxcvb"};
  string right = {"yuiophjklnm"};
  while (1) {
    string s;
    cin >> s;
    if (s == "#") {
      break;
    }
    int ans = 0, last;
    string temp;
    temp.push_back(s[0]);
    if (left.find(temp) == string::npos) {
      last = 1;
    } else {
      last = 0;
    }
    temp.erase(0);
    for (int i = 1; s[i] != '\0'; i++) {
      temp.push_back(s[i]);
      if (left.find(temp) != string::npos && last == 1) {
        ans++;
        last = 0;
      } else if (right.find(temp) != string::npos && last == 0) {
        ans++;
        last = 1;
      }
      temp.erase(0);
    }
    cout << ans << endl;
  }
  return 0;
}
