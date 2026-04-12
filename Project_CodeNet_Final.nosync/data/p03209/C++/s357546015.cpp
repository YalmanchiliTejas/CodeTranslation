#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
using namespace std;
using namespace boost;
main() {
  // total_layer[n] = pow(2, n+2) - 3
  // paty[n] = pow(2, n+1) - 1
  int64_t n, x;
  cin >> n >> x;
  
  int64_t ans = 0;
  for (; n>=0; --n) {
    auto t = pow(2L, n+2-1) - 3;
    if (x > 1 + t) {
      ans += pow(2L, n+1-1);
      x -= 1 + t;
    }
    if (x == 2 + t) --x;
    --x;
  }
  cout << ans << endl;
}
  