#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}
ll len(ll n) {
  return pow(2, n+2)-3;
}

ll f(ll n, ll x) {
  if(x==1) {
    if(n==0)
      return 1;
    else
      return 0;
  } else if(x <= 1 + len(n-1)) {
    return f(n-1, x-1);
  } else if(x == 2 + len(n-1)) {
    return f(n-1, x-2)+1;
  } else if(x < len(n)) {
    return 1 + f(n-1, len(n-1)) + f(n-1, x-(2+len(n-1)));
  } else {
    return f(n-1, (x-3)/2)*2 +1;
  }
}

void solve(long long N, long long X){
  std::cout << f(N, X) << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long X;
  scanf("%lld",&X);
  solve(N, X);
  return 0;
}

