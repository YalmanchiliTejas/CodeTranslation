#include "bits/stdc++.h"
using namespace std;

int main() {
  int N;
  string S;
  S.size() == N;
  int K;
  cin >> N;
  cin >> S;
  cin >> K;

  int i;
  for (i = 0; i < N; i++) {
    if (S.at(i) != S.at(K - 1)) {
      char c = '*';
      S.at(i) = c;
    }
  }
  cout << S << endl;
}
