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
#define rep(i, n) for(long i = 0; i < (n); i++)

using namespace std;

void solve() {
  long N;
  cin >> N;
  vector<long> A(N);
  rep (i, N) cin >> A[i];
  sort(A.begin(), A.end());

  // 1 2 3 | 4 5 6
  // 1 2 | 3 4 5

  long plus_sum = 0;
  long minus_sum = 0;
  long plus_sum_2 = 0;
  long minus_sum_2 = 0;

  if (N % 2 == 0) {
    for (long i = 0; i < N / 2; i++) minus_sum += A[i];
    for (long i = 0; i < N / 2 - 1; i++) minus_sum += A[i];
    for (long i = N / 2; i < N; i++) plus_sum += A[i];
    for (long i = N / 2 + 1; i < N; i++) plus_sum += A[i];
  } else {
    for (long i = 0; i < N / 2; i++) minus_sum += A[i];
    for (long i = 0; i < N / 2; i++) minus_sum += A[i];
    for (long i = N / 2; i < N; i++) plus_sum += A[i];
    for (long i = N / 2 + 2; i < N; i++) plus_sum += A[i];

    for (long i = 0; i < N / 2 + 1; i++) minus_sum_2 += A[i];
    for (long i = 0; i < N / 2 - 1; i++) minus_sum_2 += A[i];
    for (long i = N / 2 + 1; i < N; i++) plus_sum_2 += A[i];
    for (long i = N / 2 + 1; i < N; i++) plus_sum_2 += A[i];
  }

  long ans = max(plus_sum - minus_sum, plus_sum_2 - minus_sum_2);

  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
