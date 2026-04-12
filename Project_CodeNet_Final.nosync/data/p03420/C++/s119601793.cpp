#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,k;
  long long ans = 0;
  cin >> n >> k;
  if(k == 0){
    cout << n*n << endl;
    return 0;
  }
  for(int b = k+1;b <= n;b++){
    ans += (n/b)*(b-k);
    int edge = n-(n/b)*b-k+1;
    if(edge > 0) ans += edge;
  }
  cout << ans << endl;
}
