#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans = 0;
  if (n%2) {
    rep(i, n/2)
      ans -= a[i]*2;
    ans -= a[n/2]+a[n/2+1];
    rep(i, n/2+1)
      ans += a[i+n/2]*2;
    ll tmp = 0;
    rep(i, n/2)
      tmp += a[i+n/2+1]*2;
    tmp += a[n/2]+a[n/2-1];
    rep(i, n/2+1)
      tmp -= a[i]*2;
    chmax(ans, tmp);
  } else {
    ans += a[n/2-1]-a[n/2];
    rep(i, n/2)
      ans -= a[i]*2;
    rep(i, n/2)
      ans += a[i+n/2]*2;
  }
  cout << ans << endl;
  return 0;
}