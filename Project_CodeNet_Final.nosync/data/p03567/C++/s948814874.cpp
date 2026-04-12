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
#define guard(x) if( not ( x ) ) continue;
typedef int64_t Int;
typedef std::vector<Int> LI;
const double pi = 3.14159265358979323846264338;
const Int mod = 1000000007;

template<typename T> void scan1(T& x) { fprintf(stderr, "unknown type\n"); }
template<> void scan1(Int& x) { if( scanf("%" PRId64, &x) < 0 ) exit(0); }
template<> void scan1(std::string& x) { if( not ( std::cin >> x ) ) exit(0); }
template<> void scan1(LI& xs) { for(Int &x : xs) scan1(x); }
void scan() {}
template<typename Head, typename... Tail>
void scan(Head& x, Tail&... xs) {
  scan1(x); scan(xs...);
}

struct Solver {
   Solver() { fprintf(stderr, "--------Solver begin--------\n"); }
   ~Solver() { fprintf(stderr, "--------Solver end--------\n"); }
   void solve() {
      std::string ss; scan(ss);
      Int n = ss.size();
      for(Int i = 1; i < n; ++i) {
         if( ss[i-1] == 'A' and ss[i] == 'C' ) {
            puts("Yes");
            return;
         }
      }
      puts("No");
   }
};

int main() {
   loop std::unique_ptr<Solver>(new Solver())->solve();
}


