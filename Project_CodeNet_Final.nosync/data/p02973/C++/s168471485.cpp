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

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  reverse(ALL(a));
  vector<int> dp(n);
  int INF = MOD;
  REP(i, n) dp[i] = INF;
  REP(i, n) { *upper_bound(ALL(dp), a[i]) = a[i]; }
  cout << lower_bound(ALL(dp), INF) - dp.begin() << endl;
  return 0;
}
