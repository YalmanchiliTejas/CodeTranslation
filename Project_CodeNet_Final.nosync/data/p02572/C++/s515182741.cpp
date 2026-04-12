#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  long long mod = pow(10, 9) + 7, sum = 0, ans = 0;
  for(auto k : a) sum += k;
  for(int i = 0; i < n; i++){
    long long k = a.at(i);
    sum -= k;
    ans += sum % mod * k % mod;
    ans %= mod;
  }
  
  cout << ans << endl;
}