#include <bits/stdc++.h>
using namespace std;

int main() {
  int i,j;
  long long mod = 1000000007;
  int n;
  cin >> n;
  vector<long long> a(n, 0),b(n+1, 0);
  for(i = 0; i < n;i++){
    cin >> a.at(i);
    b.at(i+1) += b.at(i) + a.at(i);
  }
  
 
  long long ans = 0;
  for(i = 0; i < n;i++){
    long long sum = ((b.at(n) - b.at(i+1)) % mod);
    ans += a.at(i)*sum;
    ans %= mod;
  }
  

  cout << ans << endl;

}
