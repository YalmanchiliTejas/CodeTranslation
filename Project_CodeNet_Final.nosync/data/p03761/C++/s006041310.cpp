#include <bits/stdc++.h>
using namespace std;

string lcs(string S, string T) {
  int s = S.size();
  int t = T.size();
  int sz = max(s, t) + 1;
  vector<vector<int>> X(sz, vector<int>(sz));
  vector<vector<int>> Y(sz, vector<int>(sz));
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < t; j++) {
      if (S.at(i) == T.at(j)) {
        X.at(i + 1).at(j + 1) = X.at(i).at(j) + 1;
        Y.at(i + 1).at(j + 1) = 0;
      } else if (X.at(i + 1).at(j) < X.at(i).at(j + 1)) {
        X.at(i + 1).at(j + 1) = X.at(i).at(j + 1);
        Y.at(i + 1).at(j + 1) = 1;
      } else {
        X.at(i + 1).at(j + 1) = X.at(i + 1).at(j);
        Y.at(i + 1).at(j + 1) = -1;
      }
    }
  }
  string res;
  for (int i = s, j = t; i > 0 && j > 0;) {
    if (Y.at(i).at(j) > 0) {
      i--;
    } else if (Y.at(i).at(j) < 0) {
      j--;
    } else {
      res.push_back(S.at(i - 1));
      i--;
      j--;
    }
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  int N;
  string S, T;
  cin >> N >> S;
  sort(S.begin(), S.end());
  while (cin >> T) {
    sort(T.begin(), T.end());
    S = lcs(S, T);
  }
  cout << S << "\n";
}