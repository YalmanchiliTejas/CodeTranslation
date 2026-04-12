#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  vector<vector<int>> alp(26, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    int length = S[i].size();
    for (int j = 0; j < length; j++) {
      alp[S[i][j] - 97][i]++;
    }
  }
  for (int i = 0; i < 26; i++) {
    int tmp = 100000;
    for (int j = 0; j < N; j++) {
      if (tmp > alp[i][j]) tmp = alp[i][j];
    }
    for (int k = 0; k < tmp; k++) cout << char('a' + i);
  }
  cout << endl;
}
