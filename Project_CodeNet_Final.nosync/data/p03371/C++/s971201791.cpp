#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 1e18;
  rep(i,100001) {
    ll total = 2 * c * i + max(x-i,0) * a + max(y-i,0) * b;
    if (total < ans) ans = total;
  }
  cout << ans << endl;
}
