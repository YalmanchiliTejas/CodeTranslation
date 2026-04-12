#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 110;
ll dp[N][5][2];
int n;
string num;

ll rec(int pos, int k, int tight) {
  if(k < 0) return 0;
  if(pos == n) return (k == 0);
  if(dp[pos][k][tight] != -1) return dp[pos][k][tight];
  int h = (num[pos] - '0');
  ll res = 0;
  for(int i = 0; i < 10; ++i) {
    if(tight && i > h) break;
    res += rec(pos + 1, k - (i != 0), tight && (i == h));
  }
  return dp[pos][k][tight] = res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> num;
  n = (int) num.length();
  int k; cin >> k;
  memset(dp, -1, sizeof dp);
  cout << rec(0, k, 1) << '\n';
  return 0;
}
