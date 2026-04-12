#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); ++i)


int main() {
  int n;
  cin >> n;
  int x = 800 * n;
  int y = (n / 15) * 200;
  int ans = x - y;
  
  
  cout << ans << endl;
  return 0;
  
}