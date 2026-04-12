
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
#define rev_rep(i, n) for(int i = n - 1; i >= 0; --i)
#define dump(x) cout << #x << ":" << x << "\n";
#define all(v) v.begin(), v.end()

template<class T1, class T2>
std::ostream& operator << (std::ostream& os, std::pair<T1, T2>& pair){
  os << '(' << pair.first << ',' << pair.second << ')';
  return os;
}
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

ll p(ll N){
  if(N == 0){
    return 1;
  }else{
    return p(N - 1) * 2 + 1;
  }  
}

ll a(ll N){
  if(N == 0){
    return 1;
  }else{
    return a(N - 1) * 2 + 3;
  }
}

ll f(ll N, ll X){
  if(N == 0){
    if(X <= 0){
      return 0;
    }else{
      return 1;
    }
  }
  
  if(X < a(N - 1) + 2){
    return f(N - 1, X - 1);
  }
  if(X == a(N - 1) + 2){
    return p(N - 1) + 1;
  }else{
    return p(N - 1) + 1 + f(N - 1, X - 2 - a(N - 1));
  }
  
}

#ifndef BOOST_TEST_MAIN
int main(int const argc, char const** argv){
  ll N, X;
  cin >> N >> X;

  cout << f(N, X);
}
#endif
