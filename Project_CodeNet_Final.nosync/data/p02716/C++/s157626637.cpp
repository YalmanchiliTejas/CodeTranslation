#include <bits/stdc++.h>
typedef long long int ll;
 
using namespace std;
 
const ll INF = 1e17;
ll N;
ll a[300000];
ll l[300000];
ll r[300000];
map<ll, ll> dp[300000];
 
int main() {
  cin >> N;
  for (int i=0; i<N; i++)
    cin >> a[i];
  for (int i=0; i<N/2; i++) {
    l[i] = 2*i;
    r[N/2-1-i] = (N-1) - 2*i;
  }
  // for (int i=0; i<N/2; i++) {
  //   cout << l[i] << "-" << r[i] << endl;
  // }
  for (int j=l[0]; j<=r[0]; j++)
    dp[0][j] = a[j];
  for (int i=1; i<N/2; i++) for(int j=l[i]; j<=r[i]; j++) {
    dp[i][j] = -INF;
    for (int bj=l[i-1]; bj<=min(r[i-1], (ll)j-2); bj++) {
      dp[i][j] = max(dp[i][j], a[j] + dp[i-1][bj]);
    }
    // printf("dp[%d][%d]=%ld\n", i, j, dp[i][j]);
  }
  ll ans = -INF;
  for (int j=l[N/2-1]; j<=r[N/2-1]; j++) {
    ans = max(ans, dp[N/2-1][j]);
  }
  cout << ans << endl;
  return 0;
}