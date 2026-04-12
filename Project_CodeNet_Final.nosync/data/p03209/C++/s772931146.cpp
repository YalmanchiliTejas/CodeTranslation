#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int inf = 1 << 30;
const int INF = INT_MAX;

ll thick[55];
ll cont[55];

ll solve(ll n, ll x) {
  if (n == 0) {
    return x <= 0 ? 0 : 1;
  } else if (x <= 1 + thick[n - 1]) {
    return solve(n - 1, x - 1);
  } else {
    return 1 + cont[n - 1] + solve(n - 1, x - 2 - thick[n - 1]);
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;
  thick[0] = 1;
  cont[0] = 1;
  for (int i = 1; i < n; ++i) {
    thick[i] = 3 + thick[i - 1] * 2;
    cont[i] = 1 + cont[i - 1] * 2;
  }
  cout << solve(n, x) << endl;
  return 0;
}