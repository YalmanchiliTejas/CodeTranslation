#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
const int MOD = 1000000007;
int main() {
  int n; cin >> n;
  long long int a[50];
  rep(i,n) cin >> a[i];
  // sort(a,a+n,greater<int>());
  long long int ans = 0;
  bool f = true;
  while (f) {
    f = false;
    rep(i,n) {
      if (a[i] >= n) {
        f = true;
        long long int pluscnt = a[i] / n;
        a[i] = a[i] % n;
        
        ans += pluscnt;
        rep(j,n) {
          if (i==j) continue;
          a[j] += pluscnt;
        }
        
      }
    }
  }
  cout << ans << endl;
}