#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1e4+10, D = 101;

string s;
int d;
int dp[2][D][2];

void add(int& a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> d;
  int n = s.size();
  dp[1][0][0] = dp[1][0][1] = 1;
  for (int i = n-1; i >= 0; i--) {
    for (int r = 0; r < d; r++) {
      dp[0][r][0] = dp[0][r][1] = 0;
      for (int j = 0; j < 10; j++) {
        int nr = (r + j) % d;
        add(dp[0][r][1], dp[1][nr][1]);
      }
      for (int j = 0; j < s[i]-'0'; j++) {
        int nr = (r + j) % d;
        add(dp[0][r][0], dp[1][nr][1]);
      }
      int nr = (r + s[i]-'0') % d;
      add(dp[0][r][0], dp[1][nr][0]);
      //cerr << i << " " << r << " -> " << dp[0][r][0] << " " << dp[0][r][1] << nl;
    }
    swap(dp[0], dp[1]);
  }
  cout << (dp[1][0][0]+MOD-1)%MOD << nl;
  return 0;
}
