#include <bits/stdc++.h>
 
#ifndef LOCAL_
#define fprintf if( false ) fprintf
#endif // LOCAL_
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
  long n, m;
  std::vector<std::string> xs;
  Solver() {
    S002 reader;
    reader >= n >= m >n>= xs;      
  }
  void solve() {
    long count = 0;
    for(long i = 0; i < n; ++i) {
      for(long j = 0; j < m; ++j) {
        if( xs[i][j] == '#' ) count += 1;
      }
    }
    puts(count == n + m - 1 ? "Possible" : "Impossible");        
  }
};
 
int main() {
  loop std::unique_ptr<Solver>(new Solver())->solve();
  return 0;
}