#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void){
  
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0;i < n;i++) cin >> a[i];
  
  vector<ll> sum(n);
  
  ll tmp = 0;
  for(int i = 0;i < n;i++){
    tmp += a[i];
    tmp %= 1000000007;
    sum[i] = tmp;
  }
  
  long long int ans = 0;
  
  for(int i = 0;i < n - 1;i++){
    ans += sum[i] * a[i+1];
    ans %= 1000000007;
  }
  
  cout << ans << endl;
}