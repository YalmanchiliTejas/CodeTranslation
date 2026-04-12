#include <bits/stdc++.h>
#define N 26
using namespace std;
int main() {
  int n;
  cin >> n;
  string S;
  vector<vector<int>> counter(n,vector<int>(N));
  for (int i = 0; i < n; i++) {
    cin >> S;
    for (char c : S) {
      counter[i][c-'a']++;
    }
  }
  for (int i = 0; i < N; i++) {
    int m = counter[0][i];
    for (int j = 1; j < n; j++) {
      m = min(m,counter[j][i]);
    }
    cout << string(m,(char)(i+'a'));
  }
}