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
int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  ll ans = 0, num = x;
  int cnt = 0;
  vector<int> a(m, -1);
  bool ok = true;
  for(int i = 0; i < n; i++) {
    ans += num;
    if(num == 0) {
      cout << ans << endl;
      return 0;
    }
    if(a[num] >= 0) {
      cnt = i;
      ok = false;
      break;
    }
    a[num] = i;
    num = num * num % m;
  }
  if(ok) {
    cout << ans << endl;
    return 0;
  }
  n -= a[num];
  int border = a[num];
  vector<ll> sum(m, 0);
  num = x;
  ans = 0;
  for(int i = 0; i < border; i++) {
    ans += num;
    num = num * num % m;
  }
  for(int i = 0; i < cnt - border + 1; i++) {
    sum[i + 1] += sum[i] + num;
    num = num * num % m;
  }
  ans += sum[cnt - border] * (n / (cnt - border));
  ans += sum[n % (cnt - border)];
  cout << ans << endl;
  return 0;
}