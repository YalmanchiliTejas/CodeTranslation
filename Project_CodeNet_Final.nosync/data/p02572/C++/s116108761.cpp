#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  /*
  ll sum = 0;
  ll ssum = 0;
  for (int i = 0; i < n; i++){
    sum = (sum + a[i]) % MOD;
    ssum = (ssum + a[i]*a[i]) % MOD;
  }

  ll ans = ((sum*sum - ssum) / 2 + MOD) % MOD;
  */

  vector<ll> sum(n + 1, 0);
  for (int i = 0; i < n; i++){
    sum[i+1] = (sum[i] + a[n-i-1]) % MOD;
  }
  ll ans = 0;
  for (int i = 0; i < n-1; i++){
    ans = (ans + a[i] * sum[n-i-1]) % MOD;
  }

  cout << ans << endl;

  return 0;
}
