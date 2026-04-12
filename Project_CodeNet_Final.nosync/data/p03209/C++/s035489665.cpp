#include <bits/stdc++.h>

typedef long long ll;

void print(){ std::cout << std::endl; }
template <typename Head> void print(Head&& head) { std::cout << head << std::endl; }
template <typename Head, typename... Tail> void print(Head&& head, Tail&&... tail)
{
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...); // or print(tail...);
}

ll a[51];
ll p[51];

ll f(ll level, ll x)
{
  if (x == 1) {
    return level == 0 ? 1 : 0;
  }
  if (1 < x && x < 1 + a[level-1] + 1) {
    return f(level-1, x-1);
  }
  if (x == 1 + a[level-1] + 1) {
    return p[level-1] + 1;
  }
  if (1 + a[level-1] + 1 < x && x < 1 + a[level-1] + 1 + a[level-1] + 1) {
    return p[level-1] + 1 + f(level-1, x - (1 + a[level-1] + 1));
  }
  if (1 + a[level-1] + 1 < x && x < 1 + a[level-1] + 1 + a[level-1] + 1) {
    return p[level-1] + 1 + f(level-1, x - (1 + a[level-1] + 1));
  }
  if (x == 1 + a[level-1] + 1 + a[level-1] + 1) {
    return p[level-1] * 2 + 1;
  }

  return -1;
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
