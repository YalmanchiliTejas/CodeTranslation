#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<long long> v(n);
  
  for (int i = 0; i < n; i++) 
    cin >> v.at(i);
  
  long long sum = 0;
  long long mod = 1000000007;
  
  for (int i = 0; i < n; i++)
    sum += v.at(i) % mod;
  
  sum %= mod;
  
  long long ans = 0;
  
  for (int i = 0; i < n; i++) {
    sum -= v.at(i) % mod;
    if (sum < 0) sum += mod;
    ans += (sum * v.at(i)) % mod;
  }
  
  cout << ans % mod<< endl;
}