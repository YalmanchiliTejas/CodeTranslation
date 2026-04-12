#include <iostream>
using namespace std;
using ll = long long;
template <class T> inline bool chmin(T& a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}
ll INF = 1e12;

int main() {
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll abcount = max(X, Y) * 2;
  ll ans = INF;
  for(ll i = 0; i <= abcount; i += 2) {
    auto cost = i * C;
    cost += max(0LL, (X - i / 2) * A);
    cost += max(0LL, (Y - i / 2) * B);
    chmin(ans, cost);
  }
  cout << ans << endl;
  return 0;
}