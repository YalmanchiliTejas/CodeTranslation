#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

ll dp[101][2][101];
int K;
ll rec(string &S, int k = 0, bool tight = true, int state = 0) {
  if (k == S.size()) {
    if (state == K)
      return 1;
    else
      return 0;
  }

  if (dp[k][tight][state] != -1)
    return dp[k][tight][state];

  int x = S[k] - '0';
  int r = tight ? x : 9;
  ll res = 0;
  rep(i, 0, r + 1) {
    int st = i == 0 ? state : state + 1;
    res += rec(S, k + 1, tight && i == r, st);
  }

  return dp[k][tight][state] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string n;
  cin >> n >> K;
  memset(dp, -1, sizeof(dp));
  ll ans = rec(n);

  cout << ans << endl;
}
