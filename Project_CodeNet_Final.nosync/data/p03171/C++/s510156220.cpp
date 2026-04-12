#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;
const ll MAXN = 3e3 + 5;

vector < ll > p(MAXN, 0);

ll sum(ll l, ll r){
  return p[r] - p[l - 1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n;
  cin >> n;
  vector < ll > a(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    p[i] = p[i - 1] + a[i];
  }

  if(n == 1){
    cout << a[1] << '\n';
    return 0;
  }

  vector < vector < ll > > dp(n + 1, vector < ll > (n + 1, 0));
  for(int i = 1; i <= n; i++) dp[i][i] = a[i];
  for(int i = n; i >= 0; i--){
    for(int j = i + 1; j <= n; j++){
      dp[i][j] = sum(i, j) - min(dp[i + 1][j], dp[i][j - 1]);
    }
  }

  ll x = dp[1][n], y;
  if(dp[2][n] <= dp[1][n - 1]) y = dp[2][n];
  else y = dp[1][n - 1];

  cout << x - y << '\n';
}
