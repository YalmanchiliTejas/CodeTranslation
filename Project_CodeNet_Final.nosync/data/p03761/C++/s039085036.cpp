#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  for (int i = 1; i < N; i++) {
    string s, tmp;
    cin >> s;
    for (int i = 0; i < S.size(); i++)
      for (int j = 0; j < s.size(); j++)
        if (S.at(i) == s.at(j)) {
          tmp += S.at(i), s.at(j) = ' ';
          break;
        }
    S = tmp;
  }
  sort(S.begin(), S.end());
  cout << S << "\n";
}