#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector<char> t;

bool dfs(int i, bool flag_s) {
  if (i == N - 1) {
    if (flag_s) {
      if (t.at(i) != 'S')
        return false;
      t.at(i) = 'S';
      if (s.at(i) == 'o') {
        return (t.at(i - 1) == t.at(0));
      }
      else {
        return (t.at(i - 1) != t.at(0));
      }
    }
    else {
      if (t.at(i) != 'W')
        return false;
      t.at(i) = 'W';
      if (s.at(i) == 'o') {
        return (t.at(i - 1) != t.at(0));
      }
      else {
        return (t.at(i - 1) == t.at(0));
      }
    }
  }
  else if (i == 0) {
    int s0;
    if (flag_s) {
      t.at(i) = 'S';
      if (s.at(i) == 'o') {
        t.at(N - 1) = 'S';
        s0 = dfs(i + 1, true);
        if (!s0) {
          t.at(N - 1) = 'W';
          s0 = dfs(i + 1, false);
        }
        return s0;
      }
      else {
        t.at(N - 1) = 'S';
        s0 = dfs(i + 1, false);
        if (!s0) {
          t.at(N - 1) = 'W';
          s0 = dfs(i + 1, true);
        }
        return s0;
      }
    }
    else {
      t.at(i) = 'W';
      if (s.at(i) == 'o') {
        t.at(N - 1) = 'S';
        s0 = dfs(i + 1, false);
        if (!s0) {
          t.at(N - 1) = 'W';
          s0 = dfs(i + 1, true);
        }
        return s0;
      }
      else {
        t.at(N - 1) = 'S';
        s0 = dfs(i + 1, true);
        if (!s0) {
          t.at(N - 1) = 'W';
          s0 = dfs(i + 1, false);
        }
        return s0;
      }
    }
  }
  else {
    if (flag_s) {
      t.at(i) = 'S';
      if (s.at(i) == 'o') {
        return (dfs(i + 1, t.at(i - 1) == 'S'));
      }
      else {
        return (dfs(i + 1, t.at(i - 1) != 'S'));
      }
    }
    else {
      t.at(i) = 'W';
      if (s.at(i) == 'o') {
        return (dfs(i + 1, t.at(i - 1) != 'S'));
      }
      else {
        return (dfs(i + 1, t.at(i - 1) == 'S'));
      }
    }
  }
}

int main() {
  cin >> N;
  cin >> s;
  t = vector<char>(N);
  if (dfs(0, true) || dfs(0, false)) {
    for (int i=0; i<N; i++)
      cout << t.at(i);
    cout << endl;
  }
  else
    cout << "-1" << endl;
}
