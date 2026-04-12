#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, K;
  cin >> N >> K;

  if(K == 0) {
    cout << 1LL * N * N << endl;
    return (0);
  }
  int64 ret = 0;
  for(int i = K + 1; i <= N; i++) {
    for(int j = 0; j <= N; j += i) {
      int h = min(N, j + i - 1);
      int lim = j + K;
      ret += max(0, h - lim + 1);
    }
  }

  cout << ret << endl;
}
