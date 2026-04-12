#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n) - 1; 0 <= i; --i)
#define rep(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using arr = vector<ll>;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

ll n, a[100010];
int main()
{
  cin >> n;
  REP(i,n) cin >> a[i], a[i]++;
  reverse(a, a + n);

  vector<ll> dp(n + 1, INF);
  REP(i, n) {
    *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }
  cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
  return 0;
}