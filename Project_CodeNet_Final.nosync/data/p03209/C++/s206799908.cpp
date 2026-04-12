#include <iostream>
#include <vector>

typedef long long int ll;

std::vector<ll> a, p;
  
ll f(int x, ll y) {
  if(x==0) {
    return (y<=0?0:1);
  }
  else if (y <= (1 + a.at(x-1))) {
    return f(x-1, y-1);
  } else {
    return (p.at(x-1)+1+f(x-1, (y-2-a.at(x-1))));
  }
}

int main() {
  int n = 0;
  ll x = 0;
  std::cin >> n >> x;
  
  a.push_back(1);
  p.push_back(1);
  
  for (int i = 0; i < n; i++) {
    a.push_back(3 + 2 * a.at(i));
    p.push_back(1 + 2 * p.at(i));
  }

  std::cout << f(n, x) << std::endl;
  return 0;
}
