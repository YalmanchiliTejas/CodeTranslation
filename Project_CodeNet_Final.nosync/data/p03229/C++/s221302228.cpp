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
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<ll> s, l;
  for(int i = 0; i < n / 2; i++) {
    s.push_back(a[i]);
  }
  for(int i = n - 1; i >= n / 2; i--) {
    l.push_back(a[i]);
  }
  ll ans = 0;
  ll c = s[0], d = l[0];
  ans += abs(c - d);
  for(int i = 1; i < n / 2; i++) {
    if(i % 2 == 0) {
      ans += abs(c - s[i]);
      c = s[i];
      ans += abs(d - l[i]);
      d = l[i];
    } else {
      ans += abs(c - l[i]);
      c = l[i];
      ans += abs(d - s[i]);
      d = s[i];
    }
  }
  if(n % 2 != 0) {
    ans += max(abs(c - *(l.end() - 1)), abs(d - *(l.end() - 1)));
  }
  cout << ans << endl;
  return 0;
}