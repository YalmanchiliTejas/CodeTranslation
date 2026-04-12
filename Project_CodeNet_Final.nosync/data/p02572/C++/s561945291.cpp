#include <bits/stdc++.h>
using namespace std;

#define repi(i, a, n) for (int i = a; i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define all(v) begin(v), end(v)

using ll = long long;

const int kMod = 1000 * 1000 * 1000 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
  }

  vector<int> S(N);
  S[N - 1] = A[N - 1] % kMod;
  for (int i = N - 2; i >= 0; --i) {
    S[i] = (S[i + 1] + A[i]) % kMod;
  }

  int result = 0;
  rep(i, N - 1) {
    int extra = (1LL * A[i] * S[i + 1]) % kMod;
    result = (result + extra) % kMod;
  }

  cout << result << '\n';

  return 0;
}
