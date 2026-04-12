
#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int inf = 1e9 + 7;
const ll inf_ll = 1e18L + 7;

template <typename T>
void mini(T& a, T b) {
  a = min(a, b);
}

template <typename T>
void maxi(T& a, T b) {
  a = max(a, b);
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> A(n);
  for (int& a : A) scanf("%d", &a);

  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  for (int i = 0; i < n; ++i) dp[i][i] = A[i];

  for (int L = 2; L <= n; ++L) {
    for (int i = 0; i + L <= n; i++) {
      int j = i + L - 1;
      dp[i][j] = max(A[i] - dp[i + 1][j], A[j] - dp[i][j - 1]);
    }
  }
  cout << dp[0][n-1] << endl;
  return 0;
}
