#include <iostream>
using namespace std;
#define ll long long
#define inf 10000000000000

ll dp[3001][3001];
ll a[3001];

ll rec (ll l, ll r) {
  if (dp[l][r] != inf) return dp[l][r];
  if (l == r) return a[l];
  return dp[l][r] = max(-1 * rec(l, r - 1) + a[r], -1 * rec(l + 1, r)+ a[l]);    
}

int main () {
  ll n;
  cin >> n;
  for (ll i = 0; i <= 3000; i++) {
    for (ll j = 0; j <= 3000; j++) {
      dp[i][j] = inf;  
    }  
  }
  for (ll i = 0; i < n; i++) cin >> a[i];
  cout << rec(0, n - 1) << endl;  
}