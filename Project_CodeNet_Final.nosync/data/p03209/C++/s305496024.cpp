#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

const int N = 55;
ll f[N], l[N];

ll g (ll n, ll x) {
  assert(x <= l[n]);
  if (n == 0) return x;
  if (x == l[n]) return f[n];
  if (x == 0) return 0;
  ll mid = l[n - 1] + 2;
  if (x < mid) return g(n - 1, x - 1);
  else if (x > mid) return 1 + f[n - 1] + g(n - 1, x - 2 - l[n - 1]);
  else return 1 + f[n - 1];
}

int main() {
  ll n, x;
  scanf("%lld%lld", &n, &x);
  f[0] = l[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = 1 + 2 * f[i - 1];
    l[i] = 3 + 2 * l[i - 1];
  }
  printf("%lld\n", g(n, x));
}

