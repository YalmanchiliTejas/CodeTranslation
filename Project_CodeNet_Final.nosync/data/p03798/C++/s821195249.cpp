#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  char c[2] = {'S', 'W'};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      vector<int> T;
      T.push_back(i);
      T.push_back(j);
      for (int k = 0; k < N; k++) {
        if (S[k] == 'o') {
          if (T[k + 1] == 0)
            T.push_back(T[k]);
          else
            T.push_back(1 - T[k]);
        } else {
          if (T[k + 1] == 0) {
            T.push_back(1 - T[k]);
          } else {
            T.push_back(T[k]);
          }
        }
      }
      if (T[0] == T[N] && T[1] == T[N + 1]) {
        for (int i = 1; i < N + 1; i++) {
          cout << "SW"[T[i]];
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}