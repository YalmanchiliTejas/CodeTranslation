#include <bits/stdc++.h>
using namespace std;

#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(i, n) repi(i, 0, n)
#define all(x) (x).begin(), (x).end()

inline void Main() {
  // code
  int N;
  int H[30];

  cin >> N;
  rep(i, N) cin >> H[i];

  int res = 1;
  int curMax = H[0];
  repi(i, 1, N) {
    if(curMax <= H[i]) {
      res++;
      curMax = max(curMax, H[i]);
    }
  }

  cout << res << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(20);
  Main();
  return 0;
}
