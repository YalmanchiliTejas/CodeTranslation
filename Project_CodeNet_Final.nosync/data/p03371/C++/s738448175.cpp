#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

int main()
{
  ll A, B, C, X, Y;
  std::cin >> A >> B >> C >> X >> Y;

  ll ab = (A + B) < C * 2 ? (A + B) : C * 2;
  ll a  = A < C * 2 ? A : C * 2;
  ll b  = B < C * 2 ? B : C * 2;

  ll diff = std::max(X, Y) - std::min(X, Y);
  ll ans = ab * std::min(X, Y);
  if (X > Y) {
    ans += diff * a;
  } else {
    ans += diff * b;
  }

  std::cout << ans << std::endl;
  return 0;
}
