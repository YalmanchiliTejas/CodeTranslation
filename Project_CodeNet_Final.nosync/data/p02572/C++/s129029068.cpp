#include <iostream>
#include <vector>
using namespace std;
int MOD = 1000000007; 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<long long> b(n+1, 0);
  for(int i=0;i<n;i++) {
    cin >> a[i];
    b[i+1] = a[i] + b[i];
  }
  
  long long ans=0;
  long long sum;
  for(int i=0;i<n;i++) {
    sum = (b[n] - b[i+1]) % MOD;
    ans += a[i] * sum;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}