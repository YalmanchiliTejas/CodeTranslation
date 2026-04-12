#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <queue>
#include <list>
#include <unordered_map>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iomanip> // std::std::setprecision(X)
#include <limits>  //std::numeric_limits<int>::max(), min()

typedef long long ll;
long long N;
std::vector<long long> a, p;

long long build_a (long long k){
  if ( k == 0 ) return a[k] = 1;
  if ( a[k] != -1 ) return a[k];
  return a[k] = 2*build_a(k-1)+3;
}

long long build_p (long long k){
  if ( k == 0 ) return p[k] = 1;
  if ( p[k] != -1 ) return p[k];
  return p[k] = 2*build_p(k-1)+1;
}

long long sol ( ll k, ll X ) {
  if ( X == 0 ) return 0;
  else if ( X == 1 && k == 0 ) return 1;
  else if ( X == 1 ) return 0;

  else if ( 2 <= X && X <= 1+a[k-1] ) return sol(k-1, X-1);
  else if ( X == 2+a[k-1] ) return p[k-1]+1;
  else if ( (3+a[k-1]) <= X && X <= (2+2*a[k-1]) ) return p[k-1]+1+sol(k-1, X-2-a[k-1]);
  else if ( X >= a[k] ) return p[k];
  else assert(0);
}

int main (void) {

  long long X; std::cin >> N >> X;

  a.assign(N+1, -1);
  p.assign(N+1, -1);

  build_a(N);
  build_p(N);
  std::cout << sol(N, X) << std::endl;
  return 0;
}