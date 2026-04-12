#include <bits/stdc++.h>
 
#ifndef LOCAL_
#define fprintf if( false ) fprintf
#endif // LOCAL_
// #define dump() fprintf(stderr, "#%s.%d\n", __func__, __LINE__);
#define dumpl(x1) fprintf(stderr, "#%s.%d (%s) = (%ld)\n", __func__, __LINE__, #x1, x1);
#define dumpll(x1, x2) fprintf(stderr, "#%s.%d (%s, %s) = (%ld, %ld)\n", __func__, __LINE__, #x1, #x2, x1, x2);
#define dumplll(x1, x2, x3) fprintf(stderr, "#%s.%d (%s, %s, %s) = (%ld, %ld, %ld)\n", __func__, __LINE__, #x1, #x2, #x3, x1, x2, x3);
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

long dx[] = {1, 0, -1, 0};
long dy[] = {0, 1, 0, -1};


struct Solver {
  long n;
  std::vector<std::array<long, 2>> xs;
  Solver() {
    S002 reader;
    reader >= n;
    long m = n - 1;
    reader >m>= xs;
  }
  std::vector<long> neighbours[112345];
  bool visited[112345];
  long dfs(long i) {
    visited[i] = true;
    long even = 0, odd = 0;
    long max = 0;
    for(long next : neighbours[i]) {
      if( visited[next] ) continue;
      long t = dfs(next);
      if( t % 2 == 0 ) {
        even += 1;
      }
      else {
        odd += 1;
      }
      max = std::max(max, t);
    }
    if( odd >= 2 ) {
      puts("First");
      exit(0);
    }
    if( i == 1 and odd == 0 ) {
      puts("First");
      exit(0);
    }
    if( odd == 1 ) {
      return 2;
    }
    else {
      return 1;
    }
  }
  void solve() {
    for(auto x : xs) {
      neighbours[x[0]].push_back(x[1]);
      neighbours[x[1]].push_back(x[0]);
    }
    for(long i = 0; i < 112345; ++i) {
      visited[i] = false;
    }
    dfs(1);
    puts("Second");
  }
  ~Solver() { fprintf(stderr, "--end--\n"); }
};
 
int main() {
  loop std::unique_ptr<Solver>(new Solver())->solve();
  return 0;
}

