#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  int res = 0;
  for (int i = 0; i < N; ++i) cin >> H[i];
  int max_H = H[0];
  for (int i = 0; i < N; ++i) {
    if (max_H <= H[i]) {
      res++;
      max_H = H[i];
    }
  }
  cout << res << endl;
}