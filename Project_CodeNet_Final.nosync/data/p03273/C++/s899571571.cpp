#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  vector<vector<char>> v(x,vector<char>(y));
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      cin >> v[i][j];
    }
  }
  
  set<int> AllDotx, AllDoty;
  for (int i = 0; i < x; i++) {
    bool b = true;
    for (int j = 0; j < y; j++) {
      if (v[i][j] == '#') b = false;
    }
    if (b) {
      AllDotx.insert(i);
    }
  }
  for (int j = 0; j < y; j++) {
    bool b = true;
    for (int i = 0; i < x; i++) {
      if (v[i][j] == '#') b = false;
    }
    if (b) {
      AllDoty.insert(j);
    }
  }
  
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (AllDotx.count(i) || AllDoty.count(j)) continue;
      cout << v[i][j];
    }
    if (!AllDotx.count(i)) cout << endl;
  }
}