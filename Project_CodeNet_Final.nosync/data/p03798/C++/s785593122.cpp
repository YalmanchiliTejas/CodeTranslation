#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  bool ok = false;
  vector<char> ans(n);
  for (int i = 0; i < 4; i++) {
    vector<char> tmp(n);
    if(i == 0) {
      tmp[0] = 'S';
      tmp[1] = 'S';
    } else if(i == 1) {
      tmp[0] = 'S';
      tmp[1] = 'W';
    } else if(i == 2) {
      tmp[0] = 'W';
      tmp[1] = 'W';
    } else if(i == 3) {
      tmp[0] = 'W';
      tmp[1] = 'S';
    }

    for (int j = 1; j < n - 1; j++) {
      if(tmp[j] == 'S') {
        if(s[j] == 'o') tmp[j + 1] = tmp[j - 1];
        else {
          if(tmp[j - 1] == 'W') tmp[j + 1] = 'S';
          else tmp[j + 1] = 'W';
        }
      } else {
        if(s[j] == 'o') {
          if(tmp[j - 1] == 'S') tmp[j + 1] = 'W';
          else tmp[j + 1] = 'S';
        } else {
          tmp[j + 1] = tmp[j - 1];
        }
      }
    }

    bool flag = true;
    for (int j = 0; j < n; j++) {
      int prev = j - 1;
      int nxt = j + 1;
      if(j == 0) prev = n - 1;
      if(j == n - 1) nxt = 0;

      if(s[j] == 'o') {
        if(tmp[j] == 'S') {
          if(tmp[prev] != tmp[nxt]) flag = false;
        } else if(tmp[j] == 'W') {
          if(tmp[prev] == tmp[nxt]) flag = false;
        }
      } else if(s[j] == 'x') {
        if(tmp[j] == 'S') {
          if(tmp[prev] == tmp[nxt]) flag = false;
        } else if(tmp[j] == 'W') {
          if(tmp[prev] != tmp[nxt]) flag = false;
        }
      }
    }
    if(flag) {
      for (int j = 0; j < n; j++) ans[j] = tmp[j];
      ok = true;
      break;
    }
  }

  if(!ok) cout << -1 << endl;
  else {
    for (auto it : ans) cout << it;
    cout << endl;
  }
}