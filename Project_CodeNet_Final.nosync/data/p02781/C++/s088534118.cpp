#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

string s;
int n, k;
ll dp[1010][5][2];

ll dfs(int i = 0, int x = 0, bool l = true) {
  if (i == n) return x == k;
  if (x > k) return 0;
  ll &cc = dp[i][x][l];
  if (~cc) return cc;

  ll ans = 0;
  int u = l ? s[i]-'0' : 9;
  loop(d,0,u+1) {
    ans += dfs(i + 1, x + (d != 0), l && d == u);
  }
  return cc = ans;
}

int main() {
  cin >> s;
  cin >> k;
  n = s.size();
  memset(dp, -1, sizeof(dp));
  cout << dfs() << endl;
  return 0;
}
