// Code for C - Sum of product of pairs
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define FOR(i,x,y) for(ll i=x;i<(ll)(y);i++)

#define MOD 1000000007
#define mod(x) ( (x) % MOD + MOD ) % MOD

#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<typename T, typename U> void view(const std::map<T, U>& m){ for(const auto& e : m){ std::cout << e.first << "=>" << e.second << " "; } std::cout << std::endl; }

int main() {
  int N;
  cin >> N;

  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
  }

  ll t = 0;
  ll u = 0;
  REP(i, N - 1) {
    u = ( u + A[i] % MOD ) % MOD;
    t = ( t + ( u * A[i+1] ) % MOD ) % MOD;
  }

  cout << t << endl;
  return 0;
}
