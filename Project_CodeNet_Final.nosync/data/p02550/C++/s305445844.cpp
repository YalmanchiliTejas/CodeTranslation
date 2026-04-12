#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  //e
  long long n, x, m;
  cin >> n >> x >> m;
  vector<int> vis(m + 1, 0);
  long long ans = 0;
  long long cur = x;
  while (!vis[cur]) {
    vis[cur] = 1;
    cur *= cur;
    cur %= m;
  }
  long long sum_c = 0;
  int cycle = 0;
  long long st = cur;
  do {
    sum_c += cur;
    cur *= cur;
    cur %= m;
    cycle++;
  } while (cur != st);
  cur = x;
  while (cur != st) {
    n--;
    ans += cur;
    cur *= cur;
    cur %= m;
  }
  ans += sum_c * (n / cycle);
  n %= cycle;
  cur = st;
  while (n > 0) {
    n--;
    ans += cur;
    cur *= cur;
    cur %= m;
  }
  cout << ans << endl;
  return 0;
}