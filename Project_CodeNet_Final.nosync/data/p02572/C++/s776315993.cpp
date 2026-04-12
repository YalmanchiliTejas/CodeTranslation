#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define ll long long
using namespace std;
const int MOD = 1000000007;
const long long INF = 1LL << 60;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> sum(n + 1, 0);
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    sum[i + 1] = a[i] + sum[i];
  }
  for (ll i = 2; i < n + 1; i++) {
    ll value = (sum[n] - sum[i - 1]) % MOD;
    ll num = a[i - 2] % MOD;
    ans += value * num;
    ans %= MOD;
  }
  cout << ans << endl;
}