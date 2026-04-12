#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,k,ans = 0;
  cin >> n >> k;
  if(k == 0){
    ans = n*n;
    cout << ans << endl;
    return 0;
  }
  for(long b = 1;b <=n;b++){
    if(b-k > 0){
      ans += b-k;
      ans += (n-b)/b*(b-k);
      if((n-b)%b-(k-1) >= 0) ans += (n-b)%b-(k-1);
    }
  }
  cout << ans << endl;
}
