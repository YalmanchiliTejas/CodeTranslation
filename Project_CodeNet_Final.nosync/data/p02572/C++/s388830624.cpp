#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int mod = 1000000007;
  int n;
  long long int a[200005];
  cin >> n;
  for (int x = 0; x < n; ++x) {
	cin >> a[x];
  }
  long long int sum = 0;
  for (int i = 1; i < n; ++i) {
   	   sum += a[i];
       sum = sum % mod;
  }
  long long int ans = 0;
  for (int j = 0; j < n-1; ++j) {
		ans += a[j] * sum;
        ans %= mod;
        sum -= a[j+1];
        if (sum < 0) {sum += mod;}
  }
  cout << ans << endl;
 return 0; 
}