#include <string.h>

#include <algorithm>
#include <iostream>

#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main(void) {
  int N;
  cin >> N;
  int A[N];
  rep1(i, N) cin >> A[i];
  ll B[N];  //累積和
  B[0] = A[0];
  rep2(i, 1, N) B[i] = B[i - 1] + A[i];

  ll ans = 0;
  ll sum;

  rep1(i, N - 1) {
    sum = (B[N - 1] - B[i]) % MOD;
    ans += (ll)A[i] * sum;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}