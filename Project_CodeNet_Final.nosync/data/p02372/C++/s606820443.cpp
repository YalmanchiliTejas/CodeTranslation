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
   Int n;
   std::cin >> n;
   std::vector<Int> ss(n-1), ts(n-1), ws(n-1);
   rep(i, n-1) std::cin >> ss[i] >> ts[i] >> ws[i];
   std::vector<std::vector<std::pair<Int,Int>>> nexts(n);
   rep(i, n-1) {
      Int s = ss[i], t = ts[i], w = ws[i];
      nexts[s].emplace_back(t, w);
      nexts[t].emplace_back(s, w);
   }
   std::vector<Int> xs(n, -1);
   std::vector<Int> ys(n, -1);
   Int as[3] = {};
   for(Int t = 0; t < 3; ++t) {
      Int c = as[std::max((Int)0, t-1)];
      std::vector<Int>& zs = (t % 2 == 0) ? xs : ys;
      zs.clear();
      zs.resize(n, -1);
      std::queue<Int> q;
      zs[c] = 0;
      q.emplace(c);
      while( not q.empty() ) {
         Int i = q.front(); q.pop();
         for(auto kw : nexts[i]) {
            Int k, w; std::tie(k, w) = kw;
            guard( zs[k] == -1 );
            zs[k] = zs[i] + w;
            q.emplace(k);
         }
      }
      rep(i, n) if( zs[as[t]] < zs[i] ) as[t] = i;
   }
   rep(i, n) printf("%ld\n", std::max(xs[i], ys[i]));
}

