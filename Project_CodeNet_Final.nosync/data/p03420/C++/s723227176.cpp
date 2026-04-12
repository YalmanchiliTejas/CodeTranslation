#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}


void solve(long long N, long long K){
  ll ans = 0;
  for(ll a=K+1; a<=N; a++) {
    ans+=(N/a)*(a-K)+max(0ll, N%a-K+1);
  }
  if(K==0) {
    ans -= N;
  }
  std::cout << ans << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long K;
  scanf("%lld",&K);
  solve(N, K);
  return 0;
}

