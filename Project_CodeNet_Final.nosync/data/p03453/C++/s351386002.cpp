#include <bits/stdc++.h>
using Int = int64_t;
using UInt = uint64_t;
using C = std::complex<double>;
#define rep(i, n) for(Int i = 0; i < (Int)(n); ++i)
#define guard(x) if( not (x) ) continue;
#ifndef LOCAL_
#define fprintf if( false ) fprintf
#endif

template<typename T>
using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
const Int mod = 1000000007;

int main() {
   Int n, m;
   std::cin >> n >> m;
   Int s, t;
   std::cin >> s >> t;
   s -= 1, t -= 1;
   std::vector<Int> ss(m), ts(m), ds(m);
   rep(i,m) {
      std::cin >> ss[i] >> ts[i] >> ds[i];
      ss[i] -= 1, ts[i] -= 1;
   }
   std::vector<std::vector<std::pair<Int,Int>>> nexts(n);
   rep(i,m) {
      nexts[ss[i]].emplace_back(ts[i],ds[i]);
      nexts[ts[i]].emplace_back(ss[i],ds[i]);
   }
   Int inf = (Int)1 << 53;
   std::function<std::pair<std::vector<Int>,std::vector<Int>>(Int)> dijkstra = [&](Int src) {
      std::vector<Int> xs(n,inf);
      std::vector<Int> ys(n,0);
      xs[src] = 0;
      ys[src] = 1;
      PQ<std::pair<Int,Int>> q;
      q.emplace(0, src);
      while( not q.empty() ) {
         Int d, i; std::tie(d, i) = q.top(); q.pop();
         if( d != xs[i] ) continue;
         for(auto kw : nexts[i]) {
            Int k, w; std::tie(k, w) = kw;
            Int nd = d + w;
            if( xs[k] == nd ) {
               ys[k] = (ys[k] + ys[i]) % mod;
               continue;
            }
            if( xs[k] < nd ) {
               continue;
            }
            if( xs[k] > nd ) {
               xs[k] = nd;
               ys[k] = ys[i];
               q.emplace(nd, k);
            }
         }
      }
      return std::make_pair(xs,ys);
   };
   std::vector<Int> sd, sc, td, tc;
   std::tie(sd, sc) = dijkstra(s);
   std::tie(td, tc) = dijkstra(t);
   std::vector<bool> collideEdge(m,false);
   rep(i,m) {
      Int x = ss[i], y = ts[i];
      Int a, b, c, d;
      if( sd[x] < sd[y] and td[x] > td[y] ) {
         a = sd[x], b = sd[y], c = td[y], d = td[x];
      }
      else if( sd[x] > sd[y] and td[x] < td[y] ) {
         a = sd[y], b = sd[x], c = td[x], d = td[y];
      }
      else {
         collideEdge[i] = true;
      }
      // Int a = std::min(sd[x], sd[y]), b = std::max(sd[x], sd[y]);
      // Int c = std::min(td[x], td[y]), d = std::max(td[x], td[y]);
      if( d <= a or b <= c ) continue;
      collideEdge[i] = true;
   }
   std::vector<bool> validEdge(m, true);
   rep(i,m) {
      Int x = ss[i], y = ts[i];
      if( not ( sd[x] + td[x] == sd[t] and sd[y] + td[y] == td[s] and std::abs(sd[x]-sd[y]) == ds[i] ) )
         validEdge[i] = false;
   }
   std::vector<bool> collideVertex(n, false);
   rep(i,n) {
      if( sd[i] == td[i] )
         collideVertex[i] = true;
   }
   Int res = sc[t] * tc[s] % mod;
   fprintf(stderr, "all = %ld\n", res);
   rep(i,m) {
      if( not validEdge[i] ) continue;
      if( collideEdge[i] ) {
         Int x = ss[i], y = ts[i];
         if( sd[x] > sd[y] )
            std::swap(x,y);
         res = (res + mod - (sc[x] * tc[y] % mod * sc[x] % mod * tc[y] % mod)) % mod;
         fprintf(stderr, "sc[%ld] = %ld, tc[%ld] = %ld\n", x+1, sc[x], y+1, tc[y]);
      }
   }
   rep(i,n) {
      if( sd[i] + td[i] != sd[t] ) continue;
      if( collideVertex[i] ) {
         res = (res + mod - (sc[i] * tc[i] % mod * sc[i] % mod * tc[i] % mod)) % mod;
      }
   }
   printf("%ld\n", res);
}
