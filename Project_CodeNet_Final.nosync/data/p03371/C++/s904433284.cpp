#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 1001001001;
  rep(i, x+1) {
    int res = a*i + b* max(y-x+i,0) + 2*c*(x-i);
    ans = min(res, ans);
  }
  rep(i, y+1) {
    int res = b*i + a* max(x-y+i,0) + 2*c*(y-i);
    ans = min(res, ans);
  }
  cout << ans << endl;
  return 0;
}