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

struct S004 {
  S004() : s(-1), d(-1) {}             
  S004(int s_, int d_) : s(s_), d(d_) {}
  long s, d;
};

template<typename a>
struct S005 {
  typedef a e;
  std::vector<std::vector<a>> xs;
  const std::vector<a>& ys;
  long n;
  S005(const std::vector<a>& ys_, long n_) : ys(ys_), n(n_) {
    xs.resize(n);
    for(a x : ys) {
      a y = x;
      xs[x.s].push_back(y);
    }
  }
  const std::vector<a>& operator [] (long i) const {
    return xs[i];
  }
  long v() const {
    return n;
  }
  const std::vector<a>& es() const {
    return ys;
  }
};

template<typename a>
struct S026 {
  std::vector<std::vector<long>> xs;
  long n;
  S026(const a& graph, long src) : n(graph.v()) {
    std::vector<bool> visited(n, false);
    std::vector<long> path;
    dfs(graph, src, visited, 0, path);
  }
  void dfs(const a& graph, long i, std::vector<bool>& visited, long d, std::vector<long>& path) {
    if( d == n - 1 ) {
      xs.push_back(path);
      return;
    }
    visited[i] = true;
    path.push_back(i);
    for(typename a::e edge : graph[i]) {
      if( visited[edge.d] ) continue;
      dfs(graph, edge.d, visited, d + 1, path);
    }
    path.pop_back();
    visited[i] = false;
  }
  typename std::vector<std::vector<long>>::iterator begin() { return xs.begin(); }
  typename std::vector<std::vector<long>>::iterator end() { return xs.end(); }
  long size() const {
    return xs.size();
  }
};

struct Solver {
  long n, m;
  std::vector<std::array<long, 2>> xs;
  Solver() {
    S002 reader;
    reader >= n >= m >m>= xs;
  }
  void solve() {
    std::vector<S004> edges;
    for(std::array<long, 2> e : xs) {
      e[0] -= 1, e[1] -= 1;
      edges.push_back(S004(e[0], e[1]));
      edges.push_back(S004(e[1], e[0]));
    }
    S005<S004> graph(edges, n);
    S026<S005<S004>> ham(graph, 0);
    long res = ham.size();
    printf("%ld\n", res);
  }
  // long dfs(const S005<S004>& graph, long i, std::vector<bool>& visited, long d) {
  //   if( d == n - 1 ) return 1;
  //   long res = 0;
  //   visited[i] = true;
  //   for(S004 edge : graph[i]) {
  //     if( visited[edge.d] ) continue;
  //     res += dfs(graph, edge.d, visited, d + 1);
  //   }
  //   visited[i] = false;
  //   return res;
  // }
};
 
int main() {
  loop std::unique_ptr<Solver>(new Solver())->solve();
  return 0;
}