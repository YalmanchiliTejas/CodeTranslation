#include<bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int , int>;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  int m = 0, ans = 0;
  rep(i, n) {
    int x; cin >> x;
    ans += m <= x;
    m = max(m, x);
  } cout << ans;
}
    
