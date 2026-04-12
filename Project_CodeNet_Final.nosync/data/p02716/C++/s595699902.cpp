#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#define REP(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;
constexpr ll MOD = 1000000007;

ll n, k, c, a[200010], dp_not[200010], dp_take[200010];
string s;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) {
    dp_not[i] = -INF;
    dp_take[i] = -INF;
  }

  dp_not[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int j = (i - 1) / 2;
    dp_not[j + 1] = max(dp_not[j + 1], dp_take[j + 1]);
    dp_take[j + 1] = dp_not[j] + a[i - 1];

    dp_not[j] = max(dp_not[j], dp_take[j]);
    dp_take[j] = dp_not[j - 1] + a[i - 1];
  }
  cout << max(dp_not[n / 2], dp_take[n / 2]);
  return 0;
}

