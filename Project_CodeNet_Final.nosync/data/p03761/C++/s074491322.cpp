#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> V(N, vector<int>(26));
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    for (int j = 0; j < S.size(); j++) V.at(i).at(S.at(j) - 'a')++;
  }
  for (int i = 0; i < 26; i++) {
    int cnt = 1e9;
    for (int j = 0; j < N; j++) cnt = min(cnt, V.at(j).at(i));
    while (cnt--) cout << char('a' + i);
  }
  cout << "\n";
}