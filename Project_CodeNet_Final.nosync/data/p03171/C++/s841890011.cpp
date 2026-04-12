#include <bits/stdc++.h>
#include <iomanip>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

pair<ll, ll> dp[3000][3000];

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) {dp[i][i].first = a[i]; dp[i][i].second = 0;}
  for (int i=1; i<n; i++) for(int j=0; j<n-i; j++) {
    if (a[j] + dp[j+1][j+i].second - dp[j+1][j+i].first > 
        a[j+i] + dp[j][j+i-1].second - dp[j][j+i-1].first) {
      dp[j][j+i].first = a[j] + dp[j+1][j+i].second;
      dp[j][j+i].second = dp[j+1][j+i].first;
    } else {
      dp[j][j+i].first = a[j+i] + dp[j][j+i-1].second;
      dp[j][j+i].second = dp[j][j+i-1].first;
    }
//    cout << j << " " << j+i << " " << dp[j][j+i].first << " " << dp[j][j+i].second << endl;
  }
  cout << dp[0][n-1].first - dp[0][n-1].second << endl;
}
