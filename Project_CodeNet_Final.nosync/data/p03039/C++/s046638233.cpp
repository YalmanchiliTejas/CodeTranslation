#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>

using namespace std;

long long mod = 1e9+7;
vector<long long> fact;
vector<long long> factinv;

void initfact(long long n) {
  fact.push_back(1);
  for (long long i = 1; i < n+1; i++) {
    fact.push_back((fact.back()*i)%mod);
  }
}

long long sqr(long long n) {
  return n*n%mod;
}

long long bipow(long long c, long long n) {
  if (n == 0) {
    return 1;
  } else if(n == 1) {
    return c;
  } else if(n%2 == 0) {
    return sqr(bipow(c, n/2))%mod;
  } else {
    return (c*sqr(bipow(c, (n-1)/2)))%mod;
  }
}

void initfactinv() {
  factinv.push_back(bipow(fact.back(), mod-2));
  for (long long i = fact.size()-1; i > 0; i--) {
    factinv.push_back((factinv.back()*(i))%mod);
  }
  reverse(factinv.begin(), factinv.end());
}

long long C(long long n, long long m) {
  if (n < m) {
    return 0;
  }
  return (((fact[n]*factinv[m])%mod)*factinv[n-m])%mod;
}

int main() {
  long long n, m, k;

  std::cin >> n >> m >> k;

  initfact(n*m-2);
  initfactinv();

  long long ans = 0;

  for (int i = 1; i < n; i++) {
    ans += ((((((n-i) * m) % mod) * m) % mod) * i) % mod;
    ans %= mod;
  }

  for (int i = 1; i < m; i++) {
    ans += ((((((m-i) * n) % mod) * n) % mod) * i) % mod;
    ans %= mod;
  }

  ans *= C(n*m-2, k-2);
  ans %= mod;

  std::cout << ans << std::endl;

  return 0;
}

