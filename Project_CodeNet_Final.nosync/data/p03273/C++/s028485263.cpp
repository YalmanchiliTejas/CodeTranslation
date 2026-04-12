#include <bits/stdc++.h>
using namespace std;

bool is_all_white(string v) {
  for (char c: v) {
    if (c == '#') return false;
  }
  return true;
}

int main() {
  int h, w;
  cin >> h >> w;
  
  vector<string> g;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;

    if (!is_all_white(s)) {
      g.push_back(s);
    }
  }
  
  for (int i = 0; i < w; i++) {
    string s = "";
    for (int j = 0; j < g.size(); j++) {
      s += g[j][i];
    }

    if (is_all_white(s)) {
      for (int j = 0; j < g.size(); j++) {
        g[j][i] = '\0';
      }
    }
  }
  
  for (string s: g) {
    for (char c: s)
      if (c != '\0') cout << c;
    cout << endl;
  }
}

