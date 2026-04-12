#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  string s; cin >> s;
  vector<string> tmp = { "SS", "SW", "WS", "WW" };
  for (int i = 0; i < 4; i++) {
    string t = tmp.at(i);
    for (int j = 1; j < N-1; j++) {
      if (t.at(j) == 'S' && s.at(j) == 'o') {
        if (t.at(j-1) == 'S') t += 'S';
        else t += 'W';
      }
      else if (t.at(j) == 'S' && s.at(j) == 'x') {
        if (t.at(j-1) == 'S') t += 'W';
        else t += 'S';
      }
      else if (t.at(j) == 'W' && s.at(j) == 'o') {
        if (t.at(j-1) == 'S') t += 'W';
        else t += 'S';
      }
      else if (t.at(j) == 'W' && s.at(j) == 'x') {
        if (t.at(j-1) == 'S') t += 'S';
        else t += 'W';
      }
    }
    bool ok = true;
    if (t.at(N-1) == 'S' && s.at(N-1) == 'o') {
      if (t.at(N-2) != t.at(0)) ok = false;
    }
    else if (t.at(N-1) == 'S' && s.at(N-1) == 'x') {
      if (t.at(N-2) == t.at(0)) ok = false;
    }
    else if (t.at(N-1) == 'W' && s.at(N-1) == 'o') {
      if (t.at(N-2) == t.at(0)) ok = false;
    }
    else if (t.at(N-1) == 'W' && s.at(N-1) == 'x') {
      if (t.at(N-2) != t.at(0)) ok = false;
    }

    if (t.at(0) == 'S' && s.at(0) == 'o') {
      if (t.at(N-1) != t.at(1)) ok = false;
    }
    else if (t.at(0) == 'S' && s.at(0) == 'x') {
      if (t.at(N-1) == t.at(1)) ok = false;
    }
    else if (t.at(0) == 'W' && s.at(0) == 'o') {
      if (t.at(N-1) == t.at(1)) ok = false;
    }
    else if (t.at(0) == 'W' && s.at(0) == 'x') {
      if (t.at(N-1) != t.at(1)) ok = false;
    }

    if (ok) { cout << t << endl; return 0; }
  }
  cout << -1 << endl;
}