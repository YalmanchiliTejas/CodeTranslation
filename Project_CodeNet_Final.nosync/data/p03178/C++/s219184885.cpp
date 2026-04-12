#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

// 桁数、未満フラグ、mod D
ll dp[100001][2][101];
string K;
int D;

void addmod(ll& src, const ll& tgt, const ll& mod=1000000007) {
  int ans = ((src % mod) + (tgt % mod)) % mod;
  if (ans < 0) ans += mod;
  src = ans;
}

ll memo(int i, int smaller, int modD) {
  // 桁数を超えたら終了
  if (i >= K.size()) {
    return modD == 0;
  }

  // メモしてある値ならそれを返す
  if (dp[i][smaller][modD] != -1) {
    return dp[i][smaller][modD];
  }

  // 超えてるフラグ
  int current = K[i] - '0';
  int limit = smaller ? 9 : current;
  ll ret = 0;
  for (int d = 0; d <= limit; d++) {
    ll tmp = memo(i + 1, smaller ? smaller : d < limit, (modD + d) % D);
    addmod(ret, tmp);
  }

  return dp[i][smaller][modD] = ret;
}

int main() {
  rep(i, 100001) rep(j, 2) rep(k, 101) { dp[i][j][k] = -1; }

  cin >> K;
  cin >> D;

  ll cnt = memo(0, 0, 0);
  addmod(cnt, -1);
  cout << cnt << endl;
}