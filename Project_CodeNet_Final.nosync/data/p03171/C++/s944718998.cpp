#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
int main() {
	ll i,j,k,l,m,n,t;
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }

  vector<vector<ll> > dp(n+1, vector<ll>(n+1, 0));

  for (i = 1; i <= n;i++){
    for (j = i; j > 0 ;j--){
      dp[i][j] = max(a[i-1] - dp[i - 1][j], a[j-1] - dp[i][j+1]);
      // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
    }
  }

  cout << dp[n][1] << endl;

  return 0;
}