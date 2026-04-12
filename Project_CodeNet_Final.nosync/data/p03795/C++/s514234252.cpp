#include <bits/stdc++.h>
 
#ifndef LOCAL_
#define fprintf if( false ) fprintf
#endif // LOCAL_
#define dumpi(x1) fprintf(stderr, "#%s.%d (%s) = (%d)\n", __func__, __LINE__, #x1, x1);
#define dumpii(x1, x2) fprintf(stderr, "#%s.%d (%s, %s) = (%d, %d)\n", __func__, __LINE__, #x1, #x2, x1, x2);
#define dumpiii(x1, x2, x3) fprintf(stderr, "#%s.%d (%s, %s, %s) = (%d, %d, %d)\n", __func__, __LINE__, #x1, #x2, #x3, x1, x2, x3);
#define dumpl(x1) fprintf(stderr, "#%s.%d (%s) = (%ld)\n", __func__, __LINE__, #x1, x1);
#define dumpll(x1, x2) fprintf(stderr, "#%s.%d (%s, %s) = (%ld, %ld)\n", __func__, __LINE__, #x1, #x2, x1, x2);
#define dumpd(x1) fprintf(stderr, "#%s.%d (%s) = (%lf)\n", __func__, __LINE__, #x1, x1);
#define dumpdd(x1, x2) fprintf(stderr, "#%s.%d (%s, %s) = (%lf, %lf)\n", __func__, __LINE__, #x1, #x2, x1, x2);
#define loop for(;;)
 
struct S002 {
  int n;
  S002& operator > (long& x) {
    n = x;
    return *this;
  }
  S002& operator > (long&& x) {
    n = x;
    return *this;
  }
  S002& operator >= (long& x) {
    if( scanf("%ld", &x) <= 0 ) exit(0);
    return *this;
  }
  S002& operator >= (double& x) {
    if( scanf("%lf", &x) <= 0 ) exit(0);
    return *this;
  }
  S002& operator >= (std::string& s) {
    if( not (std::cin >> s) ) exit(0);
    return *this;
  }
  template<typename a>
  S002& operator >= (std::vector<a>& v) {
    v.resize(n);
    for(long i = 0; i < n; ++i) {
      *this >= v[i];
    }
    return *this;
  }
  template<typename a, std::size_t s>
  S002& operator >= (std::array<a, s>& x) {
    for(long i = 0; i < (long)s; ++i) {
      *this >= x[i];
    }
    return *this;
  }
};

struct Solver {
  long n;
  std::vector<std::string> xs;
  std::vector<std::string> ys;
  Solver() {
    S002 r;
    r >= n;
  }  
  void solve() {
    long res = n * 800 - (n / 15) * 200;
    printf("%ld\n", res);
  }
};
 
int main() {
  for(;;) std::unique_ptr<Solver>(new Solver())->solve();
  return 0;
}