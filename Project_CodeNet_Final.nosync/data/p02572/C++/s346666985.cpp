#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}


int main() {
  int64_t x = 1000000007;  
  int N;
  cin >> N;
  vector<int64_t> A(N);

  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  int64_t S;
/*  
  for (int i = 0; i < N-1; i++){
    for (int j = i+1; j < N; j++){
      S += (A[i] * A[j])%x;
    }
  }
*/
  
  int64_t Sum=0;
  int64_t SquareSum=0;
  for (int i = 0; i < N; i++){
    Sum += A[i];
    Sum = Sum%x;
    SquareSum += (A[i]*A[i]);
    SquareSum = SquareSum%x;
  }
  
  
  S = ((Sum * Sum) - SquareSum)%x;
  //cout << S << endl;
  if (S < 0) { S += x; }
  //cout << modinv(2,x) << endl;
  S = S * modinv(2,x);
  
  int64_t ans = S%x;
  
  cout << ans;  
}
