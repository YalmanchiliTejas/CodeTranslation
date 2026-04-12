#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,M,K;
  cin >> N >> M >> K;
  long long ans = 0;
  long long Ki = 1;
  long long perKi;
  for (int i=2; i<K+1; i++) {
    Ki *= i;
    Ki %= 1000000007;
  }
  long long moto;
  perKi = Ki;
  for (int i=0; i<9; i++) {
    moto = perKi;
    for (int i=0; i<9; i++) {
      perKi *= moto;
      perKi %= 1000000007;
    }
  }
  for (int i=0; i<5; i++) {
    perKi *= Ki;
    perKi %= 1000000007;
  }
  long long ansN = 0;
  long long ansM = 0;
  for (int i=1; i<N; i++) {
    ansN += i*(N-i);
    ansN %= 1000000007;
  }
  ansN *= M;
  ansN %= 1000000007;
  ansN *= M * 2;
  ansN %= 1000000007;
  
  for (int i=1; i<M; i++) {
    ansM += i*(M-i);
    ansM %= 1000000007;
  }
  ansM *= N;
  ansM %= 1000000007;
  ansM *= N * 2;
  ansM %= 1000000007;
  
  ans = ansN + ansM;
  
  long long KC2 = K * (K-1) / 2;
  KC2 %= 1000000007;
  ans *= KC2;
  ans %= 1000000007;
  cerr << ans << endl;
  
  for (int i=0; i<K-2; i++) {
    ans *= (N*M-i-2);
    ans %= 1000000007;
  }
  cerr << ans << endl;
  cerr << perKi << endl;
  ans *= perKi;
  ans %= 1000000007;
  cout << ans << endl;
  
  return 0;
}