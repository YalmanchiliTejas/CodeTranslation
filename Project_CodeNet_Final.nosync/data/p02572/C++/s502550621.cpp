#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ll ans = 0;
  sum %= MOD;
  for(int i = 0; i < n; i++) {
    sum -= a[i];
    if(sum < 0) {
      sum += MOD;
    }
    ans += a[i] * sum % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}