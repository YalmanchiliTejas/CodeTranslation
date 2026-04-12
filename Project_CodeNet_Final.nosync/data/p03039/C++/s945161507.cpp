#include <bits/stdc++.h>
#define N (long long)(1e9 + 7)
#define MAX 500000
using namespace std;

long long factorial[MAX] = {0}, finverse[MAX] = {0},
          inverse[MAX] = {0};

void smodfact() {
  factorial[0] = factorial[1] = 1;
  finverse[0] = finverse[1] = 1;
  inverse[1] = 1;
  for(int i = 2; i < MAX; ++i) {
    factorial[i] = factorial[i - 1] * i % N;
    inverse[i] = N - (inverse[N % i] * (N / i)) % N;
    finverse[i] = finverse[i - 1] * inverse[i] % N;
  }
}

long long calccomb(long long n, long long k) {
  if(n == k && n == 0) return 1;
  if(n < 0 || k < 0 || n < k) return 0;
  return factorial[n] * finverse[k] % N * finverse[n - k] %
         N;
}

long long n, m, k;
vector<vector<long long>> dp;

long long solve();

int main() {
  smodfact();
  cin >> m >> n >> k;
  dp.resize(m);
  for(int i = 0; i < m; ++i) dp[i].assign(n, 0);
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = 0;
  for(long long i = 0; i < m; ++i)
    for(long long j = 0; j < n; ++j) {
      ans += ((i + 1) * i / 2 % N * (2 * j + 1) % N +
              (j + 1) * j / 2 % N * (2 * i + 1) % N) %
             N;
      ans %= N;
    }
  while(ans < 0) ans += N;
  ans %= N;
  return ans * calccomb((n * m - 2), k - 2) % N;
}