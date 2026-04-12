#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

bool finish(vector<ll> &la) {
  int n = la.size();
  for (ll a: la) {
    if (a >= n) return false;
  }
  return true;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> la(n);
  for (ll &a: la) cin >> a;
  ll ans = 0;
  while (!finish(la)) {
    ll sum = 0;
    for (ll a: la) {
      sum += a/n;
    }
    for (ll &a: la) {
      ll diff = -(a/n)*n;
      diff += sum-a/n;
      a += diff;
    }
    ans += sum;
  }
  cout << ans << endl;
}
