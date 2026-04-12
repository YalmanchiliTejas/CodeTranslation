#include <bits/stdc++.h>
#define N 200007
using namespace std;
typedef long long ll;

inline ll rd() {
  ll x = 0;
  char c = getchar();
  while(!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
  return x;
}

ll n, x, m, p, ans, cnt[N];

inline int phi(int x) {
  int res = x;
  for (int i = 2; i <= x; ++i)
    if (x % i == 0) {
      res = res / i * (i - 1);
      while (x % i == 0) x /= i;
      if (x == 1) break;
    }
  return res;
}

inline void work1() {
  for (int i = 1; i <= n; ++i) {
    ans += x; x = x * x % m;
  }
  printf("%lld\n", ans);
}

inline ll fpow(ll x, ll t) {
  ll res = 1;
  while (t) {
    if (t & 1) res = res * x % m;
    x = x * x % m; t >>= 1;
  }
  return res;
}

int main() {
  n = rd(); x = rd();
  m = rd(); p = phi(m);
  if (n <= 1000000) {work1(); return 0;}
  ll index = 0;
  ll xx = x;
  while ((1ll << index) < p) {
    ans += x; x = x * x % m; ++index;
  }
  ll tmp = index;
  ll nw = (1ll << index) % p;
  while (cnt[nw] == 0) {
    ++cnt[nw];
    nw = (nw << 1) % p;
    ++tmp;
  }
  ll t = (n - index) / (tmp - index);
  for (int i = 0; i < p; ++i) cnt[i] *= t;
  n = (n - index) % (tmp - index);
  for (int i = 1; i <= n; ++i) {
    ++cnt[nw]; nw = (nw << 1) % p;
  }
  nw = fpow(xx, p);
  for (int i = 0; i < p; ++i) {
    ans += nw * cnt[i];
    nw = nw * xx % m;
  }
  printf("%lld\n", ans);
  return 0;
}
