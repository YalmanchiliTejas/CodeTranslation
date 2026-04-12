#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
using namespace std;
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) a = b;
  return a > b;
}
template<class T> inline bool chmax(T&a, T b) {
  if (a < b) a = b;
  return a < b;
}

signed main() {
  int N, L, R;
  cin >> N >> L >> R;
  while (N+L+R != 0) {
    vector<int> A(N);
    int ans = 0;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int x = L; x <= R; x++) {
      int exists = 0;
      for (int i = 0; i < N; i++) {
        if (x % A[i] == 0) {
          if ((i+1) % 2 == 1) {
            ans++;
          }
          exists = 1;
          break;
        }
      }
      if (exists == 0 && N % 2 == 0) ans++;
    }
    cout << ans << endl;
    cin >> N >> L >> R;
  }
}

