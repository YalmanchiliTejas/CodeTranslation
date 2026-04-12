/***
*   author:   ashikur rahman
*   created:  30.08.2020 14:19:12
***/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<ll> ar(n);
  ll sum = 0;
  for (int i = 0; i < n; i++){
    cin >> ar[i];
    sum += ar[i];
    sum %= mod;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++){
    sum -= ar[i];
    if (sum < 0){
      sum += mod;
    }
    ans += (sum * ar[i]) % mod;
    ans %= mod;
  }
  cout << ans << "\n";
  return 0;
}