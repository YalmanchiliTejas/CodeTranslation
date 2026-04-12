#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()
#define allg(v) v.begin(), v.end(), greater<int>()



signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  int n, k;
  cin >> n >> k;
  
  int ans = 0;
  rep(i, 1, n+1) {
    int cnt = 0;
    if(k <= i-1) {
      if(k == 0) {
        cout << n*n << "\n";
        return 0;
      }
      else {
        cnt += (n/i)*(i-1-k+1);
        cnt += max(0LL, n%i - k+1);
      }
    }
    ans += cnt;
  }
  
  cout << ans << "\n";

}