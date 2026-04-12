#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  long long ans = 0;
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  long long sum = 0;
  for(int i = 0; i < n; i++) sum += a.at(i);
  for(int i = 0; i < n-1; i++){
    sum -= a.at(i);
  	ans += (a.at(i) * (sum%1000000007))%1000000007;
  }
  cout << ans%1000000007 << endl;
  
}