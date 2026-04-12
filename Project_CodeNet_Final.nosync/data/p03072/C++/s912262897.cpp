#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >>n;
  vector<int> h(n);
  rep(i,n) cin >>h[i];
  int ans = 1;
  int curMax = h[0];
  for(int i = 1; i < n; i++){
    if(h[i]>=curMax && h[i]>=h[i-1]) {
      ans++;
    }
    curMax = max(curMax, h[i]);
  }
  cout << ans << endl;
  return 0;
}