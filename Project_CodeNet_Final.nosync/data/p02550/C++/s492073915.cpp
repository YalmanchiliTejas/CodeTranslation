#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

ll N, X, M;
ll A[100005];
map<ll, int> reverse_map;

ll modpow(ll a, ll n, ll MOD) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return res;
}

int main() {
  cin >> N >> X >> M;

  A[1] = X;
  reverse_map[X] = 1;
  int loop_start = 1, loop_end = N+1;
  for (int i = 1; i < N; i++) {
    ll n = modpow(A[i], 2, M) % M;
    A[i+1] = n;
    // printf("A[%d] = %lld, ", i+1, n); if (i % 10 == 0) puts("");
    if (reverse_map[n] > 0) {
      loop_start = reverse_map[n];
      loop_end = i;
      break;
    }
    reverse_map[n] = i+1;
  }

  ll mod = (N - loop_start + 1) % (loop_end - loop_start + 1);
  ll times = (N - loop_start + 1) / (loop_end - loop_start + 1);

  ll loop_sum = 0;
  for (int i = loop_start; i <= loop_end; i++) { loop_sum += A[i]; }

  ll ans = 0;
  for (int i = 1; i < loop_start; i++) { ans += A[i]; }
  ans += times * loop_sum;

  for (int i = 0; i < mod; i++) { ans += A[loop_start+i]; }

  // printf("loop_start = %d, loop_end = %d, loop_sum = %lld, times = %lld, mod = %lld\n", loop_start, loop_end, loop_sum, times, mod);

  printf("%lld\n", ans);
}
