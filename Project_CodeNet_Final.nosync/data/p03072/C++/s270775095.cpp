#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<int> h(n+1);
  vector<int> maxh(n+1);
  h[0] = 1; maxh[0] = 1;
  int ans = 0;
  for(int i=1; i<=n; i++){
    cin >> h[i];
    maxh[i] = max(maxh[i-1], h[i]);
    if (h[i] >= maxh[i]) ans++;
  }
  cout << ans;
  return 0;
}