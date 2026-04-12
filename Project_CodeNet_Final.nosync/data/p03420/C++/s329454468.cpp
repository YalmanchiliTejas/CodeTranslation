#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  
  long long ans = 0;
  for(int i = k+1; i <= n; i++){
    long long plus = max(0, (n/i) * (i-k) + max(0, (n%i) - k + 1));
    ans += plus;
    if(k == 0) ans--;
  }
  
  cout << ans << endl;
}