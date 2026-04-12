#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> V(26);
  for (auto c : S) V.at(c - 'a')++;
  while (cin >> S) {
    vector<int> tmp(26);
    for (auto c : S) tmp.at(c - 'a')++;
    for (int i = 0; i < 26; i++) {
      V.at(i) = min(V.at(i), tmp.at(i));
    }
  }
  for (int i = 0; i < 26; i++) {
    if (V.at(i)) while (V.at(i)--) cout << char('a' + i);
  }
  cout << "\n";
}