#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
  int a;
  cin >> a;
  long long int b[a];
  int long long sum = 0;
  long long int ans = 0;
  for(int i=0;i<a;i++){
  cin >> b[i];
  sum += b[i];
  sum %= MOD;
  }
  for(int i=0;i<a;i++){
      sum -= b[i];
      if (sum < 0) sum += MOD;
      ans += sum*b[i];
      ans %= MOD;
  }
  cout << ans << endl;
}
