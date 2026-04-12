
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits>
#include <map>
#include <numeric>

#define ll long long
using namespace std;
static ll imin = std::numeric_limits<ll>::min();
static ll imax = std::numeric_limits<ll>::max();
#define rep(i, n) for(int i = 0; i<n; ++i)
#define rep1(i, n) for(int i = 1; i<n; ++i)
#define debug(x) cout << #x << ":" << x << "\n";
#define all(v) v.begin(), v.end()

template<class T>
std::ostream& operator << (std::ostream& os, std::vector<T>& vec){
  std::size_t n = vec.size();
  if(n == 0){
    return os;
  }
  os << " ";
  for(int i = 0; i<n - 1; ++i){
    os << vec[i] << " ";
  }
  os << vec[n - 1];
  os << std::endl;
  return os;
}


#ifndef BOOST_TEST_MAIN
int main(int const argc, char const** argv){
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll usec = 0;
  if(x > y){
    usec = c * y * 2 + a * (x - y);
  }else{
    usec = c * x * 2 + b * (y - x);
  }
  // debug(a * x + b * y);
  // debug(usec);
  // debug(c * max(x, y));
  cout << min({
               a * x + b * y,
               usec,
               c * max(x, y) * 2
    });
  
}
#endif


