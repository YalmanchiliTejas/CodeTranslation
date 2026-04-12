#include <iostream>
#include <cstdint>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

LL modcom(const LL n, const LL k, LL mod) {
  LL nfact = 1;
  for(LL i=1; i<=n; i++) {
    nfact = (nfact * i) % mod;
  }

  LL s = max(k,n-k);
  std::vector<LL> inv(s+1);
  inv[1] = 1;
  for(LL i=2; i<= s; i++) {
    inv[i] = mod - inv[mod%i] * (mod / i) % mod;
  }
  LL kinv_fact = 1;
  for(LL i=2; i<=k; i++) {
    kinv_fact = (kinv_fact * inv[i]) % mod;
  }
  LL nkinv_fact = 1;
  for(LL i=2; i<=(n-k); i++) {
    nkinv_fact = (nkinv_fact * inv[i]) % mod;
  }

  if(n<k) { return 0; }
  if(n<0 || k<0) { return 0; }
  return nfact * (kinv_fact * nkinv_fact % mod) % mod;
}

int main() {

  LL N, M, K;
  cin >> N >> M >> K;
  LL mod = 1000000007;

  // consider x-diff
  LL score = 0;
  for(LL dx=1; dx<M; dx++) {
    score += dx * (M-dx) * N * N;
    score %= mod;
  }

  for(LL dy=1; dy<N; dy++) {
    score += dy * (N-dy) * M * M;
    score %= mod;
  }

  LL c = modcom(N*M-2, K-2, mod);
  score = (score * c) % mod;

  cout << score << endl;

  return 0;
}

