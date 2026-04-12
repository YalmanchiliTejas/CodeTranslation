#include <bits/stdc++.h>
using namespace std;

int main() {
  long long m = 1000000007;
  
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  
  long long ans = 0;
  long long sum = 0;
  
  for(int i=0; i<n; i++){
    sum += a[i]%m;
    sum %= m;
  }
  
  for(int i=0; i<n-1; i++){
    sum -= a[i]%m;
    if(sum < 0) sum += m;
    
    ans += ((a[i]%m) * sum)%m;
    ans %= m;
  }
  
  cout << ans << endl;

	return 0;
}
