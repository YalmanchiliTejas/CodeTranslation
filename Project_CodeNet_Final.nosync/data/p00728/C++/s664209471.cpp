#include <bits/stdc++.h>
using Int = int64_t;

int main() {
   for(;;) {
      Int n;
      std::cin >> n;
      if( n == 0 ) break;
      std::vector<Int> xs(n);
      for(Int i = 0; i < n; ++i) {
         std::cin >> xs[i];
      }
      std::sort(xs.begin(), xs.end());
      Int total = 0;
      for(Int i = 1; i < (Int)xs.size()-1; ++i) {
         total += xs[i];
      }
      Int res = total / (n-2);
      std::cout << res << std::endl;
   }
}

