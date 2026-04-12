#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()
#define let auto const

i64 N;
vector<i64> a;

vector<vector<bool>> flag(3030, vector<bool>(3030, false));
vector<vector<i64>> dp(3030, vector<i64>(3030, 0));
i64 rec(i64 l, i64 r) {
  if(r < l) return 0;
  if(flag[l][r]) return dp[l][r];
  i64 turn = !!((N - (r - l + 1)) & 1);
  if(turn == 0) {
    dp[l][r] = max(rec(l + 1, r) + a[l], rec(l, r - 1) + a[r]);
  }
  else {
    dp[l][r] = min(rec(l + 1, r) - a[l], rec(l, r - 1) - a[r]);
  }
  flag[l][r] = true;
  return dp[l][r];
}

int main() {
  cin >> N;
  a.resize(N);
  for(int i = 0;i < N;i++) cin >> a[i];
  cout << rec(0, N - 1) << endl;
}
