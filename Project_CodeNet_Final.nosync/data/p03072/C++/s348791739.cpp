#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  int mx = 0,ans = 0;
  for(int i = 0; i < n; i++){
    int h; cin >> h;
    if(i == 0){
      mx = h;
      ans++;
    }
    else {
      if(mx <= h){
        mx = h;
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
