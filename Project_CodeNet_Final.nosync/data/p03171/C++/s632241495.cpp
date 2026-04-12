#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int n;
int a[3030];
ll dp[3010][3010];

ll rec(int i, int j) {
  if (0 < dp[i][j]) return dp[i][j];
  if (i == j) return a[i];
  ll res1 = 1ll * a[i] - rec(i + 1, j);
  ll res2 = 1ll * a[j] - rec(i, j - 1);
  return dp[i][j] = max(res1, res2);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = -1e18;
    }
  }
  cout << rec(1, n) << endl;
  return 0;
}