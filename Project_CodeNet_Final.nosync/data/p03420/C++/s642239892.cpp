#include <bits/stdc++.h>
using Int = int64_t;
using UInt = uint64_t;
using C = std::complex<double>;
#define rep(i, n) for(Int i = 0; i < (Int)(n); ++i)
#define guard(x) if( not (x) ) continue;
#ifndef LOCAL_
#define fprintf if( false ) fprintf
#endif

int main() {
   Int n, m;
   std::cin >> n >> m;
   Int res = 0;
   if( m == 0 ) {
      res = n * n;
   }
   else {
      for(Int b = 1; b <= n; ++b) {
         guard( b > m );
         Int t = (n/b)*(b-m)+std::max((Int)0, n%b-m+1);
         res += t;
      }
   }
   printf("%ld\n", res);
}
