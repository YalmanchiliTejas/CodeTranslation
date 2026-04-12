#include <bits/stdc++.h>
using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1; finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
  long long n, m, k;
  cin>>n>>m>>k;
  COMinit();
  long long ans = 0;
  for (int i=1; i<=m; i++) {
    long long cnt = n * n % MOD * (i - 1 - (m - i)) % MOD;
    if (cnt < 0) {
      cnt += MOD;
    }
    cnt = cnt * COM(n * m - 2, k - 2) % MOD * i % MOD;
    ans = (ans + cnt) % MOD;
  }
  for (int i=1; i<=n; i++) {
    long long cnt = m * m % MOD * (i - 1 - (n - i)) % MOD;
    if (cnt < 0) {
      cnt += MOD;
    }
    cnt = cnt * COM(n * m - 2, k - 2) % MOD * i % MOD;
    ans = (ans + cnt) % MOD;
  }
  cout<<ans<<endl;
}