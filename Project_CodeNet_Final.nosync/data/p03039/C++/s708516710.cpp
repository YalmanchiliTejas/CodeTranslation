#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;

// (N*M)C(K)  (N*M-2)C(K-2) * (|x-x|+|y-y|)
// 2C0

ll M = 1000000007;

ll mod(ll x) {
  return (x + M) % M;
}

ll inv(ll x) {
  ll m = M-2;
  ll r = 1;
  ll y = x;
  while (m > 0) {
    if (m & 1) r = mod(r * y);
    y = mod(y * y);
    m >>= 1;
  }
  return r;
}

ll combi(int n, int k) {
  ll p = 1;
  for (int i = n; i > n-k; i--) {
    p = mod(p * i);
  }
  ll q = 1;
  for (int i = k; i > 0; i--) {
    q = mod(q * i);
  }
  return mod(p * inv(q));
}

ll acc(ll x) {
  return mod(mod(x * (x+1)) * inv(2));
}

int main() {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  ll c = combi(N*M-2, K-2);
  ll s = 0;
  ll xs = 0;
  for (int x1 = 0; x1 < M; x1++) {
    xs = mod(xs + mod(acc(M-1-x1)));
  }
  //printf("xs=%lld\n", xs);
  ll xxs = 0;
  for (int x1 = 0; x1 < M; x1++) {
    xxs = mod(mod(xxs + acc(x1)) + acc(M-1-x1));
  }
  //printf("xxs=%lld\n", xxs);
  for (int y1 = 0; y1 < N; y1++) {
    s = mod(s + xs);
    s = mod(s + xxs * (N-1-y1));
    s = mod(s + mod(mod(M*M) * acc(N-1-y1)));
  }
  ll ans = mod(c * s);
  printf("%lld\n", ans);
}
