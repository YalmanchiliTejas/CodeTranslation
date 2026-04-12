#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < n; i++)

using namespace std;

long modinv(long a){long M=MOD,b=M,u=1,v=0;while(b)u-=a/b*v,swap(u,v),a%=b,swap(a,b);return (u%M+M)%M;}

long foo (long N) {
  if (N == 0) return 0;
  long result = foo(N-1) + (N * (N-1) / 2);
  return result % MOD;
}

int main(void) {
  cout.precision(12);

  long N, M, K;
  cin >> N >> M >> K;

  vector<long> memo(N*M+1);
  memo[0] = 1;
  for (long i = 1; i <= N*M; i++) {
    memo[i] = (memo[i-1] * i) % MOD;
  }

  // 置き方
  long puttings = memo[N*M];
  puttings = (puttings * modinv(memo[K])) % MOD;
  puttings = (puttings * modinv(memo[N*M - K])) % MOD;

  // 期待値
  /*
  pair<long, long> n_expect = make_pair(foo(N), N*N);
  pair<long, long> m_expect = make_pair(foo(M), M*M);
  */
  // pair<long, long> expect = make_pair(foo(N) * M * M + foo(M) * N * N, N * N * M * M);

  // K == N*M のときのコスト
  long a = foo(N) * M * M + foo(M) * N * N;
  a %= MOD;
  a = (a * modinv(memo[2])) % MOD;

  long x = (N * M) * (N * M - 1) / 2;
  x %= MOD;
  long y = K * (K-1) / 2;
  y %= MOD;
  y *= puttings;
  y %= MOD;

  long result = a;
  result *= y;
  result %= MOD;
  result *= modinv(x);
  result %= MOD;

  result *= 2;
  result %= MOD;

/*
  cout << "puttings: " << puttings << endl;
  cout << "a: " << a << endl;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
*/

  cout << result << endl;

  return 0;
}
