#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  int n;
  cin >> n;
  long long MOD = 1e9 + 7;
  vector < long long > vt(n + 1), ara(n + 1);;
  for(int i = 1 ; i <= n ; ++i) {
    cin >> vt[i];
    ara[i] = vt[i];
  }
  for(int i = n - 1 ; i >= 1 ; --i) {
   	vt[i] += vt[i + 1]; 
    vt[i] %= MOD;
  }
  long long ans = 0;
  for(int i = 1 ; i < n ; ++i) {
    ans +=  (1LL * ara[i] * vt[i + 1]) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}