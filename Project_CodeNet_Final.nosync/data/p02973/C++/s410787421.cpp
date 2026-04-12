#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pl = pair<ll,ll>;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}


void solve(long long N, std::vector<long long> A){
  ll ans = 0;
  vector<ll> v;
  for(ll i=0; i<N; i++) {
    ll j = lower_bound(v.begin(), v.end(), A[i]) - v.begin(); //number of elements which are smaller than A[i]
    if(j == 0) { // not found
      v.insert(v.begin(), A[i]);
      ans++;
    } else { //found
      v[j-1] = A[i];
    }
    //sort(v.begin(), v.end());f
  }
  std::cout << ans << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  std::vector<long long> A(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&A[i]);
  }
  solve(N, std::move(A));
  return 0;
}
