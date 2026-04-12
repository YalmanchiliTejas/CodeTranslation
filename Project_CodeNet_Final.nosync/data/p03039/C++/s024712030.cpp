#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//INT_MAX	2,147,483,647 = 2*1.0e9


const int MOD = 1000000007;
const int nMax = 200050;

long long fact[nMax];  // Array of Factorial
long long invFact[nMax]; // Array of Factorial of Inverse Elements
long long inv[nMax]; // Array of Inverse Elements

void calcFact(){
    fact[0] = 1; fact[1] = 1;
    invFact[0] = 1; invFact[1] = 1;
    inv[1] = 1;     //1に対する逆元は1

    for(int i = 2; i < nMax; i++){
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = (- inv[MOD % i] * (MOD/i) ) % MOD + MOD;
        invFact[i] = invFact[i-1] * inv[i] % MOD;
    }
}

long long calcComb(long long _n, long long _k){
    if (_n < 0 || _k < 0) return 0;
    if (_n < _k) return 0;
    return fact[_n] * (invFact[_n-_k] * invFact[_k] % MOD) % MOD;
}

int main(){
  ll N, M, K;
  cin >> N >> M >> K;

  ll ans = 0;
  calcFact();


  //xについて求める
  ll pat = calcComb(N*M-2, K-2);
  ll dx_sum = 0;
  for(int i = 0; i < M; i++){
    dx_sum += ll(i) * ll(M-i);
    dx_sum %= MOD;
  }
  dx_sum *= N;
  dx_sum %= MOD;
  dx_sum *= N;
  dx_sum %= MOD;

  //yについて求める
  ll dy_sum = 0;
  for(int i = 0; i < N; i++){
    dy_sum += ll(i) * ll(N-i);
    dy_sum %= MOD;
  }
  dy_sum *= M;
  dy_sum %= MOD;
  dy_sum *= M;
  dy_sum %= MOD;

  ans = dy_sum + dx_sum;
  ans %= MOD;

  ans *= pat;
  ans %= MOD;

  cout << ans << endl;

  return 0;
}
