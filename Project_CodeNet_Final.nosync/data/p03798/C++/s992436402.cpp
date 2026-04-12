#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  string res = "";
  for (int k = 0; k < 1 << 2; k++) {
    string str = "";
    for (int i = 0; i < 2; i++) {
      if (k >> i & 1) {
        str += "W";
      } else {
        str += "S";
      }
    }
    for (int i = 1; i < n - 1; i++) {
      if (str[i] == 'S') {
        if (s[i] == 'o') {
          str += str[i - 1];
        } else {
          str += (str[i - 1] == 'S' ? "W" : "S");
        }
      } else {
        if (s[i] == 'o') {
          str += (str[i - 1] == 'S' ? "W" : "S");
        } else {
          str += str[i - 1];
        }
      }
    }
    string check = str + str + str;
    bool flag = true;
    for (int i = n; i < n + n; i++) {
      if (check[i] == 'S') {
        if (s[i - n] == 'o') {
          if (check[i - 1] != check[i + 1]) flag = false;
        } else {
          if (check[i - 1] == check[i + 1]) flag = false;
        }
      } else {
        if (s[i - n] == 'o') {
          if (check[i - 1] == check[i + 1]) flag = false;
        } else {
          if (check[i - 1] != check[i + 1]) flag = false;
        }
      }
    }
    if (flag) res = str;
  }
  if (res.size()) {
    cout << res << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}