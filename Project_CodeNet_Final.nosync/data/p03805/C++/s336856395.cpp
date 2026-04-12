#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  vector<vector<bool>> A(N, vector<bool>(N, false));
  for (int i = 0; i < M; i++) {
    cin >> a.at(i) >> b.at(i);
    A.at(a.at(i) - 1).at(b.at(i) - 1) = true;
    A.at(b.at(i) - 1).at(a.at(i) - 1) = true;
  }
  vector<int> memo(N - 1);
  for (int i = 2; i <= N; i++) {
    memo.at(i - 2) = i;
  }
  int64_t ans = 0;
  do {
    if (A.at(0).at(memo.at(0) - 1)) {
      bool ok = true;
      for (int i = 0; i < N - 2; i++) {
        if (A.at(memo.at(i) - 1).at(memo.at(i + 1) - 1) == false) {
          ok = false;
          break;
        }      
      }
      if (ok) {
        ans++;
      }
    }   
  } while (next_permutation(memo.begin(), memo.end()));
  cout << ans << endl;
}
  