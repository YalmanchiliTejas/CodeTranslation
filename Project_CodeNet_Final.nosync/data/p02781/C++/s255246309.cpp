#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

// [桁][未満フラグ][0の個数]
ll dp[101][2][101];
string N;
int K;

ll memo(int i, int smaller, int k) {
  if (i >= N.size()) {
    return k == K;
  }

  if (dp[i][smaller][k] != -1) {
    return dp[i][smaller][k];
  }

  ll ret = 0;
  int current = N[i] - '0';
  int limit = smaller ? 9 : current;
  for (int d = 0; d <= limit; d++) {
    ret += memo(i + 1, smaller || d < current, k + (d != 0));
  }

  return dp[i][smaller][k] = ret;
}

int main() {

  // fill(dp[0][0], dp[0][0] + 101 * 2 * 101, -1LL);
  memset(dp, -1, 101 * 2 * 101 * sizeof(ll));

  cin >> N;
  cin >> K;

  ll cnt = memo(0, 0, 0);
  cout << cnt << endl;
}