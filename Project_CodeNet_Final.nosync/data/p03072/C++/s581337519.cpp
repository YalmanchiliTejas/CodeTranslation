#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  int n,ans = 1;
  cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  for(int i = 1; i < n; i++) {
    bool flag = true;
    for(int j = 0; j < i; j++) {
      if(h[j] > h[i]) {
        flag = false;
        break;
      }
    }
    if(flag) ans++;
  }
  cout << ans << endl;
  return 0;
}