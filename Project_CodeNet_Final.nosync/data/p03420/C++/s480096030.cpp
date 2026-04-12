#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  for(int i=k+1; i<=n; ++i){
    int x = n /i *i;
    ans += x /i * (i-k);
    if(x != n) ans += max(0, (n-x) -max(1,k) +1);
  }
  cout << ans << endl;
}