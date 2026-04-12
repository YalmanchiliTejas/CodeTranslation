#include <iostream>
using namespace std;
using ll = long long;

string N; int n;
int dfs(int keta, int rest, bool lower) {
  // あとrest個数字を選べて、残りketa桁決めれるときの場合の数
  if (rest < 0)
    return 0;
  if (keta == n)
    return rest > 0 ? 0 : 1;

  if (lower) {
    return 9 * dfs(keta+1, rest-1, lower) + dfs(keta+1, rest, lower);
  }

  // まだ未確定
  int D = N[keta] - '0';
  int ans = dfs(keta+1, rest, (D > 0)); // 0を使う
  if (D > 0) {
    ans += (D-1) * dfs(keta+1, rest-1, true);
    ans += dfs(keta+1, rest-1, false);
  }
  return ans;
}

int main() {
  int K;
  cin >> N >> K;

  n = N.size();

  // まず、Nより桁数が小さい場合をカウントしたい。
  ll ans = 0;
  ans += dfs(1, K, true);
  ans += ((N[0]-'0')-1) * dfs(1, K-1, true);
  ans += dfs(1, K-1, false);

  cout << ans << endl;
  return 0;
}
