#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int md = 998244353;

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

int mul(int a, int b) {
  return ((ll)a * b) % md;
}

int power(int a, ll b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> f(n + 1), rf(n + 1);
  f[0] = 1;
  for (int i = 1; i <= n; ++i) f[i] = mul(f[i - 1], i);
  rf[n] = power(f[n], md - 2);
  for (int i = n - 1; i >= 0; --i) {
    rf[i] = mul(rf[i + 1], i + 1);
  }
  auto C = [&] (int n, int k) {
    return mul(f[n], mul(rf[n - k], rf[k]));
  };
  vector <int> p2(n + 1);
  p2[0] = 1;
  for (int i = 1; i <= n; ++i) p2[i] = mul(p2[i - 1], 2);
  int ans = 1;
  for (int i = 0; i < n; ++i) ans = mul(ans, 3);
  for (int cnt = n / 2 + 1; cnt <= n; ++cnt) {
    int cur = mul(C(n, cnt), p2[n - cnt]);
    sub(ans, mul(cur, 2));
  }
  cout << ans << '\n';
}

