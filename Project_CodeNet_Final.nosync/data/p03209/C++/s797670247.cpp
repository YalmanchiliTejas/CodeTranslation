#include <bits/stdc++.h>
#define DUMBER using
#define EVERY namespace
#define DAY std
DUMBER EVERY DAY;
#define el '\n'
typedef long long ll;
ll a[55], p[55];
ll serc(int n, ll x) {
  if (x == 0) return x;
  if (n == 0) {
    if (x <= 0) return 0;
    return 1;
  }
  if (x <= 1+a[n-1]) return serc(n-1, x-1);
  //  bun [burger] pat [burger] bun 
  //  xxxxxxxxxxxxxxxxxxxxx
  //  xxxxxxxxxxxxxxxxx
  return 1 + p[n-1] + serc(n-1, x-2-a[n-1]);
}
int main() {
  int n;
  ll x;
  cin >> n >> x;
  a[0] = p[0] = 1;
  for (int i = 1; i <= n; i++) {
    a[i] = 2*a[i-1]+3;
    p[i] = 2*p[i-1]+1;
  }
  cout << serc(n, x) << el;
  return 0;
}
