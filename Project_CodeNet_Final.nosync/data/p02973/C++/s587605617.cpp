#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> c(n,-1);
  rep(i,0,n) {
    int a;
    cin >> a;
    int k = lower_bound(c.begin(), c.end(), a) - c.begin();
    c[k-1] = a;
  }
  int ans = 0;
  rep(i,0,n) {
    if (c[i] != -1) ans++;
  }
  cout << ans << endl;
  return 0;
}
