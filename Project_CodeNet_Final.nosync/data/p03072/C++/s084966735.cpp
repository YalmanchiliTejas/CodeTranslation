#include <bits/stdc++.h>
#define rep(i,n) for(int i; i<(n); i++)
using namespace std;

  
int main() {

  int n;
  cin >> n;
  
  vector<int> h(n);
  
  rep(i, n) cin >> h[i];
  
  int highest = h[0];
  int ans = 1;
  
  for(int i=1; i<n; i++)
  {
    if(highest <=h[i])
    {
      highest = h[i];
      ans++;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}