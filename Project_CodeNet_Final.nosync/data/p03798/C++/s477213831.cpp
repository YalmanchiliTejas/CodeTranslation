#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  vector<char> ans(n);
  bool ok = false;
  for (int i = 0; i < 4; i++) {
    vector<char> tmp(n);
    if(i == 0) tmp[0] = tmp[1] = 'S';
    if(i == 1) tmp[0] = tmp[1] = 'W';
    if(i == 2) tmp[0] = 'S', tmp[1] = 'W';
    if(i == 3) tmp[0] = 'W', tmp[1] = 'S';
    for (int j = 1; j < n - 1; j++) {
      if(s[j] == 'o') {
        if(tmp[j] == 'S') {
          tmp[j + 1] = tmp[j - 1];
        }
        if(tmp[j] == 'W') {
          if(tmp[j - 1] == 'W') tmp[j + 1] = 'S';
          if(tmp[j - 1] == 'S') tmp[j + 1] = 'W';
        }
      }
      if(s[j] == 'x') {
        if(tmp[j] == 'W') {
          tmp[j + 1] = tmp[j - 1];
        }
        if(tmp[j] == 'S') {
          if(tmp[j - 1] == 'W') tmp[j + 1] = 'S';
          if(tmp[j - 1] == 'S') tmp[j + 1] = 'W';
        }
      }
    }

    bool flag = true;
    for (int j = 0; j < n; j++) {
      int pre = j - 1;
      int nxt = j + 1;
      if(j == 0) pre = n - 1;
      if(j == n - 1) nxt = 0;

      if(s[j] == 'o') {
        if(tmp[j] == 'S') {
          if(tmp[pre] != tmp[nxt]) flag = false;
        }
        if(tmp[j] == 'W') {
          if(tmp[pre] == tmp[nxt]) flag = false;
        }
      }
      if(s[j] == 'x') {
        if(tmp[j] == 'S') {
          if(tmp[pre] == tmp[nxt]) flag = false;
        }
        if(tmp[j] == 'W') {
          if(tmp[pre] != tmp[nxt]) flag = false;
        }
      }
    }
    if(flag) {
      for (int j = 0; j < n; j++) ans[j] = tmp[j];
      ok = true;
      break;
    }
  }
  if(ok) {
    for (auto it : ans) cout << it;
    cout << '\n';
  } else {
    cout << -1 << '\n';
  }
}