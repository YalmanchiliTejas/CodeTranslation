#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()

struct Cmp {
  bool operator()(const pll& lhs, const pll& rhs) {
    return lhs.first > rhs.first;
  }
};

ll len[51];
ll allcnt[51];

ll solve(int l, ll x) {
  if (x == 1) {
    if (l == 0)
      return 1;
    else
      return 0;
  }
  if (1 < x && x <= 1 + len[l - 1]) {
    return solve(l - 1, x - 1);
  } else if (x == 2 + len[l - 1]) {
    return allcnt[l - 1] + 1;
  } else if (2 + len[l - 1] < x && x <= 2 + 2 * len[l - 1]) {
    return allcnt[l - 1] + 1 + solve(l - 1, x - (2 + len[l - 1]));
  } else {
    return allcnt[l];
  }
}

int main() {
  int n;
  ll x;
  cin >> n >> x;
  len[0] = 1;
  allcnt[0] = 1;
  for (int i = 1; i <= n; i++) {
    len[i] = 3 + 2 * len[i - 1];
    allcnt[i] = 2 * allcnt[i - 1] + 1;
  }
  ll ans = solve(n, x);
  cout << ans << endl;
  return 0;
}
