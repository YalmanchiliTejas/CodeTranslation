#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<ll> sum(n + 1);
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + a[i];
    sum[i + 1] %= MOD;
  }
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    ll res = (sum[n] - sum[i] + MOD) % MOD;
    res = (res * a[i - 1]) % MOD;
    ans = (ans + res) % MOD;
  }
  cout << ans << endl;
  return 0;
}