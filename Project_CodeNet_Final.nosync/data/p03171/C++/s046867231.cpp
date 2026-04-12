//Daniel Grzegorzewski
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
}

const int N = 3006;

int n, a[N];
PII dp[N][N][2];

signed main() {
  init_ios();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    dp[i][i][0] = {a[i], 0};
    dp[i][i][1] = {0, a[i]};
  }
  for (int len = 2; len <= n; ++len)
    for (int i = 1; i+len-1 <= n; ++i) {
      int j = i+len-1;
      PII tmp1 = {a[i]+dp[i+1][j][1].ST, dp[i+1][j][1].ND};
      PII tmp2 = {a[j]+dp[i][j-1][1].ST, dp[i][j-1][1].ND};
      if (tmp1.ST-tmp1.ND > tmp2.ST-tmp2.ND)
        dp[i][j][0] = tmp1;
      else
        dp[i][j][0] = tmp2;
      tmp1 = {dp[i+1][j][0].ST, a[i]+dp[i+1][j][0].ND};
      tmp2 = {dp[i][j-1][0].ST, a[j]+dp[i][j-1][0].ND};
      if (tmp1.ST-tmp1.ND < tmp2.ST-tmp2.ND)
        dp[i][j][1] = tmp1;
      else
        dp[i][j][1] = tmp2;
      
    }
  cout<<dp[1][n][0].ST-dp[1][n][0].ND<<"\n";
}