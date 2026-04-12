#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> V(N, vector<int>(26));
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    for (int j = 0; j < S.size(); j++) {
      V.at(i).at(S.at(j) - 'a')++;
    }
  }
  for (int j = 0; j < 26; j++) {
    int x = 100;
    for (int i = 0; i < N; i++) {
      x = min(x, V.at(i).at(j));
    }
    for (int k = 0; k < x; k++) cout << (char)('a' + j);
  }
  cout << endl;
}