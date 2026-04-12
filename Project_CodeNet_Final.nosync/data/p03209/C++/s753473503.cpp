#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

typedef long long ll;
const ll INF = 1e18;

ll a[51];
ll p[51];

ll f(ll n, ll x)
{
  if (n == 0) {
    return x <= 0 ? 0 : 1;
  }
  if (x <= 1+a[n-1]) {
    return f(n-1,x-1);
  } else {
    return p[n-1]+1+f(n-1,x-2-a[n-1]);
  }
}

int main(int argc, char* argv[])
{
  ll N, X;
  std::cin >> N >> X;

  a[0] = 1;
  p[0] = 1;
  for (ll i = 1; i <=50; i++) {
    a[i] = 2 * a[i-1] + 3;
    p[i] = 2 * p[i-1] + 1;
  }

  std::cout << f(N, X) << std::endl;

  return 0;
}
