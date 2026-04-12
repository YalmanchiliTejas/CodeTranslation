#include <iostream>
#include <vector>
using namespace std;
using ll = int64_t;

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  vector<int> order(m);
  vector<ll> value(m);

  int ord = 1;
  ll ans = 0;
  while (n > 0) {
    if (order[x] > 0) {
      ll len = ord - order[x];
      ll val = ans - value[x] + x;
      ans += n / len * val;
      n %= len;
    }
    if (n > 0) {
    ans += x;
    --n;
    order[x] = ord++;
    value[x] = ans;
    x = x * x % m;
    }
  }
  cout << ans;
  return 0;
}
