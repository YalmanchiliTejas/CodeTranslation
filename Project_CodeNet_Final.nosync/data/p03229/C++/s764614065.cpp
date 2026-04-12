#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
using namespace std;
using ll = long long;

int main(void) {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) { cin >> A[i]; }

  sort(A.rbegin(), A.rend());
  if (N % 2 == 0) {
    ll ret = 0;
    rep(i, N / 2 - 1) { ret += A[i] * 2; }
    ret += A[N / 2 - 1];
    ret -= A[N / 2];
    for (int i = N / 2 + 1; i < N; ++i) {
      ret -= A[i] * 2;
    }
    cout << ret << endl;
  } else {
    ll ret1 = 0;
    rep(i, N / 2 - 1) { ret1 += A[i] * 2; }
    ret1 += A[N / 2 - 1];
    ret1 += A[N / 2];
    for (int i = N / 2 + 1; i < N; ++i) {
      ret1 -= 2 * A[i];
    }

    ll ret2 = 0;
    rep(i, N / 2) { ret2 += A[i] * 2; }
    ret2 -= A[N / 2];
    ret2 -= A[N / 2 + 1];
    for (int i = N / 2 + 2; i < N; ++i) {
      ret2 -= 2 * A[i];
    }


    cout << max(ret1, ret2)  << endl;
  }

  return 0;
}
