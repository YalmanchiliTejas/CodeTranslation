#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1000000007;

ll r(ll x, ll y) {
  if (y == 0) return 1;
  else if (y % 2 == 0) return r(x, y/2) * r(x, y/2) % mod;
  else return x * r(x, (y-1)/2) % mod * r(x, (y-1)/2) % mod;
}

ll s(ll x) {
  if (x==0) {
    return 1;
  }
  else {
    return 2 * s(x-1) + 3;
  }
}

ll f(ll x, ll y) {
  if (x == 0) {
    return 1;
  }
  else if (y  == 1) {
    return 0;
  }
  else if (y <= s(x-1)+1){
    return f(x-1, y-1);
  }
  else if (y == s(x-1) + 2) {
    return f(x-1, s(x-1)) + 1;
  }
  else if (y == s(x)) {
    return 2 * f(x-1, s(x-1)) + 1;
  }
  else {
    return f(x-1, s(x-1)) + 1 + f(x-1, y - s(x-1) -2);
  }
}

int main() {
  ll n, p;
  cin >> n >> p;
  printf("%lld\n", f(n, p));
}
              

