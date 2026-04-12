#include <iostream>

#define ll long long
using namespace std;

const ll M = 998244353;
const ll N = (ll)(1e7+5);

ll fac[N];
ll ifac[N];

ll pow(ll b, ll p) {
  if (!p) return 1;
  if (p%2) return (b*pow(b,p-1))% M;
  ll a = pow(b, p/2);
  return (a*a)%M;
}

void work() {
  fac[0] = 1;
  for (ll i = 1; i < N; i++) {
    fac[i] = (fac[i-1] * i) % M;
  }
  ifac[N-1] = pow(fac[N-1], M-2);
  for (ll i = N-2; i >= 0; i--) {
    ifac[i] = (ifac[i+1] * (i+1)) % M;
  }
}

ll nCk(ll n, ll k) {
  return (((fac[n]*ifac[k]) % M) * ifac[n-k]) % M;
}


int main() {
  work();
  ll n;
  cin >> n;

  ll ret = 0;
  ll p2 = 1;
  for (ll i = n; i >= n/2 + 1; i--) {
    ret = (ret + 2*nCk(n, i) * p2) % M;
    p2 = (p2+p2)%M;
  }
  ret = (pow(3, n) - ret + M) % M;
  cout << ret << endl;
}