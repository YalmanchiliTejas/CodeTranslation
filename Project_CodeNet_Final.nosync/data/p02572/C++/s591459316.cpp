#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll mod = 1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (auto &v : vec)
    cin >> v;

  ll suma = 0;
  for (auto &v : vec)
    suma = (suma + v) % mod;

  ll ans = 0;
  for (auto &v : vec) {
    suma = (suma - v) % mod;
    if (suma < 0)
      suma += mod;

    ll tmp = v * suma % mod;
    ans = (ans + tmp) % mod;
  }
  cout << ans << endl;
}
