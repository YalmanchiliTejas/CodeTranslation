#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<string> S(n);
  vector<int> s(n);
  vector<vector<int>> x(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    cin >> S.at(i);
    s.at(i) = S.at(i).size();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s.at(i); j++) {
      int a = S.at(i).at(j) - 'a';
      x.at(i).at(a)++;
    }
  }
  vector<int> y(26);
  for (int i = 0; i < 26; i++) {
    y.at(i) = x.at(0).at(i);
    for (int j = 1; j < n; j++) {
      if (x.at(j).at(i) < y.at(i)) y.at(i) = x.at(j).at(i);
    }
  }
  for (int i = 0; i < 26; i++) {
    if (y.at(i) != 0) {
      for (int j = 0; j < y.at(i); j++) {
        cout << char(i+'a');
      }
    }
  }
}