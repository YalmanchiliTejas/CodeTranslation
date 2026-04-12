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

struct Solver {
   Solver() { fprintf(stderr, "--------Solver begin--------\n"); }
   ~Solver() { fprintf(stderr, "--------Solver end--------\n"); }
   void solve() {
      long n; scan(n);
      LI xs(n); for(long &x : xs) scan(x);
      LI ys;
      LI zs;
      for(long i = 0; i < n; i+=2) {
         ys.push_back(xs[i]);
      }
      for(long i = 1; i < n; i+=2) {
         zs.push_back(xs[i]);
      }
      LI res;
      if( n % 2 == 0 ) {
         std::reverse(zs.begin(), zs.end());
         for(long z : zs) res.push_back(z);
         for(long y : ys) res.push_back(y);
      }
      else {
         std::reverse(ys.begin(), ys.end());
         for(long y : ys) res.push_back(y);
         for(long z : zs) res.push_back(z);
      }
      printf("%ld", res[0]);
      for(long i = 1; i < (long)res.size(); ++i) {
         printf(" %ld", res[i]);
      }
      putchar('\n');
   }
};

int main() {
   loop std::unique_ptr<Solver>(new Solver())->solve();
}

