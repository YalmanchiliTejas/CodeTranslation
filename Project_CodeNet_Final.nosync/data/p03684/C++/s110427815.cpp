#include <bits/stdc++.h>

#ifndef LOCAL_
#define fprintf if( false ) fprintf
#endif // LOCAL_
#define dump() fprintf(stderr, "#%s.%d\n", __func__, __LINE__);
#define dumpl(x1) fprintf(stderr, "#%s.%d (%s) = (%ld)\n", __func__, __LINE__, #x1, x1);
#define dumpll(x1, x2) fprintf(stderr, "#%s.%d (%s, %s) = (%ld, %ld)\n", __func__, __LINE__, #x1, #x2, x1, x2);
#define dumplll(x1, x2, x3) fprintf(stderr, "#%s.%d (%s, %s, %s) = (%ld, %ld, %ld)\n", __func__, __LINE__, #x1, #x2, #x3, x1, x2, x3);
#define dumpd(x1) fprintf(stderr, "#%s.%d (%s) = (%lf)\n", __func__, __LINE__, #x1, x1);
#define dumpdd(x1, x2) fprintf(stderr, "#%s.%d (%s, %s) = (%lf, %lf)\n", __func__, __LINE__, #x1, #x2, x1, x2);
#define loop for(;;)
typedef std::vector<long> LI;
typedef std::queue<long> QI;
#define rep(i,n) for(long i = 0; i < (long)n; ++i)
const double pi = M_PI;

template<typename T> void scan1(T& x) { fprintf(stderr, "unknown type\n"); }
template<> void scan1(long& x) { if( scanf("%ld", &x) < 0 ) exit(0); }
template<> void scan1(std::string& x) { if( not ( std::cin >> x ) ) exit(0); }
void scan() {}
template<typename Head, typename... Tail>
void scan(Head& x, Tail&... xs) {
  scan1(x); scan(xs...);
}

struct N001 {
   long n;
   std::vector<long> parents;
   std::vector<long> numbers;
   N001(long n_) : n(n_), parents(n+1, -1), numbers(n+1, -1) {
   }
};
long find(N001& s, long x) {
   if( s.parents[x] == -1 ) return x;
   return s.parents[x] = find(s, s.parents[x]);
}
bool same(N001& s, long x, long y) {
   return find(s, x) == find(s, y);
}
void unite(N001& s, long x, long y) {
   long x2 = find(s, x);
   long y2 = find(s, y);
   if( x2 == y2 ) return;
   if( not ( s.numbers[x2] <= s.numbers[y2] ) )
      std::swap(x2, y2);
   s.parents[x2] = y2;
   s.numbers[y2] += s.numbers[x2];
}


struct Solver {
   Solver() { fprintf(stderr, "--------Solver begin--------\n"); }
   ~Solver() { fprintf(stderr, "--------Solver end--------\n"); }
   void solve() {
      long n; scan(n);
      LI xs(n), ys(n);
      rep(i, n) scan(xs[i], ys[i]);
      std::priority_queue<std::tuple<long, long, long>> q;
      std::vector<std::pair<long, long>> zs(n);
      for(long i = 0; i < n; ++i) {
         zs[i] = std::make_pair(xs[i], i);
      }
      std::sort(zs.begin(), zs.end());
      for(long i = 1; i < n; ++i) {
         q.push(std::make_tuple(-(zs[i].first-zs[i-1].first), zs[i-1].second, zs[i].second));
      }
      for(long i = 0; i < n; ++i) {
         zs[i] = std::make_pair(ys[i], i);
      }
      std::sort(zs.begin(), zs.end());
      for(long i = 1; i < n; ++i) {
         q.push(std::make_tuple(-(zs[i].first-zs[i-1].first), zs[i-1].second, zs[i].second));
      }
      N001 uf(n);
      long count = 0;
      long res = 0;
      while( count != n - 1 ) {
         long d, i, k;
         std::tie(d, i, k) = q.top(); q.pop();
         if( same(uf, i, k) ) continue;
         unite(uf, i, k);
         count += 1;
         res += d;
      }
      printf("%ld\n", -res);
   }
};

int main() {
   loop std::unique_ptr<Solver>(new Solver())->solve();
}

