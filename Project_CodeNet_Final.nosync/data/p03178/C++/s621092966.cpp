#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dbg3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;

template<class T>void Add(T &a, const T &b, const T &mod) {
  int val = (a % mod) + (b % mod);
  if (val < 0) { val += mod; }
  a = val;
}

void print() { std::cerr << endl; }
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  std::cerr << head << " ";
  print(std::forward<Tail>(tail)...);
}

const int MOD = 1e9 + 7;
string K;
int D;

int dp[11111][2][111];

signed main() {
  cin >> K >> D;
  int n = K.size();

  dp[0][0][0] = 1;
  for (int digit = 0; digit < n; digit++) {
    for (int smaller : {0, 1}) {
      int lim = (smaller == 1 ? 9 : K[digit] - '0');
      for (int num = 0; num <= lim; num++) {
        for (int modD = 0; modD < D; modD++) {
          Add(dp[digit+1][smaller || num < lim][(modD + num) % D], dp[digit][smaller][modD], MOD);
        }
      }
    }
  }

  int ans = 0;
  for (int smaller : {0, 1}) {
    Add(ans, dp[n][smaller][0], MOD);
  }
  // print(dp[n][0][0], dp[n][1][0]);
  Add(ans, -1LL, MOD);

  cout << ans << endl;

  return 0;
}
