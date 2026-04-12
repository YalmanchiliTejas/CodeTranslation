#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int MAX = (int)(1e5 + 5);
const ll INF = (ll)(1e10 + 5);

const int MAX_N = (int)(1e5 + 5);

int n;
ll a[MAX_N];

multiset<ll> mst;

int main(void) {
  // Here your code !
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &(a[i]));
  }

  for (int i = 0; i < n; ++i) {
    auto ptr = mst.lower_bound(a[i]);

    if (ptr == mst.begin()) {
      mst.insert(a[i]);
    } else {
      ptr = prev(ptr);
      mst.erase(ptr);
      mst.insert(a[i]);
    }
  }

  printf("%d\n", mst.size());

  return 0;
}
