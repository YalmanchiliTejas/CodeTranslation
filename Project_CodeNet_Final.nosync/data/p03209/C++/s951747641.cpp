#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x;
ll num_p[51] = {};
ll num_l[51] = {};

ll dfs(int level, ll &x) {
  // cerr << level << " " << x << " " << num_l[level] << " " << num_p[level] << endl;
  if (x >= num_l[level]) {
    x -= num_l[level];
    return num_p[level];
  }

  ll ret = 0;
  if (x > 0)
    x -= 1; // B
  if (x > 0)
    ret += dfs(level - 1, x); // (L-1) Burger
  if (x > 0)
    ret++, x -= 1; // P
  if (x > 0)
    ret += dfs(level - 1, x); // (L-1) Burger
  if (x > 0)
    x -= 1; // B;

  return ret;
}

int main() {
  cin >> n >> x;

  num_p[0] = 1;
  num_l[0] = 1;
  for (int i = 1; i < 51; i++) {
    num_p[i] = num_p[i - 1] * 2 + 1;
    num_l[i] = num_l[i - 1] * 2 + 3;
    // cerr << i << " " << num_p[i] << " " << num_l[i] << endl;
  }

  cout << dfs(n, x) << endl;
}
