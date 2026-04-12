#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
ll pow(int b, int e) {
  if(e == 0) return 1LL;
  if(e % 2 == 1) return pow(b, e - 1) * b;
  ll m = pow(b, e >> 1);
  return m * m;
}
vector<ll> a(55), b(55);

ll f(ll n, ll x) {
  if(n == 0) return x <= 0 ? 0 : 1;
  if(x <= 1 + a[n - 1]) return f(n - 1, x - 1);
  return b[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
}

int main() {
  ll n, x;
  cin >> n >> x;
  rep(i, n + 1) {
    a[i] = pow(2, i + 2) - 3;
    b[i] = pow(2, i + 1) - 1;
  }
  cout << f(n, x) << endl;
  return 0;
}
