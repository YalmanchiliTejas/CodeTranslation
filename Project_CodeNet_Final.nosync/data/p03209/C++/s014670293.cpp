#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> ps;
vector<ll> as;

ll f(ll n, ll x) {
  if(n == 0) {
    return x <= 0 ? 0 : 1;
  } else if(x <= 1 + as[n - 1]) {
    return f(n - 1, x - 1);
  } else {
    return ps[n - 1] + 1 + f(n - 1, x - 2 - as[n - 1]);
  }
}

int main() {
  ll N, X;
  cin >> N >> X;
  ps = vector<ll>(N + 1); // パティの枚数の配列
  ps[0] = 1;
  as = vector<ll>(N + 1); // 枚数の配列
  as[0] = 1;
  for(ll i = 1; i <= N; ++i) {
    ps[i] = 2 * ps[i - 1] + 1;
    as[i] = 2 * as[i - 1] + 3;
  }
  cout << f(N, X) << endl;
  return 0;
}