#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (m); i < (int)(n); ++i)
#define INF 2000000000

#ifdef LOCAL
  #define eprintf(...) fprintf(stdout, __VA_ARGS__)
#else
  #define eprintf(...) 0
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

int ctoi(char c) {
  return c - '0';
}

template <class C>
void printContainer(C &container, const char *delim=",") {
  for(const auto &e : container) {
    std::cout << e << delim;
  }
  std::cout << "\n";
}

// Greatest common divisor
template<class T>
T gcd(T x, T y) {
  if(x < y) {
    std::swap(x, y);
  }
  T r = x % y;
  while(r != 0) {
    x = y;
    y = r;
    r = x % y;
  }
  return y;
}

// Least common multiple
template<class T>
T lcm(T x, T y) {
  return (x*y)/gcd(x,y);
}

int main() {
  char a, b, c;
  cin >> a >> b >> c;
  string str {a, b, c};
  int num = atoi(str.c_str());
  string ans = num % 4 ? "NO" : "YES";
  cout<<ans<<endl;

  return 0;
}
