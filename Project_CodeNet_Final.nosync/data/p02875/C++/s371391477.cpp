#include <bits/stdc++.h>
#define MOD 998244353
#define MAX 10000006
using namespace std;
long long factorial[MAX] = {0}, finverse[MAX] = {0},
          inverse[MAX] = {0};

void smodfact() {
  factorial[0] = factorial[1] = 1;
  finverse[0] = finverse[1] = 1;
  inverse[1] = 1;
  for(int i = 2; i < MAX; ++i) {
    factorial[i] = factorial[i - 1] * i % MOD;
    inverse[i] = MOD - (inverse[MOD % i] * (MOD / i)) % MOD;
    finverse[i] = finverse[i - 1] * inverse[i] % MOD;
  }
}

long long calccomb(long long n, long long k) {
  if(n == k && n == 0) return 1;
  if(n < 0 || k < 0 || n < k) return 0;
  return factorial[n] * finverse[k] % MOD *
         finverse[n - k] % MOD;
}

long long cpow(long long base, long long x) {
  long long ans = 1;
  while(x) {
    if(x & 1) (ans *= base) %= MOD;
    (base *= base) %= MOD;
    x >>= 1;
  }
  return ans;
}

long long n;

long long solve();

int main() {
  smodfact();
  cin >> n;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = cpow(3, n);
  for(int i = n / 2 + 1; i <= n; ++i) {
    long long now = calccomb(n, i) * 2 % MOD;
    (now *= cpow(2, n - i)) %= MOD;
    ans -= now;
    (ans += MOD) %= MOD;
  }
  return ans;
}