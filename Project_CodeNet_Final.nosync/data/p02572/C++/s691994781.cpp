#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int INF = 1e9;

int main(){
  long long n;
  const long long max_n = 2 * 1e5;
  long long a[max_n + 1];
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  
  long long sum_a[max_n + 1];
  sum_a[0] = a[0] % MOD;
  for(int i = 1; i < n; i++){
    sum_a[i] = sum_a[i-1] + a[i];
    sum_a[i] %= MOD;
  }

  long long ans = 0;
  for(int i = 0; i < n-1; i++){
    long long tmp = sum_a[n-1] - sum_a[i];
    tmp %= MOD;
    if(tmp < 0) tmp += MOD;
    tmp = tmp * a[i];
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}