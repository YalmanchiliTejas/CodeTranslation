#include "bits/stdc++.h"
using namespace std;
#define dump(x) cout << (x) << endl;
typedef long long ll;

ll h(ll n) {
  ll ret = 1;
  while (n--) ret = 2 * ret + 1;
  return ret;
}

ll g(ll n) {
  ll ret = 1;
  while (n--) ret = 2 * ret + 3;
  return ret;
}

ll f(ll n, ll x) {
  ll a =  g(n);
  if (n == 0) return 1;
  if (x == 1) return 0;
  else if (x < (a-3)/2 + 2) return f(n-1, x-1);
  else if (x == (a-3)/2 + 2) return h(n-1) + 1;
  else if ((a-3)/2 + 2 < x && x < a) return h(n-1) + 1 + f(n-1, x - (a-3)/2 - 2);
  else if (x == a) return h(n);
}

int main() {
  ll n, x;
  cin >> n >> x;
  dump(f(n, x));
  return 0;
}
