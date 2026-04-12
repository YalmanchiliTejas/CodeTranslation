#include <stdio.h>
#include <set>
typedef long long ll;

int main(void) {
  ll i, j, n, a;
  scanf("%lld", &n);
  std::multiset<ll> s;
  std::multiset<ll>::iterator it;
  for(i = 0; i < n; ++i) {
    scanf("%lld", &a);
    it = s.lower_bound(a);
    if(it != s.begin()) {
      it--;
      s.erase(it);
    }
    s.insert(a);
  }
  printf("%lld", s.size());
  return 0;
}