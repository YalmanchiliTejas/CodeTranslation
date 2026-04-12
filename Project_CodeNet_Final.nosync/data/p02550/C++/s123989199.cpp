#include <bits/stdc++.h>
using namespace std;

#define repi(i, a, n) for (int i = a; i < (int)(n); ++i)
#define rep(i, n) repi(i, 0, n)
#define all(v) begin(v), end(v)

using ll = long long;

int main() {
  // freopen("1.txt", "rb", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N;
  cin >> N;
  int X, M;
  cin >> X >> M;

  int h = 0;
  {
    vector<int> H(M, -1);
    int pos = X;
    while (H[pos] == -1) {
      H[pos] = h;
      pos = (1LL * pos * pos) % M;
      ++h;
    }
  }

  ll result = 0;
  int head = min((ll)h, N);
  int pos = X;
  rep(i, head) {
    result += pos;
    pos = (1LL * pos * pos) % M;
  }

  ll cycle_sum = 0;
  int cycle_len = 0;
  vector<bool> H(M);
  do {
    ++cycle_len;
    cycle_sum += pos;
    H[pos] = true;
    pos = (1LL * pos * pos) % M;
  } while (!H[pos]);

  N -= head;
  result += cycle_sum * (N / cycle_len);
  N %= cycle_len;
  rep(i, N) {
    result += pos;
    pos = (1LL * pos * pos) % M;
  }

  cout << result << '\n';
  
  return 0;
}
