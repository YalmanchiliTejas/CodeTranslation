#include <bits/stdc++.h>
using namespace std;

#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(i, n) repi(i, 0, n)
#define all(x) (x).begin(), (x).end()

using pii = pair<int, int>;

const int MAX_NM = 30;
int N, M, A, C, R = 0;
int B[MAX_NM];

inline void Main() {
  // code
  int N, M, R, H[30];
  cin >> N;
  rep(i, N) cin >> H[i];

  M = H[0];
  R = 1;
  repi(i, 1, N) {
    if(M <= H[i]) R++;
    M = max(M, H[i]);
  }

  cout << R << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(20);
  Main();
  return 0;
}
