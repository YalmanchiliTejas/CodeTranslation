#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
constexpr long long mod = 1e9 + 7;

long long extgcd(long long a, long long b, long long &x, long long &y){
  //a*x - b*y = gcd(a, b)
  long long d = a;
  if(b){
    d = extgcd(b, a%b, y, x);
    y -= (a / b)*x;
  }else{
    x = 1;
    y = 0;
  }
  return d;    
}

long long combination(long long n, long long k){
  if(n < k) return 0;
  long long ret = 1LL;
  for(long long i = 0; i < k; ++i){
    ret *= (n-i)%mod;
    ret %= mod;
  }
  long long d = 1LL;
  for(long long i = 1; i <= k; ++i){
    d *= i%mod;
    d %= mod;
  }
  long long d_inv, y;
  extgcd(d, mod, d_inv, y);
  d_inv %= mod;
  d_inv += mod;
  d_inv %= mod;
  //cout << ret << " " << d << " " << d_inv << " " << d*d_inv%mod << endl;
  assert((d*d_inv)%mod == 1);
  ret *= d_inv%mod;
  ret %= mod;
  return ret;
}

int main(){
  long long N, D, X;
  while(cin >> N >> D >> X, N){
    vector< vector<long long> > DP(N+1, vector<long long>(N+1,0));
    DP[0][0] = 1;
    for(int i = 1; i <= N; ++i){
      long long t = 0;
      for(int j = 0; j <= N; ++j){
        if(j >= X){
          t -= DP[i-1][j-X];
          t %= mod;
          t += mod;
          t %= mod;
        }
        DP[i][j] = t;
        t += DP[i-1][j];
        t %= mod;
      }
    }
    long long ans = 0;
    for(int i = 1; i <= N; ++i){
      //cout << DP[i][N] << " ";
      //cout << combination(D, i) << endl;
      ans += combination(D, i)*DP[i][N]%mod;
      ans %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}

