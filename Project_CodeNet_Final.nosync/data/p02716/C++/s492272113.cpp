#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define dbl(k, x) fixed << setprecision(k) << (x)

template <typename _T>
inline void _DBG(const char *s, _T x) {
  cerr << s << " = " << x << "\n";
}
template <typename _T, typename... args>
void _DBG(const char *s, _T x, args... a) {
  while (*s != ',') cerr << *s++;
  cerr << " = " << x << ',';
  _DBG(s + 1, a...);
}

#define _upgrade                \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define DBG(...) _DBG(#__VA_ARGS__, __VA_ARGS__)

// ********************** CODE ********************** //

const int N = 2e5 + 7;

LL dp[N][2];
LL A[N];

int main() {
  _upgrade;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }

  for (int i = 2; i <= n; i++) {
    if (i & 1) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + A[i];
    } else {
      dp[i][0] = dp[i - 2][0] + A[i - 1];
      dp[i][1] = dp[i - 1][0] + A[i];
    }
  }

  cout << max(dp[n][0], dp[n][1]) << "\n";
  return 0;
}