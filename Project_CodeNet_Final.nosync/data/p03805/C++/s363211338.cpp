#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, count = 0;
  cin >> N >> M;
  vector<int> ver(N);
  for (int i = 1; i <= N; i++) {
    ver.at(i - 1) = i;
  }
  bool judge = false;
  bool judge2 = true;
  vector<int> a(M), b(M);
  for (int i = 0; i < M; i++) cin >> a.at(i) >> b.at(i);
  do {
    if (ver.at(0) != 1) break;
    judge2 = true;
    for (int j = 0; j < N - 1; j++) {
      judge = false;
      for (int k = 0; k < M; k++) {
        if (ver.at(j) == a.at(k)) {
          if (ver.at(j + 1) == b.at(k)) {
            judge = true;
            break;
          }
        }
        if (ver.at(j) == b.at(k)) {
          if (ver.at(j + 1) == a.at(k)) {         
            judge = true;
            break;
          }
        }
      }
      if (!judge) {
        judge2 = false;
        break;
      }
    }
    if (judge2) {
      count++;
    }
  } while(next_permutation(ver.begin(), ver.end()));
  cout << count << endl;
}