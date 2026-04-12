#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

VI makev(string s) {
  VI v;
  for (char c: s) {
    if ('0' <= c && c <= '9') {
      for (int i = 0; i < c - '0'; i++) {
        v.push_back(0);
      }
    } else {
      v.push_back(1);
    }
  }
  return v;
}

VVI makeboard(string s) {
  VVI vv;
  string cur = "";
  for (char c: s) {
    if (c != '/') {
      cur += c;
    } else {
      vv.push_back(makev(cur));
      cur = "";
    }
  }
  vv.push_back(makev(cur));
  return vv;
}

string jfen(VI line) {
  int cnt = 0;
  string res = "";
  for (int i: line) {
    if (i == 1) {
      if (cnt != 0) {
        res += char('0' + cnt);
        cnt = 0;
      }
      res += "b";
    } else {
      cnt++;
    }
  }
  if (cnt != 0) {
    res += char('0' + cnt);
  }
  return res;
}

string jfen(VVI board) {
  string res = "";
  for (VI line: board) {
    res += "/";
    res += jfen(line);
  }
  return res.substr(1);
}

int main() {
  string s;
  while (1) {
    cin >> s;
    if (s == "#") return 0;
    VVI board = makeboard(s);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    assert(board[a][b] == 1);
    board[a][b] = 0;
    board[c][d] = 1;
    cout << jfen(board) << endl;
  }
}

