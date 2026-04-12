#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
using namespace std;

typedef long long ll;

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

template <uint64_t N>
class Combination {
  using _Tp = long long;
public: 
  array<_Tp, N> fac, finv, inv;

  constexpr
  Combination() {
    init();     
  }

  constexpr
  void init() {
    fac[0] = fac[1] = 1;        
    finv[0] = finv[1] = 1;      
    inv[1] = 1; 
    for(int i = 2; i < N; i++){    
      fac[i] = fac[i-1] * i % MOD;      
      inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;        
      finv[i] = finv[i-1] * inv[i] % MOD;       
    }
  }

  // n!! * k!^(-1) * ((n - k)!)^(-1)   
  constexpr
  _Tp comb(_Tp n, _Tp k) const {
    if (n < k) return 0;        
    if (n < 0 || k < 0) return 0;       
    return fac[n] * (finv[k]* finv[n - k] % MOD) % MOD; 
  }

  constexpr
  _Tp operator ()(_Tp n, _Tp k) const {
    return comb(n, k);
  }
};

void add(int64_t & a, const int64_t b) {
  a = (a + b) % MOD;
}

void mul(int64_t & a, const int64_t b) {
  a = (a * b) % MOD;
}

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  Combination<3000100> comb;

  int64_t ans1 = 0, ans2 = 0;
  for (int i = 1; i < n; ++i) {
    add(ans1, i * (n - i));
  }
  mul(ans1, m * m % MOD);
  
  for (int i = 1; i < m; ++i) {
    add(ans2, i * (m - i));
  }
  mul(ans2, n * n % MOD);
  
  add(ans1, ans2);
  
  mul(ans1, comb(n * m - 2, k - 2));
  // debug(comb(n * m - 2, k - 2));
  cout << ans1 << endl;
}
