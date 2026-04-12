#include <bits/stdc++.h>
using namespace std;

int L, dp[200001];
string s, t;



int solve(int i) {
  if (i == L) return 1;
  if (i > L) return 0;
  if (dp[i] != -1) return dp[i];
  if (solve(i + s.size())) return dp[i] = 1;
  if (solve(i + t.size())) return dp[i] = 1;
  else return dp[i] = 0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(dp, -1, sizeof dp);

  cin >> L >> s >> t;

  if (s > t) swap(s, t);

  string ans = "", tmp;

  for (int i = 0; i < 2; ++i) {
    tmp = "";
    if (i == 1) swap(s, t);

    while (tmp.size() < L) {
      if (solve(tmp.size() + s.size())) tmp += s;
      else tmp += t;
    }

    if (ans == "") ans = tmp;
    else ans = min(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}